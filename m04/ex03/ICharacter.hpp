/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:27:31 by anemet            #+#    #+#             */
/*   Updated: 2025/10/31 15:35:01 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"

// Forward declaration to prevent circular dependency issues.
// We only need to know that the type AMateria exists here.
class AMateria;

class ICharacter
{
	public:
		// A virtual destructor is essential in any base class intended
		// for polymorphic use, to ensure proper cleanup
		virtual ~ICharacter() {}

		// These are all pure virtual functions, defining the "interface".
		// Any class implementing ICharacter MUST provide these methods.
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
