#include "core.h"
#include <fstream>
#include <random>

#pragma region
// Global variable
mempool::MemoryPool *memoryPool = nullptr; // Pointer of memory pool
std::vector<int> listOfID{}; // ListOfID
std::ifstream inputFile; // Input file stream for command
bool isReadingFromFile = true; // Set default source is file
// Setup a random device for free random data
std::random_device rd; // Seed for generator
std::mt19937 gen(rd()); // Generator for random unsigned integer
#pragma endregion Global variables.

#pragma region
// Setup
void Setup()
{
	std::cout << "INSTRUCTION:\n";
	std::cout << "p: Print memory.\n";
	std::cout << "a <i, d, s, c>: Allocate memory by type double, int, short or char.\n";
	std::cout << "f: Free a random data.\n";
	std::cout << "e: Exit.\n\n";
	// Choose to read data from console or file
	char choice;
	std::cout << "Get input from file (Y) (default is from console): "; std::cin >> choice;
	// If user chooses to read data from console
	if ((choice == 'Y') || (choice == 'y'))
		isReadingFromFile = true;
	// If users chooses to read data from file
	if (isReadingFromFile)
	{
		inputFile.open("input.txt"); // Open file
		if (!inputFile.is_open())
		{
			std::cout << "Failed to open input file!\n"; // Show error
			exit(-1); // Terminate app
		}
	}
}

// Check if user choose to read data from file or console
bool checkIfReadingFromFile(char choice)
{
	if ((choice != 'Y') && (choice != 'y'))
		return true;
	else
		return false;
}
#pragma endregion Setup.

#pragma region
// Construct a memory pool
void GetMemoryPool()
{
	// Get size of memory block
	unsigned size;
	if (isReadingFromFile)
	{
		inputFile >> size; // Get size from file
	}
	else
	{
		std::cout << "Enter size of memory pool: ";
		std::cin >> size; // Get size from console
	}
	// Construct memory pool
	memoryPool = new mempool::MemoryPool(size);
}
#pragma endregion Get memory pool.

#pragma region
// Do stuff with memory pool
void CommandWithMemoryPool()
{
	// Call the overloading version of this function
	if (isReadingFromFile)
	{
		CommandWithMemoryPool(inputFile);
		CommandWithMemoryPool(std::cin);
	}
	else
	{
		CommandWithMemoryPool(std::cin);
	}
}

// Take input from istream
void  CommandWithMemoryPool(std::istream &in)
{
	bool isExit = false; // Boolean for breaking loop
	char command;
	// Do some command
	while (in >> command)
	{
		// Command instruction:
		// p: Print memory
		// a <type>: Allocate memory by type
		// f: Free a random data
		// e: Exit
		switch (command)
		{
		case 'p':
			// Print memory
			memoryPool->printMemory();
			break;
		case 'a':
		{
			// Allocate memory by type
			int _size = 0;
			in >> command; // Enter type of new data
			switch (command)
			{
			case 'i': // Integer
				_size = sizeof(int);
				break;
			case 'd': // Long integer
				_size = sizeof(double);
				break;
			case 's': // Short integer
				_size = sizeof(short int);
				break;
			case 'c': // Character
				_size = sizeof(char);
				break;
			}
			if (_size > 0)
			{
				int _ID = memoryPool->allocateMem(_size);
				if (_ID > -1)
					listOfID.push_back(_ID);
			}
		}
			break;
		case 'f':
			// Free random data
			if (listOfID.size() > 0)
			{
				int randomIndex = gen() % listOfID.size();
				// Try to free data
				if (memoryPool->freeMem(listOfID[randomIndex]))
				{
					// Erase the element of that index of listOfID if successfully free data
					listOfID.erase(std::begin(listOfID) + randomIndex);
				}
			}
			break;
		case 'e':
			//Exit
			isExit = true;
			break;
		}
		// Break out of loop if choose to exit
		if (isExit)
			break;
	}
}
#pragma endregion Command with memory pool.

#pragma region
// Free memory pool
void FreeMemoryPool()
{
	delete memoryPool; memoryPool = nullptr;
}
#pragma endregion Free memory pool.