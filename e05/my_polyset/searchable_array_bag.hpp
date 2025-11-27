/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:44:32 by anemet            #+#    #+#             */
/*   Updated: 2025/11/27 11:50:56 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
                    get() to access the underlying bag

*/


#pragma once

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag: public array_bag, public searchable_bag
{


	public:

	// default constructor
	// call array_bag() constructor
	// no need to call seachable_bag() constructor, it has only a virtual has() function
	searchable_array_bag(): array_bag() {}

	// parametrized constructor - not used in the provided main()

	// copy constructor
	// using `array_bag()` copy constructor
	searchable_array_bag(const searchable_array_bag &other): array_bag(other) {}

	// copy assignment operator
	// the parent `array_bag` has already implemented `operator=()`, we're using it
	// actually we have to using it because of the encapsulation rules:
	// if the base class changes copy rules, the code should work right away
	searchable_array_bag &operator=(const searchable_array_bag &other)
	{
		if (this != &other)
		{
			array_bag::operator=(other); // this will create new *data, copy it and copy size
		}
		return *this;
	}

	// destructor
	// the base class destructor will be called automatically
	// nothing to do in the code
	~searchable_array_bag() {};


	// has()
	// member function
	bool has(int value) const
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == value)
				return true;
		}
		return false;
	}
};
