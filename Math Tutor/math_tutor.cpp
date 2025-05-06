 #include "math_tutor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void MathTutor::start() {
    std::srand(std::time(nullptr)); // Seed for random problem generation
    int choice;

    std::cout << "Welcome to the Math Tutor AI!\n";
    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting... Final Score: " << score << "/" << totalQuestions << "\n";
            break;
        }

        handleUserChoice(choice);
    }
}

void MathTutor::displayMenu() {
    std::cout << "\nChoose a category:\n";
    std::cout << "1. Basic Algebra\n";
    std::cout << "2. Geometry\n";
    std::cout << "3. Trigonometry\n";
    std::cout << "4. Calculus\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void MathTutor::handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            generatePracticeProblem("Algebra");
            break;
        case 2:
            generatePracticeProblem("Geometry");
            break;
        case 3:
            generatePracticeProblem("Trigonometry");
            break;
        case 4:
            generatePracticeProblem("Calculus");
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
    }
}

void MathTutor::generatePracticeProblem(const std::string& category) {
    std::string problem;
    std::cout << "\nGenerating a " << category << " problem...\n";

    if (category == "Algebra") {
        int a = std::rand() % 10 + 1; // Random coefficient
        int b = std::rand() % 10 + 1; // Random constant
        problem = "Solve for x: " + std::to_string(a) + "x + " + std::to_string(b) + " = 0";
        std::cout << problem << "\n";
    }
    else if (category == "Geometry") {
        int radius = std::rand() % 10 + 1;
        problem = "Find the area of a circle with radius " + std::to_string(radius);
        std::cout << problem << "\n";
    }
    else if (category == "Trigonometry") {
        int angle = (std::rand() % 90) + 1; // Random angle in degrees
        problem = "What is sin(" + std::to_string(angle) + " degrees)?";
        std::cout << problem << "\n";
    }
    else if (category == "Calculus") {
        int coefficient = std::rand() % 5 + 1;
        problem = "Differentiate f(x) = " + std::to_string(coefficient) + "x^2";
        std::cout << problem << "\n";
    }

    totalQuestions++;
    std::cout << "Would you like a hint? (yes/no): ";
    std::string hintChoice;
    std::cin >> hintChoice;
    if (hintChoice == "yes") provideHint(problem);

    std::cout << "Enter your answer: ";
    std::string userAnswer;
    std::cin.ignore();
    std::getline(std::cin, userAnswer);

    // Mock checking answer
    bool correct = (std::rand() % 2 == 0); // Random correctness
    if (correct) {
        std::cout << "Correct!\n";
        trackScore(true);
    } else {
        std::cout << "Incorrect.\n";
        trackScore(false);
    }

    std::cout << "Would you like to see the solution? (yes/no): ";
    std::string solutionChoice;
    std::cin >> solutionChoice;
    if (solutionChoice == "yes") showSolution(problem);
}

void MathTutor::provideHint(const std::string& problem) {
    std::cout << "Hint: Think about the basic formulas for " << problem << "\n";
}

void MathTutor::showSolution(const std::string& problem) {
    std::cout << "Solution: [A detailed solution tailored for " << problem << " would be here.]\n";
}

void MathTutor::trackScore(bool correct) {
    if (correct) score++;
}
