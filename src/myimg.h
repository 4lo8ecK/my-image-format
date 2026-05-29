#pragma once

#ifndef MYIMG_H
#define MYIMG_H

#include <stdint.h>
#include <vector>
#include <string>

struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

#pragma pack(pop, 1)
struct _FileHeader {
    uint32_t    width;
    uint32_t    height;
};
#pragma pack(pop)

constexpr Pixel WHITE = {255, 255, 255}; // белый

class Image {
private:
    _FileHeader         hdr;
    uint64_t            _size;
    std::vector<Pixel>  arr;
    
    void _init(uint32_t width, uint32_t height);

public:
    Image() noexcept;
    Image(uint32_t width, uint32_t height);
    Image(const std::string& path);
    ~Image();

    void set_color(Pixel col);
    void write_to_file(const std::string& path);
    void read_from_file(const std::string& path);
};
#endif