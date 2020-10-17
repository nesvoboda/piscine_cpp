/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:18:36 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/11 22:03:00 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

// Test-related stuff below

// Needed to automatically fail tests;
#include <assert.h>
#include <exception>

bool exception_thrown = false;

void check(int expression);

#include <string.h>

#define TEST_EXCEPTION(expression, exceptionType, message) { \
	exception_thrown = false; \
	try \
	{ \
		expression; \
		assert (0 == 1); \
	} \
	catch (const exceptionType &e) \
	{ \
		exception_thrown = true; \
		check(!strcmp(e.what(), message)); \
	} \
	check(exception_thrown == true); \
}

int test_no = 1;

void out(std::string s)
{
	std::cout << std::endl;
	std::cout << "\033[0;34m" << "Test " << test_no << " | " << s << "\033[0m" << std::endl;
	test_no += 1;
}

// void eo(std::string s)
// {
// 	std::cout << "\33[1;33m" << "Expected output:" <<"\033[0m" << std::endl;
// 	std::cout << s << std::endl;
// }

void check(int expression)
{
	// If expression doesn't evaluate to 1, the program will abort
	assert(expression == 1);
	std::cout << "\033[92m✓ PASS\033[0m" << std::endl;
}


// Test-related stuff ends

int main(void)
{
	std::cout << "Tests from the subject" << std::endl << std::endl;

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << "Additional tests" << std::endl;


	out("Span | Constructor");
	Span s1(5);
	Span s2(0);

	out("Span | Copy constructor");
	Span s3(s1);

	out("Span | Assignment operator");
	s2 = s3;

	out("Span | Destructor");
	{
		Span s4(10);
	}

	out("Span | addNumber");
	Span s5(5);
	s5.addNumber(0);
	s5.addNumber(-1);
	s5.addNumber(10);
	s5.addNumber(2);
	
	out("Span | shortestSpan");
	check(s5.shortestSpan() == 1);

	out("Span | longestSpan");
	check(s5.longestSpan() == 11);

	out("Span | Assignment operator with items");
	Span s6(8);
	s6 = s5;
	check(s6.shortestSpan() == 1);
	check(s6.longestSpan() == 11);

	out("Span | Functions on empty span");
	Span s7(20);
	TEST_EXCEPTION(s7.shortestSpan(), Span::NotEnoughNumbers, "There isn't enough numbers in this Span to calculate spans");
	TEST_EXCEPTION(s7.longestSpan(), Span::NotEnoughNumbers, "There isn't enough numbers in this Span to calculate spans");

	out("Span | Functions on span with one element");
	Span s8(20);
	s8.addNumber(0);
	TEST_EXCEPTION(s8.shortestSpan(), Span::NotEnoughNumbers, "There isn't enough numbers in this Span to calculate spans");
	TEST_EXCEPTION(s8.longestSpan(), Span::NotEnoughNumbers, "There isn't enough numbers in this Span to calculate spans");

	out("Span | Too many elements");
	Span s9(3);
	s9.addNumber(0);
	s9.addNumber(0);
	s9.addNumber(0);
	TEST_EXCEPTION(s9.addNumber(0), Span::SpanFull, "This Span is full, you can't add any more numbers to it");
}