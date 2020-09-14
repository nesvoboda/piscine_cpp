/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:05:13 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/14 11:07:14 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string new_name) :
	name(new_name)
{
	std::cout << "Some random victim called " << 
	this->name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &copy)
{
	this->name = copy.name;
	std::cout << "Some random victim called " << 
	this->name << " just appeared!" << std::endl;
}

Victim& Victim::operator= (const Victim &operand)
{
	this->name = operand.name;
	return (*this);
}

Victim::~Victim()
{
	std::cout << "Victim " << 
	this->name << " just died for no apparent reason!" << std::endl;
}

std::string Victim::getName(void) const
{
	return this->name;
}

std::ostream& operator<<(std::ostream& os, const Victim& vic)
{
	os << "I'm " << vic.getName() << " and I like otters!" << std::endl;
	return os;
}

void Victim::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a cute little sheep!"
	<< std::endl;
}
