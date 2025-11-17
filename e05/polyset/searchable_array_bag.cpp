/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:46:28 by anemet            #+#    #+#             */
/*   Updated: 2025/11/17 10:24:49 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

/*

                  +-------------------------+
                  |           bag           | (Abstract Base Class):
                  +-------------------------+   insert(), print(), clear()
                               ^
          _____________________|___________________________________
         | (virtual)                     | (virtual)               | (virtual)
         |                               |                         |
+------------------------+       +----------------+        +----------------+
|   searchable_bag       |       |   array_bag    |        |    tree_bag    |
|     (Abstract): has()  |       +----------------+        +----------------+
+------------------------+              ^                          ^
         ^          ^                   |                          |
         |          |______     ________|                          |
         |                 |   |                                   |
         |                 |   |                                   |
         |       +----------------------+                          |
         |       | searchable_array_bag | (TODO)                   |
         |       +----------------------+                          |
         |                                                         |
         |__________________________________      _________________|
                                            |    |
                                            |    |
                                   +-----------------------+
                                   |  searchable_tree_bag  | (TODO)
                                   +-----------------------+
*/


// Default constructor: Initializes the object by calling the base class constructor
searchable_array_bag::searchable_array_bag() : array_bag() {}

// Copy constructor
// Explicitly calls the `array_bag` copy constructor to copy the base part
// We're calling only for `array_bag`, because `searchable_bag` has no data, it is a pure interface
searchable_array_bag::searchable_array_bag(const searchable_array_bag &other) : array_bag(other) {}

// Copy assignment operator
// it calls the `array_bag` assignment operator to handle the assignment of the base part
searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &other)
{
	if (this != &other)
	{
		array_bag::operator=(other);
	}
	return *this;
}

// Destructor: The base class destructor is automatically called
searchable_array_bag::~searchable_array_bag() {}

// has(): implements the search for the array-based bag
// it performs a linear search through the array
// it is `const` because it is not modifying the object
bool searchable_array_bag::has(int value) const
{
	for (int i = 0; i < this->size; ++i)
	{
		if (this->data[i] == value)
		{
			return true;
		}
	}
	return false;
}
