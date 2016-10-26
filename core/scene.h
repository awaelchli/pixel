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
 * File:   scene.h
 * Author: simon
 *
 * Created on October 27, 2016, 12:51 AM
 */

#ifndef SCENE_H
#define SCENE_H

#include "pixel.h"
#include "intersectable.h"

namespace pixel {
    
    // Define scene class
    class scene {
        // Constructor
        scene(const intersectable * root);
        
        // Compute intersection of a ray with scene
        bool intersect(const ray & r, surface_interaction * const interaction) const;
        
        // Check for intersection with scene
        bool intersect_p(const ray & r) const;
        
    private:
        // Scene root intersectable
        const intersectable * const intersectable_root;
    };
    
}


#endif /* SCENE_H */

