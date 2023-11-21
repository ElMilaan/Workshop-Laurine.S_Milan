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

sil::Image rgb_split_without_green(sil::Image &img)
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
        sil::Image image{"img/logo.png"};
        fake_mirror(image);
        image.save("output/fake_mirror.png");
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
        sil::Image image("img/logo.png");
        rgb_split_without_green(image).save("output/rgb_split_without_green.png");
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
    {
        // petite image compressée (qu'on utilise pour faire la mosaique)
        sil::Image image("img/logo.png");
        reduc(image).save("output/reduced.png");
    }
    {
        sil::Image image("img/logo.png");
        mosaique_reduced(image);
        image.save("output/mosaique_reduced.png");
    }
    {
        sil::Image image("img/logo.png");
        mosaique_bigger1(image).save("output/mosaique_bigger1.png");
    }
    {
        sil::Image image{"img/logo.png"};
        mosaique_bigger2(image).save("output/mosaique_bigger2.png");
    }
    {
        sil::Image image("img/logo.png");
        glitch_rate_mais_style(image);
        image.save("output/glitch_rate_mais_style.png");
    }
    {
        sil::Image image("img/logo.png");
        glitch(image);
        image.save("output/glitch.png");
    }
}