/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:30:51 by anemet            #+#    #+#             */
/*   Updated: 2025/11/26 13:47:17 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


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
					get() to access the underlying bag

*/


class set
{
	private:
		searchable_bag &bag;

	public:
		// OCF
		// (Default) Parametrized constructor
		// takes a reference to a bag
		set(searchable_bag &bag);

};
