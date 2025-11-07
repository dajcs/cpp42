/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:28:59 by anemet            #+#    #+#             */
/*   Updated: 2025/11/07 14:52:01 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>
# include <iterator> // std::distance

class Span
{
	private:
		// std::vector is a dynamic array from C++ STL (Standard Template Library)
		// it automatically manages its own memory
		std::vector<int> _numbers;

		// the max number of integers the Span can hold
		unsigned int _maxSize;

		// Default constructor is private, because Span must be created with a size.
		Span();

	public:
		/* --- Orthodox Canonical Form --- */

		// Constructor: Initializes the Span with a maximum size N
		// The 'explicit' keyword prevents unintentional implicit conversions
		// making sure that N can be only 'unsigned int', nothing else
		explicit Span(unsigned int N);

		// Copy Constructor
		Span(const Span& other);

		// Copy Assignment Operator
		Span& operator=(const Span& other);

		// Destructor
		~Span();


		/*
			--- Member Functions ---
		*/

		// Adds a single number to our vector
		void addNumber(int number);

		// Adds a range of numbers to our vector
		// Takes two iterators 'begin' and 'end' defining a sequence of numbers
		template<typename InputIterator>
		void addNumber(InputIterator begin, InputIterator end);

		// Finds and returns the shortest distance between any two numbers in the Span
		int shortestSpan();

		// Finds and returns the longest distance between any two numbers in the Span
		int longestSpan();

		// For testing purposes only: printNumbers stored in the Span
		// It's a 'const' functions because it doesn't modify the object's state
		void printNumbers() const;

		/*
			--- Custom Exceptions ---
		*/
		class SpanIsFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};


};



// Template function definitions can be in the header file
// or we could put in Span.tpp and add to header file the line: `#include Span.tpp`
// However this will be a quick implementation, so we're including the template definitions here

template<typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
	// Calculate the distance (number of elements) in the input range
	std::size_t rangeSize = std::distance(begin, end);

	// Check if there is enough space to add all the new numbers
	if (this->_numbers.size() + rangeSize > this->_maxSize)
	{
		throw SpanIsFullException();
	}

	// Insert the elements from the range [begin, end) into our vector.
	// The std::vector::insert function is highly optimized for this
	/*
		iterator insert(const_iterator pos, InputIterator first, InputIterator last);
			- pos: where to start inserting
					_numbers.end() points to the first free position
			- [begin, end) - iterators specifying the range of elements to be inserted
	*/
	this->_numbers.insert(this->_numbers.end(), begin, end);
}


#endif
