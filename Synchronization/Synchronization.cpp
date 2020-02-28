/*
	Synchronization.cpp - 2/16/2020 
	-------------------------------
	This file contains the main call of execution for the program. 
	This program will read data values from a file, perform computation on these data values, 
	and write to another file the output of this computation.
	The process will be using 3 threads:
		- one for reading from a file and filling up an input buffer,
		- another for carrying out the computation of the data placed in this buffer, and filling up an output buffer with the results,
		- and another for writing the data placed in the output buffer to a separate file

	Input and output data will come in the form of comma-separated values.
*/

#include <iostream>
#include <string>
#include "System.h"

int main()
{
    std::cout << "Hello World!\n";

	// YES I KNOW HARDCODING DIRECTORIES IS BAD
	// WILL FIX IN FUTURE

	// ON DESKTOP
	//std::string my_input_directory = "C:\\Users\\Luis\\source\\repos\\Read-Write-Synchronization\\Synchronization\\Resources\\Input Data\\input_data.txt";
	//std::string my_output_directory = "C:\\Users\\Luis\\source\\repos\\Read-Write-Synchronization\\Synchronization\\Resources\\Output Data\\input_data.txt";
	// ON LAPTOP
	std::string my_input_directory = "C:\\Users\\Luis\\source\\repos\\lumeyus\\Read-Write-Synchronization\\Synchronization\\Resources\\Input Data\\input_data.txt";
	std::string my_output_directory = "C:\\Users\\Luis\\source\\repos\\lumeyus\\Read-Write-Synchronization\\Synchronization\\Resources\\Output Data\\output_data.txt";

	System* mySystem = new System(my_input_directory, my_output_directory);
	mySystem->RunComputation();
	mySystem->PrintSummary();	/* Verify results */

	std::cout << "Goodbye World!\n";
	return 0;
}
