/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:56:36 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 18:05:02 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// DiamondTrap inherits the same member variables from ScavTrap and FragTrap
// (based from ClapTrap) but since we have virtual inheritance, a single
// shared instance will be created
class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		// This is the private name attribute specific to DiamondTrap, as requested.
		// It "shadows" the _name attribute in the ClapTrap base class.
		std::string _name;

	public:
		// The Constructor takes the DiamondTrap's own name
		DiamondTrap(const std::string& name);
		// Destructor
		~DiamondTrap();

		// The subject requires that DiamondTrap should use ScavTrap's attack.
		// We'll call it explicitly by using the scope resolution operator.
		void attack(const std::string& target);

		// The special function for DiamondTrap
		void whoAmI(void);
};

#endif
