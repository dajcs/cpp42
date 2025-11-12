/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:14:07 by anemet            #+#    #+#             */
/*   Updated: 2025/11/12 16:23:01 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream> // std::cout, std::cerr

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	// create an instance of the RPN class
	RPN calculator;

	try
	{
		calculator.evaluate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << '\n';
		// std::cerr << e.what() << '\n';  // print error messages from RPN.cpp
		return 1;
	}
	return 0;
}
