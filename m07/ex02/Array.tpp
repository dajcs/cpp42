/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:45:08 by anemet            #+#    #+#             */
/*   Updated: 2025/11/06 15:15:52 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Ensure the template declaration is visible to vscode IntelliSense
#include "Array.hpp"

// --- Orthodox Canonical Form Implementation ---

// 1. Default Constructor
// Initializing pointer = NULL and size = 0. No memory is allocated
template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

// 2. Constructor with size
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	// Allocate memory for 'n' elements of type T
	this->_array = new T[n];
	// 'new T[n]' default-initializes the elements
	// For primitive types like int, they hold indeterminate values
	// For class types, their default constructor is called.
}

// Copy Constructor
template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	// Allocate new memory for the copy
	this->_array = new T[this->_size];
	// Copy each element from the 'other' array to this new array
	// This is a "deep copy"
	for (unsigned int i = 0; i < this->_size; ++i)
	{
		this->_array[i] = other._array[i];
	}
}

// 4. Copy Assignment Operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	// 4.1. Self-assignment check: Avoid assigning an object to itself
	if (this != &other)
	{
		// 4.2. Deallocate existing memory to prevent memory leaks
		delete[] this->_array;

		// 4.3. Copy the size and allocate new memory
		this->_size = other._size;
		this->_array = new T[this->_size];

		// 4.4. Copy the elements (deep copy)
		for (unsigned int i = 0; i < this->_size; ++i)
		{
			this->_array[i] = other._array[i];
		}
	}
	// 4.5. Return a reference to the current object to allow chaining (e.g., a = b = c)
	return *this;
}

// 5. Destructor
template <typename T>
Array<T>::~Array()
{
	// Free the dynamically allocated memory
	// We use delete[] when memory was allocated with new[]
	delete[] this->_array;
}


// --- Member Functions Implementation ---

// Subscript operator
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
	{
		throw OutOfBoundsException();
	}
	return this->_array[index];
}

// const-overloaded subscript operator
// This version will be called on const Array objects
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
	{
		throw OutOfBoundsException();
	}
	return this->_array[index];
}

// size() function
template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}


// --- Exception Implamentation ---

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	// The 'throw()' part is an exception specification, indicating that this
	// function does not throw any exceptions. It's part of the std::exception interface
	return "Index is out of bounds";
}
