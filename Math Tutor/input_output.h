#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <string>

class InputOutput {
public:
    static std::string getInput(const std::string& prompt);
    static void displayOutput(const std::string& message);
};

#endif
