/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:28:11 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/24 13:38:29 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

// createStackPony will create a Pony on a stack
// and try to return its address
Pony *createStackPony(void)
{
	Pony stackPony;
	return &stackPony;
}

// createStackPony will create a 
// dynamically allocated pony
Pony *createHeapPony(void)
{
	Pony *heapPony = new Pony;
	return heapPony;
}

int main(void)
{
	Pony *heapPony = createHeapPony();
	std::cout << "Address of heapPony is: " << heapPony
	<< std::endl;
	delete heapPony;

	Pony *pointerToStackPony = createStackPony();
	// pointerToStackPony = &stackPony;
	std::cout << "Address of stackPony is: " << pointerToStackPony
	<< std::endl;
}