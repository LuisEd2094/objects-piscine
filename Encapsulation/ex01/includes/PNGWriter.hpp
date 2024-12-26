#ifndef PNGWRITER_HPP
#   define PNGWRITER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>
#include <cstring>
class PNGWriter
{
public:
    static void writePNG(const char *, const std::vector<std::vector<uint8_t> >&);
    ~PNGWriter() {};

private:
    PNGWriter() {};
    
    static void writeBigEndian(std::ofstream &, uint32_t);
    static void writeBigEndian(std::vector<unsigned char> &, uint32_t);
    static void writeIHDR(std::ofstream &, uint32_t, uint32_t);
    static void writeIDAT(std::ofstream &, const std::vector<std::vector<uint8_t> >&);
    static void writeIEND(std::ofstream &);
    static void writeChunk(std::ofstream &, std::vector<unsigned char> &);
    static uint32_t crc32(const unsigned char *, size_t);

};

#endif