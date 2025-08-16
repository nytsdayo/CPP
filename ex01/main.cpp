#include "Phonebook.hpp"
#include <iostream>
#include <string>
#include <cctype>

void add(PhoneBook& phoneBook);

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            break; // Ctrl+D (EOF) で終了
        }

        if (command == "ADD") {
            add(phoneBook);
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}

bool isValidName(const std::string& str);
bool isValidPhone(const std::string& str);
bool isValidSecret(const std::string& str);

void add(PhoneBook& phoneBook) {
    Contact newContact;
    std::string prompts[] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
    bool (*validators[])(const std::string&) = {isValidName, isValidName, isValidName, isValidPhone, isValidSecret};
    std::string error_msgs[] = {
        "Invalid input. Please use only alphabetic characters.",
        "Invalid input. Please use only alphabetic characters.",
        "Invalid input. Please use only alphabetic characters.",
        "Invalid phone number. Please use only digits, '+', or '-'.",
        "Invalid input. Please use only printable characters."
    };

    for (int i = 0; i < 5; i++) {
        std::string input;
        while (true) {
            std::cout << prompts[i] << ": ";
            std::getline(std::cin, input);
            if (input.empty()) {
                std::cout << "Field cannot be empty." << std::endl;
            } else if (!validators[i](input)) {
                std::cout << error_msgs[i] << std::endl;
            } else {
                break;
            }
        }
        newContact.setField(i, input);
    }
    phoneBook.addContact(newContact);
    std::cout << "Contact added successfully." << std::endl;
}

bool isValidName(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isalpha(str[i])) return false;
    }
    return true;
}

bool isValidPhone(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-') return false;
    }
    return true;
}

bool isValidSecret(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isprint(str[i])) return false;
    }
    return true;
}