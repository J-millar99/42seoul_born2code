#include "Harl.hpp"

typedef void (Harl::*memberFunctionPTR)(void);

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl << std::endl;
}

int Harl::insignificantProblems(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return 1;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    memberFunctionPTR exePTR[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int n = 0;

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            n = i + 1;
            break ;
        }
    }
	switch (n)
	{
	case 1:
		(this->*exePTR[0])();
		// fall through
	case 2:
		(this->*exePTR[1])();
		// fall through
	case 3:
		(this->*exePTR[2])();
		// fall through
	case 4:
		(this->*exePTR[3])();
		break;
	default:
		insignificantProblems();
	}
}
