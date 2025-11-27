/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:30:51 by anemet            #+#    #+#             */
/*   Updated: 2025/11/27 11:56:26 by anemet           ###   ########.fr       */
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
                    get_bag() to access the underlying bag

*/


class set
{
	private:
		searchable_bag &b;

	public:
		// OCF

		// (Default) Parametrized constructor
		// takes a reference to a bag, getting value in member initializer list: b(bag)
		set(searchable_bag &bag) : b(bag) {};

		// Copy constructor : initialize the b ref to the other.b ref
		set(const set& other) : b(other.b) {};

		// Copy assignment operator
		// reassigns the reference from other.b to this->b
		set& operator=(const set &other)
		{
			if (this != &other)
			{
				this->b = other.b;
			}
			return *this;
		}

		//Destructor
		// Does nothing because the set doesn't own the b object
		~set() {};


		/* --- the SET functions --- */

		// insert(val)
		// inserts a new element only if that element is not yet in the set
		void insert(int val)
		{
			if (!b.has(val))
				b.insert(val);
		}

		// insert(vals) range
		// checks for elements one-by-one and insert if not yet in the set
		void insert(int *vals, int count)
		{
			for (int i=0; i < count; i++)
			{
				if (!b.has(vals[i]))
					b.insert(vals[i]);
			}
		}

		// has()
		bool has(int val) const
		{
			return b.has(val);
		}

		// print()
		void print() const
		{
			b.print();
		}

		// clear()
		void clear()
		{
			b.clear();
		}

		// get_bag()
		searchable_bag& get_bag()
		{
			return b;
		}
};


/*


How can it accept a searchable_array_bag if it only knows about searchable_bag?
-------------------------------------------------------------------------------

This works because of the "is-a" relationship established by public inheritance.
A searchable_array_bag is-a searchable_bag.
A searchable_tree_bag is-a searchable_bag.

Because of this relationship, C++ allows you to perform an upcast. You can safely use a pointer
or reference to a derived class as if it were a pointer or reference to its base class.

When you write this in main.cpp:

searchable_bag *a = new searchable_array_bag; // 'a' is a searchable_array_bag
// ...
set sa(*a); // Call the set constructor

Here's the step-by-step of what happens when set sa(*a); is called:

1.) *a dereferences the pointer, giving you the actual searchable_array_bag object.
2.) This object is passed to the set constructor: set::set(searchable_array_bag& bag).
3.) The compiler sees that the constructor expects a searchable_bag&.
	It checks if a searchable_array_bag can be treated as a searchable_bag.
	Because of public inheritance, the answer is yes!
4.) The upcast happens automatically.
	The bag reference inside the constructor now refers to the original searchable_array_bag object,
	but it treats it statically as just a searchable_bag.
5.) Inside the constructor, b(bag) initializes the set's internal reference `b` to also refer to
	that very same searchable_array_bag object.

The set object doesn't know and doesn't care that `b` is actually a searchable_array_bag.
It only knows that it has a reference to something that guarantees it has insert(), has(), print(), etc., methods.



Under the Hood: The V-Table
---------------------------

So if the set class only knows about the searchable_bag interface, how does it call the correct insert()
method (the array version vs. the tree version) at runtime?

This is achieved through virtual functions and a mechanism called the Virtual Table (vtable).

1.) V-Table Creation: When the compiler processes a class that has virtual functions (like bag),
	it builds a static lookup table for that class called a vtable.
	This table contains pointers to the actual implementations of its virtual functions. searchable_array_bag will
	have its own vtable pointing to its own functions, and searchable_tree_bag will have another.
2.) V-Pointer (vptr) Creation: When an object of a class with virtual functions is created
	(e.g., new searchable_array_bag), the compiler secretly adds a hidden member to the object:
	a pointer called the vptr. This vptr points to the vtable for that object's class.
3.) Runtime Dispatch: When the code calls a virtual function through a base class reference or pointer
	(like b.insert(10); inside the set class), the following happens at runtime:
	- The program follows the `b` reference to get to the object.
	- It reads the object's hidden vptr.
	- It uses the vptr to find the correct vtable (the one for searchable_array_bag in this case).
	- It looks up the address of the insert function in that vtable and calls it.

This process is called dynamic dispatch or late binding, and it's how C++ implements polymorphism.

Visualized:

In main.cpp:
+--------------------------+
| searchable_array_bag obj |
|--------------------------|
|     (hidden vptr) * -----|-----> +---------------------------------+
|     data *               |       | searchable_array_bag's V-Table  |
|     size                 |       |---------------------------------|
+--------------------------+       | &searchable_array_bag::insert() |
                                   | &searchable_array_bag::has()    |
                                   | &array_bag::print()             |
                                   +---------------------------------+


In the set object:
+--------------------------+
|        set obj           |
|--------------------------|
|      b (reference) ------|------> (refers to the original object)
+--------------------------+


When set calls b.insert(), it follows the reference, finds the vptr,
and calls the correct function from the vtable.

In summary, the set constructor is a perfect example of design that leverages polymorphism: it's coded against an abstract
interface (searchable_bag) and remains completely decoupled from the concrete implementations (searchable_array_bag,
searchable_tree_bag), which are only decided at runtime.
*/
