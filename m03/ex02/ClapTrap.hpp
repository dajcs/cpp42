/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:10:43 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 13:48:11 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	// private -> protected
	// protected still inaccessible from the outside world (like 'private')
	// but they ARE accessible by any classes that inherit from ClapTrap
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		// Default constructor, needs no parameters, good to have one
		ClapTrap();
		// Constructor, needs a name to intitialize the object
		ClapTrap(const std::string& name);
		//Destructor
		~ClapTrap();

		// public member functions
		// we will "override" the attack() function in ScavTrap
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
