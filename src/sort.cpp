#include <sil/sil.hpp>
#include <vector>
#include "functions.hpp"

void sort(sil::Image &img)
{
    for (int i = 0; i < 300; i++)
    {
        int tab_begin = (i / 300.f) * img.pixels().size();
        int tab_end = ((i + 1) / 300.f) * img.pixels().size();
        std::sort(img.pixels().begin() + tab_begin, img.pixels().begin() + tab_end, [](glm::vec3 const &color1, glm::vec3 const &color2)
                  { return color1.r + color1.g + color1.b < color2.r + color2.g + color2.b; });
    }
}