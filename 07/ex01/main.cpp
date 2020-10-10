/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:28:51 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/10 15:41:10 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>


// Test-related stuff below

// Needed to automatically fail tests;
#include <assert.h>

#include "iter.hpp"

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

// Test-related stuff ends

void	print(int const &var)
{
	std::cout << var;
}

template <typename T>
void	plusone(T &var)
{
	var += 1;
}

void	act(std::string const &var)
{
	std::cout << var;
}

int main(void)
{
	
	int intarr[6] = {0,1,2,3,4,5};

	out("Iter | Print all elements");
	eo("012345");
	iter(intarr, 6, print);
	std::cout << std::endl;

	char chararr[6] = {0,1,2,3,4,5};
	out("Iter | Add one to each element with a template");
	iter(chararr, 6, plusone<char>);

	check(chararr[0] == 1);
	check(chararr[1] == 2);
	check(chararr[2] == 3);
	check(chararr[3] == 4);
	check(chararr[4] == 5);
	check(chararr[5] == 6);
	
	out("Iter | array of strings");
	eo("To be or not to be");
	std::string opus[6] = {"To ", "be ", "or ", "not ", "to ", "be "};
	iter(opus, 6, act);
	std::cout << std::endl;
	
}