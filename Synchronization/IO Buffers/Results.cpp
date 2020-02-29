#include "Results.h"
/*
	Results.h - 2/18/2020
	---------------------
	Implementation file for the Results class.
*/

/* Default constructor for Results */
Results::Results()
{
}

/* Deconstructor for Results - no dynamic mem to dealloc */
Results::~Results()
{
}

void Results::WriteTo(std::string output_directory)
{
	std::ofstream file(output_directory);
	if (file.is_open())
	{
		std::string number;
		while (number != "END!")
		{
			std::unique_lock<std::mutex> lck(mtx);
			while (StringDataEmpty()) cv.wait(lck);
			number = this->PopString();
			if (number != "END!") number.append("\n");
			file << number;
		}
		file.close();
	}
	else
	{
		printf("Unable to open file\n");
	}
}

std::mutex* Results::getLock()
{
	return &mtx;
}

std::condition_variable * Results::getCV()
{
	return &cv;
}
