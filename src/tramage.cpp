#include <sil/sil.hpp>
#include "functions.hpp"

void tramage(sil::Image &img, float seuil)
{
    const float matrix[4][4]{
        {-0.5, 0, -0.375, 0.125},
        {0.25, -0.25, 0.375, -0.125},
        {-0.3125, 0.1875, -0.4375, 0.0625},
        {0.4375, -0.0625, 0.3125, -0.1875}};

    for (int x{0}; x < img.width(); x++)
    {
        for (int y{0}; y < img.height(); y++)
        {
            // la condition définit à partir de combien le pixel est considéré comme clair par le programme
            if (img.pixel(x, y).r + img.pixel(x, y).g + img.pixel(x, y).b > seuil + matrix[x % 4][y % 4] * 4)
            {
                img.pixel(x, y) = glm::vec3{1.f};
            }
            else
            {
                img.pixel(x, y) = glm::vec3{0.f};
            }
        }
    }
}