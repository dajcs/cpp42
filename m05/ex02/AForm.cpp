/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:14:17 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 14:09:23 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
// #include "Bureaucrat.hpp" // already included in AForm.hpp

// --- Orthodox Canonical Form ---

// Default Constructor
// The const members are initialized in the initializer list
AForm::AForm() : _name("Default"), _target("Default"), _isSigned(false),
												_gradeToSign(150), _gradeToExecute(150) {}

// Parametrized Constructor
// Initializes form with given parameters
// Checks if the grades are valid before assigning them
AForm::AForm(const std::string& name, const std::string& target,
													int gradeToSign, int gradeToExecute) :
	_name(name), _target(target), _isSigned(false),
								_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1) throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150) throw AForm::GradeTooLowException();
}

// Copy Constructor
// The const members are initialized from `other` and then invoking the Copy Assignment Operator
AForm::AForm(const AForm& other) :
	_name(other._name), _target(other._target),
						_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

// Copy Assignment Operator
// We can only copy the _isSigned status, as the other members are const
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other) this->_isSigned = other._isSigned;
	return *this;
}

// Destructor
/*
	A base class destructor must be virtual.
	If deleting a derived class object through a base class pointer and the destructor
	is not virtual, only the base class destructor is called, leading to resource leaks.
*/
AForm::~AForm() {}


// --- Getters ---

const std::string& AForm::getName() const { return this->_name; }
const std::string& AForm::getTarget() const { return this->_target; }
bool AForm::getIsSigned() const { return this->_isSigned; }
int AForm::getGradeToSign() const { return this->_gradeToSign; }
int AForm::getGradeToExecute() const { return this->_gradeToExecute; }


// --- Member Functions ---

/* beSigned()
	Changes the AForm's status to signed if the bureaucrat's grade is high enough.
	A lower grade number means a higher rank.
	If the bureaucrat's grade is too low (higher number), it throws an exception.
*/
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign) { throw AForm::GradeTooLowException(); }
	this->_isSigned = true;
}

/* execute() - the "elegant" way
	We check all common requirements here.
	If they are met, we call the specific action
	implemented by concrete derived classes.
*/
void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned()) throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute()) throw AForm::GradeTooLowException();
	this->performAction();
}

// --- Exception Implementations ---
// throw() is an exception specification
const char* AForm::GradeTooHighException::what() const throw() { return "AForm grade is too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Form grade is too low!"; }
const char* AForm::FormNotSignedException::what() const throw() { return "Form is not signed!"; }

// --- Operator Overload Implementation ---

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName()
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Target: " << form.getTarget()
		<< ", Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}
