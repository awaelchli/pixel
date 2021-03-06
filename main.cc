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


/* 
 * File:   main.cc
 * Author: simon
 *
 * Created on October 21, 2016, 3:46 PM
 */

#include <cstdlib>
#include "box_film.h"
#include "clamp_tonemapper.h"
#include "ray.h"
#include "matrix.h"

int main(int argc, char** argv) {

    // Create film
    pixel::film * f = new pixel::box_filter_film(256, 256);
    for (uint32_t i = 0; i < 256; i++) {
        for (uint32_t j = 0; j < 256; j++) {
            if (!f->add_sample(pixel::sse_spectrum(1.f, 0.f, 0.f), i, j)) {
                std::cout << "Failed attempt to add spectrum to film" << std::endl;
                std::cout << i << " " << j << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    // Create tone mapper
    pixel::tone_mapper * t = new pixel::clamp_tone_mapper(2.f);
    // Process image and create it
    t->process(std::string("test.ppm"), *f);

    return 0;
}