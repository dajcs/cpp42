/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:32:13 by anemet            #+#    #+#             */
/*   Updated: 2025/10/24 21:38:21 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

/* Constructor implementation
	Reference members MUST be initialized in the member initializer list.
	This is the only way to "bind" the reference to an object.
*/
HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon)
{
	return;
}

HumanA::~HumanA(void)
{
	return;
}

void HumanA::attack(void)
{
	/* We can use the dot (.) operator on the reference,
		just as if it were the object itself.
	*/
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
