/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:13:44 by anemet            #+#    #+#             */
/*   Updated: 2025/11/11 15:25:43 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>	// std::cout
# include <string>		// std::string
# include <map>			// std::map
# include <fstream>		// file streams (std::ifstream for input)
# include <sstream>		// std::stringstream - useful for parsing strings
# include <algorithm>	// various functions e.g., searching, sorting, counting
# include <stdexcept>	// standard exception classes

class BitcoinExchange
{
	private:
		// We use a std::map to store the Bitcoin price data
		// map stores elements in a key-value pair
		// here the key is a string (the date) and the value is a double (price)
		// map automatically sorts the keys, which is useful for finding the closest date
		std::map<std::string, double> _data;

	public:
		// Orthodox Canonical Form
		BitcoinExchange(); // Default Constructor
		BitcoinExchange(const BitcoinExchange &other); // Copy constructor
		BitcoinExchange &operator=(const BitcoinExchange &other); // Copy assignment operator
		~BitcoinExchange(); // Destructor

		// Public member function to load the price database
		void loadDatabase(const std::string& filename);

		// Public member function to process the input file
		void processInput(const std::string& filename);
};

#endif
