#pragma once
/*
	System.h - Luis Ibanez - 2/16/2020
	----------------------------------
	Class that contains the 3 thread parameter functions and the output buffers
	for the read-write computation process.
*/

#include <queue>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "Data.h"

constexpr int NUM_ROLLS = 333;
constexpr int TOTAL_ROLLS = NUM_ROLLS * 2;

class System
{
public:
	/* Default constructor for the System class - allocate Data */
	System();
	
	/* Deconstructor for the System class - free Data */    
	~System();

	/* Constructor for the System class - sets input_directory */
	System(std::string new_input_directory);

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

	void GetInputDirectory(std::string new_input_directory);

private:
	/* Input handler */
	Data* systemData;

	/* Directory for reading/writing */
	std::string input_directory;
	std::string output_directory;

	/* Containers for each column of data contained in output_directory */
	std::queue<double> out_column_one;
	std::queue<double> out_column_two;
	std::queue<double> out_column_three;
	std::queue<double> out_column_four;

	/* Totals updated by the three threads */
	static int total_one;
	static int total_two;
	static int total_three;
	static int total_all;

	std::mutex in_mu;
	std::condition_variable in_cv;
	bool in_ready;
};
