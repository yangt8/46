#include <iostream>
#include <fstream>	
#include "Stack.hpp"
#include "ContainerUnderflow.hpp"
#include "ContainerOverflow.hpp"
using namespace std;	

class ArrayStack: public Stack
{
public:
	ArrayStack(int maxSize)   //O(1)
        : buf{new string[maxSize]},capacity{maxSize},tp{0}
    {}

	virtual bool isEmpty() override   //O(1)
	{
		return (tp<=0);
	}

    virtual bool isFull() override   //O(1)
    {
    	return (tp==capacity);
    }

    virtual ~ArrayStack() override //O(1)
    {
    	delete[] buf;
    }

    virtual void push(string word) override   //O(1)
    {
        if (isFull()) 
            throw ContainerOverflow("Error: Push on a full ArrayStack");
        buf[tp++] = word;
    }

    virtual string pop() override   //O(1)
    {
        if (isEmpty())
            throw ContainerUnderflow("Error: Pop on an empty ArrayStack");
        return buf[--tp];       
    }

    virtual string top() override   //O(1)
    {
        if (isEmpty())
            throw ContainerUnderflow("Error: Pop on an empty ArrayStack");
        return buf[tp-1]; 
    }


private:
	string * buf;
    int capacity;
    int tp;
};