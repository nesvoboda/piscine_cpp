/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:26:15 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/02 15:03:58 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

#include <string.h>

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

int main(void)
{
	out("Bureaucrat | Constructor");
	Bureaucrat bob("Bob", 3);

	out("Bureaucrat | Constructor with a grade too high");
	bool exceptionCaught = false;
	try
	{
		Bureaucrat jenna("Jenna", 0);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{

		check(!strcmp(e.what(), "Grade is too high!"));
		exceptionCaught = true;
		
	}
	check(exceptionCaught == true);
	
	out("Bureaucrat | Constructor with a grade too low");
	exceptionCaught = false;
	try
	{
		Bureaucrat alex("Alex", 151);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		check(!strcmp(e.what(), "Grade is too low!"));
		exceptionCaught = true;
		// std::cerr << e.what() << '\n';
	}
	check(exceptionCaught == true);
	
	out("Bureaucrat | Copy constructor");
	Bureaucrat bob2(bob);
	check(bob.getGrade() == bob2.getGrade());
	check(bob.getName() == bob2.getName());

	out("Bureaucrat | Assignment operator");
	Bureaucrat mike("Mike", 40);
	Bureaucrat don("Don", 30);

	don = mike;
	
	check(don.getGrade() == mike.getGrade());
	check(don.getName() == "Don");

	out("Bureaucrat | << operator overload");
	eo("Mike, bureaucrat grade 40");
	std::cout << mike << std::endl;

	out("Bureaucrat | Destructor");
	{
		Bureaucrat rajesh("Rajesh", 100);
	}

	out("Bureaucrat | getGrade()");
	check(mike.getGrade() == 40);
	
	out("Bureaucrat | getName()");
	check(mike.getName() == "Mike");

	out("Bureaucrat | legal incrementGrade()");
	mike.incrementGrade(1);
	check(mike.getGrade() == 39);

	out("Bureaucrat | illegal incrementGrade()");
	exceptionCaught = false;
	try
	{
		mike.incrementGrade(500);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
		// check(!strcmp(e.what(), "Grade is too high!"));
		exceptionCaught = true;
	}
	check(exceptionCaught == true);

	out("Bureaucrat | legal decrementGrade()");
	mike.decrementGrade(1);
	check(mike.getGrade() == 40);

	out("Bureaucrat | illegal decrementGrade()");
	exceptionCaught = false;
	try
	{
		mike.decrementGrade(500);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		check(!strcmp(e.what(), "Grade is too low!"));
		exceptionCaught = true;
	}
	check(exceptionCaught == true);
	
	
}