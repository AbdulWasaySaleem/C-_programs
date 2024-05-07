#include <iostream>

// Conversion functions
double celsius_to_fahrenheit(double celsius) {
    return celsius * 9 / 5 + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

int main() {
    double temperature;
    int choice;

    std::cout << "Choose conversion:\n";
    std::cout << "1. Celsius to Fahrenheit\n";
    std::cout << "2. Fahrenheit to Celsius\n";
    std::cout << "3. Celsius to Kelvin\n";
    std::cout << "4. Kelvin to Celsius\n";
    std::cin >> choice;

    std::cout << "Enter temperature: ";
    std::cin >> temperature;

    switch (choice) {
        case 1:
            std::cout << "Fahrenheit: " << celsius_to_fahrenheit(temperature) << std::endl;
            break;
        case 2:
            std::cout << "Celsius: " << fahrenheit_to_celsius(temperature) << std::endl;
            break;
        case 3:
            std::cout << "Kelvin: " << celsius_to_kelvin(temperature) << std::endl;
            break;
        case 4:
            std::cout << "Celsius: " << kelvin_to_celsius(temperature) << std::endl;
            break;
        default:
            std::cerr << "Invalid choice." << std::endl;
    }

    return 0;
}
