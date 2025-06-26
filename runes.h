// runes.h
// Votann Runes

#ifndef RUNES_H
#define RUNES_H

#include "nodes.h"
		

ProcessorNode *getNode ( std::string name );
void display ( std::string name );



namespace runes 
{

	
	void BIND (int data, std::string name); // MOV
	void FORGE (std::string name1, std::string name2); // ADD
	void SEVER (std::string name1, std::string name2); // SUB
	void HAMMER (std::string name1, std::string name2); // MUL
	void CHISEL (std::string name1, std::string name2); // DIV
	bool JUDGE (std::string name1, std::string name2, std::string oath); // CMP
	void BRAND (std::string name); // PUSH
	void SMELT (std::string name); // POP
	

} // End Runes

#endif

