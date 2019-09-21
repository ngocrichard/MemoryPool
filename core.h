#pragma once
#ifndef CORE_H__
#define CORE_H__

#include "MemoryPool.h"
#include <iostream>
#include <vector>

extern mempool::MemoryPool *memoryPool; // Pointer of memory pool
extern std::vector<int> listOfID; // List of ID of data nodes

// Setup
void Setup();

// Construct memory pool
void GetMemoryPool();

// Get command
void CommandWithMemoryPool();
void CommandWithMemoryPool(std::istream &);

// Free memory pool
void FreeMemoryPool();

#endif // !CORE_H__

