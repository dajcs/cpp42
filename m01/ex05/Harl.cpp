/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:44:17 by anemet            #+#    #+#             */
/*   Updated: 2025/10/25 16:09:10 by anemet           ###   ########.fr       */
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

void Harl::debug(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}
void Harl::debug(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}
void Harl::debug(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}


// --- Public Member Function ---

void Harl::complain(std::string level)
{
	/* C++ Pointers to Member Functions
		1. Declaration Syntax:
			`return_type (ClassName::*pointer_name)(arguments);`
			here
			`void (Harl::*...)(void)` means a pointer to a member function of
				the Harl class that returns void and takes no arguments
		2. Assignment Syntax: `&ClassName::functionName`
			We take the address of the member function
	*/

	// The array of strings representing the complaint levels
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	// The parallele array of pointers to the corresponding member functions.
	void (Harl::*functions[])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	// Loop through the levels to find a match
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			/* C++ Calling via Pointer to Member Function
				3. Calling Syntax:
					`(object_pointer->*function_pointer)();`
					or
					`(object.*function_pointer)();

				`this` is a pointer to the current object instance.
				The '->*' operator is the "pointer-to-member" operator
				It tells the compiler to call the function pointed to by `functions[i]`
				on the object pointed to by `this`
				The parentheses `(this->*functions[i])` are crucial due to operator precedence
			*/
			(this->*functions[i])();
			return; // Exit after finding and executing the command
		}
	}
	// if no match was found after the loop
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	std::cout << std::endl;
}
