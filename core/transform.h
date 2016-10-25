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
 * File:   transform.h
 * Author: simon
 *
 * Created on October 25, 2016, 11:09 PM
 */

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "matrix.h"

namespace pixel {

    /*
     * Define transform class
     */
    class transform {
    public:
        /*
         * Constructor
         */
        transform();
        
        transform(const matrix & m, const matrix & m_inv);
        
        /*
         * Get inverse transform
         */
        transform inverse() const;
        
        /*
         * Composition of two transform
         */
        transform operator*(const transform & t) const;
        
        /*
         * Transform direction / point
         */
        vector transform_dir(const vector & v) const;
        
        /*
         * Transform direction and normalize it
         */
        vector transform_normalize_dir(const vector & v) const;
        
        /*
         * Transform normal
         */
        vector transform_normal(const vector & n) const;
        
        /*
         * Transform normal and normalize it
         */
        vector transform_normalize_normal(const vector & n) const;
        
        /*
         * Transform ray
         */
        ray operator()(const ray & r) const;
        
    private:
        /*
         * Transformation matrix and inverse
         */
        matrix m, m_inv;
    };
    
    /*
     * Function to generate a specific transform
     */
    transform translate(const double x, const double y, const double z);
    transform scale(const double sx, const double sy, const double sz);
    transform rotate_x(const double deg);
    transform rotate_y(const double deg);
    transform rotate_z(const double deg);

}

#endif /* TRANSFORM_H */

