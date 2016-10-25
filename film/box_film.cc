/*
 * The MIT License
 *
 * Copyright 2016 simon.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <cassert>
#include <stdlib.h>
#include "box_film.h"

namespace pixel {

    box_filter_film::box_filter_film(const uint32_t w, const uint32_t h)
    : film(w, h) {
        raster = reinterpret_cast<spectrum *> (malloc(w * h * sizeof (spectrum)));
        num_samples = reinterpret_cast<uint32_t *> (malloc(w * h * sizeof (uint32_t)));
    }

    box_filter_film::~box_filter_film() {
        free(reinterpret_cast<void *> (raster));
        free(reinterpret_cast<void *> (num_samples));
    }

    bool box_filter_film::add_sample(const spectrum & s, const double x, const double y) {
        // Check pixel coordinates
        if (x < 0.0 || static_cast<uint32_t> (x) > width ||
                y < 0.0 || static_cast<uint32_t> (y) > height) {
            return false;
        }
        // Find pixel index
        uint32_t i = static_cast<uint32_t> (x);
        uint32_t j = static_cast<uint32_t> (y);
        // Add spectrum value
        __m256d a = _mm256_loadu_pd(raster[j * width + i].e);
        a = _mm256_add_pd(a, _mm256_load_pd(s.e));
        _mm256_storeu_pd(raster[j * width + i].e, a);

        // Increase number of samples of that pixel
        num_samples[j * width + i]++;

        return true;
    }

    spectrum box_filter_film::get_spectrum(const uint32_t i, const uint32_t j) const {
        // Load spectrum
        __m256d a = _mm256_loadu_pd(raster[j * width + i].e);
        // Divide by number of samples
        a = _mm256_div_pd(a, _mm256_set1_pd(num_samples[j * width + i]));
        spectrum result;
        // Store new spectrum and return
        _mm256_storeu_pd(result.e, a);

        return result;
    }


}
