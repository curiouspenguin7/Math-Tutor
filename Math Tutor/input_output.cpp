#include "input_output.h"
#include <iostream>

std::string InputOutput::getInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

void InputOutput::displayOutput(const std::string& message) {
    std::cout << message << "\n";
}
