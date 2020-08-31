/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:15:09 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/31 14:55:11 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string future_name) :
	FragTrap(future_name), NinjaTrap(future_name)
{
	this->typeShort = "NN7A-TP";
	this->hitPoints = FragTrap::hitPoints;
	this->maxHitPoints = FragTrap::maxHitPoints;
	this->energyPoints = NinjaTrap::energyPoints;
	this->maxEnergyPoints = NinjaTrap::maxEnergyPoints;
	this->level = 1;
	this->name = future_name;
	this->meleeAttackDamage = NinjaTrap::meleeAttackDamage;
	this->armorDamageReduction = NinjaTrap::armorDamageReduction;

	std::cout << "SuperTrap constructor called" << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap destructor called" << std::endl;
}

void	SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::rangedAttack(target);
}