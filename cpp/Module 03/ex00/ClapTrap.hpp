#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        unsigned int _health, _energy, _attack;
		ClapTrap();

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &ref);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap &ref);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif