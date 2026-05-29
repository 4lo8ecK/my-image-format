#include "src/myimg.h"

int main() {
    Image* img = new Image(32, 32);
    img->set_color(WHITE);
    img->write_to_file("./image.myimg");
    delete img;

    Image* img2 = new Image("./image.myimg");
    img2->write_to_file("./img2.myimg");
    delete img2;
}