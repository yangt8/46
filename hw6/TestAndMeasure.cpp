#include <iostream>
#include <fstream>
#include "BinarySearchTree.cpp"
#include "Timer.h"
using namespace std;  


ostream & operator << (ostream & out, BinarySearchTree<int, int> & L) 
{
  L.print(out); 
  return out;
}


void insertAllWords(BinarySearchTree<string, int> & T, int partition, const char *fileName) 
{
  int i = 0;
  Timer t;
  double eTime;
  ifstream f(fileName);
  string w;
  t.start();
  while (i<partition*4539)
  {
    f>>w;
    T.insert(w,1);
    i++;
  }
  f.close();
  t.elapsedUserTime(eTime);
  cout<< i <<"File: "<< fileName <<". Partition: " << partition << "/10. Function: insertAllWords.  Time: "<<eTime<< "s"<< endl;
}


void findAllWords(BinarySearchTree<string, int> & T, int partition, const char *fileName) 
{
  int i = 0;
  Timer t;
  double eTime;
  ifstream f(fileName);
  string w;
  t.start();
  while (i<partition*4539)
  {
    f>>w;
    T.find(w);
    i++;
  }
  f.close();
  t.elapsedUserTime(eTime);
  cout<< "File: "<< fileName <<". Partition: " << partition << "/10. Function: findAllWords.    Time: "<<eTime<< "s"<< endl;
}


void removeAllWords(BinarySearchTree<string, int> & T, int partition,const char *fileName) 
{
  int i = 0;
  Timer t;
  double eTime;
  ifstream f(fileName);
  string w;
  t.start();
  while (i<partition*4539)
  {
    f>>w;
    T.remove(w);
    i++;
  }
  f.close();
  t.elapsedUserTime(eTime);
  cout<< "File: "<< fileName <<". Partition: " << partition << "/10. Function: removeAllWords.  Time: "<<eTime<< "s"<< endl;
}


void measureAll(const char *fileName) 
{
  for (int i=1; i<=10; ++i) 
  {
    BinarySearchTree<string, int> T; 
    insertAllWords(T, i, fileName);
    findAllWords(T, i, fileName);
    removeAllWords(T, i, fileName);
  } 
}


int main()
{
  const char *fileName;
  fileName = "random.txt";

  measureAll(fileName);
  cout << "\n"<< endl;

  BinarySearchTree<int, int> T; 
  ifstream f(fileName);
  string w;
  cout << "Words in random.txt of:"<< endl;
  while (f>>w)
  {
    T.countLengths(w.size());
  }
  cout << T << endl;



  return 0;
}





