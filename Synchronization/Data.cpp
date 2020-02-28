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
		this->PushString("END! END! END! END!");
		file.close();
	}
	else 
	{
		printf("Unable to open file\n");
	}
}

std::mutex* Data::getLock()
{
	return &mtx;
}

std::condition_variable * Data::getCV()
{
	return &cv;
}
