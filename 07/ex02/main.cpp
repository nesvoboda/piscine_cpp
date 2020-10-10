/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:11:07 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/10 15:46:01 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>

// Test-related stuff below

// Needed to automatically fail tests;
#include <assert.h>

// #include <string.h>
#include <cstring>

bool exception_thrown = false;

void check(int expression);

#define TEST_EXCEPTION(expression, exceptionType) { \
	exception_thrown = false; \
	try \
	{ \
		expression; \
	} \
	catch (const exceptionType &e) \
	{ \
		exception_thrown = true; \
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
	out("Array | Default constructor");

	Array<int> intarr0;

	check(intarr0.size() == 0);
	TEST_EXCEPTION(intarr0[0], Array<int>::OutOfBoundsException);

	Array<float> farr0;

	check(farr0.size() == 0);
	TEST_EXCEPTION(farr0[0], Array<float>::OutOfBoundsException);

	out("Array | Construction with size parameter");
	Array<int> intarr1(5);
	check(intarr1.size() == 5);
	check(intarr1[0] == 0);
	check(intarr1[1] == 0);
	check(intarr1[2] == 0);
	check(intarr1[3] == 0);
	check(intarr1[4] == 0);
	TEST_EXCEPTION(intarr1[5], Array<int>::OutOfBoundsException);
	
	Array<float> floatarr1(5);
	check(floatarr1.size() == 5);
	check(floatarr1[0] == 0.0f);
	check(floatarr1[1] == 0.0f);
	check(floatarr1[2] == 0.0f);
	check(floatarr1[3] == 0.0f);
	check(floatarr1[4] == 0.0f);
	TEST_EXCEPTION(floatarr1[5], Array<float>::OutOfBoundsException);

	out("Array | Destructor");
	{
		Array<int> intarr2;
		Array<int> intarr3(5);
		Array<float> floatarr2;
		Array<float> floatarr3(5);
	}
	
	out("Array | Copy construction");
	Array<int> intarr4(4);
	intarr4[0] = 0;
	intarr4[1] = 1;
	intarr4[2] = 2;
	intarr4[3] = 3;

	Array<int> intarr5(intarr4);
	check(intarr5[0] == 0);
	check(intarr5[1] == 1);
	check(intarr5[2] == 2);
	check(intarr5[3] == 3);
	check(intarr5.size() == intarr4.size());

	// Changing the old array doesn't affect the new one
	intarr4[3] = 9;
	check(intarr5[3] == 3);

	Array<float> floatarr4(4);
	floatarr4[0] = 0.0f;
	floatarr4[1] = 1.0f;
	floatarr4[2] = 2.0f;
	floatarr4[3] = 3.0f;

	Array<float> floatarr5(floatarr4);
	check(floatarr5[0] == 0.0f);
	check(floatarr5[1] == 1.0f);
	check(floatarr5[2] == 2.0f);
	check(floatarr5[3] == 3.0f);
	check(floatarr5.size() == floatarr4.size());

	// Changing the old array doesn't affect the new one
	floatarr4[3] = 9.0f;
	check(floatarr5[3] == 3.0f);

	out("Array | Assignment operator with different sizes");
	Array<int> intarr6(4);
	intarr6[0] = 0;
	intarr6[1] = 1;
	intarr6[2] = 2;
	intarr6[3] = 3;

	Array<int> intarr7(5);
	intarr7[0] = 5;
	intarr7[1] = 6;
	intarr7[2] = 7;
	intarr7[3] = 8;
	intarr7[4] = 9;

	intarr7 = intarr6;

	check(intarr7[0] == 0);
	check(intarr7[1] == 1);
	check(intarr7[2] == 2);
	check(intarr7[3] == 3);
	TEST_EXCEPTION(intarr7[4], Array<int>::OutOfBoundsException);

	// Changing the old array doesn't affect the new one
	intarr6[3] = 9;
	check(intarr7[3] == 3);

	Array<float> floatarr6(4);
	floatarr6[0] = 0.0f;
	floatarr6[1] = 1.0f;
	floatarr6[2] = 2.0f;
	floatarr6[3] = 3.0f;

	Array<float> floatarr7(5);
	floatarr7[0] = 5.0f;
	floatarr7[1] = 6.0f;
	floatarr7[2] = 7.0f;
	floatarr7[3] = 8.0f;
	floatarr7[4] = 9.0f;

	floatarr7 = floatarr6;

	check(floatarr7[0] == 0.0f);
	check(floatarr7[1] == 1.0f);
	check(floatarr7[2] == 2.0f);
	check(floatarr7[3] == 3.0f);

	TEST_EXCEPTION(floatarr7[4], Array<float>::OutOfBoundsException);
	
	// Changing the old array doesn't affect the new one
	floatarr6[3] = 9.0f;
	check(floatarr7[3] == 3.0f);


	out("Array | Assignment operator with same sizes");
	
	Array<int> intarr8(4);
	intarr8[0] = 0;
	intarr8[1] = 1;
	intarr8[2] = 2;
	intarr8[3] = 3;

	Array<int> intarr9(4);
	intarr9[0] = 5;
	intarr9[1] = 6;
	intarr9[2] = 7;
	intarr9[3] = 8;

	intarr9 = intarr8;

	check(intarr9[0] == 0);
	check(intarr9[1] == 1);
	check(intarr9[2] == 2);
	check(intarr9[3] == 3);

	// Changing the old array doesn't affect the new one
	intarr8[3] = 9;
	check(intarr9[3] == 3);

	Array<float> floatarr8(4);
	floatarr8[0] = 0.0f;
	floatarr8[1] = 1.0f;
	floatarr8[2] = 2.0f;
	floatarr8[3] = 3.0f;

	Array<float> floatarr9(4);
	floatarr9[0] = 5.0f;
	floatarr9[1] = 6.0f;
	floatarr9[2] = 7.0f;
	floatarr9[3] = 8.0f;

	floatarr9 = floatarr8;

	check(floatarr9[0] == 0.0f);
	check(floatarr9[1] == 1.0f);
	check(floatarr9[2] == 2.0f);
	check(floatarr9[3] == 3.0f);

	// Changing the old array doesn't affect the new one
	floatarr8[3] = 9;
	check(floatarr9[3] == 3);

	out("Array | [] operator");

	Array<int> intarr10(5);
	check(intarr10[0] == 0);
	check(intarr10[0] == 0);
	check(intarr10[0] == 0);
	check(intarr10[0] == 0);
	check(intarr10[0] == 0);

	intarr10[0] = 5;
	intarr10[1] = 6;
	intarr10[2] = 7;
	intarr10[3] = 8;
	intarr10[4] = 9;

	check(intarr10[0] == 5);
	check(intarr10[1] == 6);
	check(intarr10[2] == 7);
	check(intarr10[3] == 8);
	check(intarr10[4] == 9);

	TEST_EXCEPTION(intarr10[-1], std::exception);
	TEST_EXCEPTION(intarr10[10], Array<int>::OutOfBoundsException);

	Array<float> floatarr10(5);
	check(floatarr10[0] == 0.0f);
	check(floatarr10[0] == 0.0f);
	check(floatarr10[0] == 0.0f);
	check(floatarr10[0] == 0.0f);
	check(floatarr10[0] == 0.0f);

	floatarr10[0] = 5.0f;
	floatarr10[1] = 6.0f;
	floatarr10[2] = 7.0f;
	floatarr10[3] = 8.0f;
	floatarr10[4] = 9.0f;

	check(floatarr10[0] == 5);
	check(floatarr10[1] == 6);
	check(floatarr10[2] == 7);
	check(floatarr10[3] == 8);
	check(floatarr10[4] == 9);

	TEST_EXCEPTION(floatarr10[-1], std::exception);
	TEST_EXCEPTION(floatarr10[10], Array<float>::OutOfBoundsException);

	out("Array | size");
	
	Array<int> intarr11(0);
	check(intarr11.size() == 0);
	TEST_EXCEPTION(intarr11[0], Array<int>::OutOfBoundsException);

	Array<int> intarr12(1);
	check(intarr12.size() == 1);

	Array<int> intarr13(5);
	check(intarr13.size() == 5);

	Array<float> floatarr11(0);
	check(floatarr11.size() == 0);
	TEST_EXCEPTION(floatarr11[0], Array<float>::OutOfBoundsException);

	Array<float> floatarr12(1);
	check(floatarr12.size() == 1);

	Array<float> floatarr13(5);
	check(intarr13.size() == 5);

	try 
	{
		intarr13[100500];
	}
	catch (const Array<int>::OutOfBoundsException &e)
	{
		check(!std::strcmp(e.what(), "The element is out of bounds of the array"));
	}

	const Array<int> intarr14(2);
	try 
	{
		const int z = intarr14[100500];
		(void ) z;
	}
	catch (const Array<int>::OutOfBoundsException &e)
	{
		check(!std::strcmp(e.what(), "The element is out of bounds of the array"));
	}

	
}