/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:17:56 by anemet            #+#    #+#             */
/*   Updated: 2025/10/24 21:24:51 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor - initializes the _type member variable
Weapon::Weapon(std::string type): _type(type)
{
	return;
}

Weapon::~Weapon(void)
{
	return;
}

// Getter - returns a constant reference to the _type
const std::string& Weapon::getType(void) const
{
	return (this->_type);
}

// Setter - assigns the new type to the _type member
void Weapon::setType(std::string type)
{
	this->_type = type;
}
