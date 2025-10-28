/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:50:17 by anemet            #+#    #+#             */
/*   Updated: 2025/10/28 12:59:52 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

// Helper function to print results clearly
void test_point(Point const a, Point const b, Point const c, Point const p,
					std::string const& point_name)
{
	if (bsp(a, b, c, p))
	{
		std::cout << "Point " << point_name << " is INSIDE the triangle." << std::endl;
	}
	else
	{
		std::cout << "Point " << point_name << "is OUTSIDE the triangle." << std::endl;
	}
}

int main(void)
{
	// define the vertices of a triangle.
	// Let's use a simple right-angled triangle.
	Point const vertex_a(0.0f, 0.0f);
	Point const vertex_b(10.0f, 0.0f);
	Point const vertex_c(0.0f, 10.0f);

	std::cout << "Triangle vertices are A(0,0), B(10,0), C(0,10)" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	// Test cases
	Point const p_inside(2.0f, 2.0f);
	Point const p_outside(10.0f, 10.0f);
	Point const p_on_edge(5.0f, 0.0f);
	Point const p_on_vertex(0.0f, 0.0f);

	// Run tests
	test_point(vertex_a, vertex_b, vertex_c, p_inside, "p_inside(2,2)");
	test_point(vertex_a, vertex_b, vertex_c, p_outside, "p_outside(10,10)");
	test_point(vertex_a, vertex_b, vertex_c, p_on_edge, "p_on_edge(5,0)");
	test_point(vertex_a, vertex_b, vertex_c, p_on_vertex, "p_on_vertex(0,0)");

	return 0;
}
