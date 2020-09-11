/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:39:09 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/06 14:49:49 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string future_name) :
	hitPoints(100),
	maxHitPoints(100),
	energyPoints(50),
	maxEnergyPoints(50),
	level(1),
	name(future_name),
	meleeAttackDamage(20),
	rangedAttackDamage(15),
	armorDamageReduction(3)
{
	srand( (unsigned)time(NULL) );
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "SC4V-TP " << this->name << " performs an attack " << target 
	<< " at range, causing " << this->rangedAttackDamage << " points of damage!"
	<< std::endl;
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "SC4V-TP " << this->name << " strikes a melee blow to " << target 
	<< " causing" << this->meleeAttackDamage << " points of damage!"
	<< std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
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
	std::cout << "SC4V-TP " << this->name << " recieves " << 
		realDamage << " points of damage and now has only " << this->hitPoints
		<< " hp left!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	unsigned int realAmount;

	// HP can't be more than max hp
	if (amount > this->maxHitPoints - this->hitPoints)
		realAmount = this->maxHitPoints - this->hitPoints;
	else
		realAmount = amount;
	this->hitPoints += realAmount;
	std::cout << "SC4V-TP " << this->name << " gets some repairs done, gaining " << 
		realAmount << " hp, and now has " << this->hitPoints << " hp!"
		<< std::endl;
}

void ScavTrap::challengeNewcomer(std::string const &target)
{
	if (this->energyPoints < 25)
	{
		std::cout << "No charge left, sweetie! Come back later!"
			<< std::endl;
		return;
	}
	this->energyPoints -= 25;

	std::string attacks[] = {
		"a computer reboot",
		"an infected sock",
		"a mug with burned coffee",
		"a wet stinky towel",
		"a broken Mac",
		"a broken Apple mouse with no scrolling wheel"
	};
	int	attackDamage[] = {
		100,
		25,
		35,
		40,
		42,
		40
	};

	int attackNo = rand() % 6;  // generates number in the range 1..6 

	std::cout << "SC4V-TP " << this->name << " attacks " << target 
	<< " with " << attacks[attackNo] <<", causing " << attackDamage[attackNo]
	 << " points of damage!"
	<< std::endl;
}