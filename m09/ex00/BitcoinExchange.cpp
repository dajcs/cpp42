/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:26:17 by anemet            #+#    #+#             */
/*   Updated: 2025/11/11 21:58:46 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange() {}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

// Copy assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}


// Load the price database from the CSV file
void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str()); // ifstream in C++98 expects a C-style string
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open database file");
	}

	std::string line;
	// Skip the header line
	std::getline(file, line); // extracting a line from file stream
								// and storing it in `line` variable (without terminating `\n`)

	while (std::getline(file, line))
	{
		std::stringstream ss(line);  // put the line into a stringstream `ss` for later parsing
		std::string date;
		double price;

		// parse the ss until ',' and put it in variable `date` (without the `,` separator)
		// parse the remaining part of the ss into price
		// the `>>` skips eventual leading white-space, and parses the result as a double)
		if (std::getline(ss, date, ',') && (ss >> price))
		{
			this->_data[date] = price;
		}
	}
	file.close();
}


// Process the input file
void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file");
	}

	std::string line;
	std::getline(file, line); 	// Skip the header

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, separator, valueStr;
		double value;

		// parse 3 space separated strings:
		//	- date
		//	- separator - second test: separator should be '|'
		//	- valueStr
		if (!(ss >> date >> separator >> valueStr) || separator != "|")
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		// value should be a parseable double
		std::stringstream val_ss(valueStr);
		if (!(val_ss >> value))
		{
			std::cerr << "Error: not a valid number." << " => " << valueStr << std::endl;
			continue;
		}

		// value should be positive
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		// value should be <= 1000
		if (value > 1000)
		{
			std::cerr << "Error: too large number." << std::endl;
			continue;
		}

		// Find the exchange rate for the given date
		// The lower_bound() function on a map returns an iterator to the first
		// element whose key is >= to the input date
		// In a sorted map, this means it's either the element with the exact date,
		// or the next date after it.
		std::map<std::string, double>::iterator it = this->_data.lower_bound(date);

		// if iterator points to the begin of the map, and we don't have exact date
		// we print Error message
		// it->first is the key, it->second is the value
		if (it == this->_data.begin() && it->first != date)
		{
			std::cerr << "Error: BTC price before 2009-01-02 not available, input date => " << date << std::endl;
			continue;
		}
		// If the found date is not the exact date, or it is the end of the map
		// then we need to go one step back to get the closest earlier date.
		if (it == this->_data.end() || it->first != date)
		{
			--it;
		}
		std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
	}
	file.close();
}
