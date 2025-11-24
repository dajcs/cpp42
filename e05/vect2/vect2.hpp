/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:24:31 by anemet            #+#    #+#             */
/*   Updated: 2025/11/24 15:53:55 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class vect2
{
	private:
		int x;
		int y;

	public:
		// Orthodox Canonical Form
		vect2() // default constructor
		{
			this->x = 0;
			this->y = 0;
		}
		vect2(int x, int y)  // parametrized constructor
		{
			this->x = x;
			this->y = y;
		}
		vect2(const vect2 &other) // copy constructor
		{
			*this = other;
		}
		vect2& operator=(const vect2 &other) // copy assignment operator
		{
			if (this != &other)
			{
				this->x = other.x;
				this->y = other.y;
			}
			return *this;
		}

		// Destructor
		~vect2() {};	// we're not allocating memory, nothing to do

		// pre-increment
		// increment x,y and return current object
		vect2& operator++()
		{
			++x;
			++y;
			return *this;
		}

		// post-increment
		// create copy, increment x,y, return copy with original x,y
		vect2 operator++(int)
		{
			vect2 tmp = vect2(*this);
			++x;
			++y;
			return tmp;
		}

		// pre-decrement
		// decrement x,y and return current object
		vect2& operator--()
		{
			--x;
			--y;
			return *this;
		}

		// post-decrement
		// create copy, decrement x,y, return copy with original x, y
		vect2 operator--(int)
		{
			vect2 tmp = vect2(*this);
			--x;
			--y;
			return tmp;
		}

		// operator[] read-only access to a const vect2
		const int &operator[](int index) const
		{
			return (index == 0) ? x : y;
		}

		// operator[] read/write access to components
		// returns reference to component which can be modified
		int& operator[](int index)
		{
			if (index == 0)
			{
				return this->x;
			}
			else
				return this->y;
		}

		// operator+=
		// inplace +, adds the other vector to the current one
		// and returns a reference to itself
		vect2& operator+=(const vect2& other)
		{
			this->x += other.x;
			this->y += other.y;
			return *this;
		}

		// operator-=
		// inplace -, subtracts other vector and returns reference to itself
		vect2& operator-=(const vect2& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		}

		// operator+
		vect2 operator+(const vect2& other) const
		{
			vect2 v2(*this);
			return v2 += other;
		}

		// operator-
		vect2 operator-(const vect2& other)
		{
			vect2 v2(*this);
			return v2 -= other;
		}

		// operator- (unary minus)
		// return new vector with both components negated
		vect2 operator-()
		{
			return vect2(-x, -y);
		}

		// operator*
		vect2 operator*(const int scalar) const
		{
			vect2 v2(*this);
			v2.x *= scalar;
			v2.y *= scalar;
			return v2;
		}

		// operator*=
		// multiplies components by scalar and returns reference to itself
		vect2& operator*=(const int scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			return *this;
		}

		// comparison ==
		bool operator==(const vect2& other) const
		{
			return (x == other.x && y == other.y) ? true : false;
		}

		bool operator!=(const vect2& other) const
		{
			return !(*this == other);
		}


	// scalar multiplication if form of `3 * v`
	friend vect2 operator*(const int scalar,const vect2 other)
	{
		vect2 v2(other);
		return v2 * scalar;
	}

	// print vect2 on output stream
	friend std::ostream& operator<<(std::ostream &os, const vect2 &v2)
	{
		os << "{" << v2.x << ", " << v2.y << "}";
		return os;
	}

};

