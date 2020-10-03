/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:35:14 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/03 20:59:59 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <climits>
#include <cfloat>
#include <cmath>

bool is_character_literal(std::string input)
{
	// Can only be 1 character long
	if (input.length() != 1)
		return false;

	int c = static_cast<int>(input[0]);

	// If it contains digits, we will treat it as int
	if (c >= '0' && c <= '9')
		return false;
	
	// I'm using this definition of 'printable' characters:
	// https://web.itu.edu.tr/sgunduz/courses/mikroisl/ascii.html
	if (c >= 31 && c <= 127)
		return true;
	else
		return false;
}

bool is_integer_literal(std::string input)
{
	for (int i = 0; input[i]; i++)
	{
		if (!(((i == 0) && (input[i] == '+' || input[i] == '-')) ||
				(input[i] >= '0' && input[i] <= '9')))
		{
			return false;
		}
	}
	return true;
}

template <typename myType>
int overflowsChar (myType a)
{
	if (a > CHAR_MAX)
		return 1;
	if (a < CHAR_MIN)
		return -1;
	if (isnan(a) || isinf(a))
		return 3;
	return 0;
}

template <typename myType>
int overflowsInt (myType a)
{
	if (a > INT_MAX)
		return 1;
	if (a < INT_MIN)
		return -1;
	if (isnan(a) || isinf(a))
		return 3;
	return 0;
}

void	print_char(char c)
{
	if (c >= 32 && c <= 127)
	{
		std::cout << "\'" << c << "\'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
}

template <typename myType>
void print_overflow(myType val, int overflow)
{
	if (overflow == 0)
	{
		if (std::is_same<myType, char>::value)
			return print_char(val);
		std::cout << val;
		if (std::is_same<myType, float>::value)
		{
			std::cout << "f";
		}
		std::cout << std::endl;
	}
	else if (overflow == 1)
	{
		std::cout << "overflow" << std::endl;
	}
	else if (overflow == -1)
	{
		std::cout << "underflow" << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

void print_values(char c, int i, float f, double d, int overflows[2])
{	
	std::cout << "char:   ";
	print_overflow(c, overflows[0]);
	
	std::cout << "int:    "; 
	print_overflow(i, overflows[1]);
	
	std::cout << std::setiosflags (std::ios::showpoint);
	std::cout << "float:  " << f << "f" << std::endl;
		
	std::cout << "double: " << d << std::endl;
}

void print_float_literal(double f)
{
	int overflows[2] = {
		overflowsChar(f),
		overflowsInt(f)
	};
	print_values(
		static_cast<char>(f),
		static_cast<int>(f),
		static_cast<float>(f),
		static_cast<double>(f),
		overflows
	);
}

void print_integer_literal(int i)
{
	int overflows[2] = {
		overflowsChar(i),
		overflowsInt(i)
	};
	print_values(
		static_cast<char>(i),
		i,
		static_cast<float>(i),
		static_cast<double>(i),
		overflows
	);
}

void print_double_literal(double d)
{
	int overflows[2] = {
		overflowsChar(d),
		overflowsInt(d),
	};
	print_values(
		static_cast<char>(d),
		static_cast<int>(d),
		static_cast<float>(d),
		d,
		overflows
	);
}

bool handle_float_literal(std::string input)
{
	float result;
	try
	{
		result = std::stod(input, nullptr);
	}
	catch(const std::invalid_argument& e)
	{
		return false;
	}
	catch(const std::out_of_range &e)
	{
		return false;
	}
	print_float_literal(result);
	return true;
}

bool handle_double_literal(std::string input)
{
	double result;
	try
	{
		result = std::stod(input, nullptr);
	}
	catch(const std::invalid_argument& e)
	{
		return false;
	}
	catch(const std::out_of_range &e)
	{
		return false;
	}
	print_double_literal(result);
	return true;
}

bool handle_integer_literal(std::string input)
{
	int result;
	try
	{
		result = std::stoi(input, nullptr);
	}
	catch(const std::invalid_argument& e)
	{
		return false;
	}
	catch(const std::out_of_range &e)
	{
		return false;
	}
	print_integer_literal(result);
	return true;
}

bool handle_character_literal(std::string input)
{
	char c = static_cast<char>(input[0]);
	int overflows[3] = {
		0,
		0,
		0,
	};
	print_values(
		c,
		static_cast<int>(c),
		static_cast<float>(c),
		static_cast<double>(c),
		overflows
	);
	return true;
}

void convert(std::string input)
{

	if (is_character_literal(input))
	{
		if (handle_character_literal(input))
			return;
	}
	if (input.rfind("f") == input.length()-1)
	{
		if (handle_float_literal(input))
			return;
	}
	if (is_integer_literal(input) && handle_integer_literal(input))
		return;
	if (handle_double_literal(input))
			return;
	std::cout << "All conversions are impossible" << std::endl;

}

int main(int ac, char **av)
{	
	if (ac != 2)
	{
		std::cout << "Usage: ./convert <conversion>" << std::endl;
		return 1;
	}
	convert(av[1]);
	return 1;
}