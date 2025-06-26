// logbook.h

#ifndef LOGBOOK_H
#define LOGBOOK_H

#include <stdexcept>
#include <map>

class Keystone; //Chat GDP

class Logbook
{
	private:
		std::map<int, Keystone> DataVault; // Stores KeyStones Pointers!
		int MemorySlot; // ID tracker

	public:
		Logbook() {MemorySlot=0;}


		void log(Keystone record);
		void displayRecords();
		void purgeRecord();
		Keystone findRecord();
		void purgeLog();
};

extern Logbook DataLog; // Make it Global

#endif

