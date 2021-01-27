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