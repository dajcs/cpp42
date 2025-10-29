/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:10:46 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 15:20:53 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// FragTrap Constructor
FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	// Construction message for FragTrap
	std::cout << "FragTrap " << this->_name << " has been assembled!" << std::endl;
}

// FragTrap Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has been disassembled!" << std::endl;
}

// FragTrap's own version of attack function
void FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " can't attak, it's incapaciateted!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " can't attack, its battery is dead!" << std::endl;
		return;
	}
	// if attack is possible
	this->_energyPoints--;
	// A unique message for FragTrap's attack
	std::cout << "FragTrap " << this->_name << " unleashes a chaotic attack on " << target
				<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

// FragTrap's special ability
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " cheerfully requests a high five from everyone!"
				<< std::endl;
}
