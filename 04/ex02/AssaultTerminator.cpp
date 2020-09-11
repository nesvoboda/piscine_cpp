/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:44:07 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/05 12:34:27 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &copy)
{
	(void) copy;
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

AssaultTerminator & AssaultTerminator::operator= (const AssaultTerminator &operand)
{
	(void) operand;
	return (*this);
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back..." << std::endl;
}


ISpaceMarine* AssaultTerminator::clone() const
{
	ISpaceMarine *new_marine = new AssaultTerminator(*(this));
	return new_marine;
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}
