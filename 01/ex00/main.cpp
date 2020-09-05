/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:28:11 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/04 17:47:43 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

// ponyOnTheStack will create a Pony on a stack
void	ponyOnTheStack(void)
{
	Pony stackPony;
	Pony *pointerToStackPony;

	pointerToStackPony = &stackPony;

	std::cout << "Address of stackPony is: " << pointerToStackPony
	<< std::endl;
	stackPony.neigh();
}

// ponyOnTheHeap will create a 
// dynamically allocated pony
void	ponyOnTheHeap(void)
{
	Pony *heapPony = new Pony;

	std::cout << "Address of heapPony is: " << heapPony
	<< std::endl;
	heapPony->neigh();
	delete heapPony;
	std::cout << "Heap pony will not exist by this point" << std::endl;
}

int main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	std::cout << "Stack pony will not exist by this point" << std::endl;
}