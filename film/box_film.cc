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
#include <cstdlib>
#include "box_film.h"

namespace pixel {

    box_filter_film::box_filter_film(const uint32_t w, const uint32_t h)
    : film(w, h) {
        raster = reinterpret_cast<sse_spectrum *> (malloc(w * h * sizeof (sse_spectrum)));
        num_samples = reinterpret_cast<uint32_t *> (malloc(w * h * sizeof (uint32_t)));
    }

    box_filter_film::~box_filter_film() {
        free(reinterpret_cast<void *> (raster));
        free(reinterpret_cast<void *> (num_samples));
    }

    bool box_filter_film::add_sample(const sse_spectrum & s, const float x, const float y) {
        // Check pixel coordinates
        if (x < 0.0 || static_cast<uint32_t> (x) > width ||
                y < 0.0 || static_cast<uint32_t> (y) > height) {
            return false;
        }
        // Find pixel index
        uint32_t i = static_cast<uint32_t> (x);
        uint32_t j = static_cast<uint32_t> (y);
        // Add spectrum value
        raster[j * width + i] += s;

        // Increase number of samples of that pixel
        num_samples[j * width + i]++;

        return true;
    }

    sse_spectrum box_filter_film::get_spectrum(const uint32_t i, const uint32_t j) const {
        return raster[j * width + i];
    }


}
