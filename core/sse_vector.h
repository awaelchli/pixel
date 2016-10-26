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
 * File:   sse_vector.h
 * Author: simon
 *
 * Created on October 26, 2016, 1:23 PM
 */

#ifndef SSE_VECTOR_H
#define SSE_VECTOR_H

#include <immintrin.h>
#include "pixel.h"

namespace pixel {

    // SSE vector class

    class sse_vector {
    public:
        // Constructor

        sse_vector()
        : x(0.f), y(0.f), z(0.f), w(0.f) {
        }

        sse_vector(const sse_vector & other)
        : xmm(other.xmm) {
        }

        sse_vector(const float x, const float y, const float z, const float w)
        : x(x), y(y), z(z), w(w) {
        }

        explicit sse_vector(const float v)
        : x(v), y(v), z(v), w(v) {
        }

        sse_vector(const __m128 & xmm)
        : xmm(xmm) {
        }

        // Assignment operator

        inline sse_vector & operator=(const sse_vector & other) {
            if (this != &other) {
                xmm = other.xmm;
            }

            return *this;
        }

        inline sse_vector & operator=(const __m128 & other) {
            xmm = other;

            return *this;
        }

        // Operator on self

        void operator+=(const sse_vector & v) {
            xmm = _mm_add_ps(xmm, v.xmm);
        }

        void operator+=(const __m128 & xmm1) {
            xmm = _mm_add_ps(xmm, xmm1);
        }

        void operator-=(const sse_vector & v) {
            xmm = _mm_sub_ps(xmm, v.xmm);
        }

        void operator-=(const __m128 & xmm1) {
            xmm = _mm_sub_ps(xmm, xmm1);
        }

        void operator*=(const float s) {
            xmm = _mm_mul_ps(xmm, _mm_set1_ps(s));
        }

        void operator*=(const sse_vector & v) {
            xmm = _mm_mul_ps(xmm, v.xmm);
        }

        void operator*=(const __m128 & xmm1) {
            xmm = _mm_mul_ps(xmm, xmm1);
        }

        void operator/=(const float s) {
            xmm = _mm_div_ps(xmm, _mm_set1_ps(s));
        }

        union {
            // Packed vector datatype for SSE
            __m128 xmm;
            // Named vector fields

            struct {
                float x, y, z, w;
            };
        };
    };

    // Sum

    inline __m128 operator+(const sse_vector & v1, const sse_vector & v2) {
        return _mm_add_ps(v1.xmm, v2.xmm);
    }

    inline __m128 operator+(const __m128 & xmm1, const sse_vector & v) {
        return _mm_add_ps(xmm1, v.xmm);
    }

    // Subtraction

    inline __m128 operator-(const sse_vector & v1, const sse_vector & v2) {
        return _mm_sub_ps(v1.xmm, v2.xmm);
    }

    inline __m128 operator-(const __m128 & xmm, const sse_vector & v) {
        return _mm_sub_ps(xmm, v.xmm);
    }

    // Multiplication

    inline __m128 operator*(const sse_vector & v1, const sse_vector & v2) {
        return _mm_mul_ps(v1.xmm, v2.xmm);
    }

    inline __m128 operator*(const __m128 & xmm, const sse_vector & v) {
        return _mm_mul_ps(xmm, v.xmm);
    }

    // Vector scaling

    inline __m128 operator*(const float s, const sse_vector & v) {
        return _mm_mul_ps(_mm_set1_ps(s), v.xmm);
    }

    inline __m128 operator*(const sse_vector & v, const float s) {
        return _mm_mul_ps(_mm_set1_ps(s), v.xmm);
    }

    inline __m128 operator/(const sse_vector & v, const float s) {
        return _mm_div_ps(v.xmm, _mm_set1_ps(s));
    }

    // SSE dot product
#define _MM_DOT(c0, c1, c2, c3, r0, r1, r2, r3) \
        (((c3)<<7) | ((c2)<<6) | ((c1)<<5) | ((c0)<<4) | ((r3)<<3) | ((r2)<<2) | ((r1)<<1) | r0)

#define _MM_FULL_DOT _MM_DOT(1,1,1,1,1,1,1,1)

    inline __m128 dot_product_sse(const sse_vector & v1, const sse_vector & v2) {
        return _mm_dp_ps(v1.xmm, v2.xmm, _MM_FULL_DOT);
    }

    inline __m128 dot_product_sse(const sse_vector & v, const __m128 & xmm) {
        return _mm_dp_ps(v.xmm, xmm, _MM_FULL_DOT);
    }

    inline __m128 dot_product_sse(const __m128 & xmm, const sse_vector & v) {
        return _mm_dp_ps(xmm, v.xmm, _MM_FULL_DOT);
    }

    inline __m128 dot_product_sse(const __m128 & xmm1, const __m128 & xmm2) {
        return _mm_dp_ps(xmm1, xmm2, _MM_FULL_DOT);
    }

    // SSE abs dot product
    static const __m128 SIGN_MASK = _mm_castsi128_ps(_mm_set1_epi32(0x80000000));

    inline __m128 abs_dot_product_sse(const sse_vector & v1, const sse_vector & v2) {
        return _mm_andnot_ps(SIGN_MASK, _mm_dp_ps(v1.xmm, v2.xmm, _MM_FULL_DOT));
    }

    inline __m128 abs_dot_product_sse(const sse_vector & v, const __m128 & xmm) {
        return _mm_andnot_ps(SIGN_MASK, _mm_dp_ps(v.xmm, xmm, _MM_FULL_DOT));
    }

    inline __m128 abs_dot_product_sse(const __m128 & xmm, const sse_vector & v) {
        return _mm_andnot_ps(SIGN_MASK, _mm_dp_ps(xmm, v.xmm, _MM_FULL_DOT));
    }

    inline __m128 abs_dot_product_sse(const __m128 & xmm1, const __m128 & xmm2) {
        return _mm_andnot_ps(SIGN_MASK, _mm_dp_ps(xmm1, xmm2, _MM_FULL_DOT));
    }

    // Normal dot product

    inline float dot_product(const sse_vector & v1, const sse_vector & v2) {
        return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.z * v2.z);
    }

    inline float abs_dot_product(const sse_vector & v1, const sse_vector & v2) {
        return std::abs(dot_product(v1, v2));
    }

    // SSE length of a vector

    inline __m128 sse_length(const sse_vector & v) {
        return _mm_sqrt_ps(dot_product_sse(v.xmm, v.xmm));
    }

    inline __m128 sse_length(const __m128 & xmm) {
        return _mm_sqrt_ps(dot_product_sse(xmm, xmm));
    }

    inline __m128 sse_sqrd_length(const sse_vector & v) {
        return dot_product_sse(v.xmm, v.xmm);
    }

    inline __m128 sse_sqrd_length(const __m128 & xmm) {
        return dot_product_sse(xmm, xmm);
    }

    // Normal vector length

    inline float length(const sse_vector & v) {
        return std::sqrt(dot_product(v, v));
    }

    inline float sqrd_length(const sse_vector & v) {
        return dot_product(v, v);
    }

    // Normalize vector

    inline __m128 normalize(const sse_vector & v) {
        return _mm_div_ps(v.xmm, sse_length(v));
    }

    inline __m128 normalize(const __m128 & xmm) {
        return _mm_div_ps(xmm, sse_length(xmm));
    }

    // Cross product

    inline sse_vector cross_product(const sse_vector & v1, const sse_vector & v2) {
        return sse_vector(v1.y * v2.z - v1.z * v2.y,
                v1.z * v1.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x,
                0.f);
    }

    // Create orthogonal vector

    inline sse_vector orthogonal(const sse_vector & v) {
        if (std::abs(v.x) <= std::abs(v.y) && std::abs(v.x) <= std::abs(v.z)) {
            return sse_vector(0.f, -v.z, v.y, 0.f);
        } else if (std::abs(v.y) <= std::abs(v.x) && std::abs(v.y) <= std::abs(v.z)) {
            return sse_vector(-v.z, 0, v.x, 0);
        } else {
            return sse_vector(-v.y, v.x, 0, 0);
        }
    }

    // Print vector

    inline void print_sse_vector(const sse_vector & v) {
        std::cout << "[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]" << std::endl;
    }

}

#endif /* SSE_VECTOR_H */

