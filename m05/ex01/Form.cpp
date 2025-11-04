/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:14:17 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 10:46:02 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp" // to access Bureaucrat's methods

// --- Orthodox Canonical Form ---

// Default Constructor
// The const members are initialized in the initializer list
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// Parametrized Constructor
// Initializes form with given parameters
// Checks if the grades are valid before assigning them
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

// Copy Constructor
// The const members are initialized from `other` and then invoking the Copy Assignment Operator
Form::Form(const Form& other) :
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

// Copy Assignment Operator
// We can only copy the _isSigned status, as the other members are const
Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

// Destructor
Form::~Form() {}


// --- Getters ---

const std::string& Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}


// --- Member Functions ---

/* beSigned()
	Changes the form's status to signed if the bureaucrat's grade is high enough.
	A lower grade number means a higher rank.
	If the bureaucrat's grade is too low (higher number), it throws an exception.
*/
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	this->_isSigned = true;
}

// --- Exception Implementations ---
// throw() is an exception specification
const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}


// --- Operator Overload Implementation ---

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName()
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}
