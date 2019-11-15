#include <iostream>
#include <fstream>
#include "Vertex.hpp"
using namespace std; 


class PriorityQueue
{
public:
	Vertex *l;
	int capacity,size;
	
	PriorityQueue( int cap)
	     :l{new Vertex[cap]},capacity{cap},size{0}
	{}

	void enqueue(Vertex & v, int dist = INT_MAX)
	{
    	l[size] = v;
    	l[size].dist = dist;
    	l[size].id = l[size].edges[0].src;
    	size++;
    	heapsort();
    }

	Vertex dequeue()
	{
    	Vertex ret = l[0];
    	l[0]=l[size-1];
    	size--;
    	heapsort();
    	return ret;
	}

	void id(int n, int m)
    {
    	for (int i=0;i<size;i++)
    	{
    		if (l[i].id == n)
    		{
    			l[i].dist = m;
    		}
    	}
    }

	Vertex peek()
	{
        return l[0];
	}

	bool isEmpty() 
	{
		return (size==0);
	}

	~PriorityQueue()
	{
		delete[] l;
	}

	void heapsort() 
	{
		heapify(size); 
		for ( int end = size - 1; end > 0; --end )
		{
			swap(l[0], l[end]);
			siftSmallestDown(0, end-1 ); 
		}
	}

	int leftChild(int i)
	{ 
		return 2*i+1; 
	}

	void heapify(int N)  
	{
		for ( int start = N / 2; start >= 0; --start ) 
			siftSmallestDown(start, N-1 );
	}

	void  siftSmallestDown(int cur, int N )  
	{
		int child;
		Vertex cur_str = l[cur];
		for ( ; leftChild(cur) <= N; cur = child ) 
		{
			child = leftChild(cur);
			if ( child != N && l[child].dist < l[child+1].dist )
				++child;
            if ( cur_str.dist < l[child].dist )
            	l[cur] = l[child];
            else break;
            cur = child;
        }
        l[cur] = cur_str;
    }
};
