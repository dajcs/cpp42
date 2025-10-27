/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:16:06 by anemet            #+#    #+#             */
/*   Updated: 2025/10/27 22:02:00 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // for roundf()

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
		static const int _fractionalBits = 8;

	public:
		// Orthodox Canonical Form
		Fixed(void);
		// copy constructor: e.g., Fixed b(a);
		Fixed(const Fixed &other);
		// copy assignment operator: e.g., c = b;
		Fixed& operator=(const Fixed &other);
		//Destructor
		~Fixed(void);

		// -------- New constructors ------
		// Constructor that takes a constant integer
		Fixed(const int intValue);
		// Constructor that takes a constant float
		Fixed(const float floatValue);


		// Member functions for conversion
		float toFloat(void) const;
		int toInt(void) const;

		// Getter and Setter for the raw value
		int getRawBits(void) const;
		void setRawBits(int const raw);

};

// Overload of the insertion (<<) operator.
// This is a non-member fuction, but it is related to the fixed class.
// It takes and ouput stream (like std::cout) and a Fixed object.
// It allows us to write `std::cout << myFixedObject;
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
