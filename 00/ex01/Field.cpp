/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:33:12 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/14 19:00:52 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Field::Field(std::string name)
{
	// std::cout << "Field Constructor called" << std::endl;
	this->name.assign(name);
}

Field::~Field(void)
{
	// std::cout << "Field Destructor called" << std::endl;
}

void Field::fill_field(void)
{
	std::string buffer;
	std::cout << "Enter " << this->name << ": ";
	std::getline(std::cin, buffer);
	this->value.assign(buffer);
}

void Field::print_column(int border)
{
	int length;

	length = this->value.length();
	// Print pre-spacing
	for (int i = 0; i < 10 - length; i++)
	{
		std::cout << " ";
	}
	// Print up to 9 chars
	for (int i = 0; i < 9; i++)
	{
		std::cout << this->value[i];
	}
	if (length > 10)
	{
		std::cout << ".";
	}
	else if (length == 10)
	{
		std::cout << this->value[9];
	}
}

void Field::print_field(void)
{
	std::cout << this->name << ": " << this->value << std::endl;
}