/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:41:39 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/05 21:46:37 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <stdlib.h>  

class Base {

public:
	// Base();
	virtual ~Base();
	// Base(const Base &copy);
	// Base &operator= (const Base &operand);
	Base * generate(void);

private:

};

#endif