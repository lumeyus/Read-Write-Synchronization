#pragma once
/*
	System.h - Luis Ibanez - 2/16/2020
	------------------------------------
	Class that contains the 3 thread parameter functions and the input/output buffers
	for the read-write computation process.
*/

#include <queue>
#include <thread>
#include <string>

constexpr int NUM_ROLLS = 25;
constexpr int TOTAL_ROLLS = 75;

class System
{
public:
	/* Default constructor for the System class */
	System();
	
	/* Deconstructor for the System class - no dynamic memory to deallocate */    
	~System();

	/* Creator of the threads */
	void RunComputation();

	/* 
		Input thread parameter function - fills the system's input compute buffers
		input_directory : the directory of the file containing the input data values
	*/
	void GenerateData();

	/* 
		Computational thread parameter function - performs computation on input data values
		Places computed into output buffers for saving
	*/
	void ComputeData();

	/*
		Output thread parameter function - writes to file the data from output buffers
		output_directory : the directory that the output data values will be saved at
	*/
	void SaveData();

	/* Prints summary of computation */
	void PrintSummary();

private:
	/* Directories for reading/writing */
	std::string input_directory;
	std::string output_directory;

	/* Containers for each column of data contained in input_directory */
	std::queue<double> in_column_one;
	std::queue<double> in_column_two;
	std::queue<double> in_column_three;
	std::queue<double> in_column_four;

	/* Containers for each column of data contained in output_directory */
	std::queue<double> out_column_one;
	std::queue<double> out_column_two;
	std::queue<double> out_column_three;
	std::queue<double> out_column_four;

	static int total_one;
	static int total_two;
	static int total_three;
	static int total_all;
};
