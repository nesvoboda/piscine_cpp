/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:21:58 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/12 11:12:59 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

void check(int expression)
{
	// If expression doesn't evaluate to 1, the program will abort
	assert(expression == 1);
	std::cout << "\033[92m✓ PASS\033[0m" << std::endl;
}

template <typename T>
void swap(T &a, T &b) {
	// This should protect from classes not having a default constructor.
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b) {
	if (a < b)
	{
		return a;
	}
	else if (b < a)
	{
		return b;
	}
	else
	{
		return b;
	}
}

template <typename T>
T max(T a, T b) {
	if (a > b)
	{
		return a;
	}
	else if (b > a)
	{
		return b;
	}
	else
	{
		return b;
	}
}

int main( void )
{
	std::cout << "Tests from the subject" << std::endl;

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "Additional tests" << std::endl;

	out("Swap | Normal test");
	int x = 2;
	int y = 3;
	swap(x, y);
	check(x == 3);
	check(y == 2);

	out("Min | a < b");
	
	int a1 = 2;
	int b1 = 3;
	check(min(a1, b1) == a1);

	out("Min | b < a");
	
	int a2 = 3;
	int b2 = 2;
	check(min(a2, b2) == b2);

	out("Min | b == a");
	
	int a3 = 3;
	int b3 = 3;
	check(min(a3, b3) == b3);


	out("Max | a < b");
	
	int a4 = 2;
	int b4 = 3;
	check(max(a4, b4) == b4);

	out("Max | b < a");
	
	int a5 = 3;
	int b5 = 2;
	check(max(a5, b5) == a5);

	out("Max | b == a");
	
	int a6 = 3;
	int b6 = 3;
	check(max(a6, b6) == b6);

	return 0;
}