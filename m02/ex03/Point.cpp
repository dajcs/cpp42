/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:30:55 by anemet            #+#    #+#             */
/*   Updated: 2025/10/28 12:34:29 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor using a member initializer list to set const members
Point::Point(void): x(0), y(0) {}

// Constructor with floats, also using the initializer list
Point::Point(float const x_val, float const y_val): x(x_val), y(y_val) {}

// Copy constructor, using the initializer list to copy values
Point::Point(const Point &other): x(other.x), y(other.y) {}

// Copy assignment operator.
// Since 'x' and 'y' are const, we cannot re-assign them.
// A common approach for this academic exercise is to do nothing
// or cast away const-ness, but the latter is bad practice.
// For 42, showing an understanding of the limitation is enough.
Point& Point::operator=(const Point &other)
{
	// This is a bit of philosophical issue.  We're asked to implement it,
	// but the object's state cannot be changed. The most logical action
	// is to do nothing and just return a reference to the current object.
	(void)other; // suppress unused parameter warning
	return *this;
}

// Destructor is simple as there are no dynamic resources to free
Point::~Point(void) {}

// Getter for the x-coordinate
Fixed Point::getX(void) const
{
	return this->x;
}

// Getter for the y-coordinate
Fixed Point::getY(void) const
{
	return this->y;
}
