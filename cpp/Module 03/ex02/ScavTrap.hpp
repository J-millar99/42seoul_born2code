#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap 
{
   public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &ref);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap &ref);

        void guardGate();
        void attack(const std::string &target);
};

#endif