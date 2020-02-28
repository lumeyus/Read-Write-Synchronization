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
		while (!this->ColumnOneEmpty())
		{
			file << this->PopNextString();
		}
		file.close();
	}
	else
	{
		printf("Unable to open file\n");
	}
}
