/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:16:53 by anemet            #+#    #+#             */
/*   Updated: 2025/11/01 12:23:14 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// --- Orthodox Canonical Form ---
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();

		// --- Overridden Member Functions ---
		// Implements the pure virtual function from AMateria
		virtual AMateria* clone() const;
		// Provides a specific implementation for 'use'
		virtual void use(ICharacter& target);
};

#endif
