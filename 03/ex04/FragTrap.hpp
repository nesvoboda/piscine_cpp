/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:40:22 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/31 14:48:27 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include "ClapTrap.hpp"


class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	FragTrap &operator= (const FragTrap &operand);
	~FragTrap();
	void	vaulthunter_dot_exe(std::string const & target);

};

#endif