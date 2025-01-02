#ifndef PNGWRITER_HPP
#define PNGWRITER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>
#include <map>
#include <queue>
#include <fstream>
#include <vector>
#include <iostream>

#include <zlib.h>

# ifndef ZLIB_CONST

# define ZLIB_CONST 32768 //32k as per standard

# endif

struct HuffmanNode {
    int symbol; // Literal, length, or distance
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(int s, int f) : symbol(s), frequency(f), left(NULL), right(NULL) {}
    HuffmanNode(int s, int f, HuffmanNode* left, HuffmanNode* right) : symbol(s), frequency(f), left(left), right(right) {}
};

struct CompareNode {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};


 struct Token
    {
        bool is_literal;
        unsigned char literal;
        int distance;
        int length;

        Token(bool is_literal, unsigned char literal, int distance, int length) : is_literal(is_literal), literal(literal), distance(distance), length(length) {}
    };

class PNGWriter
{
public:
    static void writePNG(const char *, const std::vector<std::vector<std::vector<uint8_t> > > &);
    ~PNGWriter() {};

private:
    PNGWriter() {};

    static void writeBigEndian(std::ofstream &, uint32_t);
    static void writeBigEndian(std::vector<unsigned char> &, uint32_t);
    static void writeIHDR(std::ofstream &, uint32_t, uint32_t);
    static void writeIDAT(std::ofstream &, const std::vector<unsigned char> &);
    static void writeIEND(std::ofstream &);
    static void writeChunk(std::ofstream &, std::vector<unsigned char> &);
    static uint32_t crc32(const unsigned char *, size_t);
    static std::vector<Token> lz77_compress(const std::vector<unsigned char> &, size_t);

    static std::vector<uint8_t> flatten_image(const std::vector<std::vector<std::vector<uint8_t> > >&);

    static void using_zlib(std::ofstream& file, const std::vector<std::vector<std::vector<uint8_t> > >& image);

};

#endif