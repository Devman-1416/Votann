// cache.cpp //Chat GDP
// Stack Memory DirectiveCache

#include "cache.h"
#include <iostream>

// Constructor
DirectiveCache::DirectiveCache () {;}

// Add to stack
void DirectiveCache::CraftCore (DataCore<int> newCore) 
	{
		//Add the core to the Bank
		CoreBank.push(newCore);
	}

// Remove from stack
void DirectiveCache::ShatterCore () 
	{
		// Only pop if cache isnt empty
		if (!CoreBank.empty()) CoreBank.pop();
	}

// Return top of stack
DataCore<int> DirectiveCache::TransferCore () 
	{
		// Pass refrence of top, if there is none return new empty core
		if (!CoreBank.empty()) return CoreBank.top();
		else return DataCore<int>(0);
	}

// Display all contents of a copy of the bank
void DirectiveCache::displayBank ()
	{
		std::stack<DataCore<int> > BankCopy = CoreBank;
		std::cout<<"\nCopy: "<<BankCopy.size();
		std::cout<<"\nMain: "<<CoreBank.size();
		
		while (!BankCopy.empty())
		{
			std::cout<<BankCopy.top().getData()<< "/ /";
			BankCopy.pop();
		}
	} 	

// global CoreBank 
DirectiveCache CoreBank;


