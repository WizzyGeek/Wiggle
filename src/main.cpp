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

#include <iostream>
#include <string>

#include "wiggle.hpp"

int main(int argc, char *argv[]) {
    int height, width, delay;
    bool infinite;
    unsigned int iter = 400;
    std::string text;

    if (argc == 1) {
        height = 80;
        width = 40;
        delay = 40;
        infinite = false;
        text = "Wiggling";
    } else {
        std::cout << "CLI is WIP" << std::endl;
        std::cout << "===========" << std::endl << "Wiggler" << std::endl << "===========" << std::endl;
        std::cout << "Wiggle width: ";
        std::cin >> width;
        std::cout << "Wiggle height: ";
        std::cin >> height;
        std::cout << "Delay in each slice of wiggle (ms): ";
        std::cin >> delay;
        std::string temp;
        std::cout << "Wiggle infinitely? (Y/n): ";
        std::cin >> temp;
        if (std::tolower(temp[0]) == 'y') {
            infinite = true;
        } else {
            infinite = false;
            std::cout << "How many times to wiggle? : ";
            std::cin >> iter;
        };
        std::cout << "The text to wiggle: ";
        std::cin >> text;
    };

    wiggle::Wiggler wiggly(width, height, delay);

    switch (infinite) {
        case true:
            wiggly.wiggleInfinitely(text);
            break;

        default:
            wiggly.wiggle(text, iter);
            break;
    };
    return 0;
};