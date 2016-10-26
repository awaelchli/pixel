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
 * File:   ray.h
 * Author: simon
 *
 * Created on October 22, 2016, 8:21 PM
 */

#ifndef RAY_H
#define RAY_H

#include "pixel.h"
#include "sse_vector.h"

namespace pixel {

    // Ray class

    class ray {
    public:

        // Constructor
        ray(const sse_vector & o, const sse_vector & d,
                const float tmin = EPS, const float tmax = INFINITY,
                const uint32_t depth = 0);

        // Get ray origin

        inline const sse_vector & origin() const {
            return o;
        }

        inline sse_vector & origin() {
            return o;
        }

        // Get ray direction

        inline const sse_vector & direction() const {
            return d;
        }

        inline sse_vector & direction() {
            return d;
        }

        // Get ray inverse direction

        inline const sse_vector & inv_direction() const {
            return inv_d;
        }

        inline sse_vector & inv_direction() {
            return inv_d;
        }

        // Get ray maximum and minimum

        inline float ray_min() const {
            return tmin;
        }

        inline float ray_max() const {
            return tmax;
        }

        // Get ray depth

        inline uint32_t ray_depth() const {
            return depth;
        }

        // Find point at a given parameter

        inline sse_vector operator()(const float t) const {
            return (o + t * d);
        }

    private:
        // Ray origin
        sse_vector o;
        // Ray direction
        sse_vector d;
        // Ray maximum and minimum
        float tmin, tmax;
        // Ray depth
        uint32_t depth;
        // Ray inverse direction
        sse_vector inv_d;
    };

    /*
     * Print ray to std::cout
     */
    void print_ray(const ray & r);

}

#endif /* RAY_H */

