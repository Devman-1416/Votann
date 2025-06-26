#include "cores.h"


template<>
DataCore<int>::DataCore() : data(0) {;}

template<>
DataCore<int>::DataCore(int data) : data(data) {;}

template<>
void DataCore<int>::storeData(int data) 
{
	this->data=data;
}

template<>
int DataCore<int>::getData() 
{
	return data;
}






