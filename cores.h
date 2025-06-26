// cores.h
// Data Cores
#ifndef CORES_H
#define CORES_H



template <typename T>
class DataCore // The actual Data
{
	private:
		T data;
		
	public:
		
		// Default Constructor
		DataCore () : data(T()) {;}

		// Constructor
		DataCore (T data) : data(data) {;}

		// Store Data
		void storeData (T data) {this->data = data;}

		// Get Data
		T getData () {return data;}

}; // End Datacore

#endif

