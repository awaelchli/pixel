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
 * File:   vector.h
 * Author: simon
 *
 * Created on October 21, 2016, 3:53 PM
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "pixel.h"
#include <cmath>

namespace pixel {

    /*
     * Define vector types
     */
    typedef vector(real, 4) vec4;
    typedef vector(real, 2) vec2;
    
    /*
     * Define inline functions for vectors
     */
    
    /*
     * Print vector
     */
    inline void print_vec(const vec4 & v) {
        std::cout << "[" << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "]" << std::endl;
    }
    
    inline void print_vec(const vec2 & v) {
        std::cout << "[" << v[0] << "," << v[1] << "]" << std::endl;
    }
    
    /*
     * Dot product
     */
    inline real dot(const vec4 & v1, const vec4 & v2) {
        vec4 v = v1 * v2;
        
        return (v[0] + v[1] + v[2] + v[3]);
    }
    
    inline real dot(const vec2 & v1, const vec2 & v2) {
        vec2 v = v1 * v2;
        
        return (v[0] + v[1]);
    }
    
    /*
     * Absolute value of the dot product
     */
    inline real abs_dot(const vec4 & v1, const vec4 & v2) {
        return std::abs(dot(v1, v2));
    }
    
    inline real abs_dot(const vec2 & v1, const vec2 & v2) {
        return std::abs(dot(v1, v2));
    }
    
    /*
     * Squared length of a vector
     */
    inline real sqrd_length(const vec4 & v) {
        vec4 v_2 = v * v;
        
        return (v_2[0] + v_2[1] + v_2[2] + v_2[3]);
    }
    
    inline real sqrd_length(const vec2 & v) {
        vec2 v_2 = v * v;
        
        return (v_2[0] + v_2[1]);
    }
    
    /*
     * Length of a vector
     */
    inline real length(const vec4 & v) {
        return (std::sqrt(sqrd_length(v)));
    }
    
    inline real length(const vec2 & v) {
        return (std::sqrt(sqrd_length(v)));
    }
    
    /*
     * Normalize vector
     */
    inline vec4 normalize(const vec4 & v) {
        return (v / length(v));
    }
    
    inline void normalize(vec4 * const v) {
        *v = *v / length(*v);
    }
    
    inline vec2 normalize(const vec2 & v) {
        return (v / length(v));
    }
    
    inline void normalize(vec2 * const v) {
        *v = *v / length(*v);
    }
    
    /*
     * Compute cross product
     * Considers only the first three component and set last to 0)
     */
    inline vec4 cross(const vec4 & v1, const vec4 & v2) {
        return vec4{ v1[1] * v2[2] - v1[2] * v2[1],
                    v1[2] * v2[0] - v1[0] * v2[2],
                    v1[0] * v2[1] - v1[1] * v2[0],
                    0 };
    }
    
    /*
     * Compute orthogonal vector to the given one
     */
    inline vec4 orthogonal(const vec4 & v) {
        if (std::abs(v[0]) <= std::abs(v[1]) && std::abs(v[0]) <= std::abs(v[2])) {
            return vec4{0, -v[2], v[1], 0};
	} else if (std::abs(v[1]) <= std::abs(v[0]) && std::abs(v[1]) <= std::abs(v[2])) {
            return vec4{-v[2], 0, v[0], 0};
	} else {
            return vec4{-v[1], v[0], 0, 0};
	}
    }
}

#endif /* VECTOR_H */

