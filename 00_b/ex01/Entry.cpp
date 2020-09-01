/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entry.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:32:52 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/01 16:39:23 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entry.hpp"

Entry::Entry(void): 
	first_name("First name"), last_name("Last name"), nickname("Nickname"),
	login("Login"), postal_address("Postal address"),
	email_address("Email address"), phone_number("Phone number"),
	birthday_date("Birthday date"), favorite_meal("Favorite meal"),
	underwear_color("Underwear color"), darkest_secret("Darkest secret"),
	filled(0)
{
}

void Entry::fill_entry(void)
{
	std::cout << "We're creating a new contact." << std::endl << std::endl;
	this->first_name.fill_field();
	this->last_name.fill_field();
	this->nickname.fill_field();
	this->login.fill_field();
	this->postal_address.fill_field();
	this->email_address.fill_field();
	this->phone_number.fill_field();
	this->birthday_date.fill_field();
	this->favorite_meal.fill_field();
	this->underwear_color.fill_field();
	this->darkest_secret.fill_field();
	this->filled = 1;
}

void Entry::print_row(int index)
{

	std::cout << "|" << std::setw(10) << index << "|";
	this->first_name.print_column();
	std::cout << "|";
	this->last_name.print_column();
	std::cout << "|";
	this->nickname.print_column();
	std::cout << "|" << std::endl;
}

void Entry::print_single(void)
{
	std::cout << "CONTACT" << std::endl << std::endl;
	this->first_name.print_field();
	this->last_name.print_field();
	this->nickname.print_field();
	this->login.print_field();
	this->postal_address.print_field();
	this->email_address.print_field();
	this->phone_number.print_field();
	this->birthday_date.print_field();
	this->favorite_meal.print_field();
	this->underwear_color.print_field();
	this->darkest_secret.print_field();
}

int Entry::getFilled(void)
{
	return this->filled;
}