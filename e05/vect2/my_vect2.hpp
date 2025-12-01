/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:27:41 by anemet            #+#    #+#             */
/*   Updated: 2025/12/01 17:33:27 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class vect2
{
	private:
		int x;
		int y;

	public:
		// OCF
		// Default constructor
		vect2() : x(0), y(0) {}
		// parametrized constructor
		vect2(int x0, int y0) : x(x0), y(y0) {}
		// copy constructor
		vect2(const vect2 &other)
		{
			*this = other;
		}
		// copy assignment operator
		vect2& operator=(const vect2 &other)
		{
			if (this != &other)
			{
				x = other.x;
				y = other.y;
			}
			return *this;
		}
		// destructor
		~vect2();

};
