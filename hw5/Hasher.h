#include <iostream>
#include <fstream>
using namespace std;  

#ifndef HASHER_HPP
#define HASHER_HPP

struct Hasher 
{
  virtual int hash(string s, int N) = 0;
};

#endif