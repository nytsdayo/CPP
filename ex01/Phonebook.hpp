#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
	    Contact contacts[8];
	    int contactCount;
	    int nextIndex;

	public:
    	PhoneBook();
    	void addContact(Contact newContact);
    	void searchContacts();
    	int getContactCount();
};

#endif