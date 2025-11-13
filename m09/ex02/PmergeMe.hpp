/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:21:11 by anemet            #+#    #+#             */
/*   Updated: 2025/11/13 09:43:35 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <exception>

# include <sys/time.h>	// C headers for timing


// PmergeMe class
// encapsulates parsing, sorting, and displaying
class PmergeMe
{
	public:
		// --- Orthodox Canonical Form (OCF) ---
		PmergeMe();									// Default Constructor
		PmergeMe(const PmergeMe& src);				// Copy Constructor
		PmergeMe& operator=(const PmergeMe& rhs);	// Copy Assignment Operator
		~PmergeMe();								// Destructor

		// --- Public Interface ---
		// The main function that will be called from the main.cpp
		// Orchestrates the entire process from parsing to printing the results
		void run(int argc, char **argv);


	private:
		// --- Data Storeage ---
		// Using two different containers - as per subject requirement
		std::vector<int> _vec;
		std::deque<int> _deq;

		// --- Time Measurement ---
		double _timeVec;
		double _timeDeq;

		// --- Parsing and Validation
		void parseAndValidate(int argc, char **argv);

		// --- Sorting Logic ---
		// Implementing the algorithm separately for each container (subject req)
		// rather than using a generic template function

		// sorting std::vector
		void sortVector();
		void mergeInsertSort(std::vector<int>& vec);
		void insertionSort(std::vector<int>& subVec); // Helper for small chunks

		// sorting std::deque
		void sortDeque();
		void mergeInsertSort(std::deque<int>& deq);
		void insertionSort(std::deque<int>& subDeq); // Helper for small chunks

		// --- Utility functions
		long long getCurrentTimeMicros();
		void printResults();

		template<typename T>
		void printContainer(const T& container, const std::string& prefix);

		// --- Custome Exception Class ---
		// inheriting from std::exception
		class ValidationException : public std::exception
		{
			public:
				// the `what()` method returns a C-style string explaining the error
				// the `throw()` is a C++98 way of saying this function won't throw exception itself
				virtual const char* what() const throw();
		};
};

#endif
