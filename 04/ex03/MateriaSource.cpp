/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/16 19:59:41 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource() : localMateria(nullptr)
{
}

MateriaSource::MateriaSource(const MateriaSource &copy) :
	localMateria(copy.localMateria)
{
	// copy materias
}

MateriaSource &MateriaSource::operator= (const MateriaSource &operand)
{
	this->localMateria = operand.localMateria;
	return (*this);
}

MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria *input)
{
	this->localMateria = input;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (this->localMateria == nullptr)
		return nullptr;
	if (type == "")
		return nullptr;
	AMateria *tmp = this->localMateria->clone();
	tmp->setType(type);
	return tmp;
}