/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:51:48 by anemet            #+#    #+#             */
/*   Updated: 2025/11/10 16:22:44 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Container Adapter - std::stack
	The std::stack is not a container in its own. It is an adapter.
	It takes an existing container (by default, std::deque, a double-ended queue)
	and provides a simplified, stack-specific interface (push / pop / top).
	The problem states the std::stack is not iterable because it hides the
	underlying container's iterators.
	Our goal is to expose them.
*/

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>	// std::stack
# include <deque>	// std::stack is using std::deque as its default underlying container

/* 'template <typename T, typename Container = std::deque<T> >'
	this line makes MutantStack a template class
		'T': placeholder for the data type the stack will hold (e.g., int, std::string)
		'Container: the underlying container type. We default it to std::deque<T> because
			that's the default for std::stack and it provides the iterators we need.
*/
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		// --- Orthodox Canonical Form ---

		// Default Constructor
		// 'explicit' preventing unintentional implicit conversions
		explicit MutantStack() : std::stack<T, Container>() {}

		// Copy Constructor
		// e.g., MutantStack<int> another_mstack(mstack);
		MutantStack(const MutantStack<T, Container>& other) : std::stack<T, Container>(other) {}

		// Copy Assignment Operator
		// e.g., another_mstack = mstack;
		MutantStack& operator=(const MutantStack<T, Container>& other)
		{
			if (this != &other)
			{
				// The base std::stack class has its own assignment operator that handles
				// copying the underlying elements. We just call it.
				std::stack<T, Container>::operator=(other);
			}
			return *this; // return a reference to the current object
		}

		// Destructor
		// std::stack manages its own memory, we don't have to make anything here
		~MutantStack() {}


		/*
				--- Adding Iterator Functionality ---

			The `std::stack` class internally uses a container (like std::deque or std::list).
			This underlying container is stored in a protected member variable named 'c'.
			Since we're inheriting from std::stack, we have access to this 'c'.

			The `std::deque` has iterators, so we can expose them.
			We use `typedef` to create aliases for the underlying container's iterator types.
		*/

		// Typedef for a regular iterator (read/write)
		typedef typename Container::iterator iterator;

		// Typedef for a constant iterator (read-only)
		typedef typename Container::const_iterator const_iterator;

		// Typedef for a reverse iterator (read/write, iterates backwards)
		typedef typename Container::reverse_iterator reverse_iterator;

		// Typedef for a constant reverse iterator (read-only, iterates backwards)
		typedef typename Container::const_reverse_iterator const_reverse_iterator;


		/*
			--- Iterator Accessor Methods ---

			These functions provide access to the iterators
				of the underlying container 'c'
		*/

		// Returns an iterator to the beginning of the stack (the oldest element)
		iterator begin();

		// Returns an iterator to the end of the stack (the position after the newest element)
		iterator end();

		// Const-qualified versions for when you have a const MutantStack object
		const_iterator begin() const;
		const_iterator end() const;

		// Reverse iterator versions
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

};

// We need to include the implementation file for templates

# include "MutantStack.tpp"

# endif	// MUTANTSTACK_HPP
