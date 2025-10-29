/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:23:50 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 14:47:19 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "---=== Testing ClapTrap ===---" << std::endl;
	{
		// Creating an instance of ClapTrap called 'clappy'
		ClapTrap clappy("Clappy");

		std::cout << std::endl;

		// Calling member function the the 'clappy' object
		clappy.attack("a random stranger");
		clappy.takeDamage(5);
		clappy.beRepaired(3);
		clappy.takeDamage(8);
		clappy.takeDamage(1); // Trying to take damage when alread at 0 HP
		clappy.beRepaired(5); // Trying to repair with no HP

		// Creating another instance to show constructor/destructor calls
		ClapTrap trappy("Trappy");
		trappy.attack("another random stranger");

		std::cout << std::endl;

	}	// 'clappy' and 'trappy' destroyed at the end of this block
		// and their destructors will be called automatically


	std::cout << "\n ---=== Testing ScavTrap ===---" << std::endl;
	{
		// Creating a ScavTrap.
		// We should get first a message from ClapTrap constructor,
		// and then anoter one from the ScavTrap constructor
		ScavTrap scavvy("Scavvy");

		std::cout << std::endl;

		// Scavvy uses its own overridden attack()
		scavvy.attack("the gate");

		// Scavvy uses the takeDamage() and beRepaired() inherited from ClapTrap
		scavvy.takeDamage(30);
		scavvy.beRepaired(15);
		scavvy.takeDamage(85);
		scavvy.takeDamage(1);  // is already at 0

		// Scavvy uses its special ability
		scavvy.guardGate();

		std::cout << std::endl;

	} // scavvy automatically destroyed at the end of the block. We should get messages
		// first from ScavTrap destructor, then from ClapTrap destructor (reverse order)

	return 0;
}
