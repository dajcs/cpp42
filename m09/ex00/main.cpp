/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:54:10 by anemet            #+#    #+#             */
/*   Updated: 2025/11/12 08:55:44 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Use: " << argv[0] << " <input file>" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange btc;
		btc.loadDatabase("data.csv");
		btc.processInput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
