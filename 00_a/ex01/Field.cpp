/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:33:12 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/26 12:31:41 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Field.hpp"

Field::Field(std::string name)
{
	this->name.assign(name);
}

int Field::fill_field(void)
{
	std::string buffer;
	std::cout << "Enter " << this->name << ": ";
	if (std::getline(std::cin, buffer))
	{
		this->value.assign(buffer);
		return (0);
	}
	else
		return (-1);
}

void Field::print_column(void)
{
	int length;

	length = this->value.length();
	std::cout << std::setw(10) << this->value.substr(0,9);
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