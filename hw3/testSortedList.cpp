#include <iostream>
#include <fstream>
#include "SortedList.hpp"
#include "SortedArrayList.cpp"
#include "SortedLinkedList.cpp"
#include "Timer.h"
using namespace std;


ostream & operator << (ostream & out, SortedArrayList & L)   //O(N)
{
     L.print(out); 
     return out;
}

ostream & operator << (ostream & out, SortedLinkedList & L)   //O(N)
{
     L.print(out); 
     return out;
}

void insert_all_words(string file_name, SortedList & L)   //O(N^2)
{
     Timer t;
     double eTime;
     ifstream f(file_name);
     t.start();
     string w;
     while (f>>w)
     {
          L.insert(w);
     }
     f.close();
     t.elapsedUserTime(eTime);
     cout << "Inset all word: "<<eTime << endl;
}

void find_all_words(string file_name, SortedList & L)   //SortedLinkedList:O(N^2) SortedArrayList: O(NlogN)
{
     Timer t;
     double eTime;
     ifstream f(file_name);
     t.start();
     string w;
     while (f>>w)
     {
          L.find(w);
     }
     f.close();
     t.elapsedUserTime(eTime);
     cout << "Find all word: "<<eTime << endl;
}

void remove_all_words(string file_name, SortedList & L)   //O(N^2)
{
     Timer t;
     double eTime;
     ifstream f(file_name);
     t.start();
     string w;
     while (f>>w)
     {
          L.remove(w);
     }
     f.close();
     t.elapsedUserTime(eTime);
     cout << "Remove all word: "<<eTime << endl;
}


void test_SortedList_methods(string file_name, SortedList & L)   //O(N^2)
{
     insert_all_words(file_name, L);
     find_all_words(file_name, L);
     remove_all_words(file_name, L);
}


int main(int argc, char * argv[])   //O(N^2)
{
	const char * input_file;
	if (argc == 2)
	{
		input_file = argv[1];
	}
	else
	{
		input_file = "random.txt";
	}

	cout << "Testing SortedArrayList:" << endl;
    SortedArrayList UAL(45500);
    test_SortedList_methods(input_file, UAL);
    cout << "-----------------------------" << endl;
    cout << "Testing SortedLinkedList:" << endl;
    SortedLinkedList ULL;
    test_SortedList_methods(input_file, ULL);
    
    return 0;
}
