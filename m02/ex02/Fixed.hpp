/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:16:06 by anemet            #+#    #+#             */
/*   Updated: 2025/10/28 00:22:40 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // for roundf()

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		// Orthodox Canonical Form
		Fixed(void);					// default constructor
		Fixed(const int intValue);		// int constructor
		Fixed(const float floatValue);	// float constructor

		Fixed(const Fixed &other);		// copy constructor: e.g., Fixed b(a);
		Fixed& operator=(const Fixed &other); // copy assignment operator: e.g., c = b;
		~Fixed(void);					//Destructor

		// Comparison Operators
		bool operator>(const Fixed &ohter) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &ohter) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &ohter) const;
		bool operator!=(const Fixed &other) const;

		// Arithmetic Operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Increment/Decrement Operators
		// Prefix (++a)
		Fixed& operator++(void);
		// Postfix (a++)
		Fixed operator++(int);
		// Prefix (--a)
		Fixed& operator--(void);
		// Postfix (a--)
		Fixed operator--(int);

		// Min/Max Functions
		// Static functions belong to the class , not an instance
		// They are called using the ClassName, e.g., Fixed::min(a,b)
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);


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
