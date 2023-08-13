#include <stdio.h>

#include "tinyfft.h"

#define N_SAMPLES 4

int main() {
    float complex s[N_SAMPLES] = {5, 3, 2, 1};
    float complex b[N_SAMPLES];
    float complex y[N_SAMPLES];

    tinyfft_reorder(s, b, N_SAMPLES);

    tinyfft_FFT(b, y, N_SAMPLES);

    printf("FFT([");

    for(size_t i = 0; i < N_SAMPLES; i ++) {
        printf("%0.2f%s", s[i], (i < (N_SAMPLES - 1)?", ":""));
    }

    printf("]) = [");

    for(size_t i = 0; i < N_SAMPLES; i ++) {
        printf("%0.2f%+0.2fi%s", crealf(y[i]), cimagf(y[i]), (i < (N_SAMPLES - 1)?", ":""));
    }

    printf("]\n");

    return 0;
}
