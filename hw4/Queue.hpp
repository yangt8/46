#include <iostream>
#include <fstream>
#ifndef QUEUE_HPP
#define QUEUE_HPP
using namespace std;

class Queue
{
public:
	Queue() {};
	virtual ~Queue() = default;
	virtual void enq(string word) = 0;
	virtual string deq() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual string front() = 0;
};

#endif 