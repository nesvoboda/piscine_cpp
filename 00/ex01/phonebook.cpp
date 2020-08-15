/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:32:09 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/14 19:30:51 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(void)
{

}

void Phonebook::add_entry(void)
{
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->contents[i].filled == 0)
		{
			this->contents[i].fill_entry();
			std::cout << std::endl << "Great!" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "SORRY! THE PHONEBOOK IS FULL." << std::endl << std::endl;
}

void Phonebook::horisontal_divider(void)
{
	for (int i = 0; i < 53; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}

void Phonebook::retrieve(int index)
{
	if (this->contents[index].filled == 0)
	{
		std::cout << "Sorry, there is no contact under this index." << 
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

	if (this->contents[0].filled == 0)
	{
		std::cout << std::endl << "No contacts added yet. Try adding one!"
		<< std::endl << std::endl;
		return;
	}
	int buffer = -1;
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
	std::cin >> buffer;
	std::cin.ignore(100,'\n');
	if (buffer < 0 || buffer > 7)
	{
		std::cout << "Sorry, index can only be an integer between 0 and 7." <<
			std::endl;
		return ;
	}
	this->retrieve(buffer);
}

void Phonebook::print_table_head(void)
{
	std::cout << "| ";
	this->pretty_print("Index");
	std::cout << " | ";
	this->pretty_print("First name");
	std::cout << " | ";
	this->pretty_print("Last name");
	std::cout << " | ";
	this->pretty_print("Nickname");
	std::cout << " |" << std::endl;
}

void Phonebook::pretty_print(std::string word)
{
	int length;

	length = word.length();
	for (int i = 0; i < 10 - length; i++)
	{
		std::cout << " ";
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << word[i];
	}
}