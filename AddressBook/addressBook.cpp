#include <iostream>
#include <vector>
#include <string>
#include <sstream> // For std::stringstream
#include <fstream> // For file operations
#include <algorithm> 

// Define a structure to represent a contact
struct Contact {
    std::string name;  // Contact's name
    std::string phone; // Contact's phone number
    std::string email; // Contact's email address
};

// Add a contact to the vector and save it to the file
void add_contact(std::vector<Contact>& contacts, const std::string& name, const std::string& phone, const std::string& email) {
    contacts.push_back({name, phone, email});  // Add the contact to the list
    
    // Open the file in append mode to add the new contact
    std::ofstream file("contacts.txt", std::ios::app);
    if (file.is_open()) {
        file << name << "," << phone << "," << email << "\n";  // Write the contact details to the file
        file.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
    }
}

// Remove a contact from the vector and update the file
void remove_contact(std::vector<Contact>& contacts, const std::string& name) {
    // Remove the contact from the list
    contacts.erase(std::remove_if(contacts.begin(), contacts.end(),
                   [&](const Contact& c) { return c.name == name; }), contacts.end());

    // Rewrite the file with the updated contact list
    std::ofstream file("contacts.txt");
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << contact.name << "," << contact.phone << "," << contact.email << "\n"; // Write the contacts to the file
        }
        file.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
    }
}

// Display all contacts
void display_contacts(const std::vector<Contact>& contacts) {
    std::cout << "Current contacts:\n";
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name 
                  << "\nPhone: " << contact.phone 
                  << "\nEmail: " << contact.email 
                  << "\n" << std::endl;
    }
}

// Load contacts from the file at program start
void load_contacts(std::vector<Contact>& contacts) {
    std::ifstream file("contacts.txt");  // Open the file for reading
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Split the line by commas to get the contact information
            std::stringstream ss(line);
            std::string name, phone, email;
            std::getline(ss, name, ',');
            std::getline(ss, phone, ',');
            std::getline(ss, email, ',');

            // Add the contact to the list
            contacts.push_back({name, phone, email});
        }
        file.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
    }
}

int main() {
    std::vector<Contact> contacts;

    // Load contacts from the file at the beginning
    load_contacts(contacts);

    bool running = true;

    while (running) {
        // Display the menu options
        std::cout << "1. Add contact\n2. Remove contact\n3. Display contacts\n4. Quit\n";
        
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:  // Add a new contact
                {
                    std::string name, phone, email;
                    std::cout << "Enter name: ";
                    std::cin >> name;
                    std::cout << "Enter phone: ";
                    std::cin >> phone;
                    std::cout << "Enter email: ";
                    std::cin >> email;

                    add_contact(contacts, name, phone, email);  // Add the contact and save to file
                }
                break;

            case 2:  // Remove a contact
                {
                    std::string name;
                    std::cout << "Enter name to remove: ";
                    std::cin >> name;

                    remove_contact(contacts, name);  // Remove the contact and update the file
                }
                break;

            case 3:  // Display all contacts
                display_contacts(contacts);
                break;

            case 4:  // Quit the program
                running = false;
                break;

            default:
                std::cerr << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
