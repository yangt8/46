#include <iostream>
#include <fstream>
#include "UnorderedArrayList.cpp"
#include "UnorderedLinkedList.cpp"
#include "Timer.h"

using namespace std;

ostream & operator << (ostream & out, UnorderedLinkedList & L) // O(N)
{
     L.print(out); 
     return out;
}

ostream & operator << (ostream & out, UnorderedArrayList & L)  // O(N)
{
     L.print(out); 
     return out;
}

void insert_all_words(string file_name, UnorderedLinkedList & L)  // O(N)
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
    cout << "Insert all word: "<<eTime << endl;
}

void find_all_words(string file_name, UnorderedLinkedList & L)  // O(N^2)
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
void remove_all_words(string file_name, UnorderedLinkedList & L)  // O(N^2)
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

void test_UnorderedLinkedList_methods(string file_name, UnorderedLinkedList & L) // O(N^2)
{
     cout << "Testing UnorderedLinkedList:" << endl;
     insert_all_words(file_name, L);
     find_all_words(file_name, L);
     remove_all_words(file_name, L);
}



void insert_all_words(string file_name, UnorderedArrayList & L) // O(N)
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

void find_all_words(string file_name, UnorderedArrayList & L) // O(N^2)
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

void remove_all_words(string file_name, UnorderedArrayList & L) // O(N^2)
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


void test_UnorderedArrayList_methods(string file_name, UnorderedArrayList & L) // O(N2)
{
     cout << "Testing UnorderedArrayList:" << endl;
     insert_all_words(file_name, L);
     find_all_words(file_name, L);
     remove_all_words(file_name, L);
}


int main(int argc, char * argv[]) // O(N2)
{
	const char * input_file;
	if (argc == 2)
	{
		input_file = argv[1];
	}
	else
	{
		input_file = "random2.txt";
	}
    UnorderedArrayList UAL(45500);
    test_UnorderedArrayList_methods(input_file, UAL);
    UnorderedLinkedList ULL;
    test_UnorderedLinkedList_methods(input_file, ULL);
    return 0;
}
