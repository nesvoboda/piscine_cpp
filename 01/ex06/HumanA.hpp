#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

/*
** Here, weapon is stored as a reference, because references are nice
** abstractions, and the task at hand totally permits the use of a reference.
** This is, however, not the case for HumanB.
*/

class HumanA
{
public:
	HumanA(std::string Name, Weapon &weapon);
	void	attack(void);

private:
	Weapon &weapon;
	std::string name;
};

#endif