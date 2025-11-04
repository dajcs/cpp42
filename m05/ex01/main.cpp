/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:59:06 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 11:09:34 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	// --- TC1: Creating a form with a grade too high ---
	std::cout << "--- Test 1: Form Grade Too High on Construction ---" << std::endl;
	try
	{
		Form f("F1", 0, 150);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	// --- TC2: Creating a form with a grade too low
	std::cout << "--- Test 2: Form Grade Too Low on Construction ---" << std::endl;
	try
	{
		Form f("F2", 151, 150);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	// --- TC3: Bureaucrat successfully signs a form ---
	std::cout << "--- Test 3: Successful Signing ---" << std::endl;
	try
	{
		Bureaucrat signer("Alice", 40);
		Form taxForm("Tax Form C42", 50, 20);
		std::cout << signer << std::endl;
		std::cout << taxForm << std::endl;
		signer.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught unexpected exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	// --- TC4: Bureaucrat faisl to sign a form (grade too low) ---
	std::cout << "--- Test 4: Failed Signing (Grade Too Low) ---" << std::endl;
	try
	{
		Bureaucrat intern("Bob", 140);
		Form topSecret("Top Secret Document", 10, 1);
		std::cout << intern << std::endl;
		std::cout << topSecret << std::endl;
		intern.signForm(topSecret); // Intern's grade 140 is > required 10
		std::cout << topSecret << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught unexpected exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	// --- TC5: Bureaucrat with exact required grade signs form ---
	std::cout << "--- Test 5: Edge Case - Exact Grade Signing ---" << std::endl;
	try
	{
		Bureaucrat manager("Carol", 75);
		Form expenseReport("Expense Report", 75, 50);
		std::cout << manager << std::endl;
		std::cout << expenseReport << std::endl;
		manager.signForm(expenseReport);
		std::cout << expenseReport << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught unexpected exception: " << e.what() << '\n';
	}
	std::cout << std::endl;



	return 0;
}
