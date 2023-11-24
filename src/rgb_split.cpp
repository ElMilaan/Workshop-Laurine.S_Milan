#include <sil/sil.hpp>
#include "functions.hpp"

sil::Image rgb_split(sil::Image &img)
{
    sil::Image res{img.width(), img.height()};
    for (int x{0}; x < img.width(); x++)
    {
        for (int y{0}; y < img.height(); y++)
        {
            if (x <= 20)
            {
                res.pixel(x, y).r = img.pixel(x + 20, y).r;
                res.pixel(x, y).b = img.pixel(x, y).b;
            }
            else if (x >= img.width() - 20)
            {
                res.pixel(x, y).r = img.pixel(x, y).r;
                res.pixel(x, y).b = img.pixel(x - 20, y).b;
            }
            else
            {
                res.pixel(x, y).r = img.pixel(x + 20, y).r;
                res.pixel(x, y).b = img.pixel(x - 20, y).b;
            }
            res.pixel(x, y).g = img.pixel(x, y).g;
        }
    }
    return res;
}

// Parce qu'on trouve ça plus joli sans vert...
sil::Image rgb_split_without_green(sil::Image &img)
{
    sil::Image res{img.width(), img.height()};
    for (int x{0}; x < img.width(); x++)
    {
        for (int y{0}; y < img.height(); y++)
        {
            if (x <= 20)
            {
                res.pixel(x, y).r = img.pixel(x + 20, y).r;
                res.pixel(x, y).b = img.pixel(x, y).b;
            }
            else if (x >= img.width() - 20)
            {
                res.pixel(x, y).r = img.pixel(x, y).r;
                res.pixel(x, y).b = img.pixel(x - 20, y).b;
            }
            else
            {
                res.pixel(x, y).r = img.pixel(x + 20, y).r;
                res.pixel(x, y).b = img.pixel(x - 20, y).b;
            }
        }
    }
    return res;
}