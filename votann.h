// votann.h
// CPU Header

#ifndef VOTANN_H
#define VOTANN_H


#include "nodes.h"
#include "cache.h"
#include "runes.h"
#include "bits.h"
#include "logbook.h"
#include <iostream>
#include <limits>
#include <map>


class VotannCPU
{	
	private:
		ProcessorNode nodes [4];

		
	
	public:
		
		VotannCPU ();
		
		ProcessorNode *getNode (std::string name); // Get correct Node
		
		void display (std::string name); // Display node value
		
		DirectiveCache CoreBank;

		
}; // End Votann CPU

#endif

