/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:48:13 by anemet            #+#    #+#             */
/*   Updated: 2025/10/21 20:00:17 by anemet           ###   ########.fr       */
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
	std::cout << "Welcome to the Awesome PhoneBook!" << std::endl;
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
	this->contacts[this->addIndex].setFirstName(getInput("Enter Frist Name: "));
	this->contacts[this->addIndex].setLastName(getInput("Enter Last Name: "));
	this->contacts[this->addIndex].setNickName(getInput("Enter NickName: "));
	this->contacts[this->addIndex].setPhoneNumber(getInput("Enter Phone Number: "));
	this->contacts[this->addIndex].setDarkestSecret(getInput("Enter Darkest Secret: "));

	// Logic to replace the oldest contact
	this->addIndex = (this->addIndex +1) % 8;

	// Increment total contacts, but cap it at 8
	if (this->contactCount < 8)
		this->contactCount++;
	std::cout << "Contact added successfully!" << std::endl;
}

// Private helper function to format and print a string for the search table
static void printColumn(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0,9) << ".";   // truncate and add a dot
	else
		std::cout << std::right << std::setw(10) << str; // right align in a 10-char wide column
}

void PhoneBook::searchContacts(void)
{
	if (this->contactCount == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}

	// Print header
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| NickName |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	// Print contacts
	for (int i = 0; i < this->contactCount; i++)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i;
		std::cout << "|";
		printColumn(this->contacts[i].getFirstName());
		std::cout << "|";
		printColumn(this->contacts[i].getLastName());
		std::cout << "|";
		printColumn(this->contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	// Prompt for index
	std::cout << "Enter the index of the contact to display: ";
	std::string input;
	std::getline(std::cin, input);

	// Validate input
	if (input.length() == 1 && input[0] >= '0' && input[0] < ('0' + this->contactCount))
	{
		int index = input[0] - '0';  // convert entered char index to int
		std::cout << "First Name:     " << this->contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name:      " << this->contacts[index].getLastName() << std::endl;
		std::cout << "NickName:       " << this->contacts[index].getNickName() << std::endl;
		std::cout << "Phone Number:   " << this->contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "Invalid index." << std::endl;
}
