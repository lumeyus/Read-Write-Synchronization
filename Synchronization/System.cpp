#include "System.h"

/*
	System.cpp - Luis Ibanez - 2/16/2020
	------------------------------------
	Implementation file for the System class.
*/

void printLine(const char* str, int n, int num);
int System::total_one = 0;
int System::total_two = 0;
int System::total_three = 0;

/* Default constructor for the System class */
System::System()
{
}

/* Deconstructor for the System class - no dynamic memory to deallocate */
System::~System()
{
}

/* Creator of the threads */
void System::RunComputation()
{
	std::thread t1(&System::GenerateData, this);
	std::thread t2(&System::ComputeData, this);
	std::thread t3(&System::SaveData, this);
	t1.join();
	t2.join();
	t3.join();
}

/*
	Input thread parameter function - fills the system's input compute buffers
	input_directory : the directory of the file containing the input data values
*/
void System::GenerateData()
{
	for (int i = 0; i < NUM_ROLLS; i++) {
		total_one++;
		printf("1 - Jellybeans Generating (%d)\n", total_one);
	}
	return;
}

/*
	Computational thread parameter function - performs computation on input data values
	Places computed into output buffers for saving
*/
void System::ComputeData()
{
	for (int i = 0; i < NUM_ROLLS; i++) {
		total_two++;
		printf("2 - Jellybeans Eating (%d)\n", total_two);
	}
	return;
}

/*
	Output thread parameter function - writes to file the data from output buffers
	output_directory : the directory that the output data values will be saved at
*/
void System::SaveData()
{
	for (int i = 0; i < NUM_ROLLS; i++) {
		total_three++;
		printf("3 - Jellybeans Disintegrating (%d)\n", total_three);
	}
	return;
}