/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:55:33 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 10:45:06 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

// Forward declaration to prevent circular dependency
class Bureaucrat;


class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// --- Orthodox Canonical Form ---
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// --- Getters ---
		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		// --- Member Functions ---
		void	beSigned(const Bureaucrat& bureaucrat);

		// --- Custom Exception Classes ---
		// our custom Exception class inherits from std::exception
		class GradeTooHighException : public std::exception
		{
			public:
				// the what() is virtual in std::exception
				// we're overriding it with our custom message
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


/* Insertion Operator (<<) Overloading
	How to handle the '<<' operator, when a Form object is on the right-hand side.
	This allows us the write 'std::cout << myForm;'
	It is declared outside the class as it takes an 'ostream' as its left-hand parameter.
*/
std::ostream& operator<<(std::ostream& os, const Form& form);









#endif
