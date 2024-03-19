#include "String.hpp"

bool argumentError(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error: number of argument" << std::endl;
		return true;
	}
	else if (!argv[1][0])
	{
		std::cout << "Error: No such file" << std::endl;
		return true;
	}
	else if (!argv[2][0])
	{
		std::cout << "Error: irreplaceable string" << std::endl;
		return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	if (argumentError(argc, argv))
		return 1;
	
	t_String sed;

	sed.fileName = argv[1];
	sed.s1 = argv[2];
	sed.s2 = argv[3];

	replaceFile(sed);
	return 0;
}