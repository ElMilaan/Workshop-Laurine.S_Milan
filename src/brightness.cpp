#include <sil/sil.hpp>
#include "functions.hpp"

void brightness(sil::Image &img, float coeff)
{
    for (glm::vec3 &color : img.pixels())
    {
        color.r = std::pow(color.r, coeff);
        color.g = std::pow(color.g, coeff);
        color.b = std::pow(color.b, coeff);
    }
}