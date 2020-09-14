/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:05:13 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/14 11:10:25 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string new_name, std::string new_title) :
	name(new_name), title(new_title)
{
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &copy)
{
	this->title = copy.title;
	this->name = copy.name;
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer &Sorcerer::operator= (const Sorcerer &operand)
{
	name = operand.name;
	title = operand.title;
	return (*this);
}
	
Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title
	<< ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName(void) const
{
	return this->name;
}

std::string Sorcerer::getTitle(void) const
{
	return this->title;
}

std::ostream& operator<<(std::ostream& os, const Sorcerer& sorc)
{
	os << "I am " << sorc.getName() << ", " << sorc.getTitle()
		<< ", and I like ponies!" << std::endl;
	return os;
}

void Sorcerer::polymorph(Victim const &vic) const
{
	vic.getPolymorphed();
}