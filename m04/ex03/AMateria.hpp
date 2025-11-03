/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:29:31 by anemet            #+#    #+#             */
/*   Updated: 2025/10/31 21:36:30 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AMateria - Abstract Base

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		// The type of the materia (e.g., "ice", "cure")
		std::string _type;

	public:
		// --- Orthodox Canonical Form ---
		AMateria(); // Default Constructor
		AMateria(std::string const & type); // Parameterized constructor
		AMateria(const AMateria& other); // Copy constructor
		AMateria& operator=(const AMateria& other); // Assignment operator
		virtual ~AMateria(); // Virtual Destructor

		// --- Member Functions ---
		std::string const & getType() const; // Returns the materia type

		// Pure virtual clone() function. This forces every concrete Materia
		// to be able to create a copy of itself.
		virtual AMateria* clone() const = 0;

		// A virtual use() function. A base implementation could be provided,
		// but derived classes will almost always override it.
		virtual void use(ICharacter& target);
};

#endif
