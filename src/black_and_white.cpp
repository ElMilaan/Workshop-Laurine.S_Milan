#include <sil/sil.hpp>
#include "functions.hpp"

void b_w(sil::Image &img)
{
    for (glm::vec3 &color : img.pixels())
    {
        float avg{(color.r + color.b + color.g) / 3};
        color.r = color.b = color.g = avg;
    }
}