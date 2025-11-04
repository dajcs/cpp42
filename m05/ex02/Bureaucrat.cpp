/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:32:47 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 15:08:56 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp" // to access Form's methods

// --- Orthodox Canonical Form ---

// Default Constructor (no parameters given)
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

// Parametrized Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	*this = other;
}

// Copy Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}


// --- Getters ---
const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}


// --- Member Functions
void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

/* signForm() (NEW)
	Attempts to sign a form. It calls the form's be Signed method.
	Wrapping this call in a try-catch block to handle both success and failure
*/
void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " coudn't sign " << form.getName()
		<< " because " << e.what() << '\n';
	}

}

/* executeForm() (NEWer)
	Attempts to execute a form. It calls the form's execute method
	and reports success or failure based on whether an exception was thrown.
*/
void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName()
		<< " because " << e.what() << '\n';
	}

}



// --- Exception Implementation
// Defining Custom Messages for our Exceptions
// 'throw()' is an exception specification, indicating this function won't throw any exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}


// --- Insertion Operator Overload Implementation ---
/*
	it takes an output stream (like std::cout) and a Bureaucrat object,
	formats the string as required, and inserts it into the stream
*/
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}


