#include <sil/sil.hpp>
#include "functions.hpp"

void circle(sil::Image &img, int rayon, int absCenter, int ordCenter)
{
    for (int x{0}; x < img.height(); x++)
    {
        for (int y{0}; y < img.width(); y++)
        {
            if (std::pow(x - absCenter, 2) + std::pow(y - ordCenter, 2) < std::pow(rayon, 2) && // Pour éviter de calculer deux fois `std::pow(x - absCenter, 2) + std::pow(y - ordCenter, 2)`, vous auriez pu stocker le résultat dans une variable, et ensuite réutiliser cette variable aux deux endroits. Ca aurait fait moins de calculs et un code plus lisible.
                std::pow(x - absCenter, 2) + std::pow(y - ordCenter, 2) > std::pow(rayon - 8, 2))
            {
                img.pixel(x, y).r = 1;
                img.pixel(x, y).g = 1;
                img.pixel(x, y).b = 1;
            }
        }
    }
}