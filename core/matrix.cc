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

#include "matrix.h"
#include <cstring>
#include <cassert>

namespace pixel {

    matrix4x4::matrix4x4() {
        for (uint32_t i = 0; i < 4; i++) {
            for (uint32_t j = 0; j < 4; j++) {
                if (i == j) {
                    rows[i][j] = 1;
                    cols[j][i] = 1;
                } else {
                    rows[i][j] = 0;
                    cols[j][i] = 0;
                }
            }
        }
    }

    matrix4x4::matrix4x4(const real m00, const real m01, const real m02, const real m03,
            const real m10, const real m11, const real m12, const real m13,
            const real m20, const real m21, const real m22, const real m23,
            const real m30, const real m31, const real m32, const real m33) {
        rows[0][0] = m00; rows[0][1] = m01; rows[0][2] = m02; rows[0][3] = m03;
        rows[1][0] = m10; rows[1][1] = m11; rows[1][2] = m12; rows[1][3] = m13;
        rows[2][0] = m20; rows[2][1] = m21; rows[2][2] = m22; rows[2][3] = m23;
        rows[3][0] = m30; rows[3][1] = m31; rows[3][2] = m32; rows[3][3] = m33;
        
        // Assign columns
        cols[0][0] = m00; cols[0][1] = m10; cols[0][2] = m20; cols[0][3] = m30;
        cols[1][0] = m01; cols[1][1] = m11; cols[1][2] = m21; cols[1][3] = m31;
        cols[2][0] = m02; cols[2][1] = m12; cols[2][2] = m22; cols[2][3] = m32;
        cols[3][0] = m03; cols[3][1] = m13; cols[3][2] = m23; cols[3][3] = m33;
    }

    matrix4x4 matrix4x4::transpose() const {
        matrix4x4 transposed;
        
        memcpy(transposed.rows, cols, 16 * sizeof(real));
        memcpy(transposed.cols, rows, 16 * sizeof(real));
        
        return transposed;
    }
    
    real matrix4x4::at(const uint32_t i, const uint32_t j) const {
        assert(i <= 4);
        assert(j <= 4);
        
        return rows[i][j];
    }

    void matrix4x4::set(const uint32_t i, const uint32_t j, const real v) {
        assert(i <= 4);
        assert(j <= 4);
        
        rows[i][j] = v;
        cols[j][i] = v;
    }
    
    matrix4x4 matrix4x4::operator*(const matrix4x4& m) const {
        matrix4x4 result;
        
        // Compute rows of the result matrix
        result.rows[0] =    m.rows[0] * rows[0][0] +
                            m.rows[1] * rows[0][1] +
                            m.rows[2] * rows[0][2] +
                            m.rows[3] * rows[0][3];
        
        result.rows[1] =    m.rows[0] * rows[1][0] +
                            m.rows[1] * rows[1][1] +
                            m.rows[2] * rows[1][2] +
                            m.rows[3] * rows[1][3];
        
        result.rows[2] =    m.rows[0] * rows[2][0] +
                            m.rows[1] * rows[2][1] +
                            m.rows[2] * rows[2][2] +
                            m.rows[3] * rows[2][3];
        
        result.rows[3] =    m.rows[0] * rows[3][0] +
                            m.rows[1] * rows[3][1] +
                            m.rows[2] * rows[3][2] +
                            m.rows[3] * rows[3][3];

        // Compute columns of the result matrix
        result.cols[0] =    cols[0] * m.cols[0][0] +
                            cols[1] * m.cols[0][1] +
                            cols[2] * m.cols[0][2] +
                            cols[3] * m.cols[0][3];
        
        result.cols[1] =    cols[0] * m.cols[1][0] +
                            cols[1] * m.cols[1][1] +
                            cols[2] * m.cols[1][2] +
                            cols[3] * m.cols[1][3];
        
        result.cols[2] =    cols[0] * m.cols[2][0] +
                            cols[1] * m.cols[2][1] +
                            cols[2] * m.cols[2][2] +
                            cols[3] * m.cols[2][3];
        
        result.cols[3] =    cols[0] * m.cols[3][0] +
                            cols[1] * m.cols[3][1] +
                            cols[2] * m.cols[3][2] +
                            cols[3] * m.cols[3][3];
        
        return result;
    }

    vec4 matrix4x4::operator*(const vec4 & v) const {
        return (cols[0] * v[0] + cols[1] * v[1] + cols[2] * v[2] + cols[3] * v[3]);
    }

    void print_mat(const matrix4x4 & m) {
        std::cout << "Matrix rows" << std::endl;
        std::cout << "[" << m.at(0, 0) << " " << m.at(0, 1) << " " << m.at(0, 2) << " " << m.at(0, 3) << "]" << std::endl; 
        std::cout << "[" << m.at(1, 0) << " " << m.at(1, 1) << " " << m.at(1, 2) << " " << m.at(1, 3) << "]" << std::endl; 
        std::cout << "[" << m.at(2, 0) << " " << m.at(2, 1) << " " << m.at(2, 2) << " " << m.at(2, 3) << "]" << std::endl; 
        std::cout << "[" << m.at(3, 0) << " " << m.at(3, 1) << " " << m.at(3, 2) << " " << m.at(3, 3) << "]" << std::endl; 
    }
}