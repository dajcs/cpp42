/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:25:34 by anemet            #+#    #+#             */
/*   Updated: 2025/11/17 13:46:34 by anemet           ###   ########.fr       */
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

#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

# include "tree_bag.hpp"
# include "searchable_bag.hpp"
# include <unistd.h>

/*
	`searchable_tree_bag` inherits from `tree_bag` and `searchable_bag`
	- it gets data structure binary tree implementation from `tree_bag`
	- it gets requirement to implement the `has()` method from `searchable_bag`
*/
class searchable_tree_bag : public tree_bag, public searchable_bag
{
	public:
		// Orthodox Canonical Form
		searchable_tree_bag();	// Default constructor
		searchable_tree_bag(const searchable_tree_bag &other); // Copy constructor
		searchable_tree_bag& operator=(const searchable_tree_bag &other); // Copy assignment operator
		~searchable_tree_bag(); // Destructor

		// Implementation of the virtual function from `searchable_bag`
		bool has(int value) const;
};

#endif
