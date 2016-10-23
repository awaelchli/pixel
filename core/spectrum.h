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
 * File:   spectrum.h
 * Author: simon
 *
 * Created on October 22, 2016, 2:35 AM
 */

#ifndef SPECTRUM_H
#define SPECTRUM_H

#include "pixel.h"

namespace pixel {
    
    /*
     * Define spectrum type
     */
    typedef vector(real, 4) spectrum;
    
    /*
     * Define inline functions for spectrum
     */
    
    /*
     * Print spectrum
     */
    inline void print_spectrum(const spectrum & s) {
        std::cout << "(" << s[0] << "," << s[1] << "," << s[2] << ")" << std::endl;
    }
    
    /*
     * Check if a color is black
     */
    inline bool is_black(const spectrum & s) {
        return (s[0] == static_cast<real>(0) &&
                s[1] == static_cast<real>(0) &&
                s[2] == static_cast<real>(0));
    }
    
    /*
     * Power function for spectrum
     */
    inline spectrum pow(const spectrum & s, const real e) {
        return spectrum{std::pow(s[0], e), std::pow(s[1], e), std::pow(s[2], e), 0};
    }
    
    /*
     * Clamp color between two values
     */
    inline spectrum clamp(const spectrum & s, const real min, const real max) {
        return spectrum{clamp(s[0], min, max), clamp(s[1], min, max), clamp(s[2], min, max), 0};
    }
}

#endif /* SPECTRUM_H */

