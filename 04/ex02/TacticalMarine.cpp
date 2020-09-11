/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:44:07 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/05 12:34:47 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &copy)
{
	(void) copy;
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine & TacticalMarine::operator= (const TacticalMarine &operand)
{
	(void) operand;
	return (*this);
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}


ISpaceMarine* TacticalMarine::clone() const
{
	ISpaceMarine *new_marine = new TacticalMarine(*(this));
	return new_marine;
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}
