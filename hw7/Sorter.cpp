#include <iostream>
#include <fstream>
#include "Sorter.hpp"
#include "Timer.h"

Sorter::Sorter(int max_len)
	     :capacity{max_len}, l{new string[max_len]}
{}

Sorter::~Sorter()
{
	delete[] l;
}

void Sorter::insertAllFromFile(const char * fileName, int numItemsToLoad)
{
	int i = 0;
	Timer t;
    double eTime;
	ifstream f(fileName);
	string w;
	t.start();
	while (i<4529*numItemsToLoad)
	{
		f>>w;
		l[i]=w;
		i++;
	}
	sort();
	f.close();
	t.elapsedUserTime(eTime);
	cout<< "Time: "<< eTime << "s"<< endl;
}

void Sorter::print(ostream & out)
{
	for (int i=0;i<capacity;i++)
	{
		out << l[i] << " ";
    }
}