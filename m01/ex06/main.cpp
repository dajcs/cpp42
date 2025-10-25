/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:09:36 by anemet            #+#    #+#             */
/*   Updated: 2025/10/25 21:58:13 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <log_level>" << std::endl;
		std::cerr << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}

	Harl harl;
	harl.complain(argv[1]);
	
	return 0;
}
