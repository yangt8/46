#include <iostream>
#include <fstream>
#include "Hasher.h"
using namespace std; 

#ifndef GENERALHASHER_HPP
#define GENERALHASHER_HPP

struct GeneralStringHasher: Hasher 
{
  int hash(string key, int N)  
  {
    const unsigned shift = 6;
    const unsigned zero = 0;
    unsigned mask = ~zero >> (32-shift);
    unsigned result = 0;
    int size=key.size();
    int len = min(size, 6);
    for (int i = 0; i < len; i++)
        result = (result << shift) | (key[i] & mask);
    return result % N;
   }
};

struct LowerSixHasher: Hasher
{
  int hash(string key, int N)
  {
    unsigned hashVal = 0;
    int size=key.size();
    int len = min(size, 6);
    for (int i = 0; i < len; i++)
         hashVal = (127 * hashVal + key[i]) % 16908799;
    return hashVal % N;
  }
};

struct SumHasher : Hasher 
{
  int hash(string s, int N) 
  {
    int result = 0;
    int size=s.size();
    for (int i=0; i<size; ++i)
      result += s[i];
    return abs(result) % N;
  }
};


struct ProdHasher : Hasher 
{
  int hash(string s, int N) 
  {
    int result = 1;
    int size=s.size();
    for (int i=0; i<size; ++i)
      result *= s[i];
    return abs(result) % N;
  } 
};

#endif



