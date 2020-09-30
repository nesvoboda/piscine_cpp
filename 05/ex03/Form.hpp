/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:02:12 by ashishae          #+#    #+#             */
/*   Updated: 2020/09/29 19:58:21 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form {

public:
	Form(std::string name, unsigned int gradeToSign,
			unsigned int gradeToExecute);
	virtual ~Form();
	Form(const Form &copy);
	Form &operator= (const Form &operand);

	std::string getName() const;
	bool getIsSigned() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;

	virtual void execute(Bureaucrat const &executor) const = 0;

	void beSigned(Bureaucrat &b);

	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class FormNotSignedException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

private:
	Form();
	const std::string	name;
	const unsigned int	gradeToSign;
	const unsigned int	gradeToExecute;
	bool				isSigned;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif