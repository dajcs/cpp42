/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:56:06 by anemet            #+#    #+#             */
/*   Updated: 2025/11/16 22:17:09 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAYBAG_HPP
# define SEARCHABLE_ARRAYBAG_HPP

#include "array_bag.hpp"
#include "searchable_bag.hpp"

/*
	`searchable_array_bag` inherits from both `array_bag`and `searchable_bag`
	- it gets the array-based implementation from `array_bag`
	- it gets the requirement to implement the `has` method from `searchable_bag`
*/
class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		// --- Orthodox Canonical Form
		searchable_array_bag(); // Default constructor
		searchable_array_bag(const searchable_array_bag &other); // Copy constructor
		searchable_array_bag &operator=(const searchable_array_bag &other); // Copy assignment operator
		~searchable_array_bag(); // Destructor

		// Implementation of the pure virtual function from `searchable_bag`
		bool has(int value) const;
};


#endif
