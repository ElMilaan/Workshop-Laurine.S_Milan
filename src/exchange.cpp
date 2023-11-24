#include <sil/sil.hpp>
#include "functions.hpp"

void exchange(sil::Image &img)
{
    for (glm::vec3 &color : img.pixels())
    {
        float r{color.r};
        color.r = color.b;
        color.b = r;
    }
}