#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		void getFirstName();
		void getLastName();
		void getNickName();
		void getPhoneNumber();
		void getDarkestSecret();
		bool checkString(const std::string &str);
		bool checkPhoneNumber(const std::string &str);
		void printSearchColumn();
		void showAllInformation();
		void istreamException();
};

# endif