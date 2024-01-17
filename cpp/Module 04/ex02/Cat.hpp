#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(const Cat &ref);
		Cat &operator=(const Cat &ref);
		~Cat();

		void makeSound() const;
		std::string getType() const;
};

#endif