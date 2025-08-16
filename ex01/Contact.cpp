#include "Contact.hpp"
#include <iostream>
#include <iomanip>

// privateなヘルパー関数：表示用に文字列を切り詰める
static std::string truncate(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void Contact::setField(int fieldIndex, std::string value) {
    if (fieldIndex >= 0 && fieldIndex < 5) {
        this->fields[fieldIndex] = value;
    }
}

std::string Contact::getField(int fieldIndex) {
    if (fieldIndex >= 0 && fieldIndex < 5) {
        return this->fields[fieldIndex];
    }
    return "";
}

bool Contact::isValid() {
    for (int i = 0; i < 5; i++) {
        if (this->fields[i].empty()) {
            return false;
        }
    }
    return true;
}

void Contact::displaySummary(int index) {
    std::cout << "|" << std::setw(10) << std::right << index;
    std::cout << "|" << std::setw(10) << std::right << truncate(this->fields[FIRST_NAME]);
    std::cout << "|" << std::setw(10) << std::right << truncate(this->fields[LAST_NAME]);
    std::cout << "|" << std::setw(10) << std::right << truncate(this->fields[NICKNAME]);
    std::cout << "|" << std::endl;
}

void Contact::displayDetail() {
    std::cout << "First Name:     " << this->fields[FIRST_NAME] << std::endl;
    std::cout << "Last Name:      " << this->fields[LAST_NAME] << std::endl;
    std::cout << "Nickname:       " << this->fields[NICKNAME] << std::endl;
    std::cout << "Phone Number:   " << this->fields[PHONE_NUMBER] << std::endl;
    std::cout << "Darkest Secret: " << this->fields[DARKEST_SECRET] << std::endl;
}
