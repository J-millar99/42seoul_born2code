#ifndef STRING_HPP
#define STRING_HPP

#include <iomanip>
#include <iostream>
#include <fstream>

void replaceFileName(std::string filename);

typedef struct s_String
{
	std::string filename;
	std::string s1;
	std::string s2;
} t_String;

#endif