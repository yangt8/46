#include <iostream>
#include <fstream>
#include <vector> 
#include "Edge.hpp"
using namespace std; 
#ifndef VERTEX_HPP
#define VERTEX_HPP

class Vertex
{
public:
	int id ;
	int dist;
	vector<Edge> edges;

	Vertex(int i=0)
	    :id(i),dist(INT_MAX)
	{}

	void add_edge( const Edge & e )
	{
		edges.push_back(e);
	}

	void print( ostream & out )
	{
		out << "id :" << id << endl;
	}
};

#endif 