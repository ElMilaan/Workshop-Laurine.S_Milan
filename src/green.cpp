#include <sil/sil.hpp>
#include "functions.hpp"

void green(sil::Image &img)
{
    for (glm::vec3 &color : img.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
}