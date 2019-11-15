#include <iostream>
#include <fstream>
#include "Sorter.hpp"
using namespace std; 


class QuickSorter: public Sorter
{
public:
	QuickSorter(int max_len)
	    :Sorter(max_len) {};


	virtual void sort() override 
	{
		quick_sort(l,0,capacity-1);
	}

	void quick_sort(string A[], int low, int high)
	{
		if ( low < high ) 
		{
			if ( high - low < 16 )
			{
				for (int i = low; i < high; i++)
					for (int j = i; j > 0 && l[j] < l[j - 1]; --j)
						swap(l[j], l[j - 1]);
			} 
			else
			{
				int i = partition( A, low, high ); 
				quick_sort( A, low, i-1 ); 
				quick_sort( A, i+1, high );
			}
		}
	}

	int partition( string A[], int low, int high )  
	{
		string pivot = median_of_three( A, low, high );
		int below = low;
		int above = high;
		for ( ; ; )
		{
			while (below<above && A[below] <  pivot)
				++below;
			while (below<above && A[above] >= pivot)
				--above;
			if (below<above)
				swap(A[below],A[above]);
			else break;
		}
		swap(A[below],A[high]); 
		return below; 
	}


	string median_of_three( string A[], int low, int high ) 
	{
		int mid = low + (high - low) / 2;
		if ( A[mid] < A[low] ) 
			swap( A[low], A[mid] );
		if ( A[high] < A[low] ) 
			swap( A[low], A[high] ); 
		if ( A[mid] < A[high] ) 
			swap( A[mid], A[high] ); 
		return A[high];
	}
};
