#include <sil/sil.hpp>
#include <complex>
#include "functions.hpp"

// Un peu pixélisé tout ça
void fractal_pixelized(sil::Image &img)
{
    for (float x{0}; x < img.width(); x++) // On n'aime pas faire des boucles où x est un float, car à cause des erreurs de précision lors de calculs entre float, on risque de louper une itération de la boucle (si les erreurs s'accumulent et dépassent 1, ce qui peut arriver sur de très grandes boucles). Il aurait été mieux que x soit un int, et de le static_cast en float au besoin (typiquement au moment de faire une division)
    {
        for (float y{0}; y < img.height(); y++)
        {
            std::complex<float> z{0.f, 0.f};
            std::complex<float> c{(x / 250 - 1) * 2, (y / 250 - 1) * 2};
            float color = 1;
            for (int i{0}; i < 100; i++)
            {
                z = z * z + c;
                color -= 0.0001;
                if (std::abs(z) > 2)
                {
                    img.pixel(x, y).r = 0.f;
                    img.pixel(x, y).g = 0.f;
                    img.pixel(x, y).b = 0.f;
                    break;
                }
            }
            if (std::abs(z) <= 2)
            {
                img.pixel(x, y).r = color;
                img.pixel(x, y).g = color;
                img.pixel(x, y).b = color;
            }
        }
    }
}

// La vraie belle fractale
void fractal(sil::Image &img)
{
    for (float x{0}; x < img.width(); x++)
    {
        for (float y{0}; y < img.height(); y++)
        {
            std::complex<float> z{0.f, 0.f};
            std::complex<float> c{(x / 250 - 1) * 2, (y / 250 - 1) * 2};
            float color = 0;
            for (int i{0}; i < 100; i++)
            {
                z = z * z + c;
                color += 0.03;
                if (std::abs(z) > 2)
                {
                    img.pixel(x, y).r = color;
                    img.pixel(x, y).g = color;
                    img.pixel(x, y).b = color;
                    break;
                }
            }
            if (std::abs(z) <= 2)
            {
                img.pixel(x, y).r = 0.8;
                img.pixel(x, y).b = 0.7;
                img.pixel(x, y).g = 0.1;
            }
        }
    }
}