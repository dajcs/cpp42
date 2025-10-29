/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:30:04 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 05:49:44 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	// 'a' created wit default constructor, value is 0
	Fixed a;

	/* the happenings in this line:
		1. Fixed(5.05f) creates a temporary Fixed object from a float
		2. Fixed(2) creates a temporary Fixed object from an int.
		3. The '*' operator is called: Fixed(5.05f).operator*(Fixed(2))
			this returns another temp Fixed object with the result of (10.1016...)
		4. 'b' is constructed from this result using the copy constructor
			'b' is 'const', meaning it cannot be changed after initialization
	*/
	Fixed const b( Fixed(5.05f) * Fixed(2) );

	// prints the initial value of a (0).
	std::cout << a << std::endl; // -> 0
	// Prefix increment: a is incremented, and the NEW value is printed.
	// The smallest possible increment is 1 on the raw value, which is 1/256 = 0.00390625
	std::cout << ++a << std::endl; // -> 0.00390625
	// Print the current value of a (now 0.00390625)
	std::cout << a << std::endl; // -> 0.00390625
	// Postfix increment: the OLD value of a is printed (0.00390625), THEN a is incremented
	std::cout << a++ << std::endl; // -> 0.00390625
	// Prints the value of a after the postfix increment (0.0078125)
	std::cout << a << std::endl; // -> 0.0078125

	// Prints the value of b
	std::cout << b << std::endl;

	// Calls the static max function to find the larger of a and b
	// Because 'b' is const, this will call the 'const' version of Fixed::max
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "\n ----------  x and y  ------------\n" << std::endl;

	Fixed x(-3.3f);
	std::cout << "x = " << x << std::endl;

	Fixed y(-3);
	std::cout << "y = " << y << std::endl;

	Fixed z = x * y;
	std::cout << "z = x * y = " << z << "\n" << std::endl;
	return 0;
}
