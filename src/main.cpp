#include <sil/sil.hpp>
#include "functions.hpp"

int main()
{
    {
        sil::Image image{200, 200};
        image.save("output/black.png");
    }
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
        disc(image, 100);
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
    {
        sil::Image image(500, 500);
        fractal_pixelized(image);
        image.save("output/fractal_pixelized.png");
    }
    {
        sil::Image image(500, 500);
        fractal(image);
        image.save("output/fractal.png");
    }
    {
        // cas 1 : blur
        // cas 2 : outline
        // cas 3 : sharpen
        // cas 4 : emboss
        sil::Image image("img/logo.png");
        convolution(image, 17, 1).save("output/blur.png");
        convolution(image, 3, 2).save("output/outline.png");
        convolution(image, 3, 3).save("output/sharpen.png");
        convolution(image, 3, 4).save("output/emboss.png");
        // convolution(convolution(convolution(convolution(image, 17, 1), 3, 4), 3, 3), 3, 2).save("output/mix_all_convolutions.png");
    }
    {
        sil::Image image("img/photo.jpg");
        tramage(image, 2.2);
        image.save("output/tramage.jpg");
    }
    {
        sil::Image image{"img/logo.png"};
        sort(image);
        image.save("output/sort.png");
    }
}
