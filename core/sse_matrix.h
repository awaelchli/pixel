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
 * File:   sse_matrix.h
 * Author: simon
 *
 * Created on October 26, 2016, 3:51 PM
 */

#ifndef SSE_MATRIX_H
#define SSE_MATRIX_H

#include "sse_vector.h"
#include <cstring>

namespace pixel {

    // SSE matrix class
    // In the notation, i represents the row and j the column

    class sse_matrix {
    public:
        // Constructor

        sse_matrix() {
            // Set to identity
            for (size_t i = 0; i < 4; i++) {
                for (size_t j = 0; j < 4; j++) {
                    if (i == j) {
                        data[j][i] = 1.f;
                    } else {
                        data[j][i] = 0.f;
                    }
                }
            }
        }

        explicit sse_matrix(const float v) {
            for (size_t i = 0; i < 4; i++) {
                for (size_t j = 0; j < 4; j++) {
                    data[j][i] = v;
                }
            }
        }

        sse_matrix(const float m00, const float m01, const float m02, const float m03,
                const float m10, const float m11, const float m12, const float m13,
                const float m20, const float m21, const float m22, const float m23,
                const float m30, const float m31, const float m32, const float m33) {
            data[0][0] = m00;
            data[1][0] = m01;
            data[2][0] = m02;
            data[3][0] = m03;

            data[0][1] = m10;
            data[1][1] = m11;
            data[2][1] = m12;
            data[3][1] = m13;

            data[0][2] = m20;
            data[1][2] = m21;
            data[2][2] = m22;
            data[3][2] = m23;

            data[0][3] = m30;
            data[1][3] = m31;
            data[2][3] = m32;
            data[3][3] = m33;
        }

        sse_matrix(const sse_matrix & other) {
            mempcpy(data, other.data, 16 * sizeof (float));
        }

        // Assignment operator

        sse_matrix & operator=(const sse_matrix & other) {
            if (this != &other) {
                for (size_t i = 0; i < 4; i++) {
                    for (size_t j = 0; j < 4; j++) {
                        data[j][i] = other.data[j][i];
                    }
                }
            }

            return *this;
        }

        // Set matrix to zero

        void set_zero() {
            for (size_t i = 0; i < 4; i++) {
                for (size_t j = 0; j < 4; j++) {
                    data[j][i] = 0.f;
                }
            }
        }

        // Index operators

        float operator()(const size_t i, const size_t j) const {
            return data[j][i];
        }

        float & operator()(const size_t i, const size_t j) {
            return data[j][i];
        }

        union {
            // Matrix columns for SSE
            __m128 xmm[4];
            // Array type data in colum order
            float data[4][4];
        };
    };

    // Sum

    sse_matrix operator+(const sse_matrix & m1, const sse_matrix & m2) {
        sse_matrix result;
        // Sum columns
        result.xmm[0] = _mm_add_ps(m1.xmm[0], m2.xmm[0]);
        result.xmm[1] = _mm_add_ps(m1.xmm[1], m2.xmm[1]);
        result.xmm[2] = _mm_add_ps(m1.xmm[2], m2.xmm[2]);
        result.xmm[3] = _mm_add_ps(m1.xmm[3], m2.xmm[3]);

        return result;
    }

    // Subtraction

    sse_matrix operator-(const sse_matrix & m1, const sse_matrix & m2) {
        sse_matrix result;
        // Sum columns
        result.xmm[0] = _mm_sub_ps(m1.xmm[0], m2.xmm[0]);
        result.xmm[1] = _mm_sub_ps(m1.xmm[1], m2.xmm[1]);
        result.xmm[2] = _mm_sub_ps(m1.xmm[2], m2.xmm[2]);
        result.xmm[3] = _mm_sub_ps(m1.xmm[3], m2.xmm[3]);

        return result;
    }

    // Multiplication with another matrix

    sse_matrix operator*(const sse_matrix & m1, const sse_matrix & m2) {
        sse_matrix result;
        // Compute first column
        result.xmm[0] = _mm_mul_ps(_mm_set1_ps(m2.data[0][0]), m1.xmm[0]);
        result.xmm[0] = _mm_add_ps(result.xmm[0], _mm_mul_ps(_mm_set1_ps(m2.data[0][1]), m1.xmm[1]));
        result.xmm[0] = _mm_add_ps(result.xmm[0], _mm_mul_ps(_mm_set1_ps(m2.data[0][2]), m1.xmm[2]));
        result.xmm[0] = _mm_add_ps(result.xmm[0], _mm_mul_ps(_mm_set1_ps(m2.data[0][3]), m1.xmm[3]));

        // Compute second column
        result.xmm[1] = _mm_mul_ps(_mm_set1_ps(m2.data[1][0]), m1.xmm[0]);
        result.xmm[1] = _mm_add_ps(result.xmm[1], _mm_mul_ps(_mm_set1_ps(m2.data[1][1]), m1.xmm[1]));
        result.xmm[1] = _mm_add_ps(result.xmm[1], _mm_mul_ps(_mm_set1_ps(m2.data[1][2]), m1.xmm[2]));
        result.xmm[1] = _mm_add_ps(result.xmm[1], _mm_mul_ps(_mm_set1_ps(m2.data[1][3]), m1.xmm[3]));

        // Compute third column
        result.xmm[2] = _mm_mul_ps(_mm_set1_ps(m2.data[2][0]), m1.xmm[0]);
        result.xmm[2] = _mm_add_ps(result.xmm[2], _mm_mul_ps(_mm_set1_ps(m2.data[2][1]), m1.xmm[1]));
        result.xmm[2] = _mm_add_ps(result.xmm[2], _mm_mul_ps(_mm_set1_ps(m2.data[2][2]), m1.xmm[2]));
        result.xmm[2] = _mm_add_ps(result.xmm[2], _mm_mul_ps(_mm_set1_ps(m2.data[2][3]), m1.xmm[3]));

        // Compute fourth column
        result.xmm[3] = _mm_mul_ps(_mm_set1_ps(m2.data[3][0]), m1.xmm[0]);
        result.xmm[3] = _mm_add_ps(result.xmm[3], _mm_mul_ps(_mm_set1_ps(m2.data[3][1]), m1.xmm[1]));
        result.xmm[3] = _mm_add_ps(result.xmm[3], _mm_mul_ps(_mm_set1_ps(m2.data[3][2]), m1.xmm[2]));
        result.xmm[3] = _mm_add_ps(result.xmm[3], _mm_mul_ps(_mm_set1_ps(m2.data[3][3]), m1.xmm[3]));

        return result;
    }

    // Multiplication with a vector

    sse_vector operator*(const sse_matrix & m, const sse_vector & v) {
        sse_vector result;

        // Compute first column
        result.xmm = _mm_mul_ps(_mm_set1_ps(v.x), m.xmm[0]);
        result.xmm = _mm_add_ps(result.xmm, _mm_mul_ps(_mm_set1_ps(v.y), m.xmm[1]));
        result.xmm = _mm_add_ps(result.xmm, _mm_mul_ps(_mm_set1_ps(v.z), m.xmm[2]));
        result.xmm = _mm_add_ps(result.xmm, _mm_mul_ps(_mm_set1_ps(v.w), m.xmm[3]));

        return result;
    }

    // Compute matrix inverse

    sse_matrix inverse(const sse_matrix & m) {
        // Matrix inversion based on the Gauss method
        int indxc[4], indxr[4];
        int ipiv[4] = {0, 0, 0, 0};
        float minv[4][4];
        memcpy(minv, m.data, 16 * sizeof (float));
        for (size_t i = 0; i < 4; i++) {
            int irow = 0, icol = 0;
            float big = 0.f;
            // Choose pivot
            for (size_t k = 0; k < 4; k++) {
                if (ipiv[k] != 1) {
                    for (size_t j = 0; j < 4; j++) {
                        if (ipiv[j] == 0) {
                            if (std::abs(minv[k][j]) >= big) {
                                big = std::abs(minv[k][j]);
                                irow = j;
                                icol = k;
                            }
                        } else if (ipiv[k] > 1) {
                            std::cerr << "Singular matrix given to inversion procedure" << std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                }
            }
            ++ipiv[icol];
            // Swap rows and col for pivot
            if (irow != icol) {
                for (size_t k = 0; k < 4; k++) {
                    std::swap(minv[k][irow], minv[k][icol]);
                }
            }
            indxr[i] = irow;
            indxc[i] = icol;
            if (minv[icol][icol] == 0.f) {
                std::cerr << "Singular matrix given to inversion procedure" << std::endl;
                exit(EXIT_FAILURE);
            }
            // Scale
            float piv_inv = 1.f / minv[icol][icol];
            minv[icol][icol] = 1.f;
            for (size_t j = 0; j < 4; j++) {
                minv[j][icol] *= piv_inv;
            }
            // Subtract this row from others to zero out their columns
            for (int j = 0; j < 4; j++) {
                if (j != icol) {
                    float save = minv[icol][j];
                    minv[icol][j] = 0.f;
                    for (size_t k = 0; k < 4; k++) {
                        minv[k][j] -= minv[k][icol] * save;
                    }
                }
            }
        }

        // Swap columns to reflect permutation
        for (int j = 3; j >= 0; j--) {
            if (indxr[j] != indxc[j]) {
                for (size_t k = 0; k < 4; k++) {
                    std::swap(minv[indxr[j]][k], minv[indxc[j]][k]);
                }
            }
        }

        return sse_matrix(minv[0][0], minv[1][0], minv[2][0], minv[3][0],
                minv[0][1], minv[1][1], minv[2][1], minv[3][1],
                minv[0][2], minv[1][2], minv[2][2], minv[3][2],
                minv[0][3], minv[1][3], minv[2][3], minv[3][3]);
    }

    // Transpose matrix

    sse_matrix transpose(const sse_matrix & m) {
        sse_matrix result;

        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                result.data[j][i] = m.data[i][j];
            }
        }

        return result;
    }

    // Print matrix

    void print_sse_matrix(const sse_matrix & m) {
        for (size_t i = 0; i < 4; i++) {
            std::cout << "[";
            for (size_t j = 0; j < 4; j++) {
                std::cout << m.data[j][i];
                if (j < 3) {
                    std::cout << "\t";
                }
            }
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
    }

}

#endif /* SSE_MATRIX_H */

