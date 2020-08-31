/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:02:00 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/31 13:07:38 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator= (const ClapTrap &operand);
	~ClapTrap();
	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:
	std::string type;
	std::string typeShort;
	unsigned int hitPoints;
	unsigned int maxHitPoints;
	unsigned int energyPoints;
	unsigned int maxEnergyPoints;
	unsigned int level;
	std::string name;
	unsigned int meleeAttackDamage;
	unsigned int rangedAttackDamage;
	unsigned int armorDamageReduction;
};

#endif