#include "convolution.h"

void convolve(const float *image, float *output, std::size_t n, const float *mask, std::size_t m) {
	// Store output in row-major order,
    // initialize all to be 0
	for(size_t i = 0; i < n * n; i++) {
        output[i] = 0;
    }

    float fval;

	for (std::size_t x = 0; x < n; x++) {
		for (std::size_t y = 0; y < n; y++) {
			for (std::size_t i = 0; i < m; i++) {
				for (std::size_t j = 0; j < m; j++) {

                    std::size_t ii = x + i - (m-1)/2;
                    std::size_t jj = y + j - (m-1)/2;

                    if (0 <= ii && ii < n && 0 <= jj && jj < n) {
                        fval = image[ii*n + jj];
                    }
                    else if ((0 <= ii && ii < n) || (0 <= jj && jj < n)) {
                        fval = 1;
                    }
                    else {
                        fval = 0;
                    }
					output[x * n + y] += mask[i * m + j] * fval;
				}
			}
		}
	}
}