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
 * File:   vector_test_class.cc
 * Author: simon
 *
 * Created on Oct 25, 2016, 1:10:27 AM
 */

#include "vector_test_class.h"
#include "vector.h"


CPPUNIT_TEST_SUITE_REGISTRATION(vector_test_class);

vector_test_class::vector_test_class() {
}

vector_test_class::~vector_test_class() {
}

void vector_test_class::setUp() {
}

void vector_test_class::tearDown() {
}

void vector_test_class::testDot() {
    const pixel::vector v1(1.0, 2.0, 3.0, 4.0);
    const pixel::vector v2(-1.0, -2.0, -3.0, -4.0);
    double result = dot(v1, v2);
    if (std::abs(result + 30.0) > pixel::EPS) {
        CPPUNIT_ASSERT(false);
    }
}

void vector_test_class::testAbs_dot() {
    const pixel::vector v1(1.0, 2.0, 3.0, 4.0);
    const pixel::vector v2(-1.0, -2.0, -3.0, -4.0);
    double result = abs_dot(v1, v2);
    if (std::abs(result - 30.0) > pixel::EPS) {
        CPPUNIT_ASSERT(false);
    }
}

void vector_test_class::testSqrd_length() {
    const pixel::vector v(1.0, 2.0, 3.0, 4.0);
    double result = pixel::sqrd_length(v);
    if (std::abs(result - 30.0) > pixel::EPS) {
        CPPUNIT_ASSERT(false);
    }
}

void vector_test_class::testLength() {
    const pixel::vector v(1.0, 2.0, 3.0, 4.0);
    double result = length(v);
    if (std::abs(result - std::sqrt(30.0)) > pixel::EPS) {
        CPPUNIT_ASSERT(false);
    }
}

void vector_test_class::testNormalize() {
    const pixel::vector v(1.0, 2.0, 3.0, 4.0);
    pixel::vector result = normalize(v);
    if (std::abs(pixel::length(result) - 1.0) > pixel::EPS) {
        CPPUNIT_ASSERT(false);
    }
}

void vector_test_class::testNormalize2() {
    pixel::vector v(1.0, 2.0, 3.0, 4.0);
    normalize(&v);
    if (std::abs(pixel::length(v) - 1.0) > pixel::EPS) {
        CPPUNIT_ASSERT(false);
    }
}

void vector_test_class::testCross() {
    const pixel::vector v1(1.0, 0.0, 0.0, 2.0);
    const pixel::vector v2(0.0, 1.0, 0.0, 2.0);
    pixel::vector result = cross(v1, v2);
    // Compute dot product
    double dot_1 = pixel::dot(v1, result);
    double dot_2 = pixel::dot(v2, result);
    if (std::abs(dot_1) > pixel::EPS || std::abs(dot_2) > pixel::EPS) {
        CPPUNIT_ASSERT(false);
    }
}

void vector_test_class::testOrthogonal() {
    const pixel::vector v(1.0, 4.0, 2.0, 0.0);
    pixel::vector result = orthogonal(v);
    if (std::abs(pixel::dot(v, result)) > pixel::EPS) {
        CPPUNIT_ASSERT(false);
    }
}

