#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <sstream>

PhoneBook::PhoneBook() {
    this->contactCount = 0;
    this->nextIndex = 0;
}

void PhoneBook::addContact(Contact newContact) {
    this->contacts[this->nextIndex] = newContact;
    this->nextIndex = (this->nextIndex + 1) % 8;
    if (this->contactCount < 8) {
        this->contactCount++;
    }
}

void PhoneBook::searchContacts() {
    if (this->contactCount == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << std::right << "index";
    std::cout << "|" << std::setw(10) << std::right << "first name";
    std::cout << "|" << std::setw(10) << std::right << "last name";
    std::cout << "|" << std::setw(10) << std::right << "nickname" << "|" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (int i = 0; i < this->contactCount; i++) {
        this->contacts[i].displaySummary(i + 1);
    }
    std::cout << "-------------------------------------------" << std::endl;

	int index = 0;
    while (true) {
        std::cout << "Enter index to display: ";
        std::string line;

		if (!std::getline(std::cin, line)) {
            throw std::runtime_error("Input stream closed.");
        }

		if (line.empty()){
			std::cout << "Field cannot be empty." << std::endl;
			continue;
		}
		std::stringstream ss(line);
    	int temp_index;
    	if (ss >> temp_index && temp_index > 0 && temp_index <= this->contactCount) {
        	index = temp_index;
			break;
    	}
		ss >> std::ws;
        if (!ss.eof()) {
            std::cout << "Invalid index (extra characters). Please try again." << std::endl;
            continue;
        }
        if (temp_index < 1 || temp_index > this->contactCount) {
            std::cout << "Index out of range. Valid: 1-" << this->contactCount << std::endl;
            continue;
        }
        std::cin.clear();
        std::cout << "Invalid index. Please try again." << std::endl;
    }

    this->contacts[index - 1].displayDetail();
}

int PhoneBook::getContactCount() {
    return this->contactCount;
}

