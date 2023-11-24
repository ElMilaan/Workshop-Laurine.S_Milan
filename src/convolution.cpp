#include <sil/sil.hpp>
#include "functions.hpp"

// Nous avons codé une fonction qui prend en paramètre un "mode"
// et effectue la convolution souhaité en fonction de ce que l'utilisateur met en 3eme paramètre.
// 1 = blur
// 2 = outline
// 3 = sharpen
// 4 = emboss
sil::Image convolution(sil::Image img, int coeff, int kernel)
{
    sil::Image res{img.width(), img.height()};
    for (int x{0}; x < res.width(); x++)
    {
        for (int y{0}; y < res.height(); y++)
        {
            // float avgR{0};
            // float avgG{0};
            // float avgB{0};
            glm::vec3 avg{0.f};
            switch (kernel)
            {
            case 1: // blur
                for (int i{-((coeff - 1) / 2)}; i < coeff - (coeff - 1) / 2; i++)
                {
                    for (int j{-((coeff - 1) / 2)}; j < coeff - (coeff - 1) / 2; j++)
                    {
                        if ((x + i >= 0 && y + j >= 0) && (x + i < img.width() && y + j < img.height()))
                        {
                            // avgR += img.pixel(x + i, y + j).r;
                            // avgG += img.pixel(x + i, y + j).g;
                            // avgB += img.pixel(x + i, y + j).b;
                            avg += img.pixel(x + i, y + j);
                        }
                    }
                }
                // res.pixel(x, y).r = avgR / std::pow(coeff, 2);
                // res.pixel(x, y).g = avgG / std::pow(coeff, 2);
                // res.pixel(x, y).b = avgB / std::pow(coeff, 2);
                avg /= std::pow(coeff, 2);
                res.pixel(x, y) = avg;
                break;

            case 2: // outline
                for (int i{-((coeff - 1) / 2)}; i < coeff - (coeff - 1) / 2; i++)
                {
                    for (int j{-((coeff - 1) / 2)}; j < coeff - (coeff - 1) / 2; j++)
                    {

                        if ((x + i >= 0 && y + j >= 0) && (x + i < img.width() && y + j < img.height()))
                        {
                            if (i == 0 && j == 0)
                            {
                                avg += img.pixel(x, y) * 8.f;
                            }
                            else
                            {
                                avg -= img.pixel(x + i, y + j);
                            }
                        }
                    }
                }
                res.pixel(x, y) = avg;
                break;

            case 3: // sharpen
                for (int i{-((coeff - 1) / 2)}; i < coeff - (coeff - 1) / 2; i++)
                {
                    for (int j{-((coeff - 1) / 2)}; j < coeff - (coeff - 1) / 2; j++)
                    {

                        if ((x + i >= 0 && y + j >= 0) && (x + i < img.width() && y + j < img.height()))
                        {
                            if (i == 0 && j == 0)
                            {
                                avg += img.pixel(x, y) * 5.f;
                            }
                            else if (i == 0 || j == 0)
                            {
                                avg -= img.pixel(x + i, y + j);
                            }
                        }
                    }
                }
                res.pixel(x, y) = avg;
                break;

            case 4: // emboss
                for (int i{-((coeff - 1) / 2)}; i < coeff - (coeff - 1) / 2; i++)
                {
                    for (int j{-((coeff - 1) / 2)}; j < coeff - (coeff - 1) / 2; j++)
                    {

                        if ((x + i >= 0 && y + j >= 0) && (x + i < img.width() && y + j < img.height()))
                        {
                            if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0))
                            {
                                avg += img.pixel(x, y);
                            }
                            else if ((i == 0 && j == -1) || (i == -1 && j == 0))
                            {
                                avg -= img.pixel(x + i, y + j);
                            }
                            else if (i == -1 && j == -1)
                            {
                                avg -= img.pixel(x + i, y + j) * 2.f;
                            }
                            else if (i == 1 && j == 1)
                            {
                                avg -= img.pixel(x + i, y + j) * -2.f;
                            }
                        }
                    }
                }
                res.pixel(x, y) = avg;
                break;
            }
        }
    }
    return res;
}