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
 * File:   vector_test_class.h
 * Author: simon
 *
 * Created on Oct 25, 2016, 1:10:27 AM
 */

#ifndef VECTOR_TEST_CLASS_H
#define VECTOR_TEST_CLASS_H

#include <cppunit/extensions/HelperMacros.h>

class vector_test_class : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(vector_test_class);

    CPPUNIT_TEST(testDot);
    CPPUNIT_TEST(testAbs_dot);
    CPPUNIT_TEST(testSqrd_length);
    CPPUNIT_TEST(testLength);
    CPPUNIT_TEST(testNormalize);
    CPPUNIT_TEST(testNormalize2);
    CPPUNIT_TEST(testCross);
    CPPUNIT_TEST(testOrthogonal);

    CPPUNIT_TEST_SUITE_END();

public:
    vector_test_class();
    virtual ~vector_test_class();
    void setUp();
    void tearDown();

private:
    void testDot();
    void testAbs_dot();
    void testSqrd_length();
    void testLength();
    void testNormalize();
    void testNormalize2();
    void testCross();
    void testOrthogonal();

};

#endif /* VECTOR_TEST_CLASS_H */

