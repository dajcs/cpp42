/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:47:36 by anemet            #+#    #+#             */
/*   Updated: 2025/11/01 12:50:15 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// --- Orthodox Canonical Form ---
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();

		// -- Overridden Member Functions ---
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
