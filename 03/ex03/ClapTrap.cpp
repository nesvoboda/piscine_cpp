/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:02:00 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/31 15:13:41 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	srand( (unsigned)time(NULL) );
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << this->typeShort << " " << this->name << " attacks " << target 
	<< " at range, causing " << this->rangedAttackDamage << " points of damage!"
	<< std::endl;
}

void	ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << this->typeShort << " " << this->name << " attacks " << target 
	<< " melee, causing" << this->meleeAttackDamage << " points of damage!"
	<< std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return this->name;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int realDamage;

	// Damage can only be reduced by armor to 0. Damage can't be negative.
	if (amount > this->armorDamageReduction)
		realDamage = amount - this->armorDamageReduction;
	else
		realDamage = 0;

	// HP can't fall below zero
	if (realDamage <= this->hitPoints)
		this->hitPoints -= realDamage;
	else
		this->hitPoints = 0;
	std::cout << this->typeShort << " " << this->name << " takes " << 
		realDamage << " points of damage and now has " << this->hitPoints
		<< " hp!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int realAmount;

	// HP can't be more than max hp
	if (amount > this->maxHitPoints - this->hitPoints)
		realAmount = this->maxHitPoints - this->hitPoints;
	else
		realAmount = amount;
	this->hitPoints += realAmount;
	std::cout << this->typeShort << " " << this->name << " gets repaired by " << 
		realAmount << " hp, and now has " << this->hitPoints << " hp!"
		<< std::endl;
}