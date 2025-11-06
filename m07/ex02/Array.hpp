/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:28:50 by anemet            #+#    #+#             */
/*   Updated: 2025/11/06 14:44:49 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception> // std::exception

/*
	'template <typename T>' prefix makes the class 'Array' a template
	'T' is a placeholder for any data type.
	This will allow us to create Array<int> or Array<float>, ... etc.
*/
template <typename T>
class Array
{
	private:
		T*			_array; // Pointer to the first element of the
							// dynamically allocated array
		unsigned int _size; // nr of elements in the array

	public:
		// --- Orthodox Canonical Form ---

		// Default Constructor
		// Creates an empty Array (no memory allocated)
		Array();

		// Constructor with size
		// Creates an Array of 'n' elements, initialized by default
		Array(unsigned int n);

		// 3. Copy Constructor
		// Creates a new Array that is a deep copy of another Array
		Array(const Array& other);

		// 4. Copy Assignment Operator
		// Makes the current Array a deep copy of another array
		Array& operator=(const Array& other);

		// 5. Destructor
		// Frees the memory allocated by the Array
		~Array();


		// --- Member Functions ---

		// Subscript operator for element access
		// It allows accessing elements like a standard C array (e.g., arr[i])
		// It throws an exceptioni if the index is out of bounds
		T& operator[](unsigned int index);
		// const-overloaded version for const objects
		const T& operator[](unsigned int index) const;

		// Returns the number of elements in the Array
		unsigned int size() const;


		// --- Exception Class ---

		// A custom exception class for out-of-bound access
		// Inheriting from std::exception
		class OutOfBoundsException : public std::exception
		{
			public:
				// The what() method returns a C-style string describing the exception
				virtual const char* what() const throw();
		};
};

// Include the implementation file for the template
// This is a common practice to separate declaration from implementation
// while allowing the compiler to have access to the implementation
// when instantiating the template.
# include "Array.tpp"

#endif
