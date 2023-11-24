#include <sil/sil.hpp>
#include "functions.hpp"

void mirror(sil::Image &img)
{
    for (int x{0}; x < img.width() / 2; x++)
    {
        for (int y{0}; y < img.height(); y++)
        {
            glm::vec3 temp = img.pixel(x, y);
            img.pixel(x, y) = img.pixel(img.width() - 1 - x, y);
            img.pixel(img.width() - 1 - x, y) = temp;
        }
    }
}

void fake_mirror(sil::Image &image)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (x >= image.width() / 2)
            {
                image.pixel(x, y) = image.pixel(image.width() - x, y);
            }
            else if (x <= image.width() / 2)
            {
                image.pixel(x, y) = image.pixel(image.width() / 2 - (image.width() / 2 - x), y);
            }
        }
    }
}