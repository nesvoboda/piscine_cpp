/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:51:54 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/06 14:55:15 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string future_name)
{
	this->typeShort = "NN7A-TP";
	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->level = 1;
	this->name = future_name;
	this->meleeAttackDamage = 60;
	this->armorDamageReduction = 0;

	std::cout << "NinjaTrap constructor called" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap destructor called" << std::endl;
}


void	NinjaTrap::ninjaShoebox(FragTrap &target)
{
	if (this->energyPoints < 25)
	{
		std::cout << "Yo, you need some charge! No more funny attacks today."
			<< std::endl;
		return;
	}
	this->energyPoints -= 25;


	std::cout << this->typeShort << " " << this->name << " attacks FragTrap " << target.getName() 
	<< " with a special ninja shoebox attack, causing " << 25
	 << " points of damage!"
	<< std::endl;
	target.takeDamage(25);
}

void	NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	if (this->energyPoints < 25)
	{
		std::cout << "Yo, you need some charge! No more funny attacks today."
			<< std::endl;
		return;
	}
	this->energyPoints -= 25;


	std::cout << this->typeShort << " " << this->name << " attacks ScavTrap " << target.getName() 
	<< " with a special ninja shoebox attack, causing " << 25
	 << " points of damage!"
	<< std::endl;
	target.takeDamage(25);
}


void	NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
		if (this->energyPoints < 25)
	{
		std::cout << "Yo, you need some charge! No more funny attacks today."
			<< std::endl;
		return;
	}
	this->energyPoints -= 25;


	std::cout << this->typeShort << " " << this->name << " attacks NinjaTrap " << target.getName() 
	<< " with a special ninja shoebox attack, causing " << 25
	 << " points of damage!"
	<< std::endl;
	target.takeDamage(25);
}

