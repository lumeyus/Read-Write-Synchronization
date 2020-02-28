#include "Buffer.h"
/*
	Buffer.cpp - 2/18/2020
	----------------------
	Implementation file for the Buffer class.
*/

/* Default constructor for Buffer */
Buffer::Buffer()
{
}

/* Deconstructor for Buffer - no dynamic mem to dealloc */
Buffer::~Buffer()
{
}

/* Gets value from column */
double Buffer::GetNextColumnOne()
{
	return column_one.front();
}
double Buffer::GetNextColumnTwo()
{
	return column_two.front();
}
double Buffer::GetNextColumnThree()
{
	return column_three.front();
}
double Buffer::GetNextColumnFour()
{
	return column_four.front();
}
/**************************/

/* Pushes value to column */
void Buffer::PushColumnOne(double value)
{
	column_one.push(value);
}
void Buffer::PushColumnTwo(double value)
{
	column_two.push(value);
}
void Buffer::PushColumnThree(double value)
{
	column_three.push(value);
}
void Buffer::PushColumnFour(double value)
{
	column_four.push(value);
}
/**************************/

/* Pops & gets next value */
double Buffer::PopNextColumnOne()
{
	double value = column_one.front();
	column_one.pop();
	return value;
}
double Buffer::PopNextColumnTwo()
{
	double value = column_two.front();
	column_two.pop();
	return value;
}
double Buffer::PopNextColumnThree()
{
	double value = column_three.front();
	column_three.pop();
	return value;
}
double Buffer::PopNextColumnFour()
{
	double value = column_four.front();
	column_four.pop();
	return value;
}
/**************************/

/* Returns state of column */
bool Buffer::ColumnOneEmpty()
{
	return column_one.empty();
}
bool Buffer::ColumnTwoEmpty()
{
	return column_two.empty();
}
bool Buffer::ColumnThreeEmpty()
{
	return column_three.empty();
}
bool Buffer::ColumnFourEmpty()
{
	return column_four.empty();
}
/***************************/

std::string Buffer::GetNextString()
{
	return string_data.front();
}

void Buffer::PushString(std::string str)
{
	string_data.push(str);
}

std::string Buffer::PopNextString()
{
	std::string next = string_data.front();
	string_data.pop();
	return next;
}

bool Buffer::StringDataEmpty() 
{
	return string_data.empty();
}