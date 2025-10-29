/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:00:12 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 17:55:58 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"  // We must include the header of the base class

// FragTrap is another public child of ClapTrap
// adding "virtual" to prevent double ClapTrap member variable instance
class FragTrap: public virtual ClapTrap
{
	public:
		// Constructor for FragTrap
		FragTrap(const std::string& name);
		// Destructor for FragTrap
		~FragTrap();

		// FragTrap will also have a different version of attack
		void	attack(const std::string& target);

		// The special ability unique to FragTrap
		void	highFivesGuys(void);
};

#endif
