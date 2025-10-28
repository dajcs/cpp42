/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:37:03 by anemet            #+#    #+#             */
/*   Updated: 2025/10/28 12:49:07 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// This is a helper function to calculate the orientation
// It uses the cross-product formula
// The result's sign determines if 'point' is left/right of the line a->b
static Fixed calculate_orientation(Point const a, Point const b, Point const point)
{
	return (a.getX() - point.getX()) * (b.getY() - a.getY()) -
			(a.getY() - point.getY()) * (b.getX() - a.getX());
}

// The main BSP function
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Calcualte the orientation of the point relative to each edge of the triangle
	Fixed w1 = calculate_orientation(a, b, point);
	Fixed w2 = calculate_orientation(b, c, point);
	Fixed w3 = calculate_orientation(c, a, point);

	// Return all orientation results have the same sign
	return ((w1 > 0) && (w2 > 0) && (w3 > 0)) ||
				((w1 < 0) && (w2 < 0) && (w3 < 0));
}
