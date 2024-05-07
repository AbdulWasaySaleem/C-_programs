#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time
#include <algorithm> // For std::find

int main() {
    // Array of words to guess || must be capital
    std::vector<std::string> words = {"APPLE", "BANANA", "CHERRY", "ORANGE", "PEACH"};

    // Seed the random generator
    std::srand(std::time(nullptr));

    // Select a random word from the array
    int random_index = std::rand() % words.size();
    std::string chosen_word = words[random_index];

    std::vector<char> guessed_letters;
    bool word_guessed = false;
    int attempts = 6;

    while (attempts > 0 && !word_guessed) {
        // Display the word with guessed letters and placeholders for unguessed letters
        std::cout << "Current word: ";
        bool all_guessed = true;
        for (char c : chosen_word) {
            if (std::find(guessed_letters.begin(), guessed_letters.end(), c) != guessed_letters.end()) {
                std::cout << c << " ";
            } else {
                std::cout << "_ ";
                all_guessed = false;
            }
        }
        std::cout << std::endl;

        // Get the user's guess
        std::cout << "Enter a letter (or type 'quit' to exit): ";
        std::string guess;
        std::cin >> guess;

        if (guess == "quit") {
            std::cout << "Game ended by the user." << std::endl;
            break;
        }

        // If the guess is a single letter
        if (guess.length() == 1) {
            char guessed_letter = guess[0];

            if (std::find(guessed_letters.begin(), guessed_letters.end(), guessed_letter) == guessed_letters.end()) {
                guessed_letters.push_back(guessed_letter);

                if (chosen_word.find(guessed_letter) == std::string::npos) {
                    attempts--;
                    std::cout << "Incorrect guess. Attempts left: " << attempts << std::endl;
                }
            }
        } else {
            // If the guess is an entire word
            if (guess == chosen_word) {
                word_guessed = true;
                std::cout << "Correct! You guessed the entire word." << std::endl;
            } else {
                attempts--;
                std::cout << "Incorrect guess. Attempts left: " << attempts << std::endl;
            }
        }

        word_guessed = all_guessed;
    }

    if (!word_guessed && attempts <= 0) {
        std::cout << "You lost. The correct word was: " << chosen_word << std::endl;
    }

    return 0;
}
