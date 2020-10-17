/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:09:33 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/11 22:31:12 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

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
	out("MutantStack | Constructor");
	MutantStack<int> ms0;
	std::stack<int> is0;
	check(ms0.size() == is0.size());
	check(ms0.empty() == is0.empty());

	out("MutantStack | Copy constructor");
	MutantStack<int> ms1;
	std::stack<int> is1;

	is1.push(3);
	ms1.push(3);

	MutantStack<int> ms2(ms1);
	std::stack<int> is2(is1);
	check(ms2.size() == is2.size());
	check(ms2.empty() == is2.empty());
	check(ms2.top() == is2.top());

	out("MutantStack | Assignment operator");
	MutantStack<int> ms3;
	std::stack<int> is3;

	ms3 = ms2;
	is3 = is2;
	check(ms3.size() == is3.size());
	check(ms3.empty() == is3.empty());
	check(ms3.top() == is3.top());
	
}