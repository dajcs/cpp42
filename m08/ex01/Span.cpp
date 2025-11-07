/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:31:26 by anemet            #+#    #+#             */
/*   Updated: 2025/11/07 15:32:45 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructor
// Takes an unsigned int N as the maximum size
// We use an initializer list (': _maxSize(N)') to initialize member variables
// This is more efficient than assigning them inside the constructor body
Span::Span(unsigned int N) : _maxSize(N)
{
	// It's a good practice to reserve emory for the vector upfront if we know
	// the max size. This avoids multiple reallocations as we add new elements.
	this->_numbers.reserve(N);
}

// Copy Constructor
Span::Span(const Span& other)
{
	// using the copy assignment operator's logic
	*this = other;
}

// Copy Assignment Operator
// Called when doing `sp2 = sp1`
// Avoiding self-assignment `sp1 = sp1` and copying data
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		// copy the max size:
		this->_maxSize = other._maxSize;
		// copy the contents of the vector.
		// the std::vector's own assignment operator=
		// handles the memory allocation and element copying correctly
		this->_numbers = other._numbers;
	}
	// Return a reference to the current object to allow for chaining (a = b = c)
	return *this;
}

// Destructor
// This is called automatically when the object's lifetime ends.
// Since we are using std::vector, we don't need to manually free the memory
// The vector's own destructor will be called, and it will clean up its elements
Span::~Span() {}


/*
	========= Member Functions ===========
*/

void Span::addNumber(int number)
{
	// Check if the vector is already full
	if (this->_numbers.size() >= this->_maxSize)
	{
		// If full, throw a custom exception
		throw Span::SpanIsFullException();
	}
	// if there is space, add the number to the end of the vector
	this->_numbers.push_back(number);
}

int Span::shortestSpan()
{
	// A span cannot be found if there are 0 or 1 numbers
	if (this->_numbers.size() <= 1)
	{
		throw Span::NotEnoughNumbersException();
	}

	// To find the shortest span, the most efficient method is to sort the numbers,
	// After sorting, the smalles difference will be between two adjacent elements.
	// We sort the elements in a temporary copy to avoid modifying the original order
	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());

	// Initialize shortest span
	int shortest = sorted[1] - sorted[0];

	// Iterate through the rest of the vector
	// and update the shortest if needed
	for (size_t i = 2; i < sorted.size(); ++i)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
		{
			shortest = diff;
		}
	}
	return shortest;
}

int Span::longestSpan()
{
	// we need at least two numbers
	if (this->_numbers.size() <= 1)
	{
		throw Span::NotEnoughNumbersException();
	}

	// The longest span is simply the difference between the largest
	// and the smallest numbers in the set
	// STL provides efficient algorightms to find these:
	// std::min_element returns an iterator to the smallest element
	// std::max_element returns an iterator to the largest element
	// We dereference the iterator with '*' to get the actual value
	int minVal = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int maxVal = *std::max_element(this->_numbers.begin(), this->_numbers.end());

	return maxVal - minVal;
}

// For testing purposes printNumbers()
void Span::printNumbers() const
{
	/* version 1.0

	// *it is dereferencing the iterator
	std::cout << "Span stores numbers: ";
	for (std::vector<int>::const_iterator it = this->_numbers.begin();
											it != this->_numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	*/

	std::cout << "Span[" << this->_numbers.size() << "/" << this->_maxSize << "] stores numbers: ";

	// Get the size for convenience
	const size_t size = this->_numbers.size();

	if (size == 0)
	{
		// special case when the Span is empty
		std::cout << "(empty)";
	}
	else if (size <= 10)
	{
		// if there are 10 or fewer numbers, print all of them
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << this->_numbers[i] << " ";
		}
	}
	else
	{
		// if more than 10 numbers, print first 5 ... last 5
		for (size_t i = 0; i < 5; ++i)
		{
			std::cout << this->_numbers[i] << " ";
		}
		std::cout << "... ";
		for (size_t i = size - 5; i < size; ++i)
		{
			std::cout << this->_numbers[i] << " ";
		}
	}
	// Always end with a newline
	std::cout << std::endl;
}


/*
	========= Exception Implementations ===========
*/

const char* Span::SpanIsFullException::what() const throw()
{
	return "Cannot add number: Span is already full";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Cannot find span: Not enough numbers stored";
}
