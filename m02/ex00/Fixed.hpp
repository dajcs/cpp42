/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:16:06 by anemet            #+#    #+#             */
/*   Updated: 2025/10/27 15:28:13 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/* Orthodox Canonical Form Class has:
	- A default constructor
	- A copy constructor
	- A copy assignment operator
	- A destructor
*/
class Fixed
{
	private:
		// an int to store the fixed-point number value
		int _fixedPointValue;
		// a static const int to store the number of fractional bits
		// `static const` means that all instances will have the same value
		// in our case: 8
		static const int _fractionalBits = 8;

	public:
		// Default constructor: Called when an object is created without arguments
		// e.g., Fixed a;
		Fixed(void);

		// copy constructor: Called when a new object is created as a copy
		// of an existing object.
		// e.g., Fixed b(a);
		Fixed(const Fixed &other);

		// copy assignment operator: Called when an existing object is assigned
		// the value of another object
		// e.g., c = b;
		// the 'operator=' is a special function that overloads the assignment operator
		// It takes a constant reference to anothr object to avoid unnecessary copying.
		// It returns a reference to the current object to allow cahining assignments
		// e.g., a = b = c
		Fixed& operator=(const Fixed &other);

		//Destructor
		~Fixed(void);

		// A member function to get the raw value of the fixed-point number.
		// 'const' at the endo fo the function signature means that this function
		// is not modifying the state of the object
		int getRawBits(void) const;

		// A member function to set the raw value of the fixed-point number
		void setRawBits(int const raw);

};

#endif
