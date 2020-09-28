/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:44:07 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/16 19:15:14 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() : storage(nullptr), count(0)
{
}

Squad::Squad(const Squad &copy)
{
	this->storage = new ISpaceMarine* [copy.count];
	for (int i = 0; i < copy.count; i++)
	{
		this->storage[i] = copy.storage[i]->clone();
	}
	this->count = copy.count;
}

Squad & Squad::operator= (const Squad &operand)
{
	if (this->count != 0)
	{
		for (int i = 0; i < this->count; i++)
		{
			delete this->storage[i];
		}
		
	}
	delete [] this->storage;
	this->storage = nullptr;
	this->storage = new ISpaceMarine* [operand.count];
	for (int i = 0; i < operand.count; i++)
	{
		this->storage[i] = operand.storage[i]->clone();
	}
	this->count = operand.count;
	return (*this);
}

Squad::~Squad()
{
	for (int i = 0; i < this->count; i++)
	{
		delete this->storage[i];
	}
	delete [] storage;
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
		delete [] temp2;
	return this->count;
}

