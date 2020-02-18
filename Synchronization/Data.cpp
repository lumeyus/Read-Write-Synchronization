#include "Data.h"
/*
	Data.cpp - Luis Ibanez - 2/17/2020
	----------------------------------
	Implementation file for the Data class.
*/

/* Default constructor for the Data class */
Data::Data()
{
}

/* Deconstructor for the Data class - maybe dynamic mem to clean? */
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
			string_data.push(line);
		}
		file.close();
	}
	else {
		printf("Unable to open file\n");
	}
	return;
}
