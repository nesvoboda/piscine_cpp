/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/28 12:22:03 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		this->localMateria[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for(int i = 0; i < 4; i++)
	{
		if (copy.localMateria[i] != nullptr)
		{
			this->localMateria[i] = copy.localMateria[i]->clone();
		}
		else
		{
			this->localMateria[i] = nullptr;
		}
	}
}

MateriaSource &MateriaSource::operator= (const MateriaSource &operand)
{
	// Free whatever we had
	for(int i = 0; i < 4; i++)
	{
		if (this->localMateria[i] != nullptr)
		{
			delete this->localMateria[i];
			this->localMateria[i] = nullptr;
		}
	}

	// Deep-copy everything from operand
	for(int i = 0; i < 4; i++)
	{
		if (operand.localMateria[i] != nullptr)
		{
			this->localMateria[i] = operand.localMateria[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	// Free whatever we had
	for(int i = 0; i < 4; i++)
	{
		if (this->localMateria[i] != nullptr)
		{
			delete this->localMateria[i];
			this->localMateria[i] = nullptr;
		}
	}
}

// Input is assumed to be allocated on the heap by the caller.
// The subject doesn't precise what to do if we try to learn the
// same type of materia twice.
// Moreover, it says that Materia stored in MateriaSource are not
// necessary unique.
// So I just store all of them.
void MateriaSource::learnMateria(AMateria *input)
{
	if (input == nullptr)
		return ;

	int i = 0;
	while (i < 4 && this->localMateria[i] != nullptr)
		i++;
	// Inverntory full
	if (i > 3)
		return;
	this->localMateria[i] = input;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	(void) type;
	while (i < 4)
	{
		if (this->localMateria[i] == nullptr)
			return nullptr;
		if (this->localMateria[i]->getType() == type)
			break;
		i++;
	}
		
	// Materia type unknown
	if (i == 4)
		return nullptr;
	return this->localMateria[i]->clone();
}