/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:03:27 by anemet            #+#    #+#             */
/*   Updated: 2025/11/17 15:16:04 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

// Constructor: Initializes the set with a reference to a searchable_bag
// The member '_bag' is a reference and must be initialized in the member initializer list
set::set(searchable_bag &bag) : _bag(bag) {}

// Copy constructor: Initializes the set with a reference from another set's bag
set::set(const set &other) : _bag(other._bag) {}

// Copy assignment operator: Reassigns the reference to the bag from another set
set& set::operator=(const set &other)
{
	if (this != &other)
	{
		this->_bag = other._bag;
	}
	return *this;
}

// Destructor: Does nothing because the set does not own the bag object
set::~set() {}

// insert (single value): Only inserts the value if it's not already in the bag
void set::insert(int value)
{
	if (!this->_bag.has(value))
	{
		this->_bag.insert(value);
	}
}

// insert (multiple values): Iterates and inserts each value if it's not present
void set::insert(int *values, int count)
{
	for (int i = 0; i < count; ++i)
	{
		this->insert(values[i]);
	}
}

// has(value): delegates the check to the underlying bag's `has()` method
bool set::has(int value) const
{
	return this->_bag.has(value);
}

// print(): delegates the printing to the underlying bag
void set::print() const
{
	this->_bag.print();
}

// clear: Delegates clearing to the underlying bag
void set::clear()
{
	this->_bag.clear();
}

// get_bag: Returns a reference to the underlying bag
searchable_bag& set::get_bag()
{
	return this->_bag;
}
