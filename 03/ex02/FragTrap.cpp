/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:40:22 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/31 14:50:23 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string future_name)
{
	this->typeShort = "FR4G-TP";
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->name = future_name;
	this->meleeAttackDamage = 20;
	this->armorDamageReduction = 5;

	srand( (unsigned)time(NULL) );
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
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