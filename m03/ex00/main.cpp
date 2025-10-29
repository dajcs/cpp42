/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:23:50 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 10:28:41 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	// Creating an instance of ClapTrap called 'clappy'
	ClapTrap clappy("Clappy");

	// Calling member function the the 'clappy' object
	clappy.attack("a random stranger");
	clappy.takeDamage(5);
	clappy.beRepaired(3);
	clappy.takeDamage(8);
	clappy.takeDamage(1); // Trying to take damage when alread at 0 HP
	clappy.beRepaired(5); // Trying to repair with no HP

	std::cout << std::endl;

	// Creating another instance to show constructor/destructor calls
	ClapTrap trappy("Trappy");
	trappy.attack("another random stranger");

	return 0;
	// 'clappy' and 'trappy' destroyed at the end of this function
	// and their destructors will be called
}
