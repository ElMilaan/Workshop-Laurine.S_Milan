#include <sil/sil.hpp>
#include "functions.hpp"

void disc(sil::Image &img, int rayon)
{
    for (int x{0}; x < img.height(); x++)
    {
        for (int y{0}; y < img.width(); y++)
        {
            if (std::pow(x - img.width() / 2, 2) + std::pow(y - img.height() / 2, 2) < std::pow(rayon, 2))
            {
                img.pixel(x, y).r = 1;
                img.pixel(x, y).g = 1;
                img.pixel(x, y).b = 1;
            }
        }
    }
}