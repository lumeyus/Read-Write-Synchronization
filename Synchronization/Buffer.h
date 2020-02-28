#pragma once
/*
	Buffer.h - 2/18/2020
	--------------------
	Interface for the buffers used to hold information that
	needs to be sent between two threads. 
	The two child classes are expected to be Data and Results.
*/
#include <queue>
#include <string>

class Buffer
{
public:
	/* Default constructor for Buffer */
	Buffer();
	
	/* Deconstructor for Buffer - no dynamic mem to dealloc */
	~Buffer();

	/* Gets the next value */
	double GetNextColumnOne();
	double GetNextColumnTwo();
	double GetNextColumnThree();
	double GetNextColumnFour();

	/* Pushes the given value */
	void PushColumnOne(double value);
	void PushColumnTwo(double value);
	void PushColumnThree(double value);
	void PushColumnFour(double value);

	/* Pops (and returns) the next value */
	double PopColumnOne();
	double PopColumnTwo();
	double PopColumnThree();
	double PopColumnFour();

	/* Returns state of column */
	bool ColumnOneEmpty();
	bool ColumnTwoEmpty();
	bool ColumnThreeEmpty();
	bool ColumnFourEmpty();

	/* Get, Push, Pop, state methods for strings */
	std::string GetNextString();
	void PushString(std::string str);
	std::string PopString();
	bool StringDataEmpty();

private:
	/* Columns of data that need to be sent */
	std::queue<double> column_one;
	std::queue<double> column_two;
	std::queue<double> column_three;
	std::queue<double> column_four;

	/* Strings that need to be sent */
	std::queue<std::string> string_data;
};

