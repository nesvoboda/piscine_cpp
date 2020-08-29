/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:34:57 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/29 13:53:31 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

/*
**	According to C++98 (you can consult a draft here: 
** http://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf),
** article 8.3.2:
** 'a reference shall be initialized to refer to a valid object or function'
** and 'a null reference cannot exist in a well-defined program'.
**
** The main for this class asks us to create a constructor without a
** 'weapon' parameter. Therefore, we have to be able to register the absence
** of weapon (a null weapon), which can only be performed by a pointer.
*/

class HumanB
{
public:
	HumanB(std::string Name);
	const void	attack(void);
	const void	setWeapon(Weapon &weapon);

private:
	Weapon *weapon;
	std::string name;
};

#endif