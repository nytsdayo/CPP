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

void Contact::setFirstName(const std::string& name) {
    this->first_name = name; // this->は省略可能
}

void Contact::setLastName(const std::string& name) {
    last_name = name;
}

void Contact::setNickname(const std::string& name) {
    nickname = name;
}

void Contact::setPhoneNumber(const std::string& number) {
    phone_number = number;
}

void Contact::setDarkestSecret(const std::string& secret) {
    darkest_secret = secret;
}

std::string Contact::getFirstName() const {
    return first_name;
}

std::string Contact::getLastName() const {
    return last_name;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phone_number;
}

std::string Contact::getDarkestSecret() const {
    return darkest_secret;
}

void Contact::displaySummary(int index) {
    std::cout << "|" << std::setw(10) << std::right << index;
    std::cout << "|" << std::setw(10) << std::right << truncate(this->first_name);
    std::cout << "|" << std::setw(10) << std::right << truncate(this->last_name);
    std::cout << "|" << std::setw(10) << std::right << truncate(this->nickname);
    std::cout << "|" << std::endl;
}

void Contact::displayDetail() {
    std::cout << "First Name:     " << this->first_name << std::endl;
    std::cout << "Last Name:      " << this->last_name << std::endl;
    std::cout << "Nickname:       " << this->nickname << std::endl;
    std::cout << "Phone Number:   " << this->phone_number << std::endl;
    std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
}
