#include <iostream>
#include <fstream>
#include "Sorter.hpp"
using namespace std; 


class InsertionSorter: public Sorter
{
public:
	InsertionSorter(int max_len)
	    :Sorter(max_len) {};

	virtual void sort() override  
	{
		for (int i = 1; i < capacity; i++)
			for (int j = i; j > 0 && l[j] < l[j - 1]; --j)
			{
				swap(l[j], l[j - 1]);
			}
	}
};

