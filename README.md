# Read-Write-Synchronization
C++ program that reads data from a file, performs computation on that data, and writes the results into a separate output file.  Uses multithreading with std::thread to improve the performance of the program.

## Purpose
To both practice simple object-oriented multithreaded programming design and to create a modularized prototype for a simulation software. 

## Progress
- 2/16 19:30 : Project created
- 2/17 2:00 : Have created a System class that executes simultaneous counting of separate private members, along with adding to a shared sum.  Verified that sums all count to set amount.
- Some time before 2/28 : Designed and implemented abstractions for input/output buffers
- 2/28 17:00 : Completed full multithreaded I/O algorithm; currently transfers string values from one file to another

## To-Do's
~~Design abstractions for the input/output buffers~~
~~Modify worker methods to use input/output buffers for reading, computing, and writing~~
~~Verify synchronization is correct with simple file tests~~
- Modify fully-functioning I/O algorithm to do computation with doubles rather than simply passing and modifying strings
- Create tests to verify that the fully-fledged 4-column read/write program works as expected
