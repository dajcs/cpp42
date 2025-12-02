/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:38:42 by anemet            #+#    #+#             */
/*   Updated: 2025/12/02 12:25:21 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>	// std::ostream
#include <sstream>	// std::stringstream
#include <string>	// std::string
// #include <cstdlib>	// used for atoi, malloc, free, exit, system,... N/A here

class bigint
{
	private:
		std::string		str;

	public:
		// OCF - Orthodox Canonical Form
		//Default constructor
		bigint() : str("0") {};

		// parametrized constructor
		bigint(unsigned int n) : str(std::to_string(n))
		{
			// std::stringstream ss;
			// ss << n;
			// this->str = ss.str();
		}

		// copy constructor
		bigint (const bigint &other) : str(other.str)
		{
			// this->str = other.str;
		}

		// copy assignment operator
		bigint& operator=(const bigint &other)
		{
			if (this != &other)
			{
				this->str = other.str;
			}
			return *this;
		}

		// destructor
		~bigint() {};


		bigint& operator+=(const bigint &other)
		{
			std::string s1 = this->str;
			std::string s2 = other.str;

			std::string result = "";
			int carry = 0;
			int i = s1.length() - 1;
			int j = s2.length() - 1;
			while(carry || i >= 0 || j >= 0)
			{
				int d1 = (i >= 0) ? s1[i--] - '0' : 0;
				int d2 = (j >= 0) ? s2[j--] - '0' : 0;
				int sum = d1 + d2 + carry;
				// new carry
				carry = sum / 10;
				// new digit char
				char c = sum % 10 + '0';
				result = c + result;
			}
			this->str = result;
			return *this;
		}

		bigint operator+(const bigint &other) const
		{
			bigint tmp(*this);
			return tmp += other;
		}

		// pre-increment
		bigint& operator++()
		{
			return *this += bigint(1);
		}

		// post-increment
		bigint operator++(int)
		{
			bigint tmp(*this);	// copy current object
			*this += bigint(1);	// incr current object
			return tmp;			// return copy with the orig value
		}


		// left-shift inplace
		bigint& operator<<=(const bigint &other)
		{
			// std::stringstream ss(other.str);
			// ss << other.str;
			unsigned int shift = std::stoul(other.str);

			// ss >> shift;
			// append shift times '0'
			this->str.append(shift, '0');
			return *this;
		}

		// left-shift
		bigint operator<<(const bigint &other) const
		{
			bigint tmp(*this);
			return tmp<<=(other);
		}

		// right-shift inplace
		bigint& operator>>=(const bigint &other)
		{
			// std::stringstream ss(other.str);
			// ss << other.str;
			unsigned int shift = std::stoul(other.str);
			// ss >> shift;
			if (shift >= this->str.length())
			{
				this->str = "0";
			}
			else
			{
				// erase from str[length - shift] to str end
				this->str.erase(str.length() - shift);
			}
			return *this;
		}

		// right shift
		bigint operator>>(const bigint &other) const
		{
			bigint tmp(*this);
			return tmp>>=(other);
		}


		// comparison

		bool operator<(const bigint &other) const
		{
			int l1 = this->str.length();
			int l2 = other.str.length();
			if (l1 < l2)
				return true;
			else if (l1 > l2)
				return false;
			else
				// return lexicographic difference
				return this->str < other.str;
		}

		bool operator==(const bigint &other) const
		{
			return this->str == other.str;
		}

		bool operator>(const bigint &other) const
		{
			return !(*this < other) && !(*this == other);
		}

		bool operator<=(const bigint &other) const
		{
			return !(*this > other);
		}

		bool operator>=(const bigint &other) const
		{
			return !(*this < other);
		}

		bool operator!=(const bigint &other) const
		{
			return !(*this == other);
		}

		friend std::ostream& operator<<(std::ostream &out, const bigint &bi)
		{
			out << bi.str;
			return out;
		}

};
