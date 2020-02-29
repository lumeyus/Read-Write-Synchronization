#include "Data.h"
/*
	Data.cpp - 2/17/2020
	--------------------
	Implementation file for the Data class.
*/

/* Default constructor for Data */
Data::Data()
{
}

/* Deconstructor for Data - no dynamic mem to dealloc */
Data::~Data()
{
}

/* 
	Reads file data from input_directory 
	-- should add a check to make sure input_directory is a directory
*/
void Data::ReadFrom(std::string input_directory)
{
	std::string line;
	std::ifstream file(input_directory);
	if (file.is_open()) 
	{	
		while (getline(file, line)) 
		{
			std::unique_lock<std::mutex> lck(mtx);
			this->PushString(line);
			cv.notify_all(); /* send message that buffer is available */
		}
		std::unique_lock<std::mutex> lck(mtx);
		this->PushString("END! END! END! END!");
		cv.notify_all(); /* send message that buffer is available */
		file.close();
	}
	else 
	{
		printf("Unable to open file\n");
		std::unique_lock<std::mutex> lck(mtx);
		this->PushString("END!");
		cv.notify_all(); /* send message that buffer is available */
	}
}

/* Gets mutex for locking */
std::mutex* Data::getMutex()
{
	return &mtx;
}

/* Gets condition variable for signal sending / reading */
std::condition_variable * Data::getCV()
{
	return &cv;
}
