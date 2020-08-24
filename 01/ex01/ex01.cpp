/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 13:38:58 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/24 13:48:46 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <unistd.h>


// In this example, the string panther is allocated
// on the heap using the keyword 'new'.
// However, this object is not destructed, and the
// memory used is not freed, causing a memory leak.
void	memoryLeak()
{
	std::string	*panther = new std::string("String panther");

	std::cout << *panther << std::endl;
}


// Here, panther is still allocated on the heap,
// however, it is explicitly deleted using the keyword
// 'delete', so, there is no memory leak.
void	noMemoryLeak1()
{
	std::string	*panther = new std::string("String panther");

	std::cout << *panther << std::endl;

	delete panther;
}

// And here, panther is allocated on the stack.
// No memory allocation, no memory leaks.
// Simple life!
void	noMemoryLeak2()
{
	std::string	panther = std::string("String panther");

	std::cout << panther << std::endl;
}


// Try running both leak-free versions and check them
// with 'leaks' on Mac OS or 'valgrind' on Linux
int		main(void)
{
	// memoryLeak();
	// noMemoryLeak1();
	noMemoryLeak2();
	sleep(50);

	return 0;
}