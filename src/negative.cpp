#include <sil/sil.hpp>
#include "functions.hpp"

void negative(sil::Image &img)
{
    for (glm::vec3 &color : img.pixels())
    {
        color.r = 1 - color.r;
        color.b = 1 - color.b;
        color.g = 1 - color.g;
    }
}