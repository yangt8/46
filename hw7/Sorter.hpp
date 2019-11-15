#include <iostream>
#include <fstream>
#ifndef SORTER_HPP
#define SORTER_HPP
using namespace std; 

class Sorter
{
public:
	int capacity;
	string *l;

	Sorter(int max_len);

	~Sorter();

	void insertAllFromFile(const char * fileName, int numItemsToLoad);

	void print(ostream & out);

	virtual void sort() = 0;
};

#endif 
