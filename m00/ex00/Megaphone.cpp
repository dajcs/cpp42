/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:44:33 by anemet            #+#    #+#             */
/*   Updated: 2025/10/21 13:43:41 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // std::cout, std::endl
#include <cctype>	// toupper()

int main(int argc, char **argv)
{
	// Case 1: No arguments provided
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	// Case 2: One or more arguments are provided
	else
	{
		// loop through each argument
		// starting from 1 (0 is the program name)
		for (int i = 1; i < argc; ++i)
		{
			// Loop through each character
			for (int j = 0; argv[i][j] != '\0'; ++j)
			{
				// print the uppercase of the character
				std::cout << (char)toupper(argv[i][j]);
			}
		}
	}
	// print newline
	std::cout << std::endl;

	return 0;
}
