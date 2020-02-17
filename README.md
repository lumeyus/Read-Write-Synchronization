# Read-Write-Synchronization
C++ program that reads data from a file, performs computation on that data, and writes the results into a separate output file.  Uses multithreading (with std::thread) to improve the performance of the program.

## Purpose
To both practice simple object-oriented multithreaded programming design and to create a modularized prototype for a simulation software. 

## Progress
- 2/16 19:30 : Project created
- 2/17 2:00 : Have created a System class that executes simultaneous counting of separate private members, along with adding to a shared sum.  Verified that sums all count to set amount.

## To-Do's
- Design abstractions of the input/output buffers
- Add read/write capability to the input and output worker methods
- Modify worker methods to use input/output buffers for reading, computing, and processing
- Verify synchronization is correct with simple file tests
- Create tests to verify the fully-fledged 4-column read/write program works as expected
