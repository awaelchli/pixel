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

#include "interaction.h"
#include "sse_spectrum.h"
#include "ray.h"
#include "sse_matrix.h"

namespace pixel {

    surface_interaction::surface_interaction(const float t_p, const sse_vector & hit, const sse_vector & n,
            const sse_vector & s, const sse_vector & t, const float u, const float v,
            const sse_vector & wo, const intersectable * isect_ptr)
    : t_param(t_p), hit_point(hit), normal(n), s(s), t(t), u(u), v(v), wo(wo), intersectable_ptr(isect_ptr) {
    }

    sse_spectrum surface_interaction::Le(const sse_vector & w) const {
        // TODO
        return sse_spectrum();
    }
     
    ray surface_interaction::spawn_ray(const sse_vector & dir) const {
        return ray(hit_point, dir);
    }
    
    void transform_surface_interaction(surface_interaction * const interaction, const sse_matrix & mat) {
        // Transform hit_point
        interaction->hit_point = mat * interaction->hit_point;
        // Transform normal
        interaction->normal = normalize(transpose(inverse(mat)) * interaction->normal);
        // Transform tangent space
        interaction->s = normalize(mat * interaction->s);
        interaction->t = normalize(mat * interaction->t);
        // Transform outgoing direction
        interaction->wo = normalize(mat * interaction->wo);
    }

}