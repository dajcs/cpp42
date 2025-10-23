/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:27:16 by anemet            #+#    #+#             */
/*   Updated: 2025/10/23 22:07:05 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	This function crates a Zombie on the HEAP

	C++ `new` keyword
		1.)	It allocates enough memory on the heap to hold a Zombie object
		2.)	It calls the Zombie constructor (`Zombie::Zombie(name)`) to initialize that memory
		3.)	It returns a pointer of type `Zombie*` to the newly created object.

	This object is on the heap and it will continue to exist until it is explicitly destoryed
	with the `delete` keyword. This allows us to return the pointer and use the object
	outside of this function's scope.
*/
Zombie* newZombie(std::string name)
{
	return(new Zombie(name));
}
