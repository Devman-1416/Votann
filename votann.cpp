// votann.cpp
// CPU Implementation

#include "votann.h"
#include <iostream>
#include <iomanip>
#include <map>



// Constructor
VotannCPU::VotannCPU ()
{
	nodes[0] = ProcessorNode("Theta");
	nodes[1] = ProcessorNode("Sigma"); 	
	nodes[2] = ProcessorNode("Omicron"); 
	nodes[3] = ProcessorNode("Epsilon");
	DirectiveCache CoreBank;


	  
}

// Get correct Node
ProcessorNode *VotannCPU::getNode (std::string name)
{
	for (int x = 0; x < 4; x++)
	{
		if (nodes[x].getName() == name)
		{
			return &nodes[x];
		}
	}
}

// Display node value
void VotannCPU::display (std::string name)
{
	ProcessorNode *nodePtr = getNode(name);
	std::cout << name << " [" << nodePtr->getData()<<"]";
}








