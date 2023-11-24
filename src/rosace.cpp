#include <sil/sil.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include "functions.hpp"

void rosace(sil::Image &img, int rayon)
{
    int absCenter = img.width() / 2;
    int ordCenter = img.height() / 2;
    circle(img, 100, absCenter, ordCenter);
    for (double i{0}; i < 2 * M_PI; i += M_PI / 3)
    {
        circle(img, 100, absCenter + rayon * std::cos(i), ordCenter + rayon * std::sin(i));
    }
}