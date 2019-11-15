#include <iostream>
#include <fstream>
#include <vector> 
#include "Edge.cpp"
using namespace std; 


class Vertex
{
public:
	int id ;
	vector<Edge> edges;

	Vertex(int i=0)
	    :id(i)
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