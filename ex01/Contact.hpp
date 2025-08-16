#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

enum Field {
    FIRST_NAME,
    LAST_NAME,
    NICKNAME,
    PHONE_NUMBER,
    DARKEST_SECRET
};

class Contact {
private:
    std::string fields[5]; // 5つのフィールドを配列で管理

public:
    void setField(int fieldIndex, std::string value);
    std::string getField(int fieldIndex);
    bool isValid();
    void displaySummary(int index);
    void displayDetail();
};

#endif

