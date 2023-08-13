#include "tinyfft.h"

size_t reverseIndex(size_t a, size_t max) {
    size_t ar = 0;
    size_t nBits = (sizeof(size_t) * 8);
    size_t minimumSize = 0;

    for(size_t i = 0; i < nBits; i ++) {
        size_t mask = (size_t)1 << (nBits - 1 - i);

        if(((max & mask) != 0) &&
           (minimumSize == 0)) {

            minimumSize = (nBits - i);

            break;
        }
    }

    for(size_t i = 0; i < minimumSize; i ++) {
        ar |= (((a & ((size_t)1 << i)) >> i) << (minimumSize - 1 - i));
    }

    return ar;
}

void tinyfft_reorder(const float complex *s, float complex *sr, size_t n) {
    for(size_t i = 0; i < n; i ++) {
        sr[reverseIndex(i, n - 1)] = s[i];
    }
}

void tinyfft_FFT(float complex *s, float complex *y, size_t n) {
    if(n == 1) {
        y[0] = s[0];

        return;
    }

    float complex omega = cexpf((2 * M_PI * I) / n);

    float complex *yeo = malloc(sizeof(float complex) * n);

    tinyfft_FFT(s           , yeo           , (n / 2));     // Even part
    tinyfft_FFT(s + (n / 2) , yeo + (n / 2) , (n / 2));     // Odd part

    for(size_t i = 0; i < (n / 2); i ++) {
        y[i          ] = yeo[i] + (cpowf(omega, i) * yeo[i + (n / 2)]);
        y[i + (n / 2)] = yeo[i] - (cpowf(omega, i) * yeo[i + (n / 2)]);
    }

    free(yeo);
}
