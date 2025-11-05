/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:22:38 by anemet            #+#    #+#             */
/*   Updated: 2025/11/05 20:24:49 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

// The virtual destructor needs an implementation, even if it's empty
Base::~Base()
{
	// We can put a message here for debugging e.g.:
	// std::cout << "Base destructor called" << std::endl;
}
