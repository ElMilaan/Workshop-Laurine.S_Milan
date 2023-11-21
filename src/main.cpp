#include <sil/sil.hpp>
#include "random.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

void green(sil::Image &img)
{
    for (glm::vec3 &color : img.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
}

void exchange(sil::Image &img)
{
    for (glm::vec3 &color : img.pixels())
    {
        float r{color.r};
        color.r = color.b;
        color.b = r;
    }
}

void b_w(sil::Image &img)
{
    for (glm::vec3 &color : img.pixels())
    {
        float avg{(color.r + color.b + color.g) / 3};
        color.r = color.b = color.g = avg;
    }
}

void negative(sil::Image &img)
{
    for (glm::vec3 &color : img.pixels())
    {
        color.r = 1 - color.r;
        color.b = 1 - color.b;
        color.g = 1 - color.g;
    }
}

void gradient_b_w(sil::Image &img)
{
    for (float x{0}; x < img.width(); x++)
    {
        for (float y{0}; y < img.height(); y++)
        {
            img.pixel(x, y).r = x / img.width();
            img.pixel(x, y).g = x / img.width();
            img.pixel(x, y).b = x / img.width();
        }
    }
}

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

void bruit(sil::Image &img)
{
    for (glm::vec3 &color : img.pixels())
    {
        int al = random_int(1, 6);
        if (al == 2)
        {
            color.r = random_float(0, 1);
            color.b = random_float(0, 1);
            color.g = random_float(0, 1);
        }
    }
}

sil::Image rotation_90(sil::Image &img)
{
    sil::Image res{img.height(), img.width()};
    for (int x{0}; x < img.height(); x++)
    {
        for (int y{0}; y < img.width(); y++)
        {
            res.pixel(x, y) = img.pixel(img.width() - y - 1, x);
        }
    }
    return res;
}

sil::Image rgb_split(sil::Image &img)
{
    sil::Image res{img.width(), img.height()};
    for (int x{0}; x < img.width(); x++)
    {
        for (int y{0}; y < img.height(); y++)
        {
            if (x <= 20)
            {
                res.pixel(x, y).r = img.pixel(x + 20, y).r;
                res.pixel(x, y).b = img.pixel(x, y).b;
            }
            else if (x >= img.width() - 20)
            {
                res.pixel(x, y).r = img.pixel(x, y).r;
                res.pixel(x, y).b = img.pixel(x - 20, y).b;
            }
            else
            {
                res.pixel(x, y).r = img.pixel(x + 20, y).r;
                res.pixel(x, y).b = img.pixel(x - 20, y).b;
            }
            res.pixel(x, y).g = img.pixel(x, y).g;
        }
    }
    return res;
}

void brightness(sil::Image &img, float coeff)
{
    for (glm::vec3 &color : img.pixels())
    {
        color.r = std::pow(color.r, coeff);
        color.g = std::pow(color.g, coeff);
        color.b = std::pow(color.b, coeff);
    }
}

void disc(sil::Image &img, int rayon)
{
    for (int x{0}; x < img.height(); x++)
    {
        for (int y{0}; y < img.width(); y++)
        {
            if (std::pow(x - img.width() / 2, 2) + std::pow(y - img.height() / 2, 2) < std::pow(rayon, 2))
            {
                img.pixel(x, y).r = 1;
                img.pixel(x, y).g = 1;
                img.pixel(x, y).b = 1;
            }
        }
    }
}

void circle(sil::Image &img, int rayon, int absCenter, int ordCenter)
{
    for (int x{0}; x < img.height(); x++)
    {
        for (int y{0}; y < img.width(); y++)
        {
            if (std::pow(x - absCenter, 2) + std::pow(y - ordCenter, 2) < std::pow(rayon, 2) &&
                std::pow(x - absCenter, 2) + std::pow(y - ordCenter, 2) > std::pow(rayon - 8, 2))
            {
                img.pixel(x, y).r = 1;
                img.pixel(x, y).g = 1;
                img.pixel(x, y).b = 1;
            }
        }
    }
}

void rosace(sil::Image &img, int rayon)
{
    int absCenter = img.width() / 2;
    int ordCenter = img.height() / 2;
    circle(img, 100, absCenter, ordCenter);
    for (double i{0}; i < 2 * M_PI; i += M_PI / 3)
    {
        circle(img, 100, absCenter + rayon * std::cos(i), ordCenter + rayon * std::sin(i));
    }
}

int main()
{
    {
        sil::Image image{"img/logo.png"};
        green(image);
        image.save("output/green.png");
    }
    {
        sil::Image image{"img/logo.png"};
        exchange(image);
        image.save("output/exchange.png");
    }
    {
        sil::Image image{"img/logo.png"};
        b_w(image);
        image.save("output/black_and_white.png");
    }
    {
        sil::Image image{"img/logo.png"};
        negative(image);
        image.save("output/negative.png");
    }
    {
        sil::Image image{300, 200};
        gradient_b_w(image);
        image.save("output/gradient_b_w.png");
    }
    {
        sil::Image image{"img/logo.png"};
        mirror(image);
        image.save("output/mirror.png");
    }
    {
        sil::Image image("img/logo.png");
        bruit(image);
        image.save("output/bruit.png");
    }
    {
        sil::Image image("img/logo.png");
        rotation_90(image).save("output/rotation_90.png");
    }
    {
        sil::Image image("img/logo.png");
        rgb_split(image).save("output/rgb_split.png");
    }
    {
        sil::Image dark("img/photo.jpg"), bright("img/photo.jpg");
        brightness(dark, 5);
        brightness(bright, 0.4);
        dark.save("output/dark.jpg");
        bright.save("output/bright.jpg");
    }
    {
        sil::Image image(500, 500);
        disc(image, 250);
        image.save("output/disc.png");
    }
    {
        sil::Image image(500, 500);
        circle(image, 100, image.width() / 2, image.height() / 2);
        image.save("output/circle.png");
    }
    {
        sil::Image image(500, 500);
        rosace(image, 100);
        image.save("output/rosace.png");
    }
}