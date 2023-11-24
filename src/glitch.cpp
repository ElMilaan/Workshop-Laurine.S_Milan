#include <sil/sil.hpp>
#include "random.hpp"
#include "functions.hpp"

// Raté mais on l'a gardé, on aimait bien ^^
void glitch_rate_mais_style(sil::Image &img)
{
    for (int x{0}; x < img.width(); x++)
    {
        for (int y{0}; y < img.height(); y++)
        {
            int proba = random_int(1, 100);
            if (proba == 1)
            {
                int x1{random_int(x, img.width())};
                int y1{random_int(y, img.height())};
                int x2{random_int(x, img.width())};
                int y2{random_int(y, img.height())};
                for (int i{0}; i < random_int(1, 20); i++)
                {
                    for (int j{0}; j < random_int(1, 10); j++)
                    {
                        if (x1 + i < img.width() && y1 + j < img.height() && x2 + i < img.width() && y2 + j < img.height())
                        {
                            std::swap(img.pixel(x1 + i, y1 + j), img.pixel(x2 + i, y2 + j));
                        }
                    }
                }
            }
        }
    }
}

// Le vrai glitch qui fonctionne tout comme il faut
void glitch(sil::Image &img)
{
    for (int x{0}; x < img.width(); x++)
    {
        for (int y{0}; y < img.height(); y++)
        {
            int proba = random_int(1, 1500);
            if (proba == 1)
            {
                int x2{random_int(0, img.width())};
                int y2{random_int(0, img.height())};
                int al{random_int(1, 10)};
                for (int i{0}; i < random_int(15, 45); i++)
                {
                    for (int j{0}; j < al; j++)
                    {
                        if (x + i < img.width() && y + j < img.height() && x2 + i < img.width() && y2 + j < img.height())
                        {
                            std::swap(img.pixel(x + i, y + j), img.pixel(x2 + i, y2 + j));
                        }
                    }
                }
            }
        }
    }
}