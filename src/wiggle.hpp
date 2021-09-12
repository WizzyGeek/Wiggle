// MIT License

// Copyright (c) 2021 WizzyGeek

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cmath>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#define PI 3.1415926

namespace wiggle {
    class Wiggler {
        private:
            unsigned int width;
            unsigned int height;
            unsigned int delay;

        public:
            Wiggler() {
                width = 30;
                height = 45;
                delay = 40;
            };

            Wiggler(unsigned int waveWidth, unsigned int waveHeight, unsigned int writeDelay) {
                width = waveWidth;
                height = waveHeight;
                delay = writeDelay;
            };
            
            void warnHeight(){
                std::cout << "Warning, since the wiggle height (wavelength) is less than or equal to 1 line, can't wiggle." << std::endl;
                std::cout << "next time, try wiggling with a bigger height (say 10)" << std::endl;
            };

            void wiggle(std::string wiggleText, int iterations) {
                std::string spaces = "";
                if(height <= 1)warnHeight();
                for (unsigned int i = 0; i < iterations; i++) {
                    if(height > 1){
                        spaces.resize(std::round(width * ((-1 * (std::cos((PI * i) / (height / 2)))) + 1)/2), ' ');
                        std::cout << spaces << wiggleText << std::endl;
                    }else{
                        std::cout << wiggleText << std::endl;
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                }
            };

            void wiggleInfinitely(std::string wiggleText) {
                std::string spaces = "";
                unsigned int i = 0;
                if(height <= 1)warnHeight();
                while (true) {
                    if(height > 1){
                        spaces.resize(std::round(width * ((-1 * (std::cos((PI * i) / (height / 2)))) + 1)/2), ' ');
                        i++;
                        i %= height;
                        std::cout << spaces << wiggleText << std::endl;
                    }else{
                        std::cout << spaces << wiggleText << std::endl;
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                }
            };
    };
};