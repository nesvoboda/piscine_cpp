/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:15:09 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/31 14:52:05 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include "ClapTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap(std::string name);
	SuperTrap(const SuperTrap &copy);
	SuperTrap &operator= (const SuperTrap &operand);
	~SuperTrap();
	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
};


#endif