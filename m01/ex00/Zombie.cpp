/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:05:17 by anemet            #+#    #+#             */
/*   Updated: 2025/10/23 20:20:39 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>  // std::cout
#include "Zombie.hpp" // Zombie class definition

/* Code for the Constructor
	The syntax: `Zombie::Zombie(...)`
		means we're defining the `Zombie` constructor which is member of the `Zombie` class
	_name(name) is a "member initializer list"
		it is more efficient than assigning inside the constructor's curly braces
*/
Zombie::Zombie(std::string name): _name(name)
{
	// The constructor body is empty because the "member initializer list" did all the work.
	// We could write `this->_name = name;` inside the braces, but better to use the initializer
	return;
}

/* Code for the Destructor
	This runs whenever a Zombie object is destroyed.
	In our case we just print a message to see when this happens.
	In real world we would free here the allocated memory or close the files associated with the object
*/
Zombie::~Zombie(void)
{
	std::cout << this->_name << ": Has been destroyed." << std::endl;
	return;
}

/* Code for Member function `announce`
*/
void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
