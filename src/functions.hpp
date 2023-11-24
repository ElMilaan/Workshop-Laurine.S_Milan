#include <sil/sil.hpp>
#include "random.hpp"

void green(sil::Image &img);

void exchange(sil::Image &img);

void b_w(sil::Image &img);

void negative(sil::Image &img);

void gradient_b_w(sil::Image &img);

void mirror(sil::Image &img);

void fake_mirror(sil::Image &image);

void bruit(sil::Image &img);

sil::Image rotation_90(sil::Image &img);

sil::Image rgb_split(sil::Image &img);

sil::Image rgb_split_without_green(sil::Image &img);

void brightness(sil::Image &img, float coeff);

void disc(sil::Image &img, int rayon);

void circle(sil::Image &img, int rayon, int absCenter, int ordCenter);

void rosace(sil::Image &img, int rayon);

sil::Image reduc(sil::Image img);

void mosaique_reduced(sil::Image &img);

sil::Image mosaique_bigger1(sil::Image img);

sil::Image mosaique_bigger2(sil::Image image1);

void glitch_rate_mais_style(sil::Image &img);

void glitch(sil::Image &img);

void fractal_pixelized(sil::Image &img);

void fractal(sil::Image &img);

sil::Image convolution(sil::Image img, int coeff, int kernel);

void tramage(sil::Image &img, float seuil);

void sort(sil::Image &img);