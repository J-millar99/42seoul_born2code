#ifndef WORNGCAT_HPP
#define WORNGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &ref);
		WrongCat &operator=(const WrongCat &ref);
		~WrongCat();

		void makeSound() const;
		std::string getType() const;
};

#endif