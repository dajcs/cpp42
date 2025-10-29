/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:23:50 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 18:42:15 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

/*

       ClapTrap
        /   \
       /     \
ScavTrap   FragTrap
       \     /
        \   /
      DiamondTrap

1. The Diamond Problem:
	- ScavTrap inherits a copy of all ClapTrap's members (_name, _hitPoints, ...)
	- FragTrap also inherits a copy of all of ClapTrap's members
	- When DiamondTrap inherits from both ScavTrap and FragTrap, it gets two separate
		copies of the ClapTrap members
	- This causes ambiguity.

2. Solution: virtual inheritance
	- C++ gives us the `virtual` keyword for inheritance, this makes sure to have only
		one instance of the multiple inherited variables from the same base class.

3.	Scope Resolution (::) for member function ambiguity
	- Even with virtual inheritance, we can have functions with same name and different
		actions (e.g., attack()). Here we can use the scope resolution operator (::)
		to specify which function we want to use. For example, ScavTrap::attack()

4.	Variable Shadowing (-Wshadow)
	- The project asks us to create a `_name` attribute in `DiamondTrap` that is the
		same as the one in `ClapTrap`. This is **variable shadowing**. The local `_name`
		"shadows" or "hides" the `_name` from the base class.  The `-Wshadow` compiler
		flag is used to warn when this happens, but in our case this is the requirement.

*/

int main(void)
{
	std::cout << "---=== Testing ClapTrap ===---" << std::endl;
	{
		// Creating an instance of ClapTrap called 'clappy'
		ClapTrap clappy("C-3PO");

		std::cout << std::endl;

		// Calling member function the the 'clappy' object
		clappy.attack("an enemy scavenger");
		clappy.takeDamage(5);
		clappy.beRepaired(3);
		clappy.takeDamage(8);
		clappy.takeDamage(1); // Trying to take damage when alread at 0 HP
		clappy.beRepaired(5); // Trying to repair with no HP

		// Creating another instance to show constructor/destructor calls
		ClapTrap trappy("Trappy");
		trappy.attack("a stranger scavenger");

		std::cout << std::endl;

	}	// 'clappy' and 'trappy' destroyed at the end of this block
		// and their destructors will be called automatically


	std::cout << "\n ---=== Testing ScavTrap ===---" << std::endl;
	{
		// Creating a ScavTrap.
		// We should get first a message from ClapTrap constructor,
		// and then anoter one from the ScavTrap constructor
		ScavTrap scavvy("R2-D2");

		std::cout << std::endl;

		// Scavvy uses its own overridden attack()
		scavvy.attack("the Sith");

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


	std::cout << "\n ---=== Testing FragTrap ===---" << std::endl;
	{
		// Creating a FragTrap.
		// Observe the construction chain ClapTrap - FragTrap
		FragTrap fraggy("BB-8");

		std::cout << std::endl;

		// Calling Fraggy's unique attack function
		fraggy.attack("the Death-Star");
		// Calling functions inherited from ClapTrap
		fraggy.takeDamage(50);
		fraggy.beRepaired(25);
		// Calling Fraggy's special ability
		fraggy.highFivesGuys();

		std::cout << std::endl;

	}	// fraggy automatically destroyed at the end of the block. We should get messages
		// first from FragTrap destructor, then from ClapTrap destructor (reverse order)


	std::cout << "\n ---=== Testing DiamondTrap ===---" << std::endl;
	{
		DiamondTrap diamondy("Skywalker");

		std::cout << std::endl;
		diamondy.whoAmI();
		std::cout << std::endl;

		// Uses ScavTrap's attack
		diamondy.attack("Darth Vader");
		// Uses FragTrap's special ability
		diamondy.highFivesGuys();
		// Uses ScavTrap's special ability
		diamondy.guardGate();
		// Uses ClapTrap's inherited ability
		diamondy.takeDamage(40);
		diamondy.beRepaired(20);

		std::cout << std::endl;

	} // Observe the full destruction chain:
		// DiamondTrap, FragTrap, ScavTrap, ClapTrap

	return 0;
}
