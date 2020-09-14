/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:48:33 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/14 12:04:22 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "Enemy.hpp"
# include "AWeapon.hpp"

class Character
{
private:
	int ap;
	AWeapon *current_weapon;
	std::string name;
	Character();

public:
	Character(std::string const &name);
	Character(const Character &copy);
	Character &operator= (const Character &operand);
	~Character();
	void recoverAP();
	void equip(AWeapon *);
	void attack(Enemy*);
	std::string const &getName() const;
	int getAP() const;
	std::string getWeaponName() const;
	int	hasWeapon() const;
	
};

std::ostream &operator<< (std::ostream &os, Character &operand);

#endif