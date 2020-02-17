#include "System.h"

/*
	System.cpp - Luis Ibanez - 2/16/2020
	------------------------------------
	Implementation file for the System class.
*/

/* Default constructor for the System class */
System::System()
{
}

/* Deconstructor for the System class - no dynamic memory to deallocate */
System::~System()
{
}

/* 
	Input thread parameter function - fills the system's input processing buffers
	input_directory : the directory of the file containing the input data values
*/
void System::GenerateData(char* input_directory)
{
	return;
}

/*
	Computational thread parameter function - performs computation on input data values
	Places computed into output buffers for saving
*/
void System::ComputeData()
{
	return;
}

/*
	Output thread parameter function - writes to file the data from output buffers
	output_directory : the directory that the output data values will be saved at
*/
void System::SaveData(char * output_directory)
{
	return;
}
