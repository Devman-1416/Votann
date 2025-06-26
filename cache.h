// cache.h
// Stack Memory DirectiveCache

#ifndef CACHE_H
#define CACHE_H

#include <stack>
#include "cores.h"

class DirectiveCache // Stack Memory
{
	private:
		std::stack<DataCore<int> > CoreBank;
		
	public:
		DirectiveCache ();

		void CraftCore (DataCore<int> newCore);    // Add to stack
		void ShatterCore ();                       // Remove from stack
		DataCore<int> TransferCore ();             // Return top of stack
		void displayBank ();					   // Display Contents
 
		friend class VotanCPU;
	
}; // End Directive Cache

// Global instance
extern DirectiveCache CoreBank;

#endif



