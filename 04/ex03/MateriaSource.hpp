/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:58:35 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/06 12:17:00 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *localMateria;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource &operator= (const MateriaSource &operand);
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif