#ifndef STRING_HPP
#define STRING_HPP

#include <iomanip>
#include <iostream>
#include <fstream>


typedef struct s_String
{
	std::string fileName;
	std::string s1;
	std::string s2;
} t_String;

void replaceFile(t_String sed);

#endif