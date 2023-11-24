#include <sil/sil.hpp>
#include "functions.hpp"

sil::Image rotation_90(sil::Image &img)
{
    sil::Image res{img.height(), img.width()};
    for (int x{0}; x < img.height(); x++)
    {
        for (int y{0}; y < img.width(); y++)
        {
            res.pixel(x, y) = img.pixel(img.width() - y - 1, x);
        }
    }
    return res;
}