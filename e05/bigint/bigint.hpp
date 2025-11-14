/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:29:07 by anemet            #+#    #+#             */
/*   Updated: 2025/11/14 16:00:17 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <iostream>

// The bigint class will store an arbitrary precisioin unsigned integer
class bigint
{
	private:
		// store the number as a string in base 10
		std::string str;

	public:
		// --- Orthodox Canonical Form ---

		// Default constructor
		bigint();
		// Parametrized constructor from a number
		bigint(long long n);
		// Copy constructor
		bigint(const bigint& other);
		// Copy assignment operator
		bigint& operator=(const bigint& other);
		// Destructor
		~bigint();


		// --- Arithmetic Operators ---

		// Addition operator
		bigint operator+(const bigint& other) const;

};








#endif
