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
    //заголовок массива
    _FileHeader         hdr;

    // размер выделяемой памяти
    // является произведением ширины, высоты и размера одного пикселя
    uint64_t            _size;

    // массив пикселей
    std::vector<Pixel>  arr;
    
    // метод для инициализации
    // вызывается в конструкторе или во время чтения из файла
    void _init(uint32_t width, uint32_t height);

public:
    // конструкторы класса
    Image() noexcept;
    Image(uint32_t width, uint32_t height);
    Image(const std::string& path);
    
    // деструктор
    ~Image();

    // set_color(Pixel) заливает всё изображение одним цветом
    void set_color(Pixel col);

    // запись в файл
    // используется std::ofstream с аргументом std::ios::binary
    void write_to_file(const std::string& path);

    // чтение из файла
    // используется std::ifstream с аргументом std::ios::binary
    void read_from_file(const std::string& path);
};
#endif