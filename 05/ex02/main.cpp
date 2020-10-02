/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:26:15 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/02 15:07:55 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
		// std::cout << e.what() << std::endl;
		check(!strcmp(e.what(), "Grade is too high!"));
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
	
	/*
	Form is now an abstract class, so no tests today :(
	*/

	out("ShrubberyCreationForm | Constructor");
	ShrubberyCreationForm scf("test1");

	out("ShrubberyCreationForm | Copy constructor");
	ShrubberyCreationForm scf2(scf);
	
	out("ShrubberyCreationForm | Assignment operator");
	ShrubberyCreationForm scf3("test2");

	scf3 = scf2;

	out("ShrubberyCreationForm | Destructor");
	{
		ShrubberyCreationForm scf4("test3");
	}
	
	out("ShrubberyCreationForm | valid execute()");
	Bureaucrat tom = Bureaucrat("Tom", 3);
	tom.signForm(scf3);
	scf3.execute(tom);

	out("ShrubberyCreationForm | execute() -> not signed");
	
	ShrubberyCreationForm scf5 = ShrubberyCreationForm("test2");

	exceptionCaught = false;
	try
	{
		scf5.execute(tom);
	}
	catch(const Form::FormNotSignedException& e)
	{
		check(!strcmp(e.what(), "The form hasn't been signed yet, can't execute."));
		exceptionCaught = true;
	}
	check(exceptionCaught == true);

	out("ShrubberyCreationForm | execute() -> grade too low");

	tom.signForm(scf5);

	Bureaucrat jan = Bureaucrat("jan", 149);
	exceptionCaught = false;
	try
	{
		scf5.execute(jan);
	}
	catch(const Form::GradeTooLowException& e)
	{
		check(!strcmp(e.what(), "Grade is too low!"));
		exceptionCaught = true;
	}
	check(exceptionCaught == true);

	out("ShrubberyCreationForm | execute() -> file error");

	ShrubberyCreationForm scf6 = ShrubberyCreationForm("/fasdfasdfile/asdfasdf/asdfadf");
	tom.signForm(scf6);

	exceptionCaught = false;
	try
	{
		scf6.execute(tom);
	}
	catch(const ShrubberyCreationForm::FileErrorException& e)
	{
		// std::cout << e.what() << std::endl;
		check(!strcmp(e.what(), "File error while executing ShrubberyCreationForm"));
		exceptionCaught = true;
	}
	check(exceptionCaught == true);



	out("RobotomyRequestForm | Constructor");
	RobotomyRequestForm rcf("test1");

	out("RobotomyRequestForm | Copy constructor");
	RobotomyRequestForm rcf2(rcf);
	
	out("RobotomyRequestForm | Assignment operator");
	RobotomyRequestForm rcf3("test2");

	rcf3 = rcf2;

	out("RobotomyRequestForm | Destructor");
	{
		RobotomyRequestForm rcf4("test3");
	}
	
	out("RobotomyRequestForm | valid execute()");
	tom.signForm(rcf3);
	rcf3.execute(tom);
	rcf3.execute(tom);
	rcf3.execute(tom);
	rcf3.execute(tom);

	out("RobotomyRequestForm | execute() -> not signed");
	
	RobotomyRequestForm rcf5 = RobotomyRequestForm("test2");

	exceptionCaught = false;
	try
	{
		rcf5.execute(tom);
	}
	catch(const Form::FormNotSignedException& e)
	{
		check(!strcmp(e.what(), "The form hasn't been signed yet, can't execute."));
		exceptionCaught = true;
	}
	check(exceptionCaught == true);

	out("RobotomyRequestForm | execute() -> grade too low");

	tom.signForm(rcf5);

	exceptionCaught = false;
	try
	{
		rcf5.execute(jan);
	}
	catch(const Form::GradeTooLowException& e)
	{
		check(!strcmp(e.what(), "Grade is too low!"));
		exceptionCaught = true;
	}
	check(exceptionCaught == true);



	out("PresidentialPardonForm | Constructor");
	PresidentialPardonForm ppf("test1");

	out("PresidentialPardonForm | Copy constructor");
	PresidentialPardonForm ppf2(ppf);
	
	out("PresidentialPardonForm | Assignment operator");
	PresidentialPardonForm ppf3("test2");

	ppf3 = ppf2;

	out("PresidentialPardonForm | Destructor");
	{
		PresidentialPardonForm ppf4("test3");
	}
	
	out("PresidentialPardonForm | valid execute()");
	tom.signForm(ppf3);
	ppf3.execute(tom);


	out("PresidentialPardonForm | execute() -> not signed");
	
	PresidentialPardonForm ppf5 = PresidentialPardonForm("test2");

	exceptionCaught = false;
	try
	{
		ppf5.execute(tom);
	}
	catch(const Form::FormNotSignedException& e)
	{
		check(!strcmp(e.what(), "The form hasn't been signed yet, can't execute."));
		exceptionCaught = true;
	}
	check(exceptionCaught == true);

	out("PresidentialPardonForm | execute() -> grade too low");

	tom.signForm(ppf5);

	exceptionCaught = false;
	try
	{
		ppf5.execute(jan);
	}
	catch(const Form::GradeTooLowException& e)
	{
		check(!strcmp(e.what(), "Grade is too low!"));
		exceptionCaught = true;
	}
	check(exceptionCaught == true);
	out("Bureaucrat | valid executeForm ");
	eo("Tom, bureaucrat grade 3 executes Presidential Pardon Form, form, grade to sign: 25, grade to execute: 5\ntest1 has been pardoned by Zafod Beeblebrox");
	tom.executeForm(ppf3);

	out("Bureaucrat | non-valid executeForm ");
	eo("Bobby, bureaucrat grade 150 cannot execute form Presidential Pardon Form, form, grade to sign: 25, grade to execute: 5 because Grade is too low!");
	Bureaucrat bobby = Bureaucrat("Bobby", 150);
	bobby.executeForm(ppf3);
	
}