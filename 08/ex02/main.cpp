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

#include <deque>
#include <list>

int main(void)
{
	std::cout << "Tests from the subject" << std::endl << std::endl;

	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::stack<int> s(mstack);
	}

	std::cout << std::endl << "Tests from the subject, replaced with list" << std::endl << std::endl;

	{
		std::list<int> mstack;
		// list has no push
		// mstack.push(5);
		// mstack.push(17);
		mstack.push_back(5);
		mstack.push_back(17);

		// top is back
		std::cout << mstack.back() << std::endl;

		// pop is pop_back()
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;

		// mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
		mstack.push_back(3); mstack.push_back(5); mstack.push_back(737); //[...] mstack.push(0);

		std::list<int>::iterator it = mstack.begin(); std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }

		// This is c++11;
		// std::stack<int> s(mstack);
	}

	out("MutantStack | Constructor");
	MutantStack<int> ms0;
	std::stack<int> is0;
	check(ms0.size() == is0.size());
	check(ms0.empty() == is0.empty());

	MutantStack<float> msf0;
	std::stack<float> isf0;
	check(ms0.size() == isf0.size());
	check(ms0.empty() == isf0.empty());

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

	MutantStack<float> msf1;
	std::stack<float> isf1;

	is1.push(3.0f);
	ms1.push(3.0f);

	MutantStack<float> msf2(msf1);
	std::stack<float> isf2(isf1);
	check(msf2.size() == isf2.size());
	check(msf2.empty() == isf2.empty());

	out("MutantStack | Destructor");
	{
		MutantStack<int> msi5;
		MutantStack<float> msf5;
	}

	out("MutantStack | Assignment operator");
	MutantStack<int> ms3;
	std::stack<int> is3;

	ms3 = ms2;
	is3 = is2;
	check(ms3.size() == is3.size());
	check(ms3.empty() == is3.empty());
	check(ms3.top() == is3.top());

	MutantStack<float> msf3;
	std::stack<float> isf3;

	msf3 = msf2;
	isf3 = isf2;
	check(msf3.size() == isf3.size());
	check(msf3.empty() == isf3.empty());


	out("MutantStack | Assignment operator with items on the left");

	MutantStack<int> ms3_i;
	std::stack<int> is3_i;

	ms3_i.push(3);
	is3_i.push(3);

	ms3_i = ms2;
	is3_i = is2;
	check(ms3_i.size() == is3_i.size());
	check(ms3_i.empty() == is3_i.empty());
	check(ms3_i.top() == is3_i.top());

	MutantStack<float> msf3_i;
	std::stack<float> isf3_i;

	msf3_i.push(3.0f);
	isf3_i.push(3.0f);

	msf3_i = msf2;
	isf3_i = isf2;
	check(msf3_i.size() == isf3_i.size());
	check(msf3_i.empty() == isf3_i.empty());

	out("MutantStack | Assignment operator with items on the right");

	MutantStack<int> ms3_ir;
	std::stack<int> is3_ir;

	ms3_ir = ms3_i;
	is3_ir = is3_i;
	check(ms3_ir.size() == is3_ir.size());
	check(ms3_ir.empty() == is3_ir.empty());
	check(ms3_ir.top() == is3_ir.top());

	MutantStack<float> msf3_ir;
	std::stack<float> isf3_ir;

	msf3_ir = msf3_i;
	isf3_ir = isf3_i;
	check(msf3_ir.size() == isf3_ir.size());
	check(msf3_ir.empty() == isf3_ir.empty());
	
	out("MutantStackIterator | Constructor");
	MutantStack<int>::iterator msi1;

	out("MutantStackIterator | Copy constructor");
	MutantStack<int>::iterator msi2(msi1);

	out("MutantStackIterator | Destructor");
	{
		MutantStack<int>::iterator msi3;
	}

	out("MutantStackIterator | Assignment operator");
	MutantStack<int>::iterator msi4;

	msi4 = msi2;

	out("MutantStackIterator | Destructor");

	out("MutantStack | begin()");
	MutantStack<int> ms4;
	ms4.push(1);
	ms4.push(2);
	ms4.push(3);
	ms4.push(4);

	MutantStack<int>::iterator msi5;
	msi5 = ms4.begin();

	out("MutantStack | i++, ++i and *i");
	check(*msi5 == 1);
	msi5++;

	check(*msi5 == 2);
	msi5++;
	
	check(*msi5 == 3);
	++msi5;
	
	check(*msi5 == 4);
	msi5++;
	
	out("MutantStack | end()");
	check(msi5 == ms4.end());

	out("MutantStack | i-- and --i");
	--msi5;
	check(*msi5 == 4);
	msi5--;
	check(*msi5 == 3);

	out("MutantStack | Copy constructor with content");

	MutantStack<int>::iterator msi5_2(msi5);
	check(*msi5_2 == *msi5);
	check(msi5 == msi5_2);

	out("MutantStack | Assignment operator with content");
	MutantStack<int>::iterator msi5_3;

	msi5_3 = msi5;

	check(*msi5_3 == *msi5);
	check(msi5 == msi5_3);


}