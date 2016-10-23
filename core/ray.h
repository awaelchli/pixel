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
    template <typename VEC_T>
    class ray {
    public:
        /*
         * Constructor
         */
        ray(const VEC_T & o, const VEC_T & d,
            const real tmin = EPS, const real tmax = INFINITY,
            const int32_t depth = 0);
        
        /*
         * Get ray origin
         */
        inline const VEC_T & origin() const { return o; }
        inline VEC_T & origin() { return o; }
        
        /*
         * Get ray direction
         */
        inline const VEC_T & direction() const { return d; }
        inline VEC_T & direction() { return d; }
        
        /*
         * Get ray inverse direction
         */
        inline const VEC_T & inv_direction() const { return inv_d; }
        inline VEC_T & inv_direction() { return inv_d; }
        
        /*
         * Get ray maximum and minimum
         */
        inline real ray_min() const { return tmin; }
        inline real ray_max() const { return tmax; }
        
        /*
         * Get ray depth
         */
        inline int32_t ray_depth() const { return depth; }
        
        /*
         * Find point at a given parameter
         */
        inline VEC_T operator()(const real t) const {
            return (o + t * d);
        }
        
    private:
        /*
         * Ray origin
         */
        VEC_T o;
        /*
         * Ray direction
         */
        VEC_T d;
        /*
         * Ray maximum and minimum
         */
        real tmin, tmax;
        /*
         * Ray depth
         */
        int32_t depth;
        /*
         * Ray inverse direction
         */
        VEC_T inv_d;
    };

    /*
     * Ray class implementation
     */
    template <typename VEC_T>
    ray<VEC_T>::ray(const VEC_T & o, const VEC_T & d,
            const real tmin, const real tmax, const int32_t depth)
    : o(o), d(d), tmin(tmin), tmax(tmax), depth(depth) {
    }
    
    /*
     * Print ray to std::cout
     */
    template <typename VEC_T>
    void print_ray(const ray<VEC_T> & r) {
        // Print origin
        std::cout << "Ray origin: ";
        print_vec(r.origin());
        // Print direction
        std::cout << "Direction: ";
        print_vec(r.direction());
        // Print ray maximum and minimum
        std::cout << "T min: " << r.ray_min() << std::endl;
        std::cout << "T max: " << r.ray_max() << std::endl;
        // Print ray depth
        std::cout << "Depth: " << r.ray_depth() << std::endl;
    }

}

#endif /* RAY_H */

