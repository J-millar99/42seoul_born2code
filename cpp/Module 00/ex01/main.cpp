#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;

	std::cout << "Welcome! The PhoneBook Program" << std::endl << std::endl;
	do
	{
		do
		{
			phonebook.showMenu();
			std::cout << "> ";
			std::getline(std::cin, command);
			phonebook.istreamException();
		}
		while (phonebook.checkString(command) == false);
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			phonebook.exit();
		else
			continue;
	}
	while (true);
}