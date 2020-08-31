/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:40:22 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/30 13:34:58 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap ftrap("Fraggie");

	std::cout << "Let's try a rangedAttack" << std::endl;
	ftrap.rangedAttack("enemy");
	std::cout << "Now, a melee attack" << std::endl;
	ftrap.rangedAttack("enemy");
	std::cout << "Now, let's try to get some damage" << std::endl;
	ftrap.takeDamage(0);
	ftrap.takeDamage(1);
	ftrap.takeDamage(50);
	std::cout << "This attack should kill Fraggie" << std::endl;
	ftrap.takeDamage(100);
	std::cout << "Let's do some repairs" << std::endl;
	ftrap.beRepaired(0);
	ftrap.beRepaired(1);
	ftrap.beRepaired(10);
	ftrap.beRepaired(200);
	std::cout << "And now, the funny attacks!" << std::endl;
	ftrap.vaulthunter_dot_exe("enemy");
	ftrap.vaulthunter_dot_exe("enemy");
	ftrap.vaulthunter_dot_exe("enemy");
	ftrap.vaulthunter_dot_exe("enemy");
	ftrap.vaulthunter_dot_exe("enemy");
	return 0;
}