#pragma once
/* 
	Results.h - 2/18/2020
	---------------------
	Class that represents the results computed by the main computation.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <mutex>
#include <condition_variable>
#include "Buffer.h"

class Results : public Buffer
{
public:
	/* Default constructor for the Results class */
	Results();

	/* Deconstructor for the Results class - maybe dynamic mem to clean? */
	~Results();

	/* Write queue information to output file */
	void WriteTo(std::string output_directory);

	/* Get buffer lock */
	std::mutex* getMutex();

	/* Get buffer empty CV */
	std::condition_variable* getCV();

private:
	/* Synchronization Components */
	std::mutex mtx;
	std::condition_variable cv;
};
