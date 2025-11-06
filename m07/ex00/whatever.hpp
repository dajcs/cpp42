/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:38:11 by anemet            #+#    #+#             */
/*   Updated: 2025/11/06 11:02:41 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>	// std::cout

/* 				--- Templates ---

	A C++ template allows us to write generic fuctions or classes that work
	on any data type.
	The `typename T` (or `class T`) is a placeholder for a data type
	that will be specified when the function is called

	When calling `swap(a, b)` where `a` and `b` are integers, the compiler
	automatically generates a version of the swap function where `T` is
	replaced by `int`.

	This is happening at compile time.
*/

/* swap(T & a, T & b)
	Swaps the values of two given parameters.
	Inputs:
		T: type of the parametes
		a: the first value to swap
		b: the second value to swap

	We use references (`&`) so we can modify the original variables.
	This is the C++ equivalent of passing pointers to achieve the same result in C
*/
template <typename T>
void swap(T & a, T & b)
{
	T temp = a;
	a = b;
	b = temp;
}

/* min()
*/
template <typename T>
T & min(T & a, T & b)
{
	return (b <= a ? b : a);
}

/* max()
*/
template <typename T>
T & max(T & a, T & b)
{
	return (b >= a ? b : a);
}

#endif
