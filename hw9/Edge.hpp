#include <iostream>
#include <fstream>
using namespace std; 
#ifndef EDGE_HPP
#define EDGE_HPP

class Edge
{
public:
	int src, dst, weight;

	Edge( int s, int d, int w )
	    :src{s},dst{d},weight{w}
	{}

	Edge reverse()
	{
		return Edge(dst, src, weight);
	}

	void print( ostream & out )
	{
		out << "src: " << src << " dst: " << dst << " weight: " << weight << " ";
	}
};

#endif 
