/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:49:37 by anemet            #+#    #+#             */
/*   Updated: 2025/11/17 15:16:37 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include "searchable_bag.hpp"

/*
	`set` class is a wrapper around a `searchable_bag`
	This is an example of the **Adapter** or **Wrapper** design pattern.
	It enforces the property of a set: no duplicate elements
		by checking for the existence of an element before insertion
*/
class set
{
	private:
		searchable_bag &_bag; // A reference to a searchable_bag

	public:
		// Orthodox Canonical Form
		set(searchable_bag &bag); // Constructor takes a reference to a bag
		set(const set &other); // Copy constructor
		set &operator=(const set &other); // Copy assignment operator
		~set(); // Destructor

		// Set operations
		void insert(int value);
		void insert(int *values,int count);
		bool has(int value) const;
		void print() const;
		void clear();
		searchable_bag& get_bag(); // A getter for the underlying bag
};

#endif
