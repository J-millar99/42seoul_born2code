#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor: Brain in ";
	std::cout << this << std::endl;
}

Brain::Brain(const Brain &ref)
{
	copyStringArray(ref.ideas, ideas, 100);
	std::cout << "Constructor: Brain in ";
	std::cout << this << std::endl;
}

Brain &Brain::operator=(const Brain &ref)
{
	if (this == &ref)
		return *this;
	copyStringArray(ref.ideas, ideas, 100);
	std::cout << "Constructor: Brain in ";
	std::cout << this << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor: Brain in ";
	std::cout << this << std::endl;
}

std::string *Brain::getIdeas()
{
	return ideas;
}

void Brain::copyStringArray(const std::string *source, std::string *destination, int size)
{
    for (int i = 0; i < size; ++i)
        destination[i] = source[i];
}