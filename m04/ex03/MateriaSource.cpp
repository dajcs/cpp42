/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:14:24 by anemet            #+#    #+#             */
/*   Updated: 2025/11/01 14:29:57 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// --- Orthodox Canonical Form ---

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		this->_templates[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._templates[i])
		{
			this->_templates[i] = other._templates[i]->clone();
		}
		else
		{
			this->_templates[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->_templates[i])
			{
				delete this->_templates[i];
			}
			if (other._templates[i])
			{
				this->_templates[i] = other._templates[i]->clone();
			}
			else
			{
				this->_templates[i] = NULL;
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	// The source owns its templates and must delete them
	for (int i = 0; i < 4; ++i)
	{
		if (this->_templates[i])
		{
			delete this->_templates[i];
		}
	}
}


// --- Implemented Interface Functions ---

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m) return;
	for (int i = 0; i < 4; ++i)
	{
		if (!this->_templates[i])
		{
			// The source takes ownership of the Materia pointer
			this->_templates[i] = m;
			return;
		}
	}
	// If the template list is full, the passed materia is not learned.
	// The caller is responsible for deleting it in this case
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_templates[i] && this->_templates[i]->getType() == type)
		{
			// Return a new clone of the learned template
			return this->_templates[i]->clone();
		}
	}
	// Return 0 (NULL) if type is unknown
	return 0;
}
