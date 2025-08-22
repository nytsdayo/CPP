#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <sstream>

// コンストラクタの初期化リストを使用してメンバ変数を初期化
PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {
    // メンバ初期化リストを使用（より効率的）
}

void PhoneBook::addContact(const Contact& contact) {
    this->contacts[this->nextIndex] = contact;
    this->nextIndex = (this->nextIndex + 1) % 8;
    if (this->contactCount < 8) {
        this->contactCount++;
    }
}

void PhoneBook::displayContactsTable() const {
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << std::right << "index";
    std::cout << "|" << std::setw(10) << std::right << "first name";
    std::cout << "|" << std::setw(10) << std::right << "last name";
    std::cout << "|" << std::setw(10) << std::right << "nickname" << "|" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < contactCount; ++i) {
        contacts[i].displaySummary(i + 1);
    }
    std::cout << "-------------------------------------------" << std::endl;
}

int PhoneBook::getValidIndexFromUser(int contactCount) const {
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

void PhoneBook::searchContacts() const {
    if (this->contactCount == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    displayContactsTable();

	int index = getValidIndexFromUser(this->contactCount);

    this->contacts[index - 1].displayDetail();
}

int PhoneBook::getContactCount() const {
    return contactCount;
}

bool PhoneBook::isEmpty() const {
    return contactCount == 0;
}
