#pragma once
/*
	System.h - 2/16/2020
	--------------------
	Class that contains the 3 thread parameter functions used
	for the read-write computation process.
*/

#include <queue>
#include <string>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "Data.h"
#include "Results.h"

constexpr int NUM_ROLLS = 333;
constexpr int TOTAL_ROLLS = NUM_ROLLS * 2;

class System
{
public:
	struct InputDir final {};
	struct OutputDir final {};

	/* Default constructor for System */
	System();
	
	/* Deconstructor for System */    
	~System();

	/* Constructor for System - sets the input_directory */
	System(InputDir, std::string directory);

	/* Constructor for System - sets the output_directory */
	System(OutputDir, std::string directory);

	/* Constructor for System - sets both directories */
	System(std::string new_input_directory, std::string new_output_directory);

	/* Handles threads */
	void RunComputation();

	/* 
		Input thread parameter function:
		fills Data with info found in input_directory
	*/
	void GenerateData();

	/* 
		Computational thread parameter function:
		performs computation on input data values
		Places computed into output buffers for saving
	*/
	void ComputeData();

	/* 
		Output thread parameter function:
		writes info found in Results to output_directory 
	*/
	void SaveData();

	/* Prints summary of computation */
	void PrintSummary();

	/* Sets input_directory to assigned string */
	void SetInputDirectory(std::string new_input_directory);

	/* Sets output_directory to assigned string */
	void SetOutputDirectory(std::string new_output_directory);

private:
	Data* systemData;	/* Input handler */
	Results* systemResults;	/* Output handler */

	std::string input_directory;
	std::string output_directory;
};
