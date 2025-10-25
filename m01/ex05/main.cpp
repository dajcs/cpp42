/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:09:36 by anemet            #+#    #+#             */
/*   Updated: 2025/10/25 17:17:08 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl harl;

	std::cout << "---Testing DEBUG ---" << std::endl;
	harl.complain("DEBUG");

	std::cout << "---Testing INFO ---" << std::endl;
	harl.complain("INFO");

	std::cout << "---Testing WARNING ---" << std::endl;
	harl.complain("WARNING");

	std::cout << "---Testing ERROR ---" << std::endl;
	harl.complain("ERROR");

	std::cout << "---Testing a NON-EXISTENT LEVEL ---" << std::endl;
	harl.complain("SOME_OTHER_LEVEL");

	return 0;
}
