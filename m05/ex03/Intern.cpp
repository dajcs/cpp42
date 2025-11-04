/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:32:44 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 20:58:19 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// --- Orthodox Canonical Form ---
Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	// no member data
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other; // silence unused parameter warning
	return *this;
}

Intern::~Intern() {}


// --- Member Function ---

/* makeForm()
	This Function acts as a factory.
	It maps a string name to the creation of a specific form object.
	We use 'new' to allocate the form on the heap, returning a pointer.
	If the name doesn't match any known form, we throw an exception.
*/
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	AForm* form = NULL;

	// Array of form names for easy lookup
	const std::string formNames[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// Determine which form to create
	int formIndex = -1;
	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			formIndex = i;
			break;
		}
	}

	// Use a switch statement to create the correct form
	switch (formIndex)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			// If no match was found, throw our custom exception
			throw Intern::UnknownFormException();
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}

// --- Custom Exception Implementation ---
const char* Intern::UnknownFormException::what() const throw()
{
	return "Unknown form name requested";
}
