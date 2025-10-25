/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:23:18 by anemet            #+#    #+#             */
/*   Updated: 2025/10/25 13:41:18 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>
#include <stdexcept> // To catch the exceptions thrown by FileReplacer.cpp

int main(int argc, char **argv)
{
	// --- Input Validation ---
	if (argc != 4)
	{
		// Using std::cerr for error messsages
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		std::cerr << "Usage: ./replace <filename> <string_to_find> <string_to_replace>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// --- Edge Case Handling ---
	if (s1.empty())
	{
		std::cerr << "Error: The string to find cannot be empty." << std::endl;
		return 1;
	}

	/* C++ try...catch
		We "try" to run code that might throw an exception.
		If an exception is thrown anywhere inside the `try` block
		(e.g., from our `replace` method), the program jumps to `catch` block
	*/
	try
	{
		FileReplacer replacer(filename, s1, s2);
		replacer.replace();
		// get replace count
		size_t count = replacer.getReplacementCount();
		std::cout << "Replaced " << count << " occurences in " << filename << std::endl;
		std::cout << "Output is saved in " << filename << ".replace" << std::endl;
	}
	catch(const std::exception& e)
	{
		// `e.what()` returns the error message we passed to `std::runtime_error`
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
