/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:55:34 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 14:11:56 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"  // we have to include the header of the base class

// C++ inheritance syntax
// `class ScavTrap : public ClapTrap' means that ScavTrap is a publicly derived
// class of ClapTrap. It gets all the public and protected members of ClapTrap.
class ScavTrap: public ClapTrap
{
	public:
		// Constructor for ScavTrap
		ScavTrap(const std::string& name);
		// Destructor for ScavTrap
		~ScavTrap();

		// "overriding" the ClapTrap attack with ScavTrap's own version
		void	attack(const std::string& target);

		// new member function specific to ScavTrap
		void	guardGate();
};


#endif
