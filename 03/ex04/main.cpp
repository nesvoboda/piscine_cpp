/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:40:22 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/31 15:02:31 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
	std::cout << "Let's test a FragTrap" << std::endl;

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

	std::cout << "Now, let's test a ScavTrap" << std::endl;

	ScavTrap strap = ScavTrap("Scavvie");

	std::cout << "Let's try a rangedAttack" << std::endl;
	strap.rangedAttack("enemy");
	std::cout << "Now, a melee attack" << std::endl;
	strap.rangedAttack("enemy");
	std::cout << "Now, let's try to get some damage" << std::endl;
	strap.takeDamage(0);
	strap.takeDamage(1);
	strap.takeDamage(50);
	std::cout << "This attack should kill Scavvie" << std::endl;
	strap.takeDamage(100);
	std::cout << "Let's do some repairs" << std::endl;
	strap.beRepaired(0);
	strap.beRepaired(1);
	strap.beRepaired(10);
	strap.beRepaired(200);
	std::cout << "And now, the funny attacks!" << std::endl;
	strap.challengeNewcomer("enemy");
	strap.challengeNewcomer("enemy");
	strap.challengeNewcomer("enemy");
	strap.challengeNewcomer("enemy");
	strap.challengeNewcomer("enemy");

	std::cout << "Now, let's test a NinjaTrap" << std::endl;

	NinjaTrap ntrap = NinjaTrap("Ninjie");

	std::cout << "Let's try a rangedAttack" << std::endl;
	ntrap.rangedAttack("enemy");
	std::cout << "Now, a melee attack" << std::endl;
	ntrap.rangedAttack("enemy");
	std::cout << "Now, let's try to get some damage" << std::endl;
	ntrap.takeDamage(0);
	ntrap.takeDamage(1);
	ntrap.takeDamage(50);
	std::cout << "This attack should kill Ninjie" << std::endl;
	ntrap.takeDamage(100);
	std::cout << "Let's do some repairs" << std::endl;
	ntrap.beRepaired(0);
	ntrap.beRepaired(1);
	ntrap.beRepaired(10);
	ntrap.beRepaired(200);
	std::cout << "And now, the funny attacks!" << std::endl;
	ntrap.ninjaShoebox(ftrap);
	ntrap.ninjaShoebox(strap);

	NinjaTrap enemy("Rogue NinjaTrap");
	ntrap.ninjaShoebox(enemy);

	std::cout << "Now, let's test a SuperTrap" << std::endl;

	SuperTrap sutrap = SuperTrap("Supa");

	std::cout << "Let's try a rangedAttack" << std::endl;
	sutrap.rangedAttack("enemy");
	std::cout << "Now, a melee attack" << std::endl;
	sutrap.rangedAttack("enemy");
	std::cout << "Now, let's try to get some damage" << std::endl;
	sutrap.takeDamage(0);
	sutrap.takeDamage(1);
	sutrap.takeDamage(50);
	std::cout << "This attack should kill Ninjie" << std::endl;
	sutrap.takeDamage(100);
	std::cout << "Let's do some repairs" << std::endl;
	sutrap.beRepaired(0);
	sutrap.beRepaired(1);
	sutrap.beRepaired(10);
	sutrap.beRepaired(200);
	std::cout << "And now, the funny attacks!" << std::endl;
	sutrap.vaulthunter_dot_exe("enemy");
	sutrap.ninjaShoebox(ftrap);
	sutrap.ninjaShoebox(strap);
	sutrap.ninjaShoebox(enemy);
	return 0;
}