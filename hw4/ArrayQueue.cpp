#include <iostream>
#include <fstream>	
#include "Queue.hpp"
#include "ContainerUnderflow.hpp"
#include "ContainerOverflow.hpp"
using namespace std;	

class ArrayQueue: public Queue
{
public:
	ArrayQueue(int maxSize)    //O(1)
	       :buf{new string[maxSize]},capacity{maxSize+1},front1{0},rear{0}
	{}

	virtual bool isEmpty() override   //O(1)
	{
		return (front1==rear);
	}

    virtual bool isFull() override   //O(1)
    {
    	return ((rear+1)%capacity == front1);
    }

    virtual ~ArrayQueue() override   //O(1)
    {
    	delete[] buf;
    }

    virtual void enq(string word) override   //O(1)
    {
        if (isFull())
            throw ContainerOverflow("Error: Enque on a full ArrayQueue");
    	buf[rear] = word;
    	rear = (rear+1) % capacity;
    }


    virtual string deq() override   //O(1)
    {
        if (isEmpty())
            throw ContainerUnderflow("Error: Deque on an empty ArrayQueue");
    	string ret = buf[front1];
    	front1 = (front1+1) % capacity;
    	return ret;
    }

    virtual string front() override   //O(1)
    {
        if (isEmpty())
            throw ContainerUnderflow("Error: Deque on an empty ArrayQueue");
        return buf[front1];
    }

private:
	string * buf;
    int capacity, front1, rear;
};