/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:05:17 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 18:22:28 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap(const std::string& name):
	// 1. Explicitly call the ClapTrap constructor.
	// With virtual inheritance, the most derived class is responsible for
	// constructing the virtual base class.
	// We pass it the modified name (as per subject request)
	ClapTrap(name + "_clap_name"),
	// 2. Call the ScavTrap and FragTrap constructors.
	// We can pass them the name as well
	ScavTrap(name),
	FragTrap(name)
{
	// 3. Set the DiamondTrap-specific name.
	this->_name = name;

	// 4. Set the attributes according to the project specification.
	// We explicitly state which parent's attributes to use to avoid ambiguity.
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap " << this->_name << " is ready for action!" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " has been deactivated!" << std::endl;
}

// ------------ Member Functions --------------

// Use ScavTrap's attack, by specifying ScavTrap::
void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

// The DiamondTrap's specific `whoAmI` function
void DiamondTrap::whoAmI(void)
{
	// this->_name refers to the DiamondTrap's own private name attribute.
	// ClapTrap::_name refers to the name attribute in the shared ClapTrap base
	std::cout << "My DiamondTrap name is " << this->_name
				<< " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
