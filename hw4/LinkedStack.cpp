#include <iostream>
#include <fstream>	
#include "Stack.hpp"
#include "ContainerUnderflow.hpp"
#include "ContainerOverflow.hpp"
#include <string>
using namespace std;	

class LinkedStack: public Stack
{
public:
	LinkedStack()    //O(1)
       :head{nullptr}
    {}

	virtual bool isEmpty() override   //O(1)
    {
        return (head==nullptr);
    }

    virtual bool isFull() override   //O(1)
    {
        return false;
    }

    virtual ~LinkedStack() override   //O(N)
    {
        ListNode *p;
        while (head!=nullptr)
        {
            p=head;
            head=head->next;
            delete p;
        }
    }

    virtual void push(string word) override   //O(1)
    {
        if (isFull())
            throw ContainerOverflow("Error: Push on a full LinkedStack");
        head=new ListNode(word,head);
    }

    virtual string pop() override   //O(1)
    {
        if (isEmpty())
            throw ContainerUnderflow("Error: Pop on an empty LinkedStack");
        ListNode* p = head;
        string o = head->info;
        head = head->next;
        delete p;
        return o;
    }

    virtual string top() override   //O(1)
    {
        if (isEmpty())
            throw ContainerUnderflow("Error: Pop on an empty LinkedStack");
        return head->info;
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
    ListNode* head;
};