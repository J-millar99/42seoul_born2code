#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public virtual ClapTrap 
{
	protected:
        FragTrap();
		
	public:
        FragTrap(std::string name);
        FragTrap(const FragTrap &ref);
        ~FragTrap();
        FragTrap& operator=(const FragTrap &ref);

        void highFivesGuys(void);
        void attack(const std::string &target);
};

#endif