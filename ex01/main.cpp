#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

namespace {
	std::string promptAndGetValidatedInput(
    const std::string& prompt,
    bool (*validator)(const std::string&),
    const std::string& error_msg) {
		std::string input;
		while (true) {
			std::cout << prompt;
			
			if (!std::getline(std::cin, input)) {
				throw std::runtime_error("Input stream closed.");
				break;
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
		if (str[0] == '-' || str[str.length() - 1] == '-') {
			return false; // '-' cannot be at the start or end
		}
		size_t start = (str[0] == '+') ? 1 : 0; // '+' is optional at the start
		bool hasDigit = false;

		for (size_t i = start; i < str.length(); ++i) {
			if (!isdigit(str[i]) && str[i] != '-') {
				return false;
			}
			if (isdigit(str[i])) {
				hasDigit = true;
			}
		}
		return hasDigit;
	}

	bool hasOnlyPrintableChars(const std::string& str) {
		for (size_t i = 0; i < str.length(); i++) {
			if (!isprint(str[i])) {
				return false;
			}
		}
		return true;
	}

	void add(PhoneBook& phoneBook) {
		std::string	firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		
		try {
			firstName = (promptAndGetValidatedInput(
				"First Name: ", 
				isValidName,
				"Name can only contain alphabet letters."));

			lastName = (promptAndGetValidatedInput(
				"Last Name: ", 
				isValidName,
				"Name can only contain alphabet letters."));

			nickname = (promptAndGetValidatedInput(
				"Nickname: ", 
				hasOnlyPrintableChars, 
				"Nickname contains invalid characters.")); 

			phoneNumber = (promptAndGetValidatedInput(
				"Phone Number: ", 
				isValidPhoneNumber, 
				"Invalid format. Use digits, hyphens (option, not start or end), and an optional '+' at the start."));

			darkestSecret = (promptAndGetValidatedInput(
				"Darkest Secret: ",
				hasOnlyPrintableChars, 
				"Secret contains invalid characters."));

			Contact newContact;

			newContact.setFirstName(firstName);
			newContact.setLastName(lastName);
			newContact.setNickname(nickname);
			newContact.setPhoneNumber(phoneNumber);
			newContact.setDarkestSecret(darkestSecret);
			
			phoneBook.addContact(newContact);
				std::cout << "Contact added successfully." << std::endl;
		}
		catch (const std::exception& e) {
			throw; 
		}
	}
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
		try {
			std::cout << "Enter command (ADD, SEARCH, EXIT): ";
			if (!std::getline(std::cin, command)) {
	            throw std::runtime_error("Input stream closed.");
				break;
			}
			if (command == "ADD") {
				add(phoneBook); 
			} else if (command == "SEARCH") {
				phoneBook.searchContacts();
			} else if (command == "EXIT") {
				break;
			}
    	}
		catch (const std::exception& e) {
			std::cout << std::endl << " Exiting program." << std::endl;
			break;
		}
	}
    return 0;
}
