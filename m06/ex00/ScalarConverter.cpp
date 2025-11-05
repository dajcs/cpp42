/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:09:18 by anemet            #+#    #+#             */
/*   Updated: 2025/11/05 15:56:45 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>	// std::cout
#include <string>	// std::string
#include <cstdlib>	// strtod (string to double)
#include <cctype>	// isprint
#include <limits>	// numeric_limits<char/int/...>min/max values
#include <cmath>	// isnan, isinf
#include <iomanip>	// std::fixed, std::setprecision

// --- Helper Functions (Private to this file via anonymous namespace) ---
// An anonymous namespace makes its contents visible only within this specific file.
// This is a C++ way to create private helper functions without polluting the global scope
namespace
{
	// Function to print the results for all four types
	void printValues(char c, int i, float f, double d, bool charPossible, bool intPossible)
	{
		// Print char
		if (!charPossible)
		{
			std::cout << "char: impossible" << std::endl;
		}
		else if (!isprint(c))
		{
			std::cout << "char: Non displayable" << std::endl;
		}
		else
		{
			std::cout << "char: '" << c << "'" << std::endl;
		}

		// Print int
		if (!intPossible)
		{
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			std::cout << "int: " << i << std::endl;
		}

		// Print float and double
		// std::fixed and std::setprecision(1) are used to ensure that
		// even whole numbers are printed with one decima place (e.g., 42.0f)
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}


	// Function to detect if the string literal is a char
	bool isChar(const std::string& literal)
	{
		return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
	}


	/*
	// Function to detect if the string literal is an int
	bool isInt(const std::string& literal)
	{
		size_t i = 0;
		if (literal[i] == '+' || literal[i] == '-')
		{
			i++;
		}
		if (i == literal.length()) return false; // string is only "+" or "-"
		for(; i< literal.length(); ++i)
		{
			if (!isdigit(literal[i])) return false;
		}
		return true;
	}


	// Function to detect if the string literal is a double
	bool isDouble(const std::string& literal)
	{
		// Handle special double cases
		if (literal == "nan" || literal == "+inf" || literal == "-inf")
			return true;
		// Must contain a '.' but not end with 'f'
		return literal.find('.') != std::string::npos;
	}
	*/
}


// --- Public method implementation ---
void ScalarConverter::convert(const std::string& literal)
{
	// --- 1. Detect Type and Convert from String ---

	// Handle empty input
	if (literal.empty())
	{
		std::cout << "Error: Empty input." << std::endl;
		return;
	}

	// Use strtod for initial conversion because it can parse doubles, floats
	// and special values.
	// We convert the std::string to a C-style string (char *) using .c_str() for strtod.
	char* endptr = NULL;
	double d = std::strtod(literal.c_str(), &endptr);

	// Check for parsing errors. If endptr is not at the end of the string
	// (and the rest isn't just an 'f' for a float), then it's an invalid input.
	// This single check robustly handles invalid inputs like "42a", "++42", etc.
	if (*endptr != '\0' && (*endptr != 'f' || *(endptr + 1) != '\0'))
	{
		if (!isChar(literal)) // Allow valid char literals like 'a'
		{
			std::cout << "Error: Invalid input format." << std::endl;
			return;
		}
	}

	// Handle char type separately because strtod can't parse it
	if (isChar(literal))
	{
		d = literal[1]; // Get the character value;
	}

	// --- 2. Perform Explicit Conversions to Other Types ---

	// Convert from double to other types using static_cast
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	// --- 3. Check for Impossibility and Overflow ---

	// A conversion  to char is possible only if the double value is not a special case
	// and if it falls within the range of a char.
	bool charPossible = !std::isnan(d) && !std::isinf(d) &&
										d >= std::numeric_limits<char>::min() &&
										d <= std::numeric_limits<char>::max();

	// A conversion to int is possible only if the double value is not a special case
	// and if it falls within the range of an int
	bool intPossible = !std::isnan(d) && !std::isinf(d) &&
										d >= std::numeric_limits<int>::min() &&
										d <= std::numeric_limits<int>::max();

	// --- 4. Print the final results
	printValues(c, i, f, d, charPossible, intPossible);
}
