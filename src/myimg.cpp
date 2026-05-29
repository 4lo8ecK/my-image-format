#include <fstream>

#include "myimg.h"

void Image::_init(uint32_t width, uint32_t height) {
    hdr.width = width;
    hdr.height = height;
    _size = sizeof(Pixel) * width * height;
    arr.reserve(width * height);
}

Image::Image(uint32_t width, uint32_t height) {
    _init(width, height);
}

Image::Image(const std::string& path) {
    read_from_file(path);
}

Image::~Image() {}

void Image::set_color(Pixel col) {
    for (uint32_t y = 0; y < hdr.height; y++) {
        for (uint32_t x = 0; x < hdr.width; x++) {
            arr[y * hdr.width + x] = col;
        }
    }
}

void Image::write_to_file(const std::string& path) {
    std::ofstream fl(path, std::ios::binary);
    
    if (!fl.is_open()) {
        perror("Не удалось открыть файл для записи\n");
    }
    
    fl.write(reinterpret_cast<const char*>(&hdr.width), sizeof(uint32_t));
    fl.write(reinterpret_cast<const char*>(&hdr.height), sizeof(uint32_t));
    fl.write(reinterpret_cast<const char*>(arr.data()), _size);
    
    fl.close();
}

void Image::read_from_file(const std::string& path) {
    std::ifstream fl(path, std::ios::binary);
    
    if (!fl.is_open()) {
        perror("Не удалось открыть файл для чтения\n");
    }
    
    fl.read(reinterpret_cast<char*>(&this->hdr), sizeof(_FileHeader));
    
    _init(hdr.width, hdr.height);

    fl.read(reinterpret_cast<char*>(arr.data()), _size);
    fl.close();
}