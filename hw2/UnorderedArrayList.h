#include <iostream>
#include <fstream>
#ifndef UNORDEREDARRAYLIST_HPP
#define UNORDEREDARRAYLIST_HPP
using namespace std;

class UnorderedArrayList
{
     string * buf;
     int capacity;
     int size;
public:
     UnorderedArrayList(int max_len);
     bool isEmpty();
     bool isFull();
     void insert(string word);
     bool find(string word);
     void remove(string word);
     void print(ostream & out);
     ~UnorderedArrayList();
};

#endif 