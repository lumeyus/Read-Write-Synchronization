/*
	Synchronization.cpp - Luis Ibanez - 2/16/2020 
	--------------------------------------------- 
	This file contains the main call of execution for the program. 
	This program will read data values from a file, process these data values, and write to another file the output of this processing.
	The program will execute this process using 3 threads:
		- one for reading from a file and filling up an input buffer,
		- another for carrying out the processing of the data placed in this buffer, and filling up an output buffer with the results,
		- and another for writing the data placed in the output buffer to a separate file
*/

#include <iostream>
#include <thread>
#include <mutex>

int main()
{
    std::cout << "Hello World!\n"; 
	return 0;
}
