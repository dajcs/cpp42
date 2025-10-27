/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:46:54 by anemet            #+#    #+#             */
/*   Updated: 2025/10/27 19:45:39 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	// create an instance of Fixed called 'a' calling the default constructor
	// std::cout << "Fixed a;" << std::endl;
	Fixed a;
	// std::cout << "---\n" << std::endl;

	// create another instance 'b' as a copy of 'a' with copy constructor
	// std::cout << "Fixed b(a);" << std::endl;
	Fixed b(a);
	// std::cout << "---\n" << std::endl;

	// create a third instance 'c' with default constructor
	// std::cout << "Fixed c;" << std::endl;
	Fixed c;
	// std::cout << "---\n" << std::endl;

	// Assign the value of 'b' to 'c'
	// the copy assignment operator is called here
	// std::cout << "c = b;" << std::endl;
	c = b;
	// std::cout << "---\n" << std::endl;

	// Print the raw bits of each object to the console
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
	// Destructors for a, b, c are called automatically here as they
	// go out of scope in the reverse order of their creation
}
