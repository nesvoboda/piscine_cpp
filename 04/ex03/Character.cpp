/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/24 18:50:07 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string future_name) :
	name(future_name)
{
	this->storage[0] = nullptr;
	this->storage[1] = nullptr;
	this->storage[2] = nullptr;
	this->storage[3] = nullptr;
}

Character::Character(const Character &copy)
{
	this->name = copy.name;
	for (int i = 0; i < 4; i++)
	{
		if (copy.storage[i])
			this->storage[i] = copy.storage[i]->clone();
		else
			this->storage[i] = nullptr;
	}
}

Character &Character::operator= (const Character &operand)
{
	this->name = operand.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->storage[i] != nullptr)
		{
			delete this->storage[i];
			this->storage[i] = nullptr;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (operand.storage[i] != nullptr)
		{
			this->storage[i] = operand.storage[i]->clone();
		}
		else
		{
			this->storage[i] = nullptr;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->storage[i] != nullptr)
		{
			delete this->storage[i];
			this->storage[i] = nullptr;
		}
	}
}

std::string const & Character::getName() const
{
	return this->name;
}

// M is assumed to be heap-allocated by the caller
void Character::equip(AMateria* m)
{
	if (m == nullptr)
	{
		return;
	}
		
	int i = 0;
	while (i < 4 && this->storage[i])
		i++;

	// No free slots
	if (i > 3)
		return;

	this->storage[i] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->storage[idx] == nullptr)
		return;
	this->storage[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->storage[idx] == nullptr)
		return;
	this->storage[idx]->use(target);
}
