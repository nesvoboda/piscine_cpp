/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:32:09 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/26 12:46:33 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

// Phonebook::Phonebook(void)
// {
// }

void Phonebook::add_entry(void)
{
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->contents[i].is_filled() == 0)
		{
			if (!this->contents[i].fill_entry())
				std::cout << std::endl << "Great!" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "SORRY! THE PHONEBOOK IS FULL." << std::endl << std::endl;
}

void Phonebook::horisontal_divider(void)
{
	for (int i = 0; i < 45; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}

void Phonebook::retrieve(int index)
{
	if (this->contents[index].is_filled() == 0)
	{
		std::cout << std::endl << "Sorry, there is no contact under this index." << 
			std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl;
		this->contents[index].print_single();
		std::cout << std::endl;
	}
}

void Phonebook::search(void)
{

	if (this->contents[0].is_filled() == 0)
	{
		std::cout << std::endl << "No contacts added yet. Try adding one!"
		<< std::endl << std::endl;
		return;
	}
	int number = -1;
	std::string line;
	std::cout << std::endl;
	this->horisontal_divider();
	this->print_table_head();
	this->horisontal_divider();
	for (int i = 0; i < 8; i++)
	{
		if (this->contents[i].filled == 0)
		{
			break ;
		}
		this->contents[i].print_row(i);
	}
	this->horisontal_divider();
	std::cout << std::endl << "Enter the index: ";
	// We're using getline here, because cin >> number would leave '\n'
	// and mess up the following lines
	std::getline(std::cin, line);
	if (line.length() != 1 || line[0] < '0' || line[0] > '9')
	{
		std::cout << "Sorry, index can only be an integer between 0 and 7." <<
			std::endl;
		return ;
	}
	number = line[0] - '0';
	if (number < 0 || number > 7)
	{
		std::cout << "Sorry, index can only be an integer between 0 and 7." <<
			std::endl;
		return ;
	}
	this->retrieve(number);
}

void Phonebook::print_table_head(void)
{
	std::cout << "|";
	this->pretty_print("Index");
	std::cout << "|";
	this->pretty_print("First name");
	std::cout << "|";
	this->pretty_print("Last name");
	std::cout << "|";
	this->pretty_print("Nickname");
	std::cout << "|" << std::endl;
}

void Phonebook::pretty_print(std::string word)
{
	int length;

	length = word.length();
	std::cout << std::setw(10) << word;
}