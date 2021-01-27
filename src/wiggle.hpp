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
                width = 15;
                height = 45;
                delay = 40;
            };

            Wiggler(unsigned int waveWidth, unsigned int waveHeight, unsigned int writeDelay) {
                width = waveWidth;
                height = waveHeight;
                delay = writeDelay;
            };

            void wiggle(std::string wiggleText, int iterations) {
                std::string spaces = "";
                for (unsigned int i = 0; i < iterations; i++) {
                    spaces.resize(std::round(width * ((-1 * (std::cos((PI * i) / (height / 2)))) + 1)), ' ');
                    std::cout << spaces << wiggleText << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                };
            };

            void wiggleInfinitely(std::string wiggleText) {
                std::string spaces = "";
                unsigned int i = 0;
                while (true) {
                    spaces.resize(std::round(width * ((-1 * (std::cos((PI * i) / (height / 2)))) + 1)), ' ');
                    i++;
                    i %= height;
                    std::cout << spaces << wiggleText << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                };
            };
    };
};