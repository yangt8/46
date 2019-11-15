#include <iostream>
#include <fstream>
#include "SortedList.hpp"   
using namespace std;

class SortedLinkedList: public SortedList
{
public:
	SortedLinkedList()    //O(1)
       :head{nullptr}
    {}

	bool isEmpty()   //O(1)
    {
        return (head==nullptr);
    }

    bool isFull()   //O(1)
    {
        return false;
    }

    virtual ~SortedLinkedList() override   //O(N)
    {
        ListNode *p;
        while (head!=nullptr)
        {
            p=head;
            head=head->next;
            delete p;
        }
    }


    virtual void insert(string word) override   //O(N)
    {
        if (head==nullptr || head->info > word)
            head = new ListNode{word,head};
        else
        {
            for (ListNode* p=head;p!=nullptr;p=p->next)
            {
                if (p->next != nullptr)
                {
                    if (p->next->info > word)
                    {
                        p->next = new ListNode{word,p->next};
                        break;
                    }
                }
                else
                {
                    if (p->info < word)
                        p->next = new ListNode{word,nullptr};
                }
            }
        }
    }


    virtual bool find(string word) override   //O(N)
    {
        for (ListNode* p=head;p!=nullptr;p=p->next)
        {
            if (p->info == word)
                return true;
        }
        return false;
    }

    virtual void remove(string word) override   //O(N)
    {
        if (head->info == word)
        {
            ListNode* u = head->next;
            delete head;
            head = u;
        }
        else
        {
            for (ListNode* p=head;p!=nullptr;p=p->next)
            {
                if (p->next != nullptr)
                {
                    if (p->next->info == word)
                    {
                        ListNode* u = p->next->next;
                        delete p->next;
                        p->next = u;
                    }
                }
            }
        }
    }

    void print(ostream & out)   //O(N)
    {
        for (ListNode *p=head;p!=nullptr;p=p->next)
        {
            out << p->info << " ";
        }
    }

private:
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

};