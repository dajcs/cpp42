/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:02:07 by anemet            #+#    #+#             */
/*   Updated: 2025/11/01 17:41:44 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// --- Helper functions for cleaning up inventory ---

// Deletes all Materia in the inventory
void Character::_clearInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

// Performs a deep copy of another characters's inventory
void Character::_copyInventory(const Character& other)
{
	for (int i; i < 4; ++i)
	{
		if (other._inventory[i])
		{
			// Use clone() for a deep copy of the Materia
			this->_inventory[i] = other._inventory[i]->clone();
		}
		else
		{
			this->_inventory[i] = NULL;
		}
	}
}


// --- Orthodox Canonical Form ---

// Default constructor
Character::Character() : _name("Default")
{
	for (int i = 0; i < 4; ++i)
	{
		this->_inventory[i] = NULL;
	}
}

// "named" constructor
Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
	{
		this->_inventory[i] = NULL;
	}
}

// copy Constructor
Character::Character(const Character& other) : ICharacter()
{
	this->_name = other._name;
	this->_copyInventory(other);
}

// assignment copy Operator
Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		// 1. Delete old inventory to prevent leaks
		this->_clearInventory();
		// 2. Perform a deep copy of the new inventory
		this->_copyInventory(other);
	}
	return *this;
}

Character::~Character()
{
	// The Character "own" its inventory, so ti must clean it up
	this->_clearInventory();
}


// --- Implemented Interface Functions ---

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (!m) return;
	for (int i = 0; i < 4; ++i)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		// The Character give up ownersip, but does not delete the Materia.
		// The caller is now responsible for this pointer
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
	}
}
