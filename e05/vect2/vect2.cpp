/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:18:28 by anemet            #+#    #+#             */
/*   Updated: 2025/11/16 18:19:59 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

// --- Orthodox Canonical Form

// Default constructor
vect2::vect2()
{
	this->x = 0;
	this->y = 0;
}

// Parametrized Constructor
vect2::vect2(int x, int y)
{
	this->x = x;
	this->y = y;
}

// Copy Constructor
vect2::vect2(const vect2 &other)
{
	*this = other; // using assignment operator
}

// Copy assignment operator
vect2 &vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this; // to allow chaining a = b= c
}

// Destructor
vect2::~vect2() {}  // we're not allocating dymanic memory, nothing to do



// --- Member Access ---

// Read/write access to componenets
int &vect2::operator[](int index)
{
	if (index == 0)
		return this->x;
	else
		return this->y;
}

// Read-only access to componenets for const objects
const int &vect2::operator[](int index) const
{
	if (index == 0)
		return this->x;
	else
		return this->y;
}


// --- Arithmetic Operators ---

// Returns a new vect2 object that is the sum of the two vectors
vect2 vect2::operator+(const vect2 &other) const
{
	return (vect2(this->x + other.x,
					this->y + other.y));
}

// Returns a new vect2 object that is the difference of the two vectors
vect2 vect2::operator-(const vect2 &other) const
{
	return (vect2(this->x - other.x,
					this->y - other.y));
}

// Returns a new vect2 object with both components negated
vect2 vect2::operator-() const
{
	return vect2(-this->x, -this->y);
}

// --- Scalar Multiplication ---

// Returns a new vect2 object with each component multiplied by the scalar
vect2 vect2::operator*(int scalar) const
{
	return (vect2(this->x * scalar, this->y * scalar));
}


// --- Compound Assignment Operators ---

// Adds the other vector to the current one and returns a reference to itself
vect2& vect2::operator+=(const vect2 &other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

// Subtracts the other vector from the current one and returns a reference to itself
vect2& vect2::operator-=(const vect2 &other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

// Multiplies the current vector by a scalar and returns a reference to itself
vect2& vect2::operator*=(const int scalar)
{
	this-> x *= scalar;
	this-> y *= scalar;
	return *this;
}


// --- Increment/Decrement Operators ---

// Post-increment: Returns a copy of the object before incrementing.
// The nameless 'int' parameter is a dummy to distinguish it from the pre-increment
vect2 vect2::operator++(int)
{
	vect2 tmp(*this);
	this->x += 1;
	this->y += 1;
	return tmp;
}

// Pre-increment: Increments the current object and returns a reference to it
vect2& vect2::operator++()
{
	this->x += 1;
	this->y += 1;
	return *this;
}

// Post-decrement: Returns a copy of the object before decrementing
// The nameless 'int' parameter is a dummy to distinguish it from the pre-decrement
vect2 vect2::operator--(int)
{
	vect2 tmp(*this);
	this->x -= 1;
	this->y -= 1;
	return tmp;
}

// Pre-decrement: Decrements the current object and returns a reference to it
vect2& vect2::operator--()
{
	this->x -= 1;
	this->y -= 1;
	return *this;
}


// --- Comparison Operators ---

// Compares if two vectors are equal component-wise
bool vect2::operator==(const vect2 &other) const
{
	return (this->x == other.x && this->y == other.y);
}

// Compares if two vectors are not equal
// Implemented by using the == operator
bool vect2::operator!=(const vect2 &other) const
{
	return !(*this == other);
}


// --- Non-member functions Overloads ---

// print vect2 on output stream
std::ostream &operator<<(std::ostream &out, const vect2 &v)
{
	out << "{" << v[0] << ", " << v[1] << "}";
	return out;
}

// scalar multiplication in the form of `3 * v`
vect2 operator*(int scalar, const vect2 &v)
{
	return (v * scalar);
}
