#include <iostream>
#include <fstream>
#include "Queue.hpp"
#include "ArrayQueue.cpp"
#include "LinkedQueue.cpp"
using namespace std;

void printout(ostream& out, string word)      //O(1)
{
    out << word << endl;
}


void fillAll(string file_name, Queue & L)   //O(N)
{
    try
    {
    ifstream f(file_name);
    if (f){
    string w;
    while (f>>w)
    {
         L.enq(w);
    }
    f.close();
    }
    else
        cout << "Error: Invalid file to read." << endl;
    }
    catch (ContainerOverflow& e)
    {
        cout << e.get_message()<< endl;
    } 
}

void emptyAll(string file_name, Queue & L)   //O(N)
{
    try
    {
    ofstream f(file_name);
    if (f){
    while (L.isEmpty() != true)
    {
        printout(f,L.deq());
    }
    f.close();
    }
    else
        cout << "Error: Invalid file to write." << endl;
    }
    catch (ContainerUnderflow& e)
    {
        cout << e.get_message()<< endl;
    } 
}


void test_queue(string input_file, string output_file1, string output_file2)   //O(N)
{
    ArrayQueue AQ(45500);
    fillAll(input_file, AQ);
    emptyAll(output_file1, AQ);

    LinkedQueue LQ;
    fillAll(input_file, LQ);
    emptyAll(output_file2, LQ);
}

int main(int argc, char * argv[])    //O(N)
{
    const char * input_file; 
    const char * output_file1;
    const char * output_file2;
	if (argc == 4)
	{
		input_file = argv[1];
        output_file1 = argv[2];
        output_file2 = argv[3];
	}
	else
	{
		cout << "Error: Invalid number of arguments." << endl;
	}
    cout << "---------TEST Queue---------" << endl;
    test_queue(input_file,output_file1,output_file2);
    
	return 0;
}
