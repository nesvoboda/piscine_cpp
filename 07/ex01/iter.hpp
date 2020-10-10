/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:29:00 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/10 15:36:50 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// We'll define a normal and a const version just in case

template <typename T>
void	iter(T array[], unsigned int len, void (*function)(T &))
{
	for (unsigned int i = 0; i < len; i++)
	{
		function(array[i]);
	}
}

template <typename T>
void	iter(T array[], unsigned int len, void (*function)(T const &))
{
	for (unsigned int i = 0; i < len; i++)
	{
		function(array[i]);
	}
}