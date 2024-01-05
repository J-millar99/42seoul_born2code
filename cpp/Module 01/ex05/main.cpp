#include "Harl.hpp"

int main()
{
	Harl harl1;
	Harl harl2;
	Harl harl3;
	Harl harl4;

	harl1.complain("debug");
	harl2.complain("info");
	harl3.complain("warning");
	harl4.complain("error");
	return 0;
}