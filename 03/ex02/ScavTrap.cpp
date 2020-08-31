/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:39:09 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/31 13:08:53 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string future_name)
{
	this->typeShort = "SC4V-TP";
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->name = future_name;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
	srand( (unsigned)time(NULL) );
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
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

	std::cout << "FR4G-TP " << this->name << " attacks " << target 
	<< " with " << attacks[attackNo] <<", causing " << attackDamage[attackNo]
	 << " points of damage!"
	<< std::endl;
}