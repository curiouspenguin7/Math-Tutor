#ifndef MATH_TUTOR_H
#define MATH_TUTOR_H

#include <string>

class MathTutor {
public:
    void start();
private:
    void displayMenu();
    void handleUserQuery(const std::string& query);
};

#endif
