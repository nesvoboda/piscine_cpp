/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:07:59 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/10 21:06:11 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>

template <typename T>
int	easyfind(T cont, int needle)
{
	typename T::iterator i;
	i = std::find(cont.begin(), cont.end(), needle);
	if (i == cont.end())
		throw std::exception();
	return (*i);
}

#endif