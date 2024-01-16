#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <climits>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		enum TrapInfo
		{
			CT_HEALTH = 10,
			CT_ENERGY = 10,
			CT_ATTACK = 0,

			ST_HEALTH = 100,
			ST_ENERGY = 50,
			ST_ATTACK = 20,

			FT_HEALTH = 100,
			FT_ENERGY = 100,
			FT_ATTACK = 30
		};
		std::string name; //상속한 ClapTrap의 name과 동일해야한다.
		DiamondTrap();
	
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &ref);
		DiamondTrap &operator=(const DiamondTrap &ref);
		~DiamondTrap();
		void attack(const std::string &target);
		void whoAmI();

};

#endif