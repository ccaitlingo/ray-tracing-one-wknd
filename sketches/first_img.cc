#include <iostream>

int main() {
    
    //Image

    int image_width = 256;
    int image_height = 256;

    //Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = 0; i < image_height; ++i) {
        std::clog << "Scanlines remaining: " << (image_height - i) << std::endl;
        for (int j = 0; j < image_width; ++j) {
            //Convention:
            //RBG components are represented (internally) by values
            //between 0.0 to 1.0
            auto r = double(j) / (image_width-1);
            auto g = double(i) / (image_height-1);
            auto b = 0;

            //They are then scaled to values between 0 and 255 before
            //we print them out!
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    //File is written to the std out stream
    //You need to direct it to an image file on the cmd line with ">"
    //i.e., sketches\first_img.exe > image.ppm
}