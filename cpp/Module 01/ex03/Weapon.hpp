#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iomanip>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	
	public:
		Weapon();
		Weapon(std::string type);
		
		const std::string &getType();
		void setType(std::string param);
};

#endif