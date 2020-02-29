#pragma once
/*
	Data.h - 2/17/2020
	------------------
	Class that represents the data to be used by the main computation.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <mutex>
#include <condition_variable>
#include "Buffer.h"

class Data : public Buffer
{
public:
	/* Default constructor for Data */
	Data();

	/* Deconstructor for Data - no dynamic mem to dealloc */
	~Data();

	/* Read input file and fill queues with information */
	void ReadFrom(std::string input_directory);

	/* Get buffer lock */
	std::mutex* getMutex();

	/* Get buffer empty CV */
	std::condition_variable* getCV();

private:
	/* Synchronization Components */
	std::mutex mtx;
	std::condition_variable cv;
};
