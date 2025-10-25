/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 07:10:49 by anemet            #+#    #+#             */
/*   Updated: 2025/10/25 13:26:29 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>		// for std::cerr
#include <fstream>		// for std::ifstream and std::ofstream
#include <stdexcept>	// for std::runtime_error

// The constructor initializes the private members and creates the ouput filename
FileReplacer::FileReplacer(std::string filename, std::string s1, std::string s2):
							_inputFile(filename), _s1(s1), _s2(s2), _replacementCount(0)
{
	this->_outputFile = this->_inputFile + ".replace";
}

FileReplacer::~FileReplacer(void)
{
	return;
}

void FileReplacer::replace(void)
{
	/* C++ ifsteam/ofstream:
		std::ifstream is for input file stream
		std::ofstream is for output file stream
		We pass to `ifstream` constructor the filename to open the file
		We use the `.c_str()` because in C++98 the stream constructors
		expect a C-style string (const char*), not a std::string object
	*/
	std::ifstream ifs(this->_inputFile.c_str());

	/* C++ exceptions
		C++ is handling errors by throwing exception.
		It stops execution and jumps to the nearest `catch` block.
		This is cleaner than returning error codes.
	*/
	if (!ifs.is_open())
	{
		throw std::runtime_error("Could not open input file: " + this->_inputFile);
	}

	std::ofstream ofs(this->_outputFile.c_str());
	if (!ofs.is_open())
	{
		throw std::runtime_error("Could not create output file: " + this->_outputFile);
	}

	std::string line;
	// Outer while loop: Read the input file, one line at a time
	while (std::getline(ifs, line))
	{
		std::string modifiedLine; 	// initialized to ""
									// principle of safe object oriented design
									// when calling default constructor is should
									// make an object which doesn't contain garbage
									// and can be used right away
		size_t startPos = 0;
		size_t foundPos;

		// Inner while loop: find each occurrence of `_s1`
		// std::string::npos - stands for "no position" - in our case means "not found"
		while ((foundPos = line.find(this->_s1, startPos)) != std::string::npos)
		{
			// 0. Increment the _replacementCount counter
			this->_replacementCount++;

			// 1. Append the part of the line BEFORE the found string
			modifiedLine.append(line, startPos, foundPos - startPos);

			// 2. Append the replacement string, _s2
			modifiedLine.append(this->_s2);

			// 3. Update the search position to be right after the found string.
			startPos = foundPos + this->_s1.length();
		}

		// 4. After the loop, append the rest of the original line
		// here `npos` ("no position") means "to infinite and beyond ;-)", aka till end of line
		// Note: the original `line` has no terminating '\n' because std::getline() is not getting it
		// so our modifiedLine won't have terminating newline '\n' character, we'll have to add "manually"
		modifiedLine.append(line, startPos, std::string::npos);

		// Write the fully modified line to the output file
		ofs << modifiedLine;

		// Add a newline unless it's the last line
		if (!ifs.eof())
		{
			ofs << std::endl;
		}
	}
	ifs.close();
	ofs.close();
}

// Implementing the count getter function
size_t FileReplacer::getReplacementCount(void) const
{
	return (this->_replacementCount);
}
