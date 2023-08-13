#ifndef TINYFFT_H
#define TINYFFT_H

#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

void tinyfft_zeroOutput(float complex *y, size_t n);
void tinyfft_FFT(const float *s, float complex *y, size_t n);

#endif // TINYFFT_H
