/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:28:45 by anemet            #+#    #+#             */
/*   Updated: 2025/10/21 19:58:31 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
	// Instantiate the PhoneBook class.
	PhoneBook phonebook;  // phonebook is now an object
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		// Read the whole line to handle potential extra spaces
		std::getline(std::cin, command);

		// Convert the command to uppercase
		for (size_t i = 0; i < command.length(); ++i)
		{
			command[i] = toupper(command[i]);
		}

		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
			break;
		// any other command is ignore and the loop continues
	}
	return 0;
}
