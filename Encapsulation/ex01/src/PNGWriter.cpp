#include <PNGWriter.hpp>

void PNGWriter::writeBigEndian(std::ofstream &file, uint32_t value)
{
    file.put((value >> 24) & 0xFF);
    file.put((value >> 16) & 0xFF);
    file.put((value >> 8) & 0xFF);
    file.put(value & 0xFF);
}
void PNGWriter::writeBigEndian(std::vector<unsigned char> &vect, uint32_t value)
{
    vect.push_back((value >> 24) & 0xFF);
    vect.push_back((value >> 16) & 0xFF);
    vect.push_back((value >> 8) & 0xFF);
    vect.push_back(value & 0xFF);
}

uint32_t PNGWriter::crc32(const unsigned char *buf, size_t len)
{
    static uint32_t table[256];
    static bool initialized = false;

    if (!initialized)
    {
        for (uint32_t i = 0; i < 256; i++)
        {
            uint32_t c = i;
            for (size_t j = 0; j < 8; j++)
            {
                c = (c & 1) ? 0xEDB88320 ^ (c >> 1) : (c >> 1);
            }
            table[i] = c;
        }
        initialized = true;
    }

    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < len; i++)
    {
        crc = table[(crc ^ buf[i]) & 0xFF] ^ (crc >> 8);
    }
    return crc ^ 0xFFFFFFFF;
}

void PNGWriter::writeChunk(std::ofstream &file, std::vector<unsigned char> &chunk)
{
    uint32_t crc = crc32(chunk.data(), chunk.size());

    writeBigEndian(file, chunk.size() - 4);
    file.write(reinterpret_cast<const char *>(chunk.data()), chunk.size());
    writeBigEndian(file, crc);
}

void PNGWriter::writeIHDR(std::ofstream &file, uint32_t width, uint32_t height)
{
    std::vector<unsigned char> ihdrChunk;

    ihdrChunk.push_back('I');
    ihdrChunk.push_back('H');
    ihdrChunk.push_back('D');
    ihdrChunk.push_back('R');
    writeBigEndian(ihdrChunk, width);
    writeBigEndian(ihdrChunk, height);
    ihdrChunk.push_back(8); // Bit depth
    ihdrChunk.push_back(2); // Color type (TrueColor RGB)
    ihdrChunk.push_back(0); // Compression method
    ihdrChunk.push_back(0); // Filter method
    ihdrChunk.push_back(0); // Interlace method

    writeChunk(file, ihdrChunk);
}

std::vector<Token> PNGWriter::lz77_compress(const std::vector<uint8_t>& data, size_t window_size) {
    std::vector<Token> tokens;
    size_t data_size = data.size();
    size_t pos = 0;

    while (pos < data_size) {
        size_t match_distance = 0;
        size_t match_length = 0;

        size_t start = (pos > window_size) ? pos - window_size : 0;
        for (size_t i = start; i < pos; ++i) {
            size_t length = 0;
            while (length < 258 && pos + length < data_size && data[i + length] == data[pos + length]) {
                length++;
            }
            if (length > match_length) {
                match_length = length;
                match_distance = pos - i;
            }
        }

        if (match_length >= 3) {
            tokens.push_back(Token(false, 0, (int)match_distance, (int)match_length));
            pos += match_length;
        } else {
            tokens.push_back(Token(true, data[pos], 0, 0));
            pos++;
        }
    }

    return tokens;
}



// Count frequencies of symbols in the LZ77 token stream
std::map<int, int> count_frequencies(const std::vector<Token>& tokens) {
    std::map<int, int> frequencies;

    for (std::vector<Token>::const_iterator it = tokens.begin(); it != tokens.end(); ++it) {
        const Token& token = *it;
        if (token.is_literal) {
            frequencies[token.literal]++;
        } else {
            frequencies[256 + token.length]++;  // Count lengths
            frequencies[514 + token.distance]++;  // Offset distances to avoid collision with literals
        }
    }

    return frequencies;
}

HuffmanNode* build_huffman_tree(const std::map<int, int>& frequencies) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNode> pq;

    for (std::map<int, int>::const_iterator it = frequencies.begin(); it != frequencies.end(); ++it) {
        const std::pair<int, int>& pair = *it;
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Combine nodes until only one tree remains
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* parent = new HuffmanNode(-1, left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top(); // Root of the Huffman tree
}

void generate_codes(HuffmanNode* node, const std::string& code, std::map<int, std::string>& codes) {
    if (!node->left && !node->right) {
        // Leaf node
        codes[node->symbol] = code;
        return;
    }

    if (node->left) {
        generate_codes(node->left, code + "0", codes);
    }
    if (node->right) {
        generate_codes(node->right, code + "1", codes);
    }
}

std::string encode_tokens(const std::vector<Token>& tokens, const std::map<int, std::string>& codes) {
    std::string bitstream;

    for (std::vector<Token>::const_iterator it = tokens.begin(); it != tokens.end(); ++it) {
        const Token& token = *it;

        if (token.is_literal) {
            // Find the Huffman code for the literal
            std::map<int, std::string>::const_iterator code_it = codes.find(token.literal);
            if (code_it != codes.end()) {
                bitstream += code_it->second;
            }
        } else {
            // Find the Huffman code for the length
            std::map<int, std::string>::const_iterator length_code_it = codes.find(256 + token.length);
            if (length_code_it != codes.end()) {
                bitstream += length_code_it->second;
            }

            // Find the Huffman code for the distance
            std::map<int, std::string>::const_iterator distance_code_it = codes.find(514 + token.distance);
            if (distance_code_it != codes.end()) {
                bitstream += distance_code_it->second;
            }
        }
    }

    return bitstream;
}

std::vector<uint8_t> pack_bitstream(const std::string& bitstream) {
    std::vector<uint8_t> packed_data;
    uint8_t current_byte = 0;
    int bit_count = 0;

    for (std::string::size_type i = 0; i < bitstream.size(); ++i) {
        char bit = bitstream[i];
        current_byte |= (bit - '0') << bit_count;
        bit_count++;

        if (bit_count == 8) {
            packed_data.push_back(current_byte);
            current_byte = 0;
            bit_count = 0;
        }
    }

    if (bit_count > 0) {
        packed_data.push_back(current_byte); // Add remaining bits
    }

    return packed_data;
}

void write_codebook(std::vector<unsigned char>& idat_chunk, const std::map<int, int>& code_lengths)
{
    // Write code lengths for literals/lengths and distances.
    // We can split this into two parts: literal/length codebook and distance codebook.

    // Encode codebook for literals and lengths (symbols 0-285)
    for (int i = 0; i <= 285; ++i) {
        std::map<int, int>::const_iterator it = code_lengths.find(i);
        if (it != code_lengths.end()) {
            idat_chunk.push_back(it->second);  // The length of the Huffman code for this symbol
        } else {
            idat_chunk.push_back(0);  // No code for this symbol
        }
    }

    // Encode codebook for distances (symbols 286-287)
    for (int i = 286; i <= 287; ++i) {
        std::map<int, int>::const_iterator it = code_lengths.find(i);
        if (it != code_lengths.end()) {
            idat_chunk.push_back(it->second);  // The length of the Huffman code for this symbol
        } else {
            idat_chunk.push_back(0);  // No code for this symbol
        }
    }

    // Optional: Include any extra information for constructing the Huffman tree dynamically
    // This is where you would encode the lengths of each Huffman codeword if needed.
}


void PNGWriter::writeIDAT(std::ofstream& file, const std::vector<unsigned char>& image)
{
    // Step 1: Compress the image data
    std::vector<Token> compressed_data = lz77_compress(image, ZLIB_CONST); // 32 KB window
    std::map<int, int> frequencies = count_frequencies(compressed_data);
    HuffmanNode* root = build_huffman_tree(frequencies);
    std::map<int, std::string> codes;
    generate_codes(root, "", codes);

        // Step 2: Generate the code lengths for the Huffman tree
    std::map<int, int> code_lengths;
    for (std::map<int, std::string>::const_iterator it = codes.begin(); it != codes.end(); ++it) {
        int symbol = it->first;
        const std::string& code = it->second;
        code_lengths[symbol] = code.length();
    }

    // Step 3: Encode the tokens into a bitstream
    std::string bitstream = encode_tokens(compressed_data, codes);
    std::vector<uint8_t> packed_data = pack_bitstream(bitstream);

    // Step 4: Prepare the IDAT chunk
    std::vector<unsigned char> idat_chunk;
    idat_chunk.push_back('I');
    idat_chunk.push_back('D');
    idat_chunk.push_back('A');
    idat_chunk.push_back('T');

    // ZLIB header (method and flags)
    idat_chunk.push_back(0x78); // Compression method and flags (DEFLATE)
    idat_chunk.push_back(0xDA); // Additional flags (no dictionary)

    // Step 5: Write the codebook (lengths and codewords)
    // This is where you need to include the Huffman code lengths and symbols.
    
    // First, write out the literal/length and distance code lengths
    write_codebook(idat_chunk, code_lengths);

    // Step 6: Write the compressed data (tokens)
    idat_chunk.insert(idat_chunk.end(), packed_data.begin(), packed_data.end());

    // Step 7: Write the final chunk to the file
    writeChunk(file, idat_chunk);
}

void PNGWriter::using_zlib(std::ofstream& file, const std::vector<std::vector<std::vector<uint8_t> > >& image)
{
    std::vector<unsigned char> uncompressed_data;

    for (size_t y = 0; y < image.size(); y++)
    {
        uncompressed_data.push_back(0); 

        for (size_t x = 0; x < image[y].size(); x++)
        {
            uncompressed_data.push_back(image[y][x][0]); // Red
            uncompressed_data.push_back(image[y][x][1]); // Green
            uncompressed_data.push_back(image[y][x][2]); // Blue
        }
    }
    // Step 2: Compress the uncompressed image data using zlib
    uLongf compressed_size = compressBound(uncompressed_data.size()); // max size after compression
    std::vector<unsigned char> compressed_data(compressed_size);

    int result = compress(compressed_data.data(), &compressed_size, uncompressed_data.data(), uncompressed_data.size());

    if (result != Z_OK)
    {
        std::cerr << "Compression failed!" << std::endl;
        return;
    }

    compressed_data.resize(compressed_size); // Resize to the actual compressed size

    std::vector<unsigned char> idat_chunk;
    idat_chunk.push_back('I');
    idat_chunk.push_back('D');
    idat_chunk.push_back('A');
    idat_chunk.push_back('T');

    idat_chunk.insert(idat_chunk.end(), compressed_data.begin(), compressed_data.end());
    writeChunk(file, idat_chunk);
}

void PNGWriter::writeIEND(std::ofstream &file)
{
    file.write("\x00\x00\x00\x00", 4);
    file.write("IEND", 4);
    uint32_t crc = crc32(reinterpret_cast<const unsigned char *>("IEND"), 4);
    writeBigEndian(file, crc);
}


std::vector<uint8_t> PNGWriter::flatten_image(const std::vector<std::vector<std::vector<uint8_t> > >& image)   {
    std::vector<uint8_t> linear_data;

    for (std::vector<std::vector<std::vector<uint8_t> > >::const_iterator row = image.begin(); row != image.end(); ++row) 
    {
        linear_data.push_back(0); // Filter type
        for (std::vector<std::vector<uint8_t> >::const_iterator pixel = row->begin(); pixel != row->end(); ++pixel) 
        {
            linear_data.push_back((*pixel)[0]); // Red
            linear_data.push_back((*pixel)[1]); // Green
            linear_data.push_back((*pixel)[2]); // Blue
        }
    }

    return linear_data;
}


void PNGWriter::writePNG(const char *filename, const std::vector<std::vector<std::vector<uint8_t> > > &image)
{
    std::ofstream file(filename, std::ios::binary);

    // PNG signature
    const unsigned char signature[8] = {0x89, 'P', 'N', 'G', 0x0D, 0x0A, 0x1A, 0x0A};
    file.write(reinterpret_cast<const char *>(signature), 8);
    writeIHDR(file, image[0].size(), image.size());
    //using_zlib(file, image);
    writeIDAT(file, flatten_image(image));
    writeIEND(file);
    file.close();
}