// Neural Interface Functions

#include "nodes.h"


// Default Constructor 
ProcessorNode::ProcessorNode (): name(""), core(0) {;}

// Constructor
ProcessorNode::ProcessorNode (std::string name): name(name), core(0) {;}

// Get Core Object
DataCore<int> ProcessorNode::getCore () {return core;}

// Get Register Name
std::string ProcessorNode::getName () {return name;}

// Set Core
void ProcessorNode::setCore (DataCore<int> core) {this->core = core;}

// Set Data in Core
void ProcessorNode::setData (int data) {core.storeData(data);}

// Get Data from Core
int ProcessorNode::getData () {return core.getData();}


