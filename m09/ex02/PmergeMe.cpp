/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:44:06 by anemet            #+#    #+#             */
/*   Updated: 2025/11/13 16:24:12 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The Merge-Insertion Sort (Ford-Johnson) Algorithm

	example L = [5, 1, 4, 2, 3]

Step 1: Pairing and initial Comparisions

	1.) Pairing the elements, if odd number of elements, the last one is a "stray"
		L = [5, 1, 4, 2, 3]
		Pairs: (5, 1), (4, 2)
		Stray: 3
	2.) Compare each pair:
		(5, 1) -> Larger: 5, Smaller: 1
		(4, 2) -> Larger: 4, Smaller: 2
	3.) Creae two Lists: a list of the "larger", and a list of "smaller" (aka "pendants")
		Larger: [5, 4]
		Pendants: [1, 2]
		We "remember" which pendant belongs to which larger element (5, 1) and (4, 2)

Step 2: Recursive Sort (Building the Main Chain)

	1.) Sort the "Larger" list recursively with our algorithm
		[5, 4] -> [4, 5]
	2.) Main Chain a = [a1, a2] = [4, 5]
	3.) Re-order Pendants: We reorder the pendants to match the new Main Chain
		b = [b1, b2] = [2, 1]

Step 3: "Smart" Insertion Phase
	1.) Insert the first Pendant.
		we know b1 < a1 => we perform a binary search the part of Main Chain before a1
		- Main Chain: [4, 5]
		- Pendant to insert: b1 = 2
		- Search space: [4] (the part of the chain before and including a1 = 4)
		- Sorted List: S = [2, 4, 5]
	2.) Insert remaining pendants.
		- Naive approach continue with b2, b3, ...
		- Ford-Johnson Magic: insert pendants in Jacobsthal order (see explanation below)
			to keep binary search spaces as efficient as possible
		- Sorted List: S = [1, 2, 4, 5]
	3.) Insert the Stray: using a standard binary search
		- Sorted List: S = [1, 2, 3, 4, 5]


Elaborating the "Smart" Insertion:
---------------------------------

The key to minimizing comparisons comes from Step 3.2.
	Why not just insert b2, then b3, then b4?

If we had a main chain [a1, a2, a3, a4, a5]
		  and pendants [b1, b2, b3, b4, b5].

After inserting b1, our list is [...b1..., a1, a2, a3, a4, a5].

If we insert b2 next: We binary search the elements before a2.
This search space has 3 elements (...b1..., a1, a2). Max 2 comparisons.
Then we insert b3: We search elements before a3.
This space now includes b2, so it has 5 elements (...b1..., a1, ...b2..., a2, a3). Max 3 comparisons.

If we use the Ford-Johnson order (b3, then b2):
Insert b3 first: We search elements before a3.
This space has 4 elements (...b1..., a1, a2, a3). Max 2 comparisons.
Then we insert b2: We search elements before a2.
This space has 3 elements (...b1..., a1, a2). Max 2 comparisons.

In the worst case, the Ford-Johnson order (b3, b2) costs 2 + 2 = 4 comparisons,
while the naive order (b2, b3) costs 2 + 3 = 5 comparisons.
The algorithm saves a comparison by inserting b3 before b2 to optimize the binary search space.

The algorithm generalizes this by grouping pendants ( b3, b2 ), then ( b5, b4 ),
then ( b11, b10, ... b6 ), etc., following a pattern related to Jacobsthal numbers,
to always ensure the binary search is as efficient as possible.

Jacobsthal numbers: similar to the Fibonacci numbers.
J_0 = 0
J_1 = 1
...
J_n = J_{n-1} + 2 * J_{n-2}

The sequence starts: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, ...

J_n = (2^n - (-1)^n) / 3

*/

#include "PmergeMe.hpp"
#include <sstream>		// std::stringstream -> used for safe string-to-int conversion
#include <algorithm>	// std::sort (for validation) and std::lower_bound (binary search)
#include <utility>		// std::pair (to group numbers)
#include <climits>		// LONG_MAX, used in parsing validation

// Default Constructor
PmergeMe::PmergeMe() : _timeVec(0.0), _timeDeq(0.0) {}

// Copy Constructor
PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src; // Delegate to the assignment operator
}

// Copy Assignment Operator
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
		this->_timeVec = rhs._timeVec;
		this->_timeDeq = rhs._timeDeq;
	}
	return *this;
}

// Destructor
PmergeMe::~PmergeMe() {}


//=============================================
// 		Public Interface
//=============================================

void PmergeMe::run(int argc, char **argv)
{
	parseAndValidate(argc, argv); // Can throw exception

	printContainer(_vec, "Before:");

	// Time and execute the sort for std::vector
	long long startVec = getCurrentTimeMicros();
	sortVector();
	long long endVec = getCurrentTimeMicros();
	_timeVec = static_cast<double>(endVec - startVec);

	// TIme and execute the sort for std::deque
	long long startDeq = getCurrentTimeMicros();
	sortDeque();
	long long endDeq = getCurrentTimeMicros();
	_timeDeq = static_cast<double>(endDeq - startDeq);

	printResults();
}


//=============================================
// 		Parsing and Validation
//=============================================

void PmergeMe::parseAndValidate(int argc, char **argv)
{
	std::vector<int> tempVec;
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		std::stringstream ss(arg);
		long num;

		// check if valid number and withing int range
		ss >> num;
		if (ss.fail() || !ss.eof() || num < 0 || num > INT_MAX)
		{
			throw ValidationException();
		}
		tempVec.push_back(static_cast<int>(num));
	}

	// if checks pass, populate the actual member containers
	this->_vec.assign(tempVec.begin(), tempVec.end());
	this->_deq.assign(tempVec.begin(), tempVec.end());
}


//=============================================
// 		Sorting Logic for std::vector
//=============================================

void PmergeMe::sortVector()
{
	if (_vec.size() > 1)
	{
		mergeInsertSort(_vec);
	}
}

// Ford-Johnson algorithm implementation for std::vector
void PmergeMe::mergeInsertSort(std::vector<int>& vec)
{
	// for small sequences a simple insertion sort is more efficient
	if (vec.size() <= 1)
	{
		// insertionSort(vec);
		return;
	}

	// Step 1: Pairing and saving the straggler
	int straggler = -1;
	if (vec.size() % 2 != 0)
	{
		// C++ doesn't return the popped element
		// we'll have to save it separately if we need it
		straggler = vec.back();
		vec.pop_back();
	}

	// Step 2: Create pairs and sort them internally
	// (larger first, smaller second)
	std::vector< std::pair<int, int> > pairs;
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (vec[i] < vec[i+1])
			pairs.push_back(std::make_pair(vec[i+1], vec[i]));
		else
			pairs.push_back(std::make_pair(vec[i], vec[i+1]));
	}

	// Step 3: Create mainChain and pendChain
	std::vector<int> mainChain, pendChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}

	// Step 4: Recursively sort the mainChain
	mergeInsertSort(mainChain);

	// Step 5: Insert pendChain elements into mainChain using Jacobsthal seq
	// This minimizes comparisons by keeping the search range for binary search
	// (std::lower_bound) as large as possible

	// Jacobsthal insertion sequence
	int jacobsthal[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691};
	size_t last_inserted = 0;
	for (int i = 0; i < 15; ++i)
	{
		// insertion upper bound: the minimum of jacobstahl bound or pendChain size
		size_t limit = std::min(static_cast<size_t>(jacobsthal[i]), pendChain.size());
		// Insert elements in reverse order from the current Jacobsthal limit
		// down to the last inserted position
		for (size_t j = limit; j > last_inserted; --j)
		{
			std::vector<int>::iterator it =
					std::lower_bound(mainChain.begin(), mainChain.end(), pendChain[j-1]);
			mainChain.insert(it, pendChain[j-1]);
		}
		if (limit == pendChain.size())
			break;
		last_inserted = limit;
	}

	// Step 6: Isert the straggler if it exists
	if (straggler > -1)
	{
		std::vector<int>::iterator it =
				std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	// result in reference vec
	vec = mainChain;
}

// insertionSort for short vectors
void PmergeMe::insertionSort(std::vector<int>& subVec)
{
	// 1. Start loop from the second element (i = 1) to the end of the vector
	// 		The first element (at i = 0) is considered our initial "sorted" part
	for (size_t i = 1; i < subVec.size(); ++i)
	{
		// 2. we pick the next element and store it in 'key'
		int key = subVec[i];

		// 3. we use 'j' to scan backwards through the sorted part of the array
		//		starting at the element just before our 'key'
		int j = i - 1;

		// 4. loop to find the correct insertion point
		// 		it runs as long as we haven't reached the beginning of the array (j >= 0)
		//		AND the element in the sorted part (subVec[j]) is greater than our 'key'
		while (j >= 0 && subVec[j] > key)
		{
			// 5. if subVec[j] > key we shift the element one position to the right
			subVec[j+1] = subVec[j];
			j--; // move left to the next element
		}
		// the loop to find the correct insertion point ended
		// The position will be 'j+1' because the loop stops when subVec[j] <= key
		subVec[j+1] = key;
	}
}


//=============================================
// 		Sorting Logic for std::deque
//=============================================


void PmergeMe::sortDeque()
{
	if (_deq.size() > 1)
	{
		mergeInsertSort(_deq);
	}
}

// Ford-Johnson algorithm implementation for std::deque
void PmergeMe::mergeInsertSort(std::deque<int>& deq)
{
	// for small sequences a simple insertion sort is more efficient
	if (deq.size() <= 1)
	{
		// insertionSort(deq);
		return;
	}

	// Step 1: Pairing and saving the straggler
	int straggler = -1;
	if (deq.size() % 2 != 0)
	{
		// C++ doesn't return the popped element
		// we'll have to save it separately if we need it
		straggler = deq.back();
		deq.pop_back();
	}

	// Step 2: Create pairs and sort them internally
	// (larger first, smaller second)
	std::deque< std::pair<int, int> > pairs;
	for (size_t i = 0; i < deq.size(); i += 2)
	{
		if (deq[i] < deq[i+1])
			pairs.push_back(std::make_pair(deq[i+1], deq[i]));
		else
			pairs.push_back(std::make_pair(deq[i], deq[i+1]));
	}

	// Step 3: Create mainChain and pendChain
	std::deque<int> mainChain, pendChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}

	// Step 4: Recursively sort the mainChain
	mergeInsertSort(mainChain);

	// Step 5: Insert pendChain elements into mainChain using Jacobsthal seq
	// This minimizes comparisons by keeping the search range for binary search
	// (std::lower_bound) as large as possible

	// Jacobsthal insertion sequence
	int jacobsthal[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691};
	size_t last_inserted = 0;
	for (int i = 0; i < 15; ++i)
	{
		// insertion upper bound: the minimum of jacobstahl bound or pendChain size
		size_t limit = std::min(static_cast<size_t>(jacobsthal[i]), pendChain.size());
		// Insert elements in reverse order from the current Jacobsthal limit
		// down to the last inserted position
		for (size_t j = limit; j > last_inserted; --j)
		{
			std::deque<int>::iterator it =
					std::lower_bound(mainChain.begin(), mainChain.end(), pendChain[j-1]);
			mainChain.insert(it, pendChain[j-1]);
		}
		if (limit == pendChain.size())
			break;
		last_inserted = limit;
	}

	// Step 6: Isert the straggler if it exists
	if (straggler > -1)
	{
		std::deque<int>::iterator it =
				std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	// result in reference deq
	deq = mainChain;
}

// insertionSort for short deques
void PmergeMe::insertionSort(std::deque<int>& subDeq)
{
	// 1. Start loop from the second element (i = 1) to the end of the deque
	// 		The first element (at i = 0) is considered our initial "sorted" part
	for (size_t i = 1; i < subDeq.size(); ++i)
	{
		// 2. we pick the next element and store it in 'key'
		int key = subDeq[i];

		// 3. we use 'j' to scan backwards through the sorted part of the array
		//		starting at the element just before our 'key'
		int j = i - 1;

		// 4. loop to find the correct insertion point
		// 		it runs as long as we haven't reached the beginning of the array (j >= 0)
		//		AND the element in the sorted part (subDeq[j]) is greater than our 'key'
		while (j >= 0 && subDeq[j] > key)
		{
			// 5. if subDeq[j] > key we shift the element one position to the right
			subDeq[j+1] = subDeq[j];
			j--; // move left to the next element
		}
		// the loop to find the correct insertion point ended
		// The position will be 'j+1' because the loop stops when subDeq[j] <= key
		subDeq[j+1] = key;
	}
}


//=============================================
// 		Utility Functions
//=============================================

long long PmergeMe::getCurrentTimeMicros()
{
	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000LL + tv.tv_usec;
}

void PmergeMe::printResults()
{
	printContainer(_vec, "After:");
	std::cout << "Time to process a range of " << _vec.size()
				<< " elements with std::vector : " << _timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
				<< " elements with std::deque  : " << _timeDeq << " us" << std::endl;
}

// Template function to print any container that supports iterators
// Its implementation can be in .cpp as long as it's only used within this file
// For wider use, it would need to be in the .hpp file
template<typename T>
void PmergeMe::printContainer(const T& container, const std::string& prefix)
{
	std::cout << prefix << " ";
	// Use a const iterator because we are not modifying the container
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


//=============================================
// 		Custom Exception
//=============================================

const char* PmergeMe::ValidationException::what() const throw()
{
	return "Error";
}
