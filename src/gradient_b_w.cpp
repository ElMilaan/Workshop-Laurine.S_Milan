#include <sil/sil.hpp>
#include "functions.hpp"

void gradient_b_w(sil::Image &img)
{
    for (float x{0}; x < img.width(); x++)
    {
        for (float y{0}; y < img.height(); y++)
        {
            img.pixel(x, y).r = x / img.width();
            img.pixel(x, y).g = x / img.width();
            img.pixel(x, y).b = x / img.width();
        }
    }
}