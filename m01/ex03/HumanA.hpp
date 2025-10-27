/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:38:46 by anemet            #+#    #+#             */
/*   Updated: 2025/10/27 09:57:31 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA
{
	private:
		std::string _name;
		// HumanA holds a REFERENCE to a Weapon.
		// This means it doesn't own the weapon, it just refers to one
		// that exists somewhere else. It can never be null.
		Weapon& _weapon;

	public:
		// The constructor requires a name and a Weapon object to refer to.
		// This enforces the rule that HumanA is always armed.
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);

		void attack(void);
};

#endif
