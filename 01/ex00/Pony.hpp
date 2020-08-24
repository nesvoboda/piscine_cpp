/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:28:11 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/24 13:21:38 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

class Pony {

public:
	int height;
	int weight;

	static int poniesCounter;
	void clipClop(void);
	void neigh(void);
	Pony(void);
	~Pony(void);

private:

	int clipClopCounter;
	int neighCounter;

};

#endif