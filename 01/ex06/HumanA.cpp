/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:45:47 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/05 08:31:40 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &future_weapon) :
weapon(future_weapon)
{
	this->name.assign(Name);
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon.getType()
	<< std::endl;
}