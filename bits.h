// bits.h
// Data Types

#ifndef BITS_H 
#define BITS_H

#include <iostream>
#include <string>
#include <map>
#include "votann.h"

template <typename T>
class Bit
{
	private:
		T dataX;
		static int key; //static increment

	public:
		// Constructor
		Bit ():dataX(0) {;}
		Bit (T data):dataX(data) {;}

		// Get Value
		T getNum () {return dataX;}
		// Set Value
		T setNum (T num) {dataX = num;}

		// Assign T
		Bit &operator= (T dataY)
		{
			dataX = dataY;
			return *this;
		}

		////////////////////MATH///////////////////////

		// Add
		Bit operator+ (Bit &dataY)
		{
			std::cout<<"\n-------------------- VOTAN TRANSMISSION --------------------\n";
			DataCore<T> coreOne(dataX); 			// Make Core 1
			DataCore<T> coreTwo(dataY.getNum()); 	// Make Core 2
			CoreBank.CraftCore(coreOne); 			// Add Core 1 to CoreBank
			CoreBank.CraftCore(coreTwo);			// Add Core 2 to CoreBank
			runes::SMELT("Theta");					// Get Theta Node,Take Top Copy from CoreBank into Theta:Core, Shatter Core 2 from Corebank
			runes::SMELT("Sigma");					// Get Sigma Node,Take Top Copy from CoreBank into Sigma:Core, Shatter Core 1 from Corebank
			runes::FORGE("Theta", "Sigma");			// Add Core 1 and Core 2 data and Store data in Theta:Core
			runes::BRAND("Theta");					// Get Theta Node, Make Core 3 from Theta:Core, Add Core 3 to CoreBank
			T result = CoreBank.TransferCore().getData(); // Get Core Data from Top Core (Core 3) from CoreBank and store into result
			CoreBank.ShatterCore(); 				// Remove the Top Core from CoreBank (Core 3)
			std::cout<<"\n\n------------------- TRANSMISSION COMPLETE -------------------\n";
			return Bit(result);						
		}

		// Subtract
		Bit operator- (Bit &dataY)
		{
			std::cout<<"\n-------------------- VOTAN TRANSMISSION --------------------\n";
			DataCore<T> coreOne(dataX);
			DataCore<T> coreTwo(dataY.getNum());
			CoreBank.CraftCore(coreOne);
			CoreBank.CraftCore(coreTwo);
			runes::SMELT("Theta");
			runes::SMELT("Sigma");
			runes::SEVER("Sigma", "Theta");
			runes::BRAND("Sigma");
			T result = CoreBank.TransferCore().getData();
			CoreBank.ShatterCore();
			std::cout<<"\n\n------------------- TRANSMISSION COMPLETE -------------------\n";
			return Bit(result);
		}

		// Multiply
		Bit operator* (Bit &dataY)
		{
			std::cout<<"\n-------------------- VOTAN TRANSMISSION --------------------\n";
			DataCore<T> coreOne(dataX);
			DataCore<T> coreTwo(dataY.getNum());
			CoreBank.CraftCore(coreOne);
			CoreBank.CraftCore(coreTwo);
			runes::SMELT("Theta");
			runes::SMELT("Sigma");
			runes::HAMMER("Theta", "Sigma");
			runes::BRAND("Theta");
			T result = CoreBank.TransferCore().getData();
			CoreBank.ShatterCore();
			std::cout<<"\n\n------------------- TRANSMISSION COMPLETE -------------------\n";
			return Bit(result);
		}

		// Divide
		Bit operator/ (Bit &dataY)
		{
			std::cout<<"\n-------------------- VOTAN TRANSMISSION --------------------\n";
			DataCore<T> coreOne(dataX);
			DataCore<T> coreTwo(dataY.getNum());
			CoreBank.CraftCore(coreOne);
			CoreBank.CraftCore(coreTwo);
			runes::SMELT("Theta");
			runes::SMELT("Sigma");
			runes::CHISEL("Theta", "Sigma");
			runes::BRAND("Theta");
			T result = CoreBank.TransferCore().getData();
			CoreBank.ShatterCore();
			std::cout<<"\n\n------------------- TRANSMISSION COMPLETE -------------------\n";
			return Bit(result);
		}

		// Greater than
		bool operator> (Bit &dataY)
		{
			std::cout<<"\n-------------------- VOTAN TRANSMISSION --------------------\n";
			DataCore<T> coreOne(dataX);
			DataCore<T> coreTwo(dataY.getNum());
			bool verdict = Oath(coreOne,coreTwo, ">");
			
			std::cout<<"\n\n------------------- TRANSMISSION COMPLETE -------------------\n";
			return verdict;
		}

		// Less than
		bool operator< (Bit &dataY)
		{
			std::cout<<"\n-------------------- VOTAN TRANSMISSION --------------------\n";
			DataCore<T> coreOne(dataX);
			DataCore<T> coreTwo(dataY.getNum());
			bool verdict = Oath(coreOne,coreTwo, "<");
			
			std::cout<<"\n\n------------------- TRANSMISSION COMPLETE -------------------\n";
			return verdict;
		}

		// Equal
		bool operator== (Bit &dataY)
		{
			std::cout<<"\n-------------------- VOTAN TRANSMISSION --------------------\n";
			DataCore<T> coreOne(dataX);
			DataCore<T> coreTwo(dataY.getNum());
			bool verdict = Oath(coreOne,coreTwo, "==");
			
			std::cout<<"\n\n------------------- TRANSMISSION COMPLETE -------------------\n";
			return verdict;
		}

		// Used by all Comparison Operators
		bool Oath (DataCore<T> coreOne, DataCore<T> coreTwo,std::string oath)
		{
			std::cout<<"\n-------------------- VOTAN TRANSMISSION --------------------\n";
			CoreBank.CraftCore(coreOne);
			CoreBank.CraftCore(coreTwo);
			
			runes::SMELT("Theta");
			runes::SMELT("Sigma");
			bool verdict = runes::JUDGE("Theta", "Sigma" ,oath);
			CoreBank.ShatterCore();
			std::cout<<"\n\n------------------- TRANSMISSION COMPLETE -------------------\n";
			return verdict;	
		}

		// Display
		void display ()
		{
			std::cout << "\nKin Reckoning: " << dataX << std::endl;
		}
		

}; // End Bit


//////////////////////////// Data Types //////////////////////////////

#include "logbook.h"

//Int
class Keystone : public Bit<int> 
{
	friend std::istream& operator>>(std::istream &in, Keystone &data); 
	
	public:
	    using Bit<int>::Bit;  // keep inherited constructors
	
	    // Bit<int> to Keystone
	    Keystone(const Bit<int>& bit) : Bit<int>(bit) {}
	    

	    
	    // Add to DataLog (Memory)
	    Keystone(int bit) : Bit<int>(bit)
	    {
	    	DataLog.log(*this);
		}
};
	// KeyStone Input
	inline std::istream& operator>>(std::istream &in, Keystone &data) 
	{
		int num;
		in>>num;
		data.setNum(num);
		return in;
	}

//Float
class Embercore : public Bit<float> 
{
	public:
	    using Bit<float>::Bit;  // keep inherited constructors
	
	    // Bit<float> to Embercore
	    Embercore(const Bit<float> &bit) : Bit<float>(bit) {}
};


 //Stings
class Runechant : public Bit<std::string> 
{
	friend 	std::istream& operator>>(std::istream& in, Runechant& chant);
	public:
	    using Bit<std::string>::Bit;  // keep inherited constructors
	
	    // Bit<string> to Runechant
	    Runechant(const Bit<std::string> &bit) : Bit<std::string>(bit) {}
	
	    // const char* to Runechant
	    Runechant(const char *str) : Bit<std::string>(std::string(str)) {}
};

	// Runechant Input
	inline std::istream& operator>>(std::istream &in, Runechant &chant) 
	{
		std::string input;
		in>>input;
		chant = Runechant(input);
		return in;
	}

//Bool
class Verdict : public Bit<bool> 
{
	public:
	    using Bit<bool>::Bit;  // keep inherited constructors
	
	    // Bit<bool> to Verdict
	    Verdict(const Bit<bool> &bit) : Bit<bool>(bit) {}
};





#endif
