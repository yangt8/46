#include "UnorderedArrayList.h"

UnorderedArrayList::UnorderedArrayList(int max_len)  // O(1)
               :buf{new string[max_len]},capacity{max_len},size{0}
{
}

bool UnorderedArrayList::isEmpty()  // O(1)
{
     return (size==0);
}

bool UnorderedArrayList::isFull()  // O(1)
{
     return (size==capacity);
}

void UnorderedArrayList::insert(string word)  // O(1)
{
     if (isFull()==false)
          buf[size]=word;
          size++;
}

bool UnorderedArrayList::find(string word)  // O(N)
{
     for (int i =0;i<size;i++)
     {
          if (buf[i] == word)
               return true;
     }
     return false;
}

void UnorderedArrayList::remove(string word)  // O(N)
{
     for (int i =0;i<size;i++)
     {
          if (buf[i] == word)
          {
               buf[i]=buf[size-1];
               buf[size-1].clear();
               size--; 
          }
     }
     
}

void UnorderedArrayList::print(ostream & out)  // O(N)
{
     for (int i=0;i<size;i++)
     {
          out << buf[i] << " ";
     }
}

UnorderedArrayList::~UnorderedArrayList()  // O(N)
{
     delete[] buf;
}

