/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:13:23 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 15:01:48 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

// Forward declaratioin for Form class to avoid circular dependencies
class AForm;

class Bureaucrat
{
	private:
		const std::string 	_name;
		int 				_grade;

	public:
		// --- Orthodox Canonical Form
		Bureaucrat(); // Default Constructor
		Bureaucrat(const std::string& name, int grade); // Parameterized Constructor
		Bureaucrat(const Bureaucrat& other); // Copy Constructor
		Bureaucrat& operator=(const Bureaucrat& other); // Copy Assignment Operator
		~Bureaucrat(); // Destructor

		// --- Getters ---
		const std::string&	getName() const;
		int					getGrade() const;

		// --- Member functions ---
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form) const;
		void executeForm(AForm const & form) const; // New function

		// --- Custom Exception Classes ---
		/*
			Defining our own exception classes that inherit from std::exception
			Exceptions can be caught by a generic 'char(std::exception& e)' block.
			The what() method is virtual in std::exception, and we override it
			to provide our own custom message.
		*/
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};


/* Insertion Operator (<<) Overloading
	How to handle the '<<' operator, when a Bureaucrat object is on the right-hand side.
	This allows us the write 'std::cout << myBureaucrat;'
	It is declared outside the class as it takes an 'ostream' as its left-hand parameter.
*/
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
