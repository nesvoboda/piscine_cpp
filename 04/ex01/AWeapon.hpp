/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:48:33 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/28 17:17:35 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon
{
private:
	std::string name;
	int apcost;
	int damage;
	AWeapon();

public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(const AWeapon &copy);
	AWeapon &operator= (const AWeapon &operand);
	virtual ~AWeapon();
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
	std::string const &getName() const;
};

#endif