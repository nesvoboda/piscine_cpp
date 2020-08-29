/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:06:09 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/27 16:21:23 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string sentence = "HI THIS IS BRAIN";

	std::string *pointer;

	pointer = &sentence;

	std::cout << "Here's the string by pointer: " << *pointer << std::endl;

	std::string &reference = sentence;

	std::cout << "Here's the string by reference: " << reference << std::endl;
	return 0;
}