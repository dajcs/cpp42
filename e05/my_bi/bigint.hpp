/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:34:13 by anemet            #+#    #+#             */
/*   Updated: 2025/11/19 15:39:34 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

class bigint
{
	private:
		std::string str;

	public:
		bigint(); // Default constructor
		bigint(unsigned int n); // Parametrized constructor
		bigint(const bigint &other); // Copy constructor
		bigint& operator=(const bigint& other); // Copy assignment operator
		~bigint(); // destructor;

		// getter
		std::string getStr() const;

		// --- + operators ---
		bigint operator+(const bigint &other) const; // add, create new obj
		bigint& operator+=(const bigint &other); // add inplace

		//  ++ operators
		bigint& operator++(); // pre-increment
		bigint operator++(int); // post-increment

		// --- shift with num
		// not necessary, the compiler knows we can convert unsigned int to bigint,
		// 		bigint(unsigned int n); // Parametrized constructor
		// and it will use that constructor to create the obj

		/*
			We could do the reverse, define only the shift with num
			but then we would need to have a default conversion from
			obj -> unsigned int with operator unsigned int
		public:
			operator unsigned int() const;

		implementation:
		bigint::operator unsigned int() const
		{
			unsigned int result;
			std::stringstream ss(this->str);
			ss >> result;  // no protection against overflow
			return result;
		}

		**Note**: the return type should not be specified because
		the operator name tells the function what will be the return type.

		*/
		// bigint operator>>(unsigned int shift) const; // right shift
		// bigint& operator>>=(unsigned int shift); // inplace right-shift
		// bigint operator<<(unsigned int shift) const; // left shift
		// bigint& operator<<=(unsigned int shift); // inplace left-shift

		// --- shift with obj
		bigint operator>>(const bigint& other) const; // right shift
		bigint& operator>>=(const bigint& other); // inplace right-shift
		bigint operator<<(const bigint& other) const; // left shift
		bigint& operator<<=(const bigint& other); // inplace left-shift

		// --- comparison operators
		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
};

std::ostream& operator<<(std::ostream& output, const bigint& obj);
