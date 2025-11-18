/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:34:13 by anemet            #+#    #+#             */
/*   Updated: 2025/11/18 16:43:13 by anemet           ###   ########.fr       */
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

		// --- ++/-- operators
		bigint& operator++(); // pre-increment
		bigint operator++(int); // post-increment
		bigint& operator--(); // pre-decrement
		bigint operator--(int); // post-decrement

		// --- shift with num
		bigint operator>>(unsigned int shift) const; // right shift
		bigint& operator>>=(unsigned int shift); // inplace right-shift
		bigint operator<<(unsigned int shift) const; // left shift
		bigint& operator<<=(unsigned int shift); // inplace left-shift

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
