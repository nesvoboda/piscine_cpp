/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:44:07 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/06 10:51:54 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

void check(int condition)
{
	if (condition)
		std::cout << "\033[92m✓ PASS\033[0m" << std::endl;
	else
		std::cout << "\033[91m✗ FAIL\033[0m" << std::endl;
}

int main()
{

	// Test from the subject
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	std::cout << "And now some additional tests\n";
	std::cout << "Let's create a new squad";

	ISquad *sqd = new Squad;

	std::cout << "Squad's count (should be 0): " << sqd->getCount() << std::endl;
	check(sqd->getCount() == 0);
	std::cout << "Squad's first element (should be nullptr): " << sqd->getUnit(0) << std::endl;
	check(sqd->getUnit(0) == nullptr);
	std::cout << "Squad's -1th element (should be nullptr): " << sqd->getUnit(-1) << std::endl;
	check(sqd->getUnit(-1) == nullptr);
	std::cout << "Squad's 100th element (should be nullptr): " << sqd->getUnit(100) << std::endl;
	check(sqd->getUnit(100) == nullptr);

	std::cout << "Let's create a new TacticalMarine" << std::endl;
	ISpaceMarine *dwight = new TacticalMarine;

	std::cout << "Let's push this marine to the squad" << std::endl;
	sqd->push(dwight);

	std::cout << "Squad's count (should be 1): " << sqd->getCount() << std::endl;
	check(sqd->getCount() == 1);
	
	std::cout << "Squad's first element should be Dwight. His battleCry should be: For the holy PLOT!" 
	<< std::endl;
	sqd->getUnit(0)->battleCry();
	std::cout << "Squad's second element (should be nullptr): " << sqd->getUnit(1) << std::endl;
	check(sqd->getUnit(1) == nullptr);

	std::cout << "Let's create a new AssaultTerminator" << std::endl;
	ISpaceMarine *jimothy = new AssaultTerminator;

	std::cout << "Let's push this AT to the squad" << std::endl;
	sqd->push(jimothy);

	std::cout << "Squad's count (should be 2): " << sqd->getCount() << std::endl;
	check(sqd->getCount() == 2);

	std::cout << "Squad's first second should be Jimothy. His battleCry should be: This code is unclean. PURIFY IT!" 
	<< std::endl;
	sqd->getUnit(1)->battleCry();
	
	std::cout << "Let's test the squad copy constructor" << std::endl;
	ISpaceMarine *dwight2 = new TacticalMarine;
	ISpaceMarine *jimothy2 = new AssaultTerminator;
	Squad sqd2;
	sqd2.push(dwight2);
	sqd2.push(jimothy2);

	Squad sqd3 = sqd2;
	std::cout << "Squad's count (should be 2): " << sqd3.getCount() << std::endl;
	check(sqd3.getCount() == 2);
	std::cout << "Squad's first second should be Jimothy. His battleCry should be: This code is unclean. PURIFY IT!" 
	<< std::endl;
	sqd3.getUnit(1)->battleCry();

	std::cout << "sqd3 is a copy of sqd2, but soldiers addresses are different\n";
	check(sqd2.getUnit(0) != sqd3.getUnit(0));

	std::cout << "Let's test the squad assignment operator" << std::endl;
	Squad sqd4;
	ISpaceMarine *dwight3 = new TacticalMarine;
	sqd4.push(dwight3);
	sqd4 = sqd3;
	std::cout << "sqd4 is a copy of sqd3, but soldiers addresses are different\n";
	check(sqd4.getUnit(0) != sqd3.getUnit(0));

	std::cout << "Let's test AT and TM copy and assignment" << std::endl;
	TacticalMarine michael;
	TacticalMarine michael2 = michael;
	michael2.rangedAttack();

	AssaultTerminator jan;
	AssaultTerminator jan2 = jan;
	jan2.rangedAttack();
	michael = michael2;
	jan = jan2;
	jan.rangedAttack();
	michael.rangedAttack();

	return 0;
}