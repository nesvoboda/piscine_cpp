/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:44:07 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/16 19:18:33 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

// Sleep
#include <unistd.h>

// Needed to automatically fail tests;
#include <assert.h>

int test_no = 1;

void out(std::string s)
{
	std::cout << std::endl;
	std::cout << "\033[0;34m" << "Test " << test_no << " | " << s << "\033[0m" << std::endl;
	test_no += 1;
}

void eo(std::string s)
{
	std::cout << "\33[1;33m" << "Expected output:" <<"\033[0m" << std::endl;
	std::cout << s << std::endl;
}

void check(int expression)
{
	// If expression doesn't evaluate to 1, the program will abort
	assert(expression == 1);
	std::cout << "\033[92m✓ PASS\033[0m" << std::endl;
}

int main()
{
	{
		// Test from the subject
		std::cout << "\nSubject tests\n\n";
		{
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
		}

		std::cout << "\nAnd now some additional tests\n";

		out("Squad | Constructor");
		Squad s1 = Squad();

		out("Squad | Copy constructor");
		Squad s2 = Squad(s1);

		out("Squad | Equality operator");
		Squad s3;
		
		s3 = s2;

		out("Squad | Destructor");
		{
			Squad s4;
		}

		out("Squad | getCount with empty squad");
		check(s1.getCount() == 0);

		out("Squad | getUnit with empty squad");
		check(s1.getUnit(0) == nullptr);
		check(s1.getUnit(-1) == nullptr);
		check(s1.getUnit(10) == nullptr);

		out("Tactical Marine | Constructor");

		eo("Tactical Marine ready for battle!");
		TacticalMarine *t1 = new TacticalMarine();

		out("Tactical Marine | Copy constructor");
		eo("Tactical Marine ready for battle!");
		TacticalMarine *t2 = new TacticalMarine(*t1);

		out("Tactical Marine | Assignment operator");
		eo("Tactical Marine ready for battle!");
		TacticalMarine *t3 = new TacticalMarine();

		*(t3) = *(t2);

		out("Tactical Marine | Destructor");
		{
			eo("Tactical Marine ready for battle!");
			TacticalMarine *t4 = new TacticalMarine();
			eo("Aaargh..");
			delete t4;
		}

		out("Tactical Marine | battleCry");
		eo("For the holy PLOT!");
		t3->battleCry();

		out("Tactical Marine | rangedAttack");
		eo("* attacks with a bolter *");
		t3->rangedAttack();

		out("Tactical Marine | meleeAttack");
		eo("* attacks with a chainsword *");
		t3->meleeAttack();

		out("Tactical Marine | Clone");
		eo("Tactical Marine ready for battle!");
		ISpaceMarine *t5 = t3->clone();
		(void) t5;

		out("AssaultTerminator | Constructor");

		eo("* teleports from space *");
		AssaultTerminator *a1 = new AssaultTerminator();

		out("AssaultTerminator | Copy constructor");
		eo("* teleports from space *");
		AssaultTerminator *a2 = new AssaultTerminator(*a1);

		out("AssaultTerminator | Assignment operator");
		eo("* teleports from space *");
		AssaultTerminator *a3 = new AssaultTerminator();

		*(a3) = *(a2);

		out("AssaultTerminator | Destructor");
		{
			eo("* teleports from space *");
			AssaultTerminator *a4 = new AssaultTerminator();
			eo("I’ll be back...");
			delete a4;
		}

		out("AssaultTerminator | battleCry");
		eo("This code is unclean. PURIFY IT!");
		a3->battleCry();

		out("AssaultTerminator | rangedAttack");
		eo("* does nothing *");
		a3->rangedAttack();

		out("AssaultTerminator | meleeAttack");
		eo("* attacks with chainfists *");
		a3->meleeAttack();

		out("AssaultTerminator | Clone");
		eo("* teleports from space *");
		ISpaceMarine *a5 = a3->clone();
		(void) a5;

		out("Squad | Push TacticalMarine");
		s1.push(t1);

		out("Squad | getCount with 1 unit");
		check(s1.getCount() == 1);

		out("Squad | getUnit with 1 unit");
		check(s1.getUnit(0) == t1);
		check(s1.getUnit(1) == nullptr);
		check(s1.getUnit(-1) == nullptr);
		check(s1.getUnit(10) == nullptr);

		out("Squad | Push AssaultTerminator");
		s1.push(a1);

		out("Squad | getCount with 2 units");
		check(s1.getCount() == 2);

		out("Squad | getUnit with 2 units");
		check(s1.getUnit(0) == t1);
		check(s1.getUnit(1) == a1);
		check(s1.getUnit(2) == nullptr);
		check(s1.getUnit(-1) == nullptr);
		check(s1.getUnit(10) == nullptr);

		out("Squad | Copy constructor with units");
		Squad *s4 =  new Squad(s1);
		check(s4->getCount() == 2);
		check(s4->getUnit(0) != nullptr);
		check(s4->getUnit(1) != nullptr);

		// Check it's a deep copy, and not a shallow one
		check(s4->getUnit(0) != t1);
		check(s4->getUnit(1) != a1);

		check(s4->getUnit(-1) == nullptr);
		check(s4->getUnit(2) == nullptr);
		check(s4->getUnit(10) == nullptr);

		out("Squad | Destructor with units");
		delete s4;
		
		out("Squad | Assignment operator with units");
		Squad s5 = Squad();

		s5 = s1;
		check(s5.getCount() == 2);
		check(s5.getUnit(0) != nullptr);
		check(s5.getUnit(1) != nullptr);

		// Check it's a deep copy, and not a shallow one
		check(s5.getUnit(0) != t1);
		check(s5.getUnit(1) != a1);

		check(s5.getUnit(-1) == nullptr);
		check(s5.getUnit(2) == nullptr);
		check(s5.getUnit(10) == nullptr);

		out("Squad | Assignment operator with units on the left");
		Squad s6;
		
		s5 = s6;

		delete t2;
		delete t3;
		delete t5;

		delete a2;
		delete a3;
		delete a5;
		
	}

	// Uncomment the 2 following lines if you're using leaks on Mac OS instead of Valgrind
	// std::cout << "You now have 30 seconds to check for leaks" << std::endl;
	// sleep(30);
	return 0;
}