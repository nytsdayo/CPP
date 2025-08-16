#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <limits> // std::numeric_limits を使うために必要

PhoneBook::PhoneBook() {
    this->contactCount = 0;
    this->nextIndex = 0;
}

void PhoneBook::addContact(Contact newContact) {
    this->contacts[this->nextIndex] = newContact;
    this->nextIndex = (this->nextIndex + 1) % 8; // 0-7を循環
    if (this->contactCount < 8) {
        this->contactCount++;
    }
}

void PhoneBook::searchContacts() {
    if (this->contactCount == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    // ヘッダー表示
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << std::right << "index";
    std::cout << "|" << std::setw(10) << std::right << "first name";
    std::cout << "|" << std::setw(10) << std::right << "last name";
    std::cout << "|" << std::setw(10) << std::right << "nickname" << "|" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    // 連絡先一覧表示
    for (int i = 0; i < this->contactCount; i++) {
        this->contacts[i].displaySummary(i + 1);
    }
    std::cout << "-------------------------------------------" << std::endl;

    // インデックス入力
    int index;
    while (true) {
        std::cout << "Enter index to display: ";
        std::cin >> index;
        if (std::cin.good() && index > 0 && index <= this->contactCount) {
            // 入力バッファをクリア
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        std::cin.clear(); // エラーフラグをクリア
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // バッファをクリア
        std::cout << "Invalid index. Please try again." << std::endl;
    }

    this->contacts[index - 1].displayDetail();
}

int PhoneBook::getContactCount() {
    return this->contactCount;
}