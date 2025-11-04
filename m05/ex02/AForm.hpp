/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:55:33 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 13:57:36 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

// Forward declaration to prevent circular dependency
// class Bureaucrat;

/*
	Forward declaration of Bureaucrat is no longer sufficient,
	as we now call its methods in the AForm::execute function.
	So, we included the full header "Bureaucrat.hpp"
*/



class AForm
{
	private:
		const std::string	_name;
		const std::string	_target;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// --- Orthodox Canonical Form ---
		AForm();
		AForm(const std::string& name, const std::string& target,
										 int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		// Destructor
		/*
			A base class destructor must be virtual.
			If deleting a derived class object through a base class pointer and the destructor
			is not virtual, only the base class destructor is called, leading to resource leaks.
		*/
		virtual ~AForm();

		// --- Getters ---
		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		// --- Member Functions ---
		void	beSigned(const Bureaucrat& bureaucrat);
		void	execute(Bureaucrat const & executor) const;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		// --- Pure Virtual Function ---
		/*
			This function is "pure virtual" (=0).
			It forces any concrete subclass to implement it.
			It also makes AForm an "abstract class", which cannot be instantiated
		*/
		virtual void performAction() const = 0;
};


/* Insertion Operator (<<) Overloading
	How to handle the '<<' operator, when a AForm object is on the right-hand side.
	This allows us the write 'std::cout << myAForm;'
	It is declared outside the class as it takes an 'ostream' as its left-hand parameter.
*/
std::ostream& operator<<(std::ostream& os, const AForm& form);



#endif
