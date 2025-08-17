#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
private:
    std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	// セッター
    void setFirstName(const std::string& name);
    void setLastName(const std::string& name);
    void setNickname(const std::string& name);
    void setPhoneNumber(const std::string& number);
    void setDarkestSecret(const std::string& secret);
    // ゲッター
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    bool isValid();
    void displaySummary(int index);
    void displayDetail();
};

#endif

