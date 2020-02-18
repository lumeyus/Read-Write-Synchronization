#pragma once
/*
	Data.h - Luis Ibane - 2/17/2020
	-------------------------------
	Class that holds input information and
	the 
*/

#include <queue>
#include <string>
#include <iostream>
#include <fstream>

class Data
{
public:
	/* Default constructor for the Data class */
	Data();

	/* Deconstructor for the Data class - maybe dynamic mem to clean? */
	~Data();

	/* Read input file and fill queues with information */
	void ReadFrom(std::string input_directory);

private:
	/* Containers for each column of data contained in input_directory */
	std::queue<double> column_one;
	std::queue<double> column_two;
	std::queue<double> column_three;
	std::queue<double> column_four;

	/* Container for input strings to be printed */
	std::queue<std::string> string_data;
};

