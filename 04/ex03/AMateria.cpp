/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/23 13:23:32 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const AMateria &copy) :
	type(copy.type), _xp(copy._xp)
{
}

AMateria &AMateria::operator= (const AMateria &operand)
{
	this->_xp = operand._xp;
	return (*this);
}

//Returns the materia type
std::string const & AMateria::getType() const
{
	return this->type;
}

AMateria::AMateria(std::string const & new_type) :
	type(new_type), _xp(0)
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

AMateria::~AMateria()
{
}