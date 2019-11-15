#include <iostream>
#include <fstream>
#include "Hasher.h"
#include <cmath>
using namespace std;  

class ChainedHashTable 
{
private:
  struct ListNode 
    {
      string key;
      int value;
      ListNode * next;
    };
  int length;
  ListNode** T;
  Hasher& hash_func;
  int *chained_list_lengths;

public:
  ChainedHashTable(int capacity, Hasher & myHasher) 
              :length(capacity),T(new ListNode*[capacity]),hash_func(myHasher),chained_list_lengths(new int[capacity])
  {
    for (int i = 0; i < capacity; ++i)
    {
      T[i] = nullptr;
      chained_list_lengths[i] = 0;
    }
  }

  ChainedHashTable(const ChainedHashTable & s )
            :length(s.length),T(new ListNode*[s.length]),hash_func(s.hash_func),chained_list_lengths(new int[s.length])
  {
    for (int i = 0; i < s.length; ++i)
    {
      T[i] = nullptr;
      chained_list_lengths[i] = s.chained_list_lengths[i];
    }
    arraycopy(T,s.T,s.length);
  } 

  int &operator[] (string s) 
  {
    if (find(s)!=-1)
    {
      unsigned int i = hash_func.hash(s,length)%length;
      ListNode* l=T[i];
      while (l != nullptr)
      {
        if (l->key == s)
        {
          int& r = l->value;
          return r;
        }
        l = l->next;
      }
    }
    throw 1;
  }

  ~ChainedHashTable()
  {
    for (int i = 0; i < length; ++i)
      deleList(T[i]);
    delete[] T;
    delete[] chained_list_lengths;
  }


  void insert(string key, int value) 
  {
    unsigned int location = hash_func.hash(key,length)%length;
    if (find(key)!=-1)
    {
      for (ListNode* p=T[location];p!=nullptr;p=p->next)
      {
        if (p->key==key)
          p->value+=1;
      }
    }
    else
    {
      ListNode* n = T[location];
      chained_list_lengths[location]++;
      if (n != nullptr)
      {
        T[location]= new ListNode{key,value, nullptr};
        T[location]->next = n;
      }
      else
        T[location]= new ListNode{key,value, nullptr};
    }
  }


  int find(string key) 
  {
    unsigned int i = hash_func.hash(key,length)%length;
    ListNode* l;
    l = T[i];
    while (l != nullptr)
    {
      if (l->key == key)
        return l->value;
      l = l->next;
    }
    return -1;
  }


  void remove(string key) 
  {
    unsigned int i = hash_func.hash(key,length)%length;
    if (T[i] != nullptr)
    {
    if (T[i]->key == key)
    {
      chained_list_lengths[i]--;
      ListNode* u = T[i]->next;
      delete T[i];
      T[i] = u;
    }
    else
    {
      for (ListNode* p=T[i];p!=nullptr;p=p->next)
      {
        if (p->next != nullptr)
        {
          if (p->next->key == key)
          {
            chained_list_lengths[i]--;
            ListNode* u = p->next->next;
            delete p->next;
            p->next = u;
          }
        }
      }
    }}
  }

  void deleList(ListNode* L)
  {
    ListNode *p;
    while (L!=nullptr)
    {
      p=L;
      L=L->next;
      delete p;
    }
  }

  void arraycopy(ListNode** target, ListNode** source, unsigned int cap)
  {
    for (unsigned int i = 0; i < cap; i++)
    {
      target[i] = nullptr;
      ListNode* snode = source[i];
      if (snode != nullptr)
      {
        target[i] = new ListNode{snode->key, snode->value, nullptr};
        while (snode->next != nullptr)
        {
          ListNode* p = new ListNode{snode->next->key, snode->next->value, nullptr};
          p -> next = target[i];
          snode = snode->next;
          target[i] = p;
        }
      }
    }
  }

  void arraycopy(ListNode** target, ListNode** source, unsigned int cap)
  {
    for (unsigned int i = 0; i < cap; i++)
    {
      target[i] = nullptr;
      ListNode* snode = source[i];
      if (snode != nullptr)
      {
        target[i] = new ListNode{snode->key, snode->value, nullptr};
        while (snode->next != nullptr)
        {
          target[i] = new ListNode{snode->next->key, snode->next->value, target[i]};
          snode = snode->next;
        }
      }
    }
  }

  void print(ostream & out)  
  {
    for (int i=0;i<length;i++)
    {
      for (ListNode *p=T[i];p!=nullptr;p=p->next)
      {
        out << i << " key: "<< p->key << " value:" << p->value<< endl;
      }
    }
  }

  int maximum_chain_length()
  {
    int m=0;
    for (int i=0;i<length;i++)
      m = max(m,chained_list_lengths[i]);
    return m;
  }

  int minimum_chain_length()
  {
    int m=0;
    for (int i=0;i<length;i++)
      m = min(m,chained_list_lengths[i]);
    return m;
  }

  double average_chain_length()
  {
    double m=0;
    for (int i=0;i<length;i++)
      m += chained_list_lengths[i];
    return m/length;
  }

  double standard_deviation()
  {
    double m=0;
    for (int i=0;i<length;i++)
    {
      m+=(chained_list_lengths[i]- average_chain_length())*(chained_list_lengths[i]- average_chain_length());
    }
    m=sqrt(m/length);
    return m;
  }
};