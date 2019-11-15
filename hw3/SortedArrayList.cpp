#include <iostream>
#include <fstream>
#include "SortedList.hpp"	
using namespace std;					

class SortedArrayList: public SortedList
{
public:
	SortedArrayList(int max_len)   //O(1)
	       :buf{new string[max_len]},capacity{max_len},size{0}
	{}

	bool isEmpty()   //O(1)
	{
		return (size==0);
	}

    bool isFull()   //O(1)
    {
    	return (size==capacity);
    }

    virtual ~SortedArrayList() override   //O(1)
    {
    	delete[] buf;
    }

    virtual void insert(string word) override   //O(N)
    {
    	int hole = binary_search(word);
    	copy_down(hole);
    	buf[hole] = word;
    	size++;
    }

	virtual bool find(string word) override   //O(logN)
	{
		return (buf[binary_search(word)] == word);
	}
	

	virtual void remove(string word) override   //O(N)
	{
		int hole = binary_search(word);
		if (hole != size-1)
		{
			for (int i =hole; i < size; i++)
				buf[i] = buf[i+1];
		}
    	buf[size-1].clear();
    	size--;
	}

	void print(ostream & out)   //O(N)
	{
		for (int i=0;i<size;i++)
		{
			out << buf[i] << " ";
		}
    }


private:
	string * buf;
    int capacity;
    int size;

    int binary_search(string word)   //O(logN)
    {
    	int min = 0;
		int max = size-1;
		int mid;
		while (min <= max)
		{
			mid = (max-min)/2 + min;
			if (word < buf[mid])
			{
				max = mid - 1;
			}
			else if (word > buf[mid])
				min = mid + 1;
			else
				return mid;
		}
		mid = (max-min)/2 + min;
		return mid;
    }

    void copy_down(int hole)   //O(N)
    {
    	for (int i = size; i > hole; i--)
    		buf[i] = buf[i-1];
    }

};
