#include <iostream>
#include <fstream>
#include "Sorter.cpp"
#include "HeapSorter.cpp"
#include "InsertionSorter.cpp"
#include "QuickSorter.cpp"
using namespace std;  


ostream & operator << (ostream & out, Sorter & L) 
{
  L.print(out); 
  return out;
}


void measureAll(const char *fileName) 
{
  for (int i=1; i<=10; ++i) 
  {
    InsertionSorter T1(i*4529);
    QuickSorter T2(i*4529);
    HeapSorter T3(i*4529);

    cout<< "File: "<< fileName <<". Partition: " << i << "/10. Sorter: InsertionSorter  ";
    T1.insertAllFromFile(fileName,i); 
    
    cout<< "File: "<< fileName <<". Partition: " << i << "/10. Sorter: QuickSorter      ";
    T2.insertAllFromFile(fileName,i); 

    cout<< "File: "<< fileName <<". Partition: " << i << "/10. Sorter: HeapSorter       ";
    T3.insertAllFromFile(fileName,i); 
  } 
}


int main()
{
  const char *fileName;
  fileName = "random.txt";
  measureAll(fileName);
  return 0;
}

