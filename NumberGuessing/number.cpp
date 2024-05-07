#include <iostream>
#include <cstdlib> // For rand
#include <ctime>   // For time

int main() {
    std::srand(std::time(nullptr)); // Seed the random generator
    int target = std::rand() % 100 + 1; // Random number between 1 and 100
    int guess = 0;
    int attempts = 0;

    while (guess != target) {
        std::cout << "Guess the number (1-100): ";
        std::cin >> guess;
        attempts++;

        if (guess < target) {
            std::cout << "Too low." << std::endl;
        } else if (guess > target) {
            std::cout << "Too high." << std::endl;
        } else {
            std::cout << "Correct! You guessed it in " << attempts << " attempts." << std::endl;
        }
    }

    return 0;
}
