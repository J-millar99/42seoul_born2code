#include "String.hpp"

bool argumentError(int argc)
{
	if (argc != 4)
	{
		std::cout << "number of argument error" << std::endl;
		return true;
	}
	return false;
}
// void f(void)
// {
// 	system("leaks sed");
// }

int main(int argc, char *argv[])
{
	// atexit(f);
	if (argumentError(argc))
		return (1);
	
	t_String sed;

	sed.filename = argv[1];
	sed.s1 = argv[2];
	sed.s2 = argv[3];

	replaceFileName(sed.filename);
	sed.s1 = sed.s2;

	std::cout << "s1: " << sed.s1 << std::endl
			  << "s2: " << sed.s2 << std::endl;
	std::cout << "s1: " << &sed.s1 << std::endl
			  << "s2: " << &sed.s2 << std::endl;
	return 0;
}