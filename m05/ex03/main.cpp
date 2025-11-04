/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:59:06 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 22:18:05 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Seed for RobotomyRequestForm's randomness
	srand(time(NULL));

	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);
	AForm* createdForm = NULL;

	// --- Test 1: Create RobotomyRequestForm ---
	std::cout << "--- Test1: Create Robotomy Request ---" << std::endl;
	try
	{
		createdForm = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *createdForm << std::endl;
		boss.signForm(*createdForm);
		boss.executeForm(*createdForm);
		// clean up the memory allocated by the intern
		delete createdForm;
		createdForm = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
		// If creation failed, createdForm is still NULL, so no delete needed
	}
	std::cout << std::endl;


	// --- Test 2: Create ShrubberyCreationForm ---
	std::cout << "--- Test 2: Create Shrubbery Creation---" << std::endl;
	try
	{
		createdForm = someRandomIntern.makeForm("shrubbery creation", "home");
		std::cout << *createdForm << std::endl;
		boss.signForm(*createdForm);
		boss.executeForm(*createdForm);

		delete createdForm;
		createdForm = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	std::cout << std::endl;


	// --- Test 3: Create PresidentialPardonForm ---
	std::cout << "--- Test 3: Create Presidential Pardon ---" << std::endl;
	try
	{
		createdForm = someRandomIntern.makeForm("presidential pardon", "Marvin");
		std::cout << *createdForm << std::endl;
		boss.signForm(*createdForm);
		boss.executeForm(*createdForm);

		delete createdForm;
		createdForm = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	std::cout << std::endl;


	// --- Test 4: Attempt to create a non-existent form ---
	std::cout << "--- Test 4: Trying to Create Unknown Form ---" << std::endl;
	try
	{
		// This should throw an exception
		createdForm = someRandomIntern.makeForm("resignation letter", "myself");
		// This should not be reached
		std::cout <<"This should not be printed." << std::endl;
		delete createdForm;
		createdForm = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Catching expected exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	return 0;
}
