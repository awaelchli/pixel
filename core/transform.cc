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
#include "ray.h"

namespace pixel {

    transform::transform()
    : m(), m_inv() {}

    transform::transform(const matrix & m, const matrix & m_inv)
    : m(m), m_inv(m_inv) {}

    transform transform::inverse() const {
        return transform(m_inv, m);
    }

    transform transform::operator*(const transform & t) const {
        return transform(m * t.m, t.m_inv * m_inv);
    }

    vector transform::transform_dir(const vector & v) const {
        return m.transform_dir(v);
    }

    vector transform::transform_normalize_dir(const vector & v) const {
        return m.transform_normalize_dir(v);
    }

    vector transform::transform_normal(const vector & n) const {
        return m_inv.transform_normal(n);
    }

    vector transform::transform_normalize_normal(const vector & n) const {
        return m_inv.transform_normalize_normal(n);
    }

    ray transform::operator()(const ray & r) const {
        return ray(m.transform_dir(r.origin()), m.transform_dir(r.direction()), r.ray_min(), r.ray_max(), r.ray_depth());
    }

    transform translate(const double x, const double y, const double z) {
        matrix m(1.0, 0.0, 0.0, x,
                    0.0, 1.0, 0.0, y,
                    0.0, 0.0, 1.0, z,
                    0.0, 0.0, 0.0, 1.0);
        matrix m_inv(1.0, 0.0, 0.0, x,
                        0.0, 1.0, 0.0, y,
                        0.0, 0.0, 1.0, z,
                        0.0, 0.0, 0.0, 1.0);
        
        return transform(m, m_inv);
    }
    
    transform scale(const double sx, const double sy, const double sz) {
        matrix m(sx, 0.0, 0.0, 0.0,
                    0.0, sy, 0.0, 0.0,
                    0.0, 0.0, sz, 0.0,
                    0.0, 0.0, 0.0, 1.0);
        matrix m_inv(1.0 / sx, 0.0, 0.0, 0.0,
                        0.0, 1.0 / sy, 0.0, 0.0,
                        0.0, 0.0, 1.0 / sz, 0.0,
                        0.0, 0.0, 0.0, 1);
        
        return transform(m, m_inv);
    }
    
    transform rotate_x(const double deg) {
        double s = std::sin(deg_to_rad(deg));
        double c = std::cos(deg_to_rad(deg));
        matrix m(1.0, 0.0, 0.0, 0.0,
                    0.0, c, -s, 0.0,
                    0.0, s, c, 0.0,
                    0.0, 0.0, 0.0, 1.0);
        
        return transform(m, m.transpose());
    }
    
    transform rotate_y(const double deg) {
        double s = std::sin(deg_to_rad(deg));
        double c = std::cos(deg_to_rad(deg));
        matrix m(c, 0.0, s, 0.0,
                    0.0, 1.0, 0.0, 0.0,
                    -s, 0.0, c, 0.0,
                    0.0, 0.0, 0.0, 1.0);
        
        return transform(m, m.transpose());
    }
    
    transform rotate_z(const double deg) {
        double s = std::sin(deg_to_rad(deg));
        double c = std::cos(deg_to_rad(deg));
        matrix m(c, -s, 0.0, 0.0,
                    s, c, 0.0, 0.0,
                    0.0, 0.0, 1.0, 0.0,
                    0.0, 0.0, 0.0, 1.0);
        
        return transform(m, m.transpose());
    }

}