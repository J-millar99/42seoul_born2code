#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <climits>

class ClapTrap
{
    private:
        std::string name;
        unsigned int _health, _energy, _attack;
	
	protected:
        ClapTrap();

    public:
        ClapTrap(std::string name);
        ClapTrap(std::string name, int _hel, int _eng, int _atk);
        ClapTrap(const ClapTrap &ref);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap &ref);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        const std::string &getName() const;
        const unsigned int &getAttack() const;
        const unsigned int &getEnergy() const;
        const unsigned int &getHealth() const;
        void setName(const std::string &ref);
        void setAttack(const int &ref);
        void setEnergy(const int &ref);
        void setHealth(const int &ref);
};

#endif