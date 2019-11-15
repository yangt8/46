#include "UnorderedLinkedList.h"

UnorderedLinkedList::UnorderedLinkedList()  // O(1)
        :head{nullptr}
{
}

bool UnorderedLinkedList::isEmpty()  // O(1)
{
	return (head==nullptr);
}

bool UnorderedLinkedList::isFull()  // O(1)
{
	return false;
}

void UnorderedLinkedList::insert(string word)  // O(1)
{
	head = new ListNode{word,head};
}

bool UnorderedLinkedList::find(string word)  // O(N)
{
	for (ListNode *p=head;p!=nullptr;p=p->next)
	{
		if (p->info == word)
			return true;
	}
	return false;
}

void UnorderedLinkedList::remove(string word)  // O(N)
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

void UnorderedLinkedList::print(ostream & out)  // O(N)
{
	for (ListNode *p=head;p!=nullptr;p=p->next)
	{
		out << p->info << " ";
	}
}

UnorderedLinkedList::~UnorderedLinkedList()  // O(N)
{
	ListNode *p;
	while (head!=nullptr)
	{
		p=head;
		head=head->next;
		delete p;
	}
}
