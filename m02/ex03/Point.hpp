/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:23:26 by anemet            #+#    #+#             */
/*   Updated: 2025/10/28 11:30:34 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		// These member variables are constant. They must be initialized in the
		// constructor's initializer list and cannot be changed later.
		Fixed const x;
		Fixed const y;

	public:
		// Orthodox Canonical Form
		// Default constructor: Initializes x and y to 0
		Point(void);
		// Constructor with float values.
		Point(float const x_val, float const y_val);
		// Copy constructor
		Point(const Point &other);
		// Copy assignment operator. Note: this won't be able to do much
		// because the member variables are const
		Point& operator=(const Point &other);
		// Destructor
		~Point(void);

		// Public getter functions to access the private const coordinates
		Fixed getX(void) const;
		Fixed getY(void) const;
};

// Declaration of the BSP function
bool bsp(Point const a, Point const b, Point const c, Point const point);


#endif
