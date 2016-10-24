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

#include "clamp_tonemapper.h"
#include <fstream>

namespace pixel {

    clamp_tone_mapper::clamp_tone_mapper(const real g)
    : tone_mapper(), gamma(g) {}

    void clamp_tone_mapper::process(const std::string & file_name, const film & f) const {
        // Create output file
        std::fstream file;
        file.open(file_name, std::fstream::out);
        // Write ppm file header
        file << "P3\n";
        file << f.get_width() << " " << f.get_height() << "\n";
        file << "255\n";
        // Write colors to file
        for (int32_t j = f.get_height() - 1; j >= 0; j--) {
            for (uint32_t i = 0; i < f.get_width(); i++) {
                // Get color
                const spectrum & c = f.get_spectrum(i, j);
                // Clamp the color and correct gamma
                spectrum clamped_c = pow(clamp(c, 0, 1), gamma);
                // Output color
                file << static_cast<int32_t>(clamped_c[0] * 255) << " ";
                file << static_cast<int32_t>(clamped_c[1] * 255) << " ";
                file << static_cast<int32_t>(clamped_c[2] * 255) << " ";
            }
            file << "\n";
        }
        // Close file
        file.close();
    }

}