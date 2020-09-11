/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:44:07 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/06 10:47:10 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() : storage(nullptr), count(0)
{
}

Squad::Squad(const Squad &copy)
{
	std::cout << "Copy constructor!" << std::endl;
	this->storage = new ISpaceMarine* [copy.count];
	for (int i = 0; i < copy.count; i++)
	{
		// this->storage[i] = copy.storage[i];
		this->storage[i] = copy.storage[i]->clone();
	}
	this->count = copy.count;
}

Squad & Squad::operator= (const Squad &operand)
{
	std::cout << "[ASSIGN] op.count: " << operand.count << ", op.storage: " << operand.storage << std::endl;
	if (this->count != 0)
	{
		std::cout << "[ASSIGN] clearing" << std::endl;
		for (int i = 0; i < count; i++)
		{
			delete this->storage[i];
		}
		delete storage;
	}

	this->storage = new ISpaceMarine* [operand.count];
	for (int i = 0; i < operand.count; i++)
	{
		this->storage[i] = operand.storage[i]->clone();
	}
	this->count = operand.count;
	std::cout << "[ASSIGN] end. count: " << this->count << ", storage: " << this->storage << std::endl;
	return (*this);
}

Squad::~Squad()
{
	for (int i = 0; i < this->count; i++)
	{
		delete this->storage[i];
	}
	if (this->count != 0)
		delete storage;
}


int Squad::getCount() const
{
	return this->count;
}

ISpaceMarine* Squad::getUnit(int index) const
{
	if (index < 0 || index > count-1)
	{
		return nullptr;
	}
	return this->storage[index];

}

int Squad::push(ISpaceMarine *new_marine)
{
	std::cout << "[PUSH] count: " << this->count << ", storage: " << this->storage << std::endl;
	ISpaceMarine **temp;
	ISpaceMarine **temp2;
	temp = new ISpaceMarine* [this->count + 1];
	for (int i = 0; i < this->count; i++)
	{
		temp[i] = this->storage[i];
	}
	temp[this->count] = new_marine;
	this->count += 1;
	temp2 = this->storage;
	this->storage = temp;
	if (temp2 != nullptr)
		delete temp2;
	return this->count;
}

