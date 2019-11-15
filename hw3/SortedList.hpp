#include <iostream>
#include <fstream>
#ifndef SORTEDLIST_HPP
#define SORTEDLIST_HPP
using namespace std;

class SortedList
{
public:
	SortedList() {};
	virtual ~SortedList() = default;
	virtual void insert(string word) = 0;
	virtual bool find(string word) = 0;
	virtual void remove(string word) = 0;

};

#endif 