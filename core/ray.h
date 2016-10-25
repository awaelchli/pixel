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

#include "vector.h"

namespace pixel {

    /*
     * Ray class
     */
    class ray {
    public:

        /*
         * Constructor
         */
        ray(const vector & o, const vector & d,
                const double tmin = EPS, const double tmax = INFINITY,
                const uint32_t depth = 0);

        /*
         * Get ray origin
         */
        inline const vector & origin() const {
            return o;
        }

        inline vector & origin() {
            return o;
        }

        /*
         * Get ray direction
         */
        inline const vector & direction() const {
            return d;
        }

        inline vector & direction() {
            return d;
        }

        /*
         * Get ray inverse direction
         */
        inline const vector & inv_direction() const {
            return inv_d;
        }

        inline vector & inv_direction() {
            return inv_d;
        }

        /*
         * Get ray maximum and minimum
         */
        inline double ray_min() const {
            return tmin;
        }

        inline double ray_max() const {
            return tmax;
        }

        /*
         * Get ray depth
         */
        inline uint32_t ray_depth() const {
            return depth;
        }

        /*
         * Find point at a given parameter
         */
        inline vector operator()(const double t) const {
            // Load origin into __m256d variable
            __m256d a = _mm256_load_pd(o.e);
            // Compute ray point
            a = _mm256_add_pd(a, _mm256_mul_pd(_mm256_load_pd(d.e), _mm256_set1_pd(t)));
            // Result
            vector result;
            _mm256_store_pd(result.e, a);

            return result;
        }

    private:
        /*
         * Ray origin
         */
        vector o;
        /*
         * Ray direction
         */
        vector d;
        /*
         * Ray maximum and minimum
         */
        double tmin, tmax;
        /*
         * Ray depth
         */
        uint32_t depth;
        /*
         * Ray inverse direction
         */
        vector inv_d;
    };

    /*
     * Print ray to std::cout
     */
    void print_ray(const ray & r);

}

#endif /* RAY_H */

