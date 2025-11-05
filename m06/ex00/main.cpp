/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:10:51 by anemet            #+#    #+#             */
/*   Updated: 2025/11/05 15:13:39 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		// std::cerr to print error messages
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1; // return non-zero to indicate error
	}

	// Call the static convert method from the ScalarConverter class
	ScalarConverter::convert(argv[1]);

	return 0;
}
