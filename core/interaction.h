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
 * File:   interaction.h
 * Author: simon
 *
 * Created on October 26, 2016, 11:56 PM
 */

#ifndef INTERACTION_H
#define INTERACTION_H

#include "pixel.h"
#include "sse_vector.h"
#include "intersectable.h"

namespace pixel {

    // Define surface_interaction class

    class surface_interaction {
    public:
        // Constructor
        surface_interaction(const float t_p, const sse_vector & hit, const sse_vector & n,
                const sse_vector & s, const sse_vector & t, const float u, const float v,
                const sse_vector & wo, const intersectable * isect_ptr);

        // Compute emission at interaction in given direction
        sse_spectrum Le(const sse_vector & w) const;

        // Spawn ray in given direction
        ray spawn_ray(const sse_vector & dir) const;

        // Interaction parameter
        float t_param;
        // Hit point
        sse_vector hit_point;
        // Geometric normal at hit point
        sse_vector normal;
        // Local tangent vectors
        sse_vector s, t;
        // UV coordinates
        float u, v;
        // Outgoing direction at intersection
        sse_vector wo;
        // Intersectable hit
        const intersectable * intersectable_ptr;
    };
    
    // Transform surface_interaction for a given matrix
    void transform_surface_interaction(surface_interaction * const interaction,
            const sse_matrix & mat);

}

#endif /* INTERACTION_H */

