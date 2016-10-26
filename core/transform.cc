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

#include "transform.h"
#include "sse_matrix.h"

namespace pixel {

    sse_matrix translate(const float x, const float y, const float z) {
        return sse_matrix(1.f, 0.f, 0.f, x,
                0.f, 1.f, 0.f, y,
                0.f, 0.f, 1.f, z,
                0.f, 0.f, 0.f, 1.f);
    }

    sse_matrix scale(const float sx, const float sy, const float sz) {
        return sse_matrix(sx, 0.f, 0.f, 0.f,
                0.f, sy, 0.f, 0.f,
                0.f, 0.f, sz, 0.f,
                0.f, 0.f, 0.f, 1.f);
    }

    sse_matrix rotate_x(const float deg) {
        float s = std::sin(deg_to_rad(deg));
        float c = std::cos(deg_to_rad(deg));

        return sse_matrix(1.f, 0.f, 0.f, 0.f,
                0.f, c, -s, 0.f,
                0.f, s, c, 0.f,
                0.f, 0.f, 0.f, 1.f);
    }

    sse_matrix rotate_y(const float deg) {
        float s = std::sin(deg_to_rad(deg));
        float c = std::cos(deg_to_rad(deg));

        return sse_matrix(c, 0.f, s, 0.f,
                0.f, 1.f, 0.f, 0.f,
                -s, 0.f, c, 0.f,
                0.f, 0.f, 0.f, 1.f);
    }

    sse_matrix rotate_z(const float deg) {
        float s = std::sin(deg_to_rad(deg));
        float c = std::cos(deg_to_rad(deg));

        return sse_matrix(c, -s, 0.f, 0.f,
                s, c, 0.f, 0.f,
                0.f, 0.f, 1.f, 0.f,
                0.f, 0.f, 0.f, 1.f);
    }

    sse_matrix look_at(const sse_vector & eye, const sse_vector & at, const sse_vector & up) {
        // Compute local base
        sse_vector v = normalize(at - eye);
        sse_vector u = normalize(cross_product(v, up));
        sse_vector w = cross_product(u, v);

        return sse_matrix(u.x, v.x, w.x, eye.x,
                u.y, v.y, w.y, eye.y,
                u.z, v.z, w.z, eye.z,
                0.f, 0.f, 0.f, 1.f);
    }

}