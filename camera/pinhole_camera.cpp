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

#include "pinhole_camera.h"
#include "transform.h"
#include "ray.h"

namespace pixel {

    pinhole_camera::pinhole_camera(const sse_vector & eye, const sse_vector & at, const sse_vector & up,
            const float fov, const uint32_t width, const uint32_t height)
    : eye_world(eye), width(width), height(height) {
        // Compute camera view volume
        top = std::tan(deg_to_rad(fov / 2.f));
        bottom = -top;
        right = (width / static_cast<float>(height)) * top;
        left = -right;
        
        // Compute transformation matrix
        view_matrix = look_at(eye, at, up);
    }

    ray pinhole_camera::generate_ray(const uint32_t i, const uint32_t j, const float u1, const float u2) const {
        // Compute point on view point
        sse_vector s = sse_vector(  left + (right - left) * (i + u1) / static_cast<float>(width),
                                    1.f,
                                    bottom + (top - bottom) * (j + u2) / static_cast<float>(height),
                                    1.f);
        // Compute point in world space
        sse_vector s_world = view_matrix * s;
        // Compute direction
        sse_vector dir = s_world - eye_world;
        
        // Return ray
        return ray(eye_world, dir);
    }
    
}