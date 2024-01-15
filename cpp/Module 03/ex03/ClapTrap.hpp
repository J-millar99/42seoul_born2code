#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int _health, _energy, _attack;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(std::string name, int _hel, int _eng, int _atk);
        ClapTrap(const ClapTrap &ref);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap &ref);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        const std::string &getName() const;
        const int &getAttack() const;
        const int &getEnergy() const;
        const int &getHealth() const;
        void setName(const std::string &ref);
        void setAttack(const int &ref);
        void setEnergy(const int &ref);
        void setHealth(const int &ref);
};

#endif