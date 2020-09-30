/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:55:34 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/29 20:17:12 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {

public:
	Intern();
	~Intern();
	Intern(const Intern &copy);
	Intern &operator= (const Intern &operand);

	Form *makeForm(std::string label, std::string target);

private:
	// I've made these arrays static, because they're supposed to stay the same
	// for all interns, and it's logical to change them in one place rather
	// than in all constructors etc...

	// Also, I've made them constant, because it doesn't make any sense to change
	// them in runtime. This has made the type declaration quite cryptic
	// for functions.

	static const std::string labels[3];
	static Form *(* const functions[3])(std::string);
};

#endif