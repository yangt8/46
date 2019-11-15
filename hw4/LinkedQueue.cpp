#include <iostream>
#include <fstream>	
#include "Queue.hpp"
#include "ContainerUnderflow.hpp"
#include "ContainerOverflow.hpp"
using namespace std;	


class LinkedQueue: public Queue
{
public:
	LinkedQueue()    //O(1)
    {
    	head = tail = nullptr;
    }

	virtual bool isEmpty() override   //O(1)
    {
        return (head == nullptr);
    }

    virtual bool isFull() override   //O(1)
    {
        return false;
    }

    virtual ~LinkedQueue() override   //O(N)
    {
        ListNode *p;
        while (head!=nullptr)
        {
            p=head;
            head=head->next;
            delete p;
        }
    }

    virtual void enq(string word) override   //O(1)
    {
    	ListNode* newNode = new ListNode(word,nullptr);
    	if (isEmpty())
    		head = newNode;
    	else
    		tail->next = newNode;
    	tail = newNode;
    }

    virtual string deq() override   //O(1)
    {
        if (isEmpty())
            throw ContainerUnderflow("Error: Deque on an empty LinkedQueue");
        ListNode* p = head;
        string o = head->info;
        head = head->next;
        delete p;
        return o;       
    }

    virtual string front() override   //O(1)
    {
        if (isEmpty())
            throw ContainerUnderflow("Error: Deque on an empty ArrayQueue");
        return (head->info);
    }

    
private:
	struct ListNode 
    {
    	string info;
        ListNode * next;
        ListNode(string new_info, ListNode *new_next):
                info(new_info), next(new_next) { }
    };
    ListNode * head;
    ListNode * tail;

};