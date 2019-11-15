#include <iostream>
#include <fstream>
#include "Sorter.hpp"
using namespace std; 


class HeapSorter: public Sorter
{
public:
	HeapSorter(int max_len)
	    :Sorter(max_len) {};

	virtual void sort() override 
	{
		heapify( l, capacity ); 
		for ( int end = capacity - 1; end > 0; --end )
		{
			swap( l[0], l[end] );
			siftSmallestDown( l, 0, end-1 ); 
		}
	}

	int leftChild(int i)
	{ 
		return 2*i+1; 
	}

	void heapify( string A[], int N )  
	{
		for ( int start = N / 2; start >= 0; --start ) 
			siftSmallestDown( A, start, N-1 );
	}

	void  siftSmallestDown( string A[], int cur, int N )  
	{
		int child;
		string cur_str = A[cur];
		for ( ; leftChild(cur) <= N; cur = child ) 
		{
			child = leftChild(cur);
			if ( child != N && A[child] < A[child+1] )
			    ++child;
            if ( cur_str < A[child] )
            	A[cur] = A[child];
            else break;
            cur = child;
        }
        A[cur] = cur_str;
    }
};

