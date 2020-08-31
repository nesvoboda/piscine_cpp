/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:39:09 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/31 12:49:34 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator= (const ScavTrap &operand);
	~ScavTrap();
	void	challengeNewcomer(std::string const & target);
};


#endif

