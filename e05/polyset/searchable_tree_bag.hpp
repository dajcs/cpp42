/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:35:11 by anemet            #+#    #+#             */
/*   Updated: 2025/11/27 11:56:26 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"


/*


                  +-------------------------+
                  |           bag           | (Abstract Base Class):
                  +-------------------------+  2 x insert(), print(), clear()
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
         |       | searchable_array_bag | TODO: OCF, has()         |
         |       +----------------------+  Orthodox Canonical Form |
         |         ^                                               |
         |         |                                               |
         |__________________________________      _________________|
                   |                        |    |
                   | wrap                   |    |
          +--------o-------+ wrap  +-----------------------+
          |      set       o - - > |  searchable_tree_bag  | TODO: OCF, has()
          +----------------+       +-----------------------+
            TODO: OCF, wrap a bag
            expose: 2 x insert(), has(), print(), clear()
                    insert() must avoid duplicates
                    get_bag() to access the underlying bag

*/


// public inherit -> public members will stay public
// parents (tree_bag, searchable_bag) have virtual inheritance from grandparent(bag)
// -> bag members won't be duplicated
class searchable_tree_bag: public tree_bag, public searchable_bag
{
	public:
	// OCF

	// Default constructor
	searchable_tree_bag() {}
	// Copy constructor
	searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {}
	// Copy assignment operator
	searchable_tree_bag& operator=(const searchable_tree_bag &other)
	{
		if (this != &other)
		{
			tree_bag::operator=(other);
		}
		return *this;
	}
	~searchable_tree_bag() {};

	// has()
	bool has(int val) const
	{
		node* current = this->tree;
		while (current)
		{
			if (current->value < val)
			{
				current = current->l;
			}
			else if (current->value > val)
			{
				current = current->r;
			}
			else
				return true;
		}
		return false;
	}

};
