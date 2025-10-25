/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:44:17 by anemet            #+#    #+#             */
/*   Updated: 2025/10/25 22:02:38 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}


// --- Private Member Functions ---

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}
void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}
void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}


// --- Public Member Function --- with Switch Logic ---

void Harl::complain(std::string level)
{
	// An array of the possible level strings
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelIndex = -1; // Default to an invalid index

	// Loop to find the index corresponding to the input string
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			levelIndex = i;
			break;
		}
	}

	// C++ the `switch` statement
	// It evaluates the integer `levelIndex` and jumps to the matching case.
	switch (levelIndex)
	{
		// Case for DEBUG level (index 0)
		case 0:
			this->debug();
			/* fall through */

		// Case for INFO level (index 1)
		case 1:
			this->info();
			/* fall through */

		// Case for WARNING level (Index 2)
		case 2:
			this->warning();
			/* fall through */

		// Case for ERROR level (index 3)
		case 3:
			this->error();
			break;  // This break stops the fall-through

		// The 'default' case runs if levelIndex matches no other case (i.e. is -1)
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
