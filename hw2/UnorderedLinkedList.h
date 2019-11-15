#include <iostream>
#include <fstream>
#ifndef UNORDEREDLINKEDLIST_HPP
#define UNORDEREDLINKEDLIST_HPP
using namespace std;

class UnorderedLinkedList
{
     struct ListNode 
     {
          string info;
          ListNode * next;
          ListNode(string new_info, ListNode *new_next):
               info(new_info), next(new_next) { }
          static void print(ostream & out, ListNode *L)
          {
               if (L) 
               {
                    out << L->info << endl;
                    print(out, L->next);
               }
          } 
     };
     ListNode * head;
public:
     UnorderedLinkedList();
     bool isEmpty();
     bool isFull();
     void insert(string word);
     bool find(string word);
     void remove(string word);
     void print(ostream & out);
     ~UnorderedLinkedList();
};


#endif 


