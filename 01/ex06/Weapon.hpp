/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:45:47 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/29 13:26:29 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
public:
	Weapon(std::string type);
	// ~Weapon();
	const std::string	&getType(void);
	const void			setType(std::string type);

private:
	std::string type;

};

#endif