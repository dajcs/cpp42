/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:37:03 by anemet            #+#    #+#             */
/*   Updated: 2025/10/28 13:18:51 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


/* The Logic:

A triangle is defined by three vertices, say A, B, and C.
These vertices, taken in order (e.g., clockwise or counter-clockwise),
form three directed edges: AB, BC, and CA.

For a point P to be inside the triangle, it must be on the same side
of all three lines formed by these edges.
For instance, it must be "to the left" of AB, "to the left" of BC,
and "to the left" of CA (assuming a counter-clockwise vertex order).

We can determine which side a point is on by using a mathematical formula derived
from the 2D cross-product.
For an edge (let's say from point p1 to p2) and a test point p, the formula is:

orientation = (p1.x - p.x) * (p2.y - p1.y) - (p1.y - p.y) * (p2.x - p1.x)

The sign of the orientation value tells us where the point p is relative to the directed line p1 -> p2:
If the sign is positive, it's on one side.
If the sign is negative, it's on the other side.
If the value is zero, the point is exactly on the line.

To solve the problem, we calculate this orientation for the test point against all three edges of the triangle.
If all three calculations result in a positive sign, OR if all three result in a negative sign, the point is inside.
If the signs are mixed, or if any result is zero (meaning the point is on an edge), it is outside.

*/

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
