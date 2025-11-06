/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:16:02 by anemet            #+#    #+#             */
/*   Updated: 2025/11/06 13:37:27 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream> // size_t

/* 'template <typename T>'
	This line tells to the compiler that the following function is a template.
	'typename' is a keyword
	'T' is a placeholder for a data type that will be determined at compilation time.
	This allows 'iter' to work with arrays of any type (int, char, float, etc.)
*/

/* iter() v1: for non-const arrays (arrays that can be modified)
	Input:
		*array: A pointer to the first element of the array
		length: The number of elements in the array
		(*f)(T&): A function pointer to a function that takes a reference to an
					element of type T and returns void. The function can modify
					the element because it takes a non-const reference (T&)
*/
template <typename T>
void iter(T* array, const size_t length, void (*f)(T&))
{
	// Basic loop to iterate through the array
	for (size_t i = 0; i < length; i++)
	{
		// Call the function 'f' for each element of the array
		f(array[i]);
	}
}

/* iter() v2: for const arrays (read-only arrays)
	An overload of the 'iter' function.
	We can re-use the 'iter' name as long as the parameters are different
	Input:
		const T* array: A pointer to the first element of the read-only array
		length: The number of elements in the array
		(*f)(const T&): A function pointer to a function that takes a reference to an
					element of type T and returns void. The function can modify
					the element because it takes a non-const reference (T&)
*/
template <typename T>
void iter(const T* array, const size_t length, void (*f)(const T&))
{
	// Basic loop to iterate through the array
	for (size_t i = 0; i < length; i++)
	{
		// Call the function 'f' for each element of the array
		f(array[i]);
	}
}

#endif
