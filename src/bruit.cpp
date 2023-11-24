#include <sil/sil.hpp>
#include "functions.hpp"

void bruit(sil::Image &img)
{
    for (glm::vec3 &color : img.pixels())
    {
        int al = random_int(1, 6);
        if (al == 2)
        {
            color.r = random_float(0, 1);
            color.b = random_float(0, 1);
            color.g = random_float(0, 1);
        }
    }
}