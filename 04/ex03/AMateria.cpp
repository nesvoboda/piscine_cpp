/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/06 12:49:00 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() :
	type("NoType")
{
}

AMateria::AMateria(const AMateria &copy) :
	type(copy.type)
{
}

AMateria &AMateria::operator= (const AMateria &operand)
{
	// this->type = operand.type;
	this->_xp = operand._xp;
	return (*this);
}

//Returns the materia type
std::string const & AMateria::getType() const
{
	return this->type;
}

AMateria::AMateria(std::string const & new_type) :
	type(new_type)
{
}

//Returns the Materia's XP
unsigned int AMateria::getXP() const
{
	return this->_xp;
}

void AMateria::use(ICharacter& target)
{
	this->_xp += 10;
	(void) target;
}

void AMateria::incrementXp(void)
{
	this->_xp += 10;
}

AMateria::~AMateria()
{
}