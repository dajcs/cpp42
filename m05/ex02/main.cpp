/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:59:06 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 15:23:13 by anemet           ###   ########.fr       */
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


	return 0;
}
