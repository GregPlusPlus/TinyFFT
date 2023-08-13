#include "tinyfft.h"

void tinyfft_zeroOutput(float complex *y, size_t n) {
    for(size_t i = 0; i < n; i ++) {
        y[i] = 0;
    }
}

void tinyfft_FFT(const float *s, float complex *y, size_t n) {
    if(n == 1) {
        y[0] = s[0];

        return;
    }

    float complex omega = cexpf((2 * M_PI * I) / n);

    float *se = malloc(sizeof(float) * (n / 2));
    float *so = malloc(sizeof(float) * (n / 2));
    float complex *ye = malloc(sizeof(float complex) * (n / 2));
    float complex *yo = malloc(sizeof(float complex) * (n / 2));

    for(size_t i = 0; i < (n / 2); i ++) {
        se[i] = s[(i * 2) + 0];
        so[i] = s[(i * 2) + 1];
    }

    tinyfft_zeroOutput(ye, (n / 2));
    tinyfft_zeroOutput(yo, (n / 2));

    tinyfft_FFT(se, ye, (n / 2));
    tinyfft_FFT(so, yo, (n / 2));

    for(size_t i = 0; i < (n / 2); i ++) {
        y[i          ] = ye[i] + (cpowf(omega, i) * yo[i]);
        y[i + (n / 2)] = ye[i] - (cpowf(omega, i) * yo[i]);
    }

    free(se);
    free(so);
    free(ye);
    free(yo);
}
