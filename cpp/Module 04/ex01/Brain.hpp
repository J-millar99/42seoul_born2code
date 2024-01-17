#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &ref);
		Brain &operator=(const Brain &ref);
		~Brain();

		std::string* getIdeas();
		void copyStringArray(const std::string *src, std::string *dest,int size);
};

#endif