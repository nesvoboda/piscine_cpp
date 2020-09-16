/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:48:33 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/16 19:29:59 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &new_name) :
	ap(40), current_weapon(NULL), name(new_name)
{
}

Character::Character(const Character &copy) : 
	ap(copy.ap), current_weapon(copy.current_weapon), name(copy.name)
{
}

Character& Character::operator= (const Character &operand)
{
	this->ap = operand.ap;
	this->current_weapon = operand.current_weapon;
	this->name = operand.name;
	return (*this);
}

Character::~Character()
{
	//
}

void Character::recoverAP(void)
{
	if (this->ap <= 30)
		this->ap += 10;
	else if (this->ap < 40)
		this->ap = 40;
}

void Character::equip(AWeapon *new_weapon)
{
	this->current_weapon = new_weapon;
}

void Character::attack(Enemy* target)
{
	if (this->current_weapon == nullptr)
	{
		std::cout << "Get yourself a weapon first" << std::endl;
		return;
	}
	if (this->ap < this->current_weapon->getAPCost())
	{
		std::cout << "AP too low :(" << std::endl;
		return;
	}
	
	std::cout << this->name << " attacks " << target->getType() 
	<< " with a " << this->current_weapon->getName() << std::endl;

	this->current_weapon->attack();

	this->ap -= this->current_weapon->getAPCost();
	target->takeDamage(this->current_weapon->getDamage());
	
	if (target->getHP() == 0)
		delete target;
}

std::string const &Character::getName() const
{
	return this->name;
}

int	Character::getAP() const
{
	return this->ap;
}

int Character::hasWeapon() const
{
	if (this->current_weapon)
		return 1;
	else
		return 0;
}

std::string Character::getWeaponName() const
{
	if (this->current_weapon)
		return this->current_weapon->getName();
	else
		return "";
}

std::ostream &operator<< (std::ostream &os, Character &operand)
{
	os << operand.getName() << " has " << operand.getAP()
	<< " AP";
	if (operand.hasWeapon())
		os << " and wields a " << operand.getWeaponName();
	else
		os << " and is unarmed";
	os << std::endl;
	return os;
}
