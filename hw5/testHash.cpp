#include <iostream>
#include <fstream>
#include "GeneralHasher.h"
#include "ChainedHashTable.cpp"
#include "Timer.h"
using namespace std;  

ostream & operator << (ostream & out, ChainedHashTable & L) 
{
  L.print(out); 
  return out;
}

void testConstructor(Hasher & hasher)
{
  ChainedHashTable L(0,hasher);
}

void testCopyConstructor(Hasher & hasher)
{
  ChainedHashTable L1(0,hasher);
  ChainedHashTable L2{L1};
}

void print_output(ChainedHashTable  & L)
{
  cout << "       min = "<< L.minimum_chain_length()<<"; max = "<<L.maximum_chain_length() <<"; average = "<< L.average_chain_length()<<"; std_dev = "<<L.standard_deviation() << endl;
}


void insertAll(ChainedHashTable  & L, const char* file_name, int number)   
{
  int i = 0;
  Timer t;
  double eTime;
  ifstream f(file_name);
  string w;
  t.start();
  while (i<number)
  {
    f>>w;
    L.insert(w,1);
    i++;
  }
  f.close();
  t.elapsedUserTime(eTime);
  print_output(L);
  cout <<"       insertAll = " <<eTime<< " sec"<< endl; 
}

void findAll(ChainedHashTable & L, const char* file_name, int number)  
{
  int i = 0;
  Timer t;
  double eTime;
  ifstream f(file_name);
  string w;
  t.start();
  while (i<number)
  {
    f>>w;
    L.find(w);
    i++;
  }
  f.close();
  t.elapsedUserTime(eTime);
  cout <<"       findAll = " << eTime<<" sec"<< endl;
}

void removeAll(ChainedHashTable & L, const char* file_name, int number) 
{
  int i = 0;
  Timer t;
  double eTime;
  ifstream f(file_name);
  string w;
  t.start();
  while (i<number)
  {
    f>>w;
    L.remove(w);
    i++;
  }
  f.close();
  t.elapsedUserTime(eTime);
  cout <<"       removeAll = " << eTime<<" sec"<< endl;
}

void testHash(const char* inputFileName, Hasher & hasher)
{
  for (int k=1; k<=10; k++)
  {
    ChainedHashTable L(5000,hasher);
    insertAll(L, inputFileName,4500*k);
    findAll(L, inputFileName,4500*k);
    removeAll(L, inputFileName,4500*k);
    cout << '\n' << endl;
  }
  /*
  ChainedHashTable L(5000,hasher);
  insertAll(L, inputFileName,4500);
  findAll(L, inputFileName,4500);
  removeAll(L, inputFileName,4500);
  */
}

int main()
{
  /*
  GeneralStringHasher h;
  testConstructor(h);
  testCopyConstructor(h);
  cout << "test GeneralStringHasher" << endl;
  testHash("random.txt", h);*/

  GeneralStringHasher h;
  h.countLengths();
  /*
  cout << '\n' << endl;
  LowerSixHasher h2;
  SumHasher h3;
  ProdHasher h4;
  cout << "Hash function 1 chain length statistics:" << endl;
  testHash("random.txt", h2);
  cout << '\n' << endl;
  cout << "Hash function 2 chain length statistics:" << endl;
  testHash("random.txt", h3);
  cout << '\n' << endl;
  cout << "Hash function 3 chain length statistics:" << endl;
  testHash("random.txt", h4);
  */
  return 0;
}
