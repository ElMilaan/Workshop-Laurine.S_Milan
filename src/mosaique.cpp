#include <sil/sil.hpp>
#include "functions.hpp"

// Réduction de la résolution de l'image (pour garder la meme taille d'image pour la mosaique)
sil::Image reduc(sil::Image img)
{
    sil::Image res{img.width() / 5, img.height() / 5};
    for (int x{0}; x < img.width(); x++)
    {
        for (int y{0}; y < img.height(); y++)
        {
            if (x % 5 == 0 && y % 5 == 0)
            {
                res.pixel(x / 5, y / 5) = img.pixel(x, y);
            }
        }
    }
    return res;
}

// mosaique qui prend des images réduite pour que l'image finale soit de la meme taille que l'image dupliquée
void mosaique_reduced(sil::Image &img)
{
    sil::Image reduced{reduc(img)};
    for (int x{0}; x < img.width(); x += reduced.width())
    {
        for (int y{0}; y < img.height(); y += reduced.height())
        {
            for (int abs{0}; abs < reduced.width(); abs++)
            {
                for (int ord{0}; ord < reduced.height(); ord++)
                {
                    img.pixel(abs + x, ord + y) = reduced.pixel(abs, ord);
                }
            }
        }
    }
}

// mosaique dont la résolution est 5 fois plus grande que l'image de base

// PROGRAMME MILAN
sil::Image mosaique_bigger1(sil::Image img)
{
    sil::Image res{img.width() * 5, img.height() * 5};
    for (int x{0}; x < res.width(); x++)
    {
        for (int y{0}; y < res.height(); y++)
        {
            res.pixel(x, y) = img.pixel(x % img.width(), y % img.height());
        }
    }
    return res;
}

// PROGRAMME LAURINE
sil::Image mosaique_bigger2(sil::Image image1)
{
    sil::Image image2{image1.width() * 5, image1.height() * 5};
    for (int x{0}; x < image2.width(); x += image1.width())
    {
        for (int y{0}; y < image2.height(); y += image1.height())
        {
            for (int k{0}; k < image1.width(); k++)
            {
                for (int l{0}; l < image1.height(); l++)
                {
                    image2.pixel(x + k, y + l) = image1.pixel(k, l);
                }
            }
        }
    }
    return image2;
}