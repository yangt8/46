#include <iostream>
#include <fstream>
#ifndef STACK_HPP
#define STACK_HPP
using namespace std;

class Stack
{
public:
	Stack() {};
	virtual ~Stack() = default;
	virtual void push(string word) = 0;
	virtual string pop() = 0;
	virtual string top() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
};

#endif 