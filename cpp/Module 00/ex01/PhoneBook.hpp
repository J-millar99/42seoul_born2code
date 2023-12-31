#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook : public Contact
{
	private:
		Contact contacts[8];
		int idx;

	public:
		PhoneBook() : idx(0) {}
		void showMenu();
		void add();
		void search();
		void exit();
		bool inRange(const std::string &str);
};

# endif