/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:59:06 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 20:00:36 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Seed for RobotomyRequestForm's randomness
	srand(time(NULL));

	// Create some bureaucrats
	Bureaucrat highGrade("Alice", 1);
	Bureaucrat midGrade("Bob", 50);
	Bureaucrat lowGrade("Charlie", 150);

	// Create the three types of forms
	ShrubberyCreationForm shrubForm("garden");
	RobotomyRequestForm roboForm("Bender");
	PresidentialPardonForm pardonForm("Ford Prefect");

	std::cout << "--- Shrubbery Creation Form Tests ---" << std::endl;
	std::cout << highGrade << std::endl;
	std::cout << midGrade << std::endl;
	std::cout << lowGrade << "\n" << std::endl;
	std::cout << shrubForm << "\n" << std::endl;
	midGrade.executeForm(shrubForm); // Fails - not signed
	lowGrade.signForm(shrubForm); // Fails (grade 150 vs 145)
	highGrade.signForm(shrubForm); // Succeeds
	lowGrade.executeForm(shrubForm); // Fails (grade 150 vs 137)
	highGrade.executeForm(shrubForm); // Succeeds
	std::cout << std::endl;

	std::cout << "--- Robotomy Request Form Tests ---" << std::endl;
	std::cout << midGrade << std::endl;
	std::cout << roboForm << std::endl;
	midGrade.executeForm(roboForm); // Fails (not signed)
	midGrade.signForm(roboForm); // Succeeds (grade 50 vs 72)
	midGrade.executeForm(roboForm); // Fails (grade 50 vs 45)
	highGrade.executeForm(roboForm); // Succeeds
	std::cout << std::endl;

	std::cout << "--- Presidential Pardon Form Tests ---" << std::endl;
	std::cout << highGrade << std::endl;
	std::cout << pardonForm << std::endl;
	highGrade.signForm(pardonForm); // Succeeds
	midGrade.executeForm(pardonForm); // Fails (grade 50 vs 5)
	highGrade.executeForm(pardonForm); // Succeeds
	std::cout << std::endl;

	return 0;
}
