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
 * File:   pixel.h
 * Author: simon
 *
 * Created on October 21, 2016, 5:18 PM
 */

#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <cmath>
#include <string>

namespace pixel {
    
    /*
     * Define type to use
     */
#ifdef DOUBLE_PRECISION
    typedef double real;
#else
    typedef float real;
#endif
    
    /*
     * Declare constant values
     */
    static real EPS = 10e-5;
    static real PI = 3.14159265;
    static real TWO_PI = 6.28318530718;
    static real ONE_OVER_PI = 0.318309886184;
    static real ONE_OVER_2_PI = 0.159154943092;
    static real ONE_OVER_4_PI = 0.07957747154;
    
    /*
     * Macro to define vector types
     */
    #define vector(type, size) type __attribute__ ((vector_size (sizeof(type) * (size))))
    
    /*
     * Maximum and minium functions
     */
    template <typename T>
    inline real fmin(const T a, const T b) {
        return (a < b ? a : b);
    }
    
    template <typename T>
    inline real fmax(const T a, const T b) {
        return (a > b ? a : b);
    }

    /*
     *  Clamp value
     */
    template <typename T>
    inline real clamp(const T val, const T min, const T max) {
        return fmin(fmax(val, min), max);
    }

    /*
     * Degree to radians
     */
    template <typename T>
    inline real deg_to_rad(const T deg) {
        return ((PI / 180.0) * deg);
    }

    /*
     * Radians to degree
     */
    template <typename T>
    inline real rad_to_deg(const T rad) {
        return ((180.0 / PI) * rad);
    }
}

#endif /* PIXEL_H */
