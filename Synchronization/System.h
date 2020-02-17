#pragma once
/*
	System.h - Luis Ibanez - 2/16/2020
	------------------------------------
	Class that contains the input processing buffers and the method that fills them.
*/

#include <queue>

class System
{
public:
	/* Default constructor for the System class */
	System();
	
	/* Deconstructor for the System class - no dynamic memory to deallocate */    
	~System();

	/* 
		Input thread parameter function - fills the system's input processing buffers
		input_directory : the directory of the file containing the input data values
	*/
	void GenerateData(char* input_directory);

	/* 
		Computational thread parameter function - performs computation on input data values
		Places computed into output buffers for saving
	*/
	void ComputeData();

	/*
		Output thread parameter function - writes to file the data from output buffers
		output_directory : the directory that the output data values will be saved at
	*/
	void SaveData(char* output_directory);

private:
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
};
