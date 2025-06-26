// logbook.cpp

#include "logbook.h"
#include "bits.h" // Chat GDP Help
#include <iostream>

Logbook DataLog; // global instance

void Logbook::log(Keystone record)
{
	DataVault.insert(std::pair<int, Keystone>(MemorySlot,record));
	MemorySlot++;
}

void Logbook::displayRecords()
{
	std::cout<<"\n>>=== MEMORY CORE INDEX ===<<\n";
	std::cout<<"        Key    |   Value\n";
	std::cout<<"------------------------------\n";
	
	for (std::map<int,Keystone>::iterator it = DataVault.begin();
		 it != DataVault.end(); it++)
		 {
		 	// Prints RuneMark (ID)        Prints Keystone data (int)
			std::cout<<"        "<<it->first<<"    |      " 
			<<it->second.getNum()<<"\n";
		 }
	std::cout<<"------------------------------\n";
}

// Removes top record and increment back one
void Logbook::purgeRecord()
{
	if (MemorySlot == 0) 
	{
		std::cout<<"\n[No Runes Left in the Vault!]";
		return;	
	}
	else
	{
		MemorySlot--;
		DataVault.erase(MemorySlot);
	}
}

// Return Selected Keystone for Math
Keystone Logbook::findRecord()
{
	int key;
	std::cout<<"\nEnter Rune Key: ";
    while (!(std::cin >> key)) {
        std::cout<<"\nAncestors Angered! Enter a Valid Key to: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
 	
	
	for (std::map<int,Keystone>::iterator it = DataVault.begin();
		 it != DataVault.end() ; it++  )
		 {
			if (it->first == key)
			{
				return it->second;
			}
		 }
		
	throw std::runtime_error("Key not found.");
		
}

// Purge All
void Logbook::purgeLog()
{
	DataVault.clear();
	MemorySlot = 0;	
}


