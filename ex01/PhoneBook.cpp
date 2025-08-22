#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <sstream>

// 無名名前空間 (Cでいう static)
// ここに定義された関数はこのファイル内でのみ使用可能
namespace {
    void printContactsSummary(const Contact contacts[], int contactCount) {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "|" << std::setw(10) << std::right << "index";
        std::cout << "|" << std::setw(10) << std::right << "first name";
        std::cout << "|" << std::setw(10) << std::right << "last name";
        std::cout << "|" << std::setw(10) << std::right << "nickname" << "|" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
		for (int i = 0; i < contactCount; i++) {
			contacts[i].displaySummary(i + 1);
		}
    	std::cout << "-------------------------------------------" << std::endl;
	}

	int promptIndex(const int contactCount) {
        while (true) {
            std::cout << "Enter index to display: ";
            std::string line;
            if (!std::getline(std::cin, line)) {
                throw std::runtime_error("Input stream closed.");
            }
            if (line.empty()) {
                std::cout << "Field cannot be empty." << std::endl;
                continue;
            }
            std::stringstream ss(line);
            int temp;
            if (!(ss >> temp)) {
                std::cout << "Invalid index. Please enter a number." << std::endl;
                continue;
            }
            if (!ss.eof()) {
                std::cout << "Invalid index (extra characters). Please try again." << std::endl;
                continue;
            }
            if (temp < 1 || temp > contactCount) {
                std::cout << "Index out of range. Valid: 1-" << contactCount << std::endl;
                continue;
            }
            return temp;
        }
    }
}

PhoneBook::PhoneBook() {
    this->contactCount = 0;
    this->nextIndex = 0;
}

void PhoneBook::addContact(const Contact newContact) {
    this->contacts[this->nextIndex] = newContact;
    this->nextIndex = (this->nextIndex + 1) % 8;
    if (this->contactCount < 8) {
        this->contactCount++;
    }
}

void PhoneBook::searchContacts() const {
    if (this->contactCount == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    printContactsSummary(this->contacts, this->contactCount);

	int index = promptIndex(contactCount); // promptIndex は有効な index を返す保証がある

    this->contacts[index - 1].displayDetail();
}

int PhoneBook::getContactCount() const {
    return this->contactCount;
}

