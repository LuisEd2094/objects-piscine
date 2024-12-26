#include <PNGWriter.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>

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
    ihdrChunk.push_back(0); // Color type (grayscale)
    ihdrChunk.push_back(0); // Compression method
    ihdrChunk.push_back(0); // Filter method
    ihdrChunk.push_back(0); // Interlace method

    uint32_t crc = crc32(ihdrChunk.data(), ihdrChunk.size());
    writeChunk(file, ihdrChunk);
}

void PNGWriter::writeIDAT(std::ofstream &file, const std::vector<std::vector<uint8_t>> &image)
{
    std::vector<unsigned char> idat;
    idat.push_back('I');
    idat.push_back('D');
    idat.push_back('A');
    idat.push_back('T');

    for (size_t y = 0; y < image.size(); y++)
    {
        idat.push_back(0);
        idat.insert(idat.end(), image[y].begin(), image[y].end());
    }
    uint32_t crc = crc32(idat.data(), idat.size());
    writeChunk(file, idat);
}
void PNGWriter::writeIEND(std::ofstream &file)
{
    file.write("\x00\x00\x00\x00", 4);
    file.write("IEND", 4);
    uint32_t crc = crc32(reinterpret_cast<const unsigned char *>("IEND"), 4);
    writeBigEndian(file, crc);
}

void PNGWriter::writePNG(const char *filename, const std::vector<std::vector<uint8_t>> &image)
{
    std::ofstream file(filename, std::ios::binary);

    // PNG signature
    const unsigned char signature[8] = {0x89, 'P', 'N', 'G', 0x0D, 0x0A, 0x1A, 0x0A};
    file.write(reinterpret_cast<const char *>(signature), 8);

    writeIHDR(file, image[0].size(), image.size());
    writeIDAT(file, image);
    writeIEND(file);
    file.close();
}