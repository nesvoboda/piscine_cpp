/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:40:22 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/30 13:47:12 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string future_name) :
	hitPoints(100),
	maxHitPoints(100),
	energyPoints(100),
	maxEnergyPoints(100),
	level(1),
	name(future_name),
	meleeAttackDamage(30),
	rangedAttackDamage(20),
	armorDamageReduction(5)
{
	srand( (unsigned)time(NULL) );
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target 
	<< " at range, causing " << this->rangedAttackDamage << " points of damage!"
	<< std::endl;
}

void	FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target 
	<< " melee, causing" << this->meleeAttackDamage << " points of damage!"
	<< std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
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
	std::cout << "FR4G-TP " << this->name << " takes " << 
		realDamage << " points of damage and now has " << this->hitPoints
		<< " hp!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	unsigned int realAmount;

	// HP can't be more than max hp
	if (amount > this->maxHitPoints - this->hitPoints)
		realAmount = this->maxHitPoints - this->hitPoints;
	else
		realAmount = amount;
	this->hitPoints += realAmount;
	std::cout << "FR4G-TP " << this->name << " gets repaired by " << 
		realAmount << " hp, and now has " << this->hitPoints << " hp!"
		<< std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->energyPoints < 25)
	{
		std::cout << "Yo, you need some charge! No more funny attacks today."
			<< std::endl;
		return;
	}
	this->energyPoints -= 25;

	std::string attacks[] = {
		"some 4h of TIG",
		"a forgotten printf",
		"a bug in a Makefile",
		"a corrector that is one hour late",
		"a missing semicolon",
		"an overly enthusiastic corrector"
	};
	int	attackDamage[] = {
		70,
		25,
		35,
		40,
		42,
		40
	};
	
	


	int attackNo = rand() % 6;  // generates number in the range 1..6 

	std::cout << "FR4G-TP " << this->name << " attacks " << target 
	<< " with " << attacks[attackNo] <<", causing " << attackDamage[attackNo]
	 << " points of damage!"
	<< std::endl;
}