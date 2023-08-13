#ifndef TINYFFT_H
#define TINYFFT_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <complex.h>

void tinyfft_reorder(const float complex *s, float complex *sr, size_t n);
void tinyfft_FFT(float complex *s, float complex *y, size_t n);

#endif // TINYFFT_H
