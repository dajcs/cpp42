/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:59:58 by anemet            #+#    #+#             */
/*   Updated: 2025/11/17 13:47:21 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

#include "searchable_tree_bag.hpp"

// Default constructor: Initializes the object by calling the `tree_bag` constructor
// The `searchable_bag` has no data to be initiated
searchable_tree_bag::searchable_tree_bag() : tree_bag() {}

// Copy constructor: Calls the base class constructor `tree_bag`
// doesn't call `searchable_bag` because that has no data to be copied
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {}

// Copy assignment operator: Calls the `tree_bag` assignment operator
searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
	if (this != &other)
	{
		tree_bag::operator=(other);
	}
	return *this;
}

// Destructor: The base class destructor is automatically called, nothing to do
searchable_tree_bag::~searchable_tree_bag() {}


// has(): Implements the search functionality for the tree-based bag
// It leverages the binary search tree structure for an efficient search.
// This function is 'const' because it does not modify the object's state.
bool searchable_tree_bag::has(int value) const
{
	node *current = this->tree;
	while (current != NULL)
	{
		if (value < current->value)
			current = current->l;
		else if (value > current->value)
			current = current->r;
		else
			return true; // value found
	}
	return false; // value not found
}


