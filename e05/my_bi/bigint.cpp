/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:38:19 by anemet            #+#    #+#             */
/*   Updated: 2025/11/18 16:54:11 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

// default constructor
bigint::bigint()
{
	this->str = "0";
}

// parametrized constructor
bigint::bigint(unsigned int n)
{
	std::stringstream ss;
	ss << n;
	this->str = ss.str();
}

// copy constructor
bigint::bigint(const bigint& other)
{
	*this = other;
}
