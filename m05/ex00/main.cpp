/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:59:06 by anemet            #+#    #+#             */
/*   Updated: 2025/11/03 21:33:27 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	// --- TC1: Creating a bureaucrat with a grade that is too high ---
	std::cout << "--- Test 1: Grade Too High on Construction ---" << std::endl;
	try
	{
		Bureaucrat high("Hyghflyer", 0); // Should throw GradeTooHighException
		std::cout << high << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- TC2: Creating a bureaucrat with a grade that is too low  ---
	std::cout << "--- Test 2: Grade Too Low on Construction ---" << std::endl;
	try
	{
		Bureaucrat low("Lowballer", 151); // Should throw GradeTooLowException
		std::cout << low << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- TC3: Creating a valid bureaucrat and printing it ---
	std::cout << "--- Test 3: Valid Bureaucrat ---" << std::endl;
	try
	{
		Bureaucrat valid("Vali D.", 75);
		std::cout << valid << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	// --- TC4: Incrementing a grade ---
	std::cout << "--- Test 4: Incrementing Grade ---" << std::endl;
	try
	{
		Bureaucrat b("Bob", 3);
		std::cout << "Initial: " << b << std::endl;
		b.incrementGrade(); // Grade becomes 2
		std::cout << "After increment: " << b << std::endl;
		b.incrementGrade(); // Grade becomes 2
		std::cout << "After another increment: " << b << std::endl;
		std::cout << "Trying the impossible increment..." << std::endl;
		b.incrementGrade(); // invalid increment
		std::cout << "After invalid increment: " << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	// --- TC5: Decrementing a grade ---
	std::cout << "--- Test 5: Decrementing Grade ---" << std::endl;
	try
	{
		Bureaucrat b("Bill", 148);
		std::cout << "Initial: " << b << std::endl;
		b.decrementGrade(); // Grade becomes 149
		std::cout << "After decrement: " << b << std::endl;
		b.decrementGrade(); // Grade becomes 150
		std::cout << "After another decrement: " << b << std::endl;
		std::cout << "Trying the impossible decrement..." << std::endl;
		b.decrementGrade(); // invalid increment
		std::cout << "After invalid decrement: " << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	// --- TC6: Copy constructor and assignment operator ---
	std::cout << "--- Test 6: Copy and Assignment ---" << std::endl;
	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original); // Copy Constructor
		Bureaucrat assigned;
		assigned = original; // Assignment operator

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std:: endl;
		std::cout << "Assigned: " << assigned << std::endl;

		// Modify original to show they are separate objects
		original.incrementGrade();
		std::cout << "Original after increment: " << original << std::endl;
		std::cout << "Copy should be unchanged: " << copy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}


	return 0;
}
