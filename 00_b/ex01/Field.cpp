/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:33:12 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/01 16:37:07 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Field.hpp"

Field::Field(std::string name)
{
	this->name.assign(name);
}

void Field::fill_field(void)
{
	std::string buffer;
	std::cout << "Enter " << this->name << ": ";
	if (std::getline(std::cin, buffer))
		this->value.assign(buffer);
	else
		exit(-1);
}

void Field::print_column(void)
{
	int length = this->value.length();
	std::string temp;
	if (length > 10)
	{
		temp = this->value.substr(0,9);
		temp.append(".");
	}
	else
		temp = this->value;
	std::cout << std::setw(10) << temp;
}

void Field::print_field(void)
{
	std::cout << this->name << ": " << this->value << std::endl;
}