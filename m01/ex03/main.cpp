/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:07:28 by anemet            #+#    #+#             */
/*   Updated: 2025/10/24 22:37:51 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{

	{
		// Create a weapon on the stack
		Weapon club("crude spiked club");

		// Create Bob with a reference to `club`
		// Bob is now linke to the original `club` object
		HumanA bob("Bob", club);
		bob.attack();

		// Change the original `club` object's type
		club.setType("some other type of club");

		// Because Bob holds a reference, his weapon's type is also updated.
		bob.attack();
	}

	{
		// Create another weapon on the stack
		Weapon club("crude spiked club");

		// Create Jim. He is initialized without a weapon
		HumanB jim("Jim");

		// Give Jim's weapon pointer the address of the `club` object.
		jim.setWeapon(club);
		jim.attack();

		// Change the original `club` object's type.
		club.setType("some other type of club");

		// Because Jim's pointer points to `club`, his attack reflects the change
		jim.attack();

	}
}
