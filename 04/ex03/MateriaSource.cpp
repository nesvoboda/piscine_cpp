/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/24 19:01:18 by ashishae         ###   ########.fr       */
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

// So, this is the way I decided to approach the problem of createMateria.
//
// Our goals are:
// - create an object of type corresponding to the parameter
// - transfer XP from learned Materia to the new object.
//
// I found two ways to accomplish this:
//
// 1) Add setters of type and xp, as well as a default constructor,
//		to AMateria. Pros: lets you create Materia of arbitrary type.
//		Cons: modifies the abstract class significantly
// 2) Use the assignment operator (that transfers the xp) on an object 
//		of known type. Pros: uses the abstract class fully. Cons:
//		Type of Materia has to be reflected in this function.
//
// I've selected the second way, as it seemed to give me more opportunity
// to learn new things.

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