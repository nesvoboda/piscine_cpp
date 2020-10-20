/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:18:36 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/20 12:41:09 by ashishae         ###   ########.fr       */
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

void check(int expression)
{
	// If expression doesn't evaluate to 1, the program will abort
	assert(expression == 1);
	std::cout << "\033[92m✓ PASS\033[0m" << std::endl;
}


#include <vector>
#include <algorithm>
#include <deque>

int f()
{
	static int i = 0;
	return i++;
}

int f2()
{
	static int i = 0;
	return i++;
}

// Test-related stuff ends

// You may want to reduce this number if you're running
// valgrind or you're on a slow machine
#define BIG_TEST 10000000

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

	out("Span | addRange");
	std::vector<int> v(BIG_TEST);
	
	std::cout << "Generating a range of " << BIG_TEST << " numbers" << std::endl;
	std::generate(v.begin(), v.end(), f);
	
	Span s10(BIG_TEST);
	std::cout << "Adding range" << std::endl;
	s10.addRange(v.begin(), v.end());

	std::cout << "Running checks" << std::endl;
	check(s10.shortestSpan() == 1);
	check(s10.longestSpan() == BIG_TEST-1);
	
	out("Span | addRange in two bursts");
	std::vector<int> v1(500);
	std::vector<int> v2(500);
	std::generate(v1.begin(), v1.end(), f2);
	std::generate(v2.begin(), v2.end(), f2);

	Span s11(1000);
	s11.addRange(v1.begin(), v1.end());
	s11.addRange(v2.begin(), v2.end());
	check(s11.shortestSpan() == 1);
	check(s11.longestSpan() == 999);

	out("Span | illegal addRange");
	TEST_EXCEPTION(s11.addRange(v2.begin(), v2.end()), Span::SpanFull, "This Span is full, you can't add any more numbers to it");
	
	Span s12(500);
	TEST_EXCEPTION(s12.addRange(v.begin(), v.end()), Span::SpanFull, "This Span is full, you can't add any more numbers to it");
	
	out("Span | addRange can take different (iterable) containers");
	std::deque<int> d1(1000);
	std::generate(d1.begin(), d1.end(), f);
	
	Span s13(1000);
	s13.addRange(d1.begin(), d1.end());

	check(s13.shortestSpan() == 1);
	check(s13.longestSpan() == 999);
}