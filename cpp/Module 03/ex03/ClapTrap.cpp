#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{ }

ClapTrap::ClapTrap(std::string name) : _health(10), _energy(10), _attack(0)
{
    this->name = name;
    std::cout << name + " is running" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int _atk, int _eng, int _hel) // ScavTrap
{
    this->name = name;
    _attack = _atk;
    _energy = _eng;
    _health = _hel;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
    *this = ref;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: " + name + " is destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref)
{
    _attack = ref._attack;
    _energy = ref._energy;
    _health = ref._health;
    name = ref.name;
    std::cout << name
              << " is running" << std::endl;
    return *this;
}


void ClapTrap::attack(const std::string &target)
{
    if (!_energy || !_health)
    {
        std::cout << "ClapTrap: " + name + " can't operate" << std::endl << std::endl;
        return ;
    }
    _energy--;
    std::cout << "ClapTrap: " + name
              << " attacks " + target
              << ", causing " << _attack
              << " points of damage!" << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!_health)
    {
        std::cout << name
                  << " is already destoryed" << std::endl << std::endl;
        return ;
    }
    if (_health < amount)
        _health = 0;
    else
        _health -= amount;
   std::cout << name
              << " is damaged: "
              << amount << std::endl
              << "Hit points: "
              << _health << std::endl << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!_energy || !_health)
    {
        std::cout << name
                  << " can't operate" << std::endl << std::endl;
        return ;
    }
    _energy--;
    _health += amount;
    std::cout << name
              << " is repaired: "
              << amount << std::endl
              << "Hit points: "
              << _health << std::endl << std::endl;
}

const std::string &ClapTrap::getName() const
{
    return name;
}

const unsigned int &ClapTrap::getAttack() const
{
    return _attack;
}

const unsigned int &ClapTrap::getEnergy() const
{
    return _energy;
}

const unsigned int &ClapTrap::getHealth() const
{
    return _health;
}

void ClapTrap::setName(const std::string &ref)
{
    name = ref;
}

void ClapTrap::setAttack(const int &ref)
{
    _attack = ref;
}

void ClapTrap::setEnergy(const int &ref)
{
    _energy = ref;
}

void ClapTrap::setHealth(const int &ref)
{
    _health = ref;
}
