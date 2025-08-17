#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

bool isValidName(const std::string& str);
bool isValidPhoneNumber(const std::string& str);
bool hasOnlyPrintableChars(const std::string& text);
std::string promptAndGetValidatedInput(
    const std::string& prompt,
    bool (*validator)(const std::string&),
    const std::string& error_msg);
void add(PhoneBook& phoneBook);

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            break;
        }
        if (command == "ADD") {
            try {
                add(phoneBook); 
			}
            catch (const std::exception& e) {
                std::cout << std::endl << " Exiting program." << std::endl;
                break;
            }
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}

void add(PhoneBook& phoneBook) {
	std::string	FirstName;
	std::string LastName;
	std::string Nickname;
	std::string PhoneNumber;
	std::string DarkestSecret;
	
	try {
    FirstName = (promptAndGetValidatedInput(
        "First Name: ", 
        isValidName,
        "Name can only contain alphabet letters."));

    LastName = (promptAndGetValidatedInput(
        "Last Name: ", 
        isValidName,
        "Name can only contain alphabet letters."));

    Nickname = (promptAndGetValidatedInput(
        "Nickname: ", 
        hasOnlyPrintableChars, 
        "Nickname contains invalid characters.")); 

    PhoneNumber = (promptAndGetValidatedInput(
        "Phone Number: ", 
        isValidPhoneNumber, 
        "Invalid format. Use digits, hyphens, and an optional '+' at the start."));

    DarkestSecret = (promptAndGetValidatedInput(
        "Darkest Secret: ",
        hasOnlyPrintableChars, 
        "Secret contains invalid characters."));

	Contact newContact;

	newContact.setFirstName(FirstName);
	newContact.setLastName(LastName);
	newContact.setNickname(Nickname);
	newContact.setPhoneNumber(PhoneNumber);
	newContact.setDarkestSecret(DarkestSecret);
	
    phoneBook.addContact(newContact);
    std::cout << "Contact added successfully." << std::endl;
	}
	catch (const std::exception& e) {
        throw; 
    }
}

std::string promptAndGetValidatedInput(
    const std::string& prompt,
    bool (*validator)(const std::string&),
    const std::string& error_msg) 
{
    std::string input;
    while (true) {
        std::cout << prompt;
        
		if (!std::getline(std::cin, input)) {
            throw std::runtime_error("Input stream closed.");
        }
        if (input.empty()) {
            std::cout << "Field cannot be empty." << std::endl;
        } else if (!validator(input)) {
            std::cout << error_msg << std::endl;
        } else {
            return input;
        }
    }
}

bool isValidName(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isalpha(str[i])) return false;
    }
    return true;
}

bool isValidPhoneNumber(const std::string& str) {
    if (str.empty()) return false;

    size_t start = (str[0] == '+') ? 1 : 0;

    for (size_t i = start; i < str.length(); ++i) {
        if (!isdigit(str[i]) && str[i] != '-') {
            return false;
        }
    }
    return true;
}

bool hasOnlyPrintableChars(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isprint(str[i])) {
            return false;
        }
    }
    return true;
}
