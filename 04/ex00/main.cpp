/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:05:13 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/13 18:13:41 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Peon.hpp"

// Needed to automatically fail tests;
#include <assert.h>

void out(std::string s)
{
	std::cout << std::endl;
	std::cout << s << std::endl;
}

void eo(std::string s)
{
	std::cout << "Expected output:" << std::endl;
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
	// Tests from the subject
	{
		std::cout << "Here are the tests from the subject: " << std::endl;
		Sorcerer robert("Robert", "the Magnificent");
		Victim jim("Jimmy");
		Peon joe("Joe");
		std::cout << robert << jim << joe;
		robert.polymorph(jim);
		robert.polymorph(joe);
	}

	// SORCERER
	out("Test 1: Sorcerer | Constructor");
	eo("Robert, the Magnificent, is born!");
	Sorcerer robert("Robert", "the Magnificent");
	check(robert.getName() == "Robert");
	check(robert.getTitle() == "the Magnificent");

	out("Test 2: Sorcerer | Copy Constructor");
	eo("Robert, the Magnificent, is born!");
	Sorcerer rob(robert);
	check(rob.getName() == "Robert");
	check(rob.getTitle() == "the Magnificent");

	out("Test 3: Sorcerer | Assignment operator");
	eo("Billy, the dork, is born!");
	Sorcerer billy("Billy", "the dork");
	check(billy.getName() == "Billy");
	check(billy.getTitle() == "the dork");
	
	rob = billy;
	check(rob.getName() == "Billy");
	check(rob.getTitle() == "the dork");

	out("Test 4: Sorcerer | << overload");
	eo("I am " + rob.getName() + ", " + rob.getTitle() + ", and I like ponies!");
	std::cout << rob << std::endl;

	out("Test 5: Sorcerer | Destructor");
	{
		eo("John, the wisard, is born!");
		Sorcerer j("John", "the wizard");
		eo("John, the wisard, is dead. Consequences will never be the same!");
	}

	// VICTIM

	out("Test 6: Victim | Constructor");
	eo("Some random victim called Jimmy just appeared!");
	Victim jim("Jimmy");
	check(jim.getName() == "Jimmy");
	
	out("Test 7: Victim | Copy constructor");
	eo("Some random victim called Jimmy just appeared!");
	Victim jimothy(jim);
	check(jimothy.getName() == "Jimmy");

	out("Test 8: Victim | << operator overload");
	eo("I'm Jimmy and I like otters!");
	std::cout << jimothy << std::endl;

	out("Test 9: Victim | Assignment operator");
	eo("Some random victim called Dwight just appeared!");
	Victim dwight("Dwight");
	
	dwight = jim;
	check(dwight.getName() == "Jimmy");

	eo("I'm Jimmy and I like otters!");
	std::cout << dwight << std::endl;
	
	out("Test 10: Victim | Destructor");
	{
		eo("Some random victim called Toby just appeared!");
		Victim toby("Toby");
		eo("Victim Toby just died for no apparent reason!");
	}

	out("Test 11: Victim | getPolymorphed");
	eo("Jimmy has been turned into a cute little sheep!");
	jimothy.getPolymorphed();

	out("Test 12: Sorcerer | polymorph -> victim");
	eo("Jimmy has been turned into a cute little sheep!");
	rob.polymorph(jimothy);


	// PEON
	out("Test 13: Peon | Constructor");
	eo("Some random victim called Pam just appeared!\nZog zog");
	Peon p1("Pam");
	check(p1.getName() == "Pam");
	
	out("Test 14: Peon | Copy constructor");
	eo("Some random victim called Pam just appeared!\nZog zog");
	Peon p2(p1);
	check(p2.getName() == "Pam");

	out("Test 15: Peon | << operator overload");
	eo("I'm Pam and I like otters!");
	std::cout << p2 << std::endl;

	out("Test 16: Peon | Assignment operator");
	eo("Some random victim called Karen just appeared!\nZog zog");
	Peon p3("Karen");
	check(p3.getName() == "Karen");

	p3 = p2;
	check(p3.getName() == "Pam");
	
	eo("I'm Pam and I like otters!");
	std::cout << p2 << std::endl;

	out("Test 17: Victim | Destructor");
	{
		eo("Some random victim called Andy just appeared!\nZog zog");
		Peon p4("Andy");
		eo("Bleuark...\nVictim Andy just died for no apparent reason!");
	}

	out("Test 18: Peon | getPolymorphed");
	eo("Pam has been turned into a pink pony!");
	p3.getPolymorphed();

	out("Test 19: Sorcerer | polymorph -> peon");
	eo("Pam has been turned into a pink pony!");
	rob.polymorph(p3);

	std::cout << "TESTS END\n" << std::endl;
	return 0;
}
