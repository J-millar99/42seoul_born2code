#include "Contact.hpp"

void Contact::getFirstName()
{
	do
	{
		std::cout << "First Name> ";
		std::getline(std::cin, firstName);
		istreamException();
	}
	while (checkString(firstName) == false);
}

void Contact::getLastName()
{
	do
	{
		std::cout << "Last Name> ";
		std::getline(std::cin, lastName);
		istreamException();
	}
	while (checkString(lastName) == false);
}

void Contact::getNickName()
{
	while (true)
	{
		std::cout << "Nick Name> ";
		std::getline(std::cin, nickName);
		istreamException();
		if (nickName.empty())
		{
			std::cout << "empty error" << std::endl;
			continue;
		}
		else if (std::isspace(static_cast<unsigned char>(nickName[0])) || std::isspace(static_cast<unsigned char>(nickName[nickName.length() - 1])))
		{
			std::cout << "white space error" << std::endl;
			continue;
		}
		else
			break;
	}
}

void Contact::getPhoneNumber()
{
	do
	{
		std::cout << "Phone Number> ";
		std::getline(std::cin, phoneNumber);
		istreamException();
	}
	while (checkPhoneNumber(phoneNumber) == false);
}

void Contact::getDarkestSecret()
{
	do
	{
		std::cout << "Darkest Secret> ";
		std::getline(std::cin, darkestSecret);
		istreamException();
	}
	while (darkestSecret.empty());
}

bool Contact::checkString(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "empty error" << std::endl;
		return false;
	}
	for (std::string::size_type i = 0; i < str.length(); i++) 
	{
		if (std::isspace(static_cast<unsigned char>(str[i])))
		{
			std::cout << "white space error" << std::endl;
			return false;
		}
		else if (!std::isalpha(str[i]))
		{
			std::cout << "alphabet error" << std::endl;
			return false;
		}
	}
	return true;
}

bool Contact::checkPhoneNumber(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "empty error" << std::endl;
		return false;
	}
	for (std::string::size_type i = 0; i < str.length(); i++) 
	{
		if (std::isspace(static_cast<unsigned char>(str[i])))
		{
			std::cout << "white space error" << std::endl;
			return false;
		}
		else if (!std::isdigit(str[i]))
		{
			std::cout << "wrong format error" << std::endl;
			return false;
		}
	}
	return true;
}

void Contact::printSearchColumn()
{
	if (firstName.length() > 10)
		std::cout << std::setw(9) << std::right << firstName.substr(0, 9) << '.' << '|';
	else
		std::cout << std::setw(10) << std::right << firstName << '|';

	if (lastName.length() > 10)
		std::cout << std::setw(9) << std::right << lastName.substr(0, 9) << '.' << '|';
	else
		std::cout << std::setw(10) << std::right << lastName << '|';

	if (nickName.length() > 10)
		std::cout << std::setw(9) << std::right << nickName.substr(0, 9) << '.' << '|' << std::endl;
	else
		std::cout << std::setw(10) << std::right << nickName << '|' << std::endl;
}

void Contact::showAllInformation()
{
	if (firstName.empty())
		std::cout << "unregistered contact" << std::endl;
	else
	{
		std::cout << "First Name: " << firstName << std::endl;
		std::cout << "Last Name: " << lastName << std::endl;
		std::cout << "Nick Name: " << nickName << std::endl;
		std::cout << "Phone Number: " << phoneNumber << std::endl;
		std::cout << "Darkest Secret: " << darkestSecret << std::endl;
	}
}

void Contact::istreamException()
{
	if (std::cin.fail() ||std::cin.eof())
	{
		std::cout << "input stream exit" << std::endl;
		std::exit(0);
	}
}