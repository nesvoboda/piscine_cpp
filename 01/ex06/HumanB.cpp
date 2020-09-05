/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:45:47 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/05 08:31:24 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string Name) :
	weapon(NULL)
{
	this->name.assign(Name);
}

// Note that even though now the weapon is stored as a pointer,
// the parameter to setWeapon is still a reference. This is because
// in the main we are given the variable without '&'.

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon->getType()
	<< std::endl;
}