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
 * File:   sse_spectrum.h
 * Author: simon
 *
 * Created on October 26, 2016, 10:38 PM
 */

#ifndef SSE_SPECTRUM_H
#define SSE_SPECTRUM_H

#include "pixel.h"
#include <immintrin.h>

namespace pixel {

    class sse_spectrum {
    public:
        // Constructor

        sse_spectrum()
        : r(0.f), g(0.f), b(0.f), w(0.f) {
        }

        sse_spectrum(const sse_spectrum & other)
        : xmm(other.xmm) {
        }

        sse_spectrum(const float r, const float g, const float b)
        : r(r), g(g), b(b), w(0.f) {
        }

        explicit sse_spectrum(const float v)
        : r(v), g(v), b(v), w(0.f) {
        }

        sse_spectrum(const __m128 & xmm)
        : xmm(xmm) {
        }

        // Assignment operator

        inline sse_spectrum & operator=(const sse_spectrum & other) {
            if (this != &other) {
                xmm = other.xmm;
            }

            return *this;
        }

        inline sse_spectrum & operator=(const __m128 & other) {
            xmm = other;

            return *this;
        }

        // Operator on self

        void operator+=(const sse_spectrum & s) {
            xmm = _mm_add_ps(xmm, s.xmm);
        }

        void operator+=(const __m128 & xmm1) {
            xmm = _mm_add_ps(xmm, xmm1);
        }

        void operator-=(const sse_spectrum & s) {
            xmm = _mm_sub_ps(xmm, s.xmm);
        }

        void operator-=(const __m128 & xmm1) {
            xmm = _mm_sub_ps(xmm, xmm1);
        }

        void operator*=(const float s) {
            xmm = _mm_mul_ps(xmm, _mm_set1_ps(s));
        }

        void operator*=(const sse_spectrum & s) {
            xmm = _mm_mul_ps(xmm, s.xmm);
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
                float r, g, b, w;
            };
        };
    };

    // Sum

    inline __m128 operator+(const sse_spectrum & s1, const sse_spectrum & s2) {
        return _mm_add_ps(s1.xmm, s2.xmm);
    }

    inline __m128 operator+(const __m128 & xmm1, const sse_spectrum & s) {
        return _mm_add_ps(xmm1, s.xmm);
    }

    // Subtraction

    inline __m128 operator-(const sse_spectrum & s1, const sse_spectrum & s2) {
        return _mm_sub_ps(s1.xmm, s2.xmm);
    }

    inline __m128 operator-(const __m128 & xmm, const sse_spectrum & s) {
        return _mm_sub_ps(xmm, s.xmm);
    }

    // Multiplication

    inline __m128 operator*(const sse_spectrum & s1, const sse_spectrum & s2) {
        return _mm_mul_ps(s1.xmm, s2.xmm);
    }

    inline __m128 operator*(const __m128 & xmm, const sse_spectrum & s) {
        return _mm_mul_ps(xmm, s.xmm);
    }

    // Spectrum scaling

    inline __m128 operator*(const float t, const sse_spectrum & s) {
        return _mm_mul_ps(_mm_set1_ps(t), s.xmm);
    }

    inline __m128 operator*(const sse_spectrum & s, const float t) {
        return _mm_mul_ps(_mm_set1_ps(t), s.xmm);
    }

    inline __m128 operator/(const sse_spectrum & s, const float t) {
        return _mm_div_ps(s.xmm, _mm_set1_ps(t));
    }

    // Check if spectrum is black

    inline bool is_black(const sse_spectrum & s) {
        return (s.r == 0.f && s.g == 0.f && s.b == 0.f);
    }

    // Spectrum power function

    inline sse_spectrum pow(const sse_spectrum & s, const float e) {
        return sse_spectrum(std::pow(s.r, e), std::pow(s.g, e), std::pow(s.b, e));
    }

    // Print spectrum

    inline void print_sse_spectrum(const sse_spectrum & s) {
        std::cout << "[" << s.r << ", " << s.g << ", " << s.b << "]" << std::endl;
    }

    // Clamp color

    inline sse_spectrum clamp(const sse_spectrum & s, const float min, const float max) {
        return sse_spectrum(clamp(s.r, min, max), clamp(s.g, min, max), clamp(s.b, min, max));
    }

}

#endif /* SSE_SPECTRUM_H */

