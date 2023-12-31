#include "PhoneBook.hpp"

bool PhoneBook::inRange(const std::string &str)
{
	if (str == "1" || str == "2" || str == "3" || str == "4" || str == "5" || str == "6" || str == "7" || str == "8")
		return true;
	std::cout << "out of range error or wrong command" << std::endl;
	return false;
}

void PhoneBook::add()
{
	contacts[idx].getFirstName();
	contacts[idx].getLastName();
	contacts[idx].getNickName();
	contacts[idx].getPhoneNumber();
	contacts[idx].getDarkestSecret();
	++idx;
	if (idx == 8)
		idx = 0;
}

void PhoneBook::search()
{
	std::string choice;

	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << std::right << i + 1 << '|';
		contacts[i].printSearchColumn();
	}
	do
	{
		std::cout << "index: ";
		std::getline(std::cin, choice);
		istreamException();
		if (inRange(choice))
			break ;
	}
	while (true);
	contacts[std::stoi(choice) - 1].showAllInformation();
}

void PhoneBook::exit()
{
	std::cout << "Program Exit" << std::endl;
	std::exit(0);
}

void PhoneBook::showMenu()
{
	std::cout << "----Menu----" << std::endl;
	std::cout << "*   ADD   *" << std::endl;
	std::cout << "*  SEARCH  *" << std::endl;
	std::cout << "*   EXIT   *" << std::endl;
}