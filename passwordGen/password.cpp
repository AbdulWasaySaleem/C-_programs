#include <iostream>
#include <cstdlib> // For random operations
#include <ctime>   // For time
#include <string>  // For std::string

std::string generate_password(int length, bool use_uppercase, bool use_numbers, bool use_special) {
    std::string characters = "abcdefghijklmnopqrstuvwxyz";

    if (use_uppercase) {
        characters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (use_numbers) {
        characters += "0123456789";
    }
    if (use_special) {
        characters += "!@#$%^&*()-_+=<>?";
    }

    std::string password;
    for (int i = 0; i < length; ++i) {
        int random_index = std::rand() % characters.length();
        password += characters[random_index];
    }

    return password;
}

int main() {
    std::srand(std::time(nullptr)); // Seed for randomization

    int length;
    std::cout << "Enter the desired password length: ";
    std::cin >> length;

    std::string password = generate_password(length, true, true, true);

    std::cout << "Generated password: " << password << std::endl;

    return 0;
}
