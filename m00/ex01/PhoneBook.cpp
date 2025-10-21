/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:48:13 by anemet            #+#    #+#             */
/*   Updated: 2025/10/21 16:01:25 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // std::cout, std::cin
#include <iomanip>	// std::setw, std::right
#include "PhoneBook.hpp"

// Constructor implementation
PhoneBook::PhoneBook(void)
{
	// Initialize indices when a PhoneBook object is created
	this->addIndex = 0;
	this->contactCount = 0;
	std::cout << "Welcome the the Awesome PhoneBook!" << std::endl;
}

// Private helper function to read non-empty input from the user
static std::string getInput(std::string prompt)
{
	std::string input = "";
	while (input.empty())
	{
		std::cout << prompt;
		// std::getline reads an entire line of text from std::cin
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Field cannot be empty. Please try again." << std::endl;
		}
	}
	return input;
}

void PhoneBook::addContact(void)
{
	// Use the private helper to get user input for each field
}
