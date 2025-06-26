// runes.cpp
// Votan Runes

#include <iostream>
#include "runes.h"
#include "cache.h"
#include "votann.h"
VotannCPU VotannCPU; // Chat GDP Help


namespace runes 
{
	
///////////////////// Instructions //////////////////////////
	void BIND (int data, std::string name) // MOV
	{
		ProcessorNode *nodePtr;
		nodePtr = VotannCPU.getNode(name);
		
		nodePtr->setData(data);
		std::cout<<"\nBIND RUNE: Inscribing " << data << " into chamber ";
		VotannCPU.display(name);
	}
	
	void FORGE (std::string name1, std::string name2) // ADD
	{
		ProcessorNode *nodePtrOne;
		ProcessorNode *nodePtrTwo;
		
		nodePtrOne = VotannCPU.getNode(name1);
		nodePtrTwo = VotannCPU.getNode(name2);
	
		std::cout<<"\nFORGE RUNE: Binding might of ";
		VotannCPU.display(name1);
		std::cout<<" with ";
		VotannCPU.display(name2);
		
		nodePtrOne->setData(nodePtrOne->getData() + nodePtrTwo->getData());

	}
	
	void SEVER (std::string name1, std::string name2) // SUB
	{
		ProcessorNode *nodePtrOne;
		ProcessorNode *nodePtrTwo;
	
		nodePtrOne = VotannCPU.getNode(name1);
		nodePtrTwo = VotannCPU.getNode(name2);
		
		std::cout<<"\nSEVER RUNE: Severing burden of ";
		VotannCPU.display(name1);
		std::cout<<" by ";
		VotannCPU.display(name2);
	
		nodePtrOne->setData(nodePtrOne->getData() - nodePtrTwo->getData());
	
	}
	
	void HAMMER (std::string name1, std::string name2) // MUL
	{
		ProcessorNode *nodePtrOne;
		ProcessorNode *nodePtrTwo;
	
		nodePtrOne = VotannCPU.getNode(name1);
		nodePtrTwo = VotannCPU.getNode(name2);
		
		std::cout<<"\nHAMMER RUNE: Striking the force of ";
		VotannCPU.display(name1);
		std::cout<<" against ";
		VotannCPU.display(name2);
			
		nodePtrOne->setData(nodePtrOne->getData() * nodePtrTwo->getData());
	
	}
	
	void CHISEL (std::string name1, std::string name2) // DIV
	{
		ProcessorNode *nodePtrOne;
		ProcessorNode *nodePtrTwo;
	
		nodePtrOne = VotannCPU.getNode(name1);
		nodePtrTwo = VotannCPU.getNode(name2);
		
		std::cout<<"\nCHISEL RUNE: Splitting ";
		VotannCPU.display(name1);
		std::cout<<" by ";
		VotannCPU.display(name2);
	
		nodePtrOne->setData(nodePtrOne->getData() / nodePtrTwo->getData());
	
	}
	
	bool JUDGE (std::string name1, std::string name2, std::string oath) // CMP
	{
		ProcessorNode *nodePtrOne;
		ProcessorNode *nodePtrTwo;
	
		nodePtrOne = VotannCPU.getNode(name1);
		nodePtrTwo = VotannCPU.getNode(name2);
	
		std::cout<<"\nJUDGE RUNE: Comparing ";
		VotannCPU.display(name1);
		std::cout<<" vs ";
		VotannCPU.display(name2);
	
		if (nodePtrOne->getData() == nodePtrTwo->getData() && oath == "==")
		{
			std::cout<<" => Oath: Equivalence Logged";
			return 1;
		}
		else if (nodePtrOne->getData() > nodePtrTwo->getData() && oath == ">")
		{
			std::cout<<" => Oath: Primary Exceeds Secondary";
			return 1;
		}
		else if (nodePtrOne->getData() < nodePtrTwo->getData() && oath == "<")
		{
			std::cout<<" => Oath: Primary Falls Below Secondary";
			return 1;
		}
		else 
		{
			std::cout<<" => Oath: Invaild";
			return 0;	
		}
	}
	
	void BRAND (std::string name) // PUSH
	{
		ProcessorNode *nodePtr;
		nodePtr = VotannCPU.getNode(name);
	
		CoreBank.CraftCore(nodePtr->getCore());
		std::cout<<"\nBRAND RUNE: Imprinting ";
		VotannCPU.display(name);
		std::cout<<" into the Ancestor Stack";
	}
	
	void SMELT (std::string name) // POP
	{
		ProcessorNode *nodePtr;
		nodePtr = VotannCPU.getNode(name);
	
		nodePtr->setCore(CoreBank.TransferCore());
		std::cout<<"\nSMELT RUNE: Extracting core into ";
		VotannCPU.display(name);
	
		CoreBank.ShatterCore();
	}

	

	
	

} // End Votan Runes

