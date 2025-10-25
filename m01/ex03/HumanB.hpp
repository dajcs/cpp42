/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:47:35 by anemet            #+#    #+#             */
/*   Updated: 2025/10/25 16:50:28 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
	private:
		std::string _name;
		// HumanB holds a POINTER to a Weapon.
		// A pointer can be NULL (0), representing that HumanB is unarmed.
		Weapon* _weapon;

	public:
		// The constructor only needs a name. The weapon can be set later.
		HumanB(std::string name);
		~HumanB(void);

		// A setter to give HumanB a wapon (or change it)
		void setWeapon(Weapon& weapon);
		void attack(void);
};


#endif
