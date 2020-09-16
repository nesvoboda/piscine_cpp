/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:49:27 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/16 19:25:09 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &new_name, int new_apcost, int new_damage) :
	name(new_name), apcost(new_apcost), damage(new_damage)
{
}

AWeapon::~AWeapon()
{
}

AWeapon::AWeapon(const AWeapon &copy) :
	name(copy.name), apcost(copy.apcost), damage(copy.damage)
{
}

AWeapon & AWeapon::operator= (const AWeapon &operand)
{
	this->name = operand.name;
	this->apcost = operand.apcost;
	this->damage = operand.damage;
	return (*this);
}

int AWeapon::getAPCost() const
{
	return this->apcost;
}

int AWeapon::getDamage() const
{
	return this->damage;
}

std::string const &AWeapon::getName() const
{
	return this->name;
}