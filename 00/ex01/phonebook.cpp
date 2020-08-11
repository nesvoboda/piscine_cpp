#include "phonebook.hpp"
#include <iostream>

Entry::Entry(void)
{
	std::cout << "Constructor called" << std::endl;
}

Entry::~Entry(void)
{
	std::cout << "Destructor called" << std::endl;
}

Field::Field(std::string name)
{
	std::cout << "Field Constructor called" << std::endl;
	this->name.assign(name);
}

Field::~Field(void)
{
	std::cout << "Field Destructor called" << std::endl;
}

void Field::fill_field(void)
{
	std::string buffer;
	std::cout << "Enter " << this->name << ": ";
	std::cin >> buffer;
	this->value.assign(buffer);
}


void Entry::fill_entry(void)
{
	std::string buffer;

	std::cout << "We're creating a new contact." << std::endl;

	std::cout << "Enter first_name: " << std::endl;
	std::cin >> buffer;
	this->first_name.assign(buffer);

	std::cout << "Enter last_name: " << std::endl;
	std::cin >> buffer;
	this->last_name.assign(buffer);

	std::cout << "Enter nickname: " << std::endl;
	std::cin >> buffer;
	this->nickname.assign(buffer);

	std::cout << "Enter login: " << std::endl;
	std::cin >> buffer;
	this->login.assign(buffer);

	std::cout << "Enter postal_address: " << std::endl;
	std::cin >> buffer;
	this->postal_address.assign(buffer);

	std::cout << "Enter email_address: " << std::endl;
	std::cin >> buffer;
	this->email_address.assign(buffer);

	std::cout << "Enter phone_number: " << std::endl;
	std::cin >> buffer;
	this->phone_number.assign(buffer);

	std::cout << "Enter birthday_date: " << std::endl;
	std::cin >> buffer;
	this->birthday_date.assign(buffer);

	std::cout << "Enter favorite_meal: " << std::endl;
	std::cin >> buffer;
	this->favorite_meal.assign(buffer);

	std::cout << "Enter underwear_color: " << std::endl;
	std::cin >> buffer;
	this->underwear_color.assign(buffer);

	std::cout << "Enter darkest_secret: " << std::endl;
	std::cin >> buffer;
	this->darkest_secret.assign(buffer);
}

int main(void)
{
	std::string buffer;
	Entry telephone;

	std::cout << "Hello!" << std::endl;

	for(int i = 0; i < 3; i++)
	{
		std::cout << "Enter number: ";
		std::cin >> buffer;
		telephone.set_number(buffer);
		std::cout << "The number is: " << telephone.number << std::endl;
		std::cout << "Or" << std::endl;
		telephone.print_number();
	}
}