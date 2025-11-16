/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:33:03 by anemet            #+#    #+#             */
/*   Updated: 2025/11/16 18:04:09 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>

class vect2
{
	private:
		int x;
		int y;


	public:
		// --- Orthodox Canonical Form ---

		// Default constructor - creates vect2[0, 0]
		vect2();
		// Parametrized constructor - creates vect2[x, y]
		vect2(int x, int y);
		// Copy constructor
		vect2(const vect2 &other);
		// Copy assignment operator
		vect2& operator=(const vect2 &other);
		// Destructor
		~vect2();


		// --- Member Access ---

		// Overloading the [] operator to access vector components (read/write)
		int &operator[](int index);
		// Overloading the [] operator for const objects (read only)
		const int &operator[](int index) const;


		// --- Arithmetic Operators ---

		// Vector addition
		vect2 operator+(const vect2 &other) const;
		// Vector subtraction
		vect2 operator-(const vect2 &other) const;
		// Unary minus (negation)
		vect2 operator-() const;


		// --- Scalar Multiplication ---

		// Multiplication by a scalar (e.g., v * 2)
		vect2 operator*(int scalar) const;


		// --- Compound Assignment Operators

		vect2 &operator+=(const vect2 &other);
		vect2 &operator-=(const vect2 &other);
		vect2 &operator*=(int scalar);


		// --- Increment/Decrement Operators ---

		// Post-increment (e.g., v++)
		vect2 operator++(int);
		// Pre-increment (e.g., ++v)
		vect2& operator++();
		// Post-decrement (e.g., v--)
		vect2 operator--(int);
		// Pre-decrement (e.g., --v)
		vect2& operator--();


		// --- Comparison Operators ---

		bool operator==(const vect2 &other) const;
		bool operator!=(const vect2 &other) const;

};





// --- Non-Member Function Overloads ---

// Overloading the << operator for printing
std::ostream &operator<<(std::ostream &out, const vect2 &v);


// Overloading scalar multiplication for the case e.g., 3 * v
vect2 operator*(int scalar, const vect2 &v);






#endif
