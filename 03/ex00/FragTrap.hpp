/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:40:22 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/30 13:45:07 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
// # include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


class FragTrap
{
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	FragTrap &operator= (const FragTrap &operand);
	~FragTrap();

	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);

private:
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