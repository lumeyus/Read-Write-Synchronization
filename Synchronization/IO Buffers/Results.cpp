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

/*
	Writes computation results to output_directory
	-- should add a check to make sure output_directory is realistic
*/
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

/* Gets mutex for locking */
std::mutex* Results::getMutex()
{
	return &mtx;
}

/* Gets condition variable for signal sending / reading */
std::condition_variable * Results::getCV()
{
	return &cv;
}
