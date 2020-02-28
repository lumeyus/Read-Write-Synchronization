#include "System.h"
/*
	System.cpp - 2/16/2020
	----------------------
	Implementation file for the System class.
*/

/* Static member initializations */
int System::total_one = 0;
int System::total_two = 0;
int System::total_three = 0;
int System::total_all = 0;

/* Default constructor for the System class - allocate Data */
System::System()
{
	systemData = new Data();
	systemResults = new Results();
}

/* Deconstructor for the System class - free Data */
System::~System()
{
	delete systemData;
	delete systemResults;
}

System::System(InputDir, std::string directory)
{
	systemData = new Data();
	systemResults = new Results();
	input_directory = directory;
}

System::System(OutputDir, std::string directory)
{
	systemData = new Data();
	systemResults = new Results();
	output_directory = directory;
}

System::System(std::string new_input_directory, std::string new_output_directory)
{
	systemData = new Data();
	systemResults = new Results();
	input_directory = new_input_directory;
	output_directory = new_output_directory;
}

/* Creator of the threads */
void System::RunComputation()
{
	/* Start threads, passing worker methods as arguments */
	std::thread t1(&System::GenerateData, this);
	std::thread t2(&System::ComputeData, this);
	std::thread t3(&System::SaveData, this);
	/* Rejoin threads once computation completed */
	t1.join();
	t2.join();
	t3.join();
}

/* Input thread parameter function - fills the system's input compute buffers */
void System::GenerateData()
{
	systemData->ReadFrom(input_directory);
	return;
}

/*
	Computational thread parameter function - performs computation on input data values
	Places computed into output buffers for saving
*/
void System::ComputeData()
{
	std::string number;
	while (number != "END!") 
	{
		std::unique_lock<std::mutex> lck(*systemData->getLock());
		/* Lock until buffer has items */
		while (systemData->StringDataEmpty()) systemData->getCV()->wait(lck);
		std::stringstream row(systemData->PopNextString());
		row >> number;
		std::cout << number << std::endl;
	}
	return;
}

/*
	Output thread parameter function - writes to file the data from output buffers
	output_directory : the directory that the output data values will be saved at
*/
void System::SaveData()
{
	systemResults->WriteTo(output_directory);
	return;
}

void System::PrintSummary()
{
	//TODO- make this a meaningful check
	printf("Made it to the end of the computation!\n");
	return;
}

void System::SetInputDirectory(std::string new_input_directory)
{
	input_directory = new_input_directory;
	return;
}
