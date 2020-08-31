/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:51:54 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/31 14:48:21 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &copy);
	NinjaTrap &operator= (const NinjaTrap &operand);
	~NinjaTrap();
	void	ninjaShoebox(FragTrap &target);
	void	ninjaShoebox(ScavTrap &target);
	void	ninjaShoebox(NinjaTrap &target);

};

#endif