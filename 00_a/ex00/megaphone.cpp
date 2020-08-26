/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:07:21 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/10 17:43:10 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void shout(char *word)
{
	char c;

	for (int i = 0; word[i]; i++)
	{
		if (word[i] >= 'a' && word[i] <= 'z')
		{
			c = word[i] - 32;
			std::cout << c;
		}
		else
		{
			std::cout << word[i];
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		shout(av[i]);
	}
	std::cout << "\n";
	return 0;
}