#include <iostream>
#include <fstream>
#include <sstream>
#include "Vertex.hpp"
using namespace std; 

class Graph
{
public:
	Vertex * vertices;
	int num_vertex=0;
	int num_edge=0;

	Graph( string file_name )
	{
		ifstream f(file_name);
		string s;
		int src, dst, w;
		while (getline(f,s))
		{
			if (num_vertex == 0)
			{
				num_vertex = stoi(s);
				vertices = new Vertex[num_vertex];
			}
			else
			{
				stringstream temp(s);
				temp>>src>>dst>>w;
		        add_edge(src, dst, w);
		    }
		}
		f.close();
	}
		

	void add_edge( int src, int dst, int w )
	{
		vertices[src].add_edge(Edge(src, dst, w));
		num_edge++;
	}


	vector<Edge> outgoingEdges(Vertex& v)
	{
		return vertices[v.id].edges;
	}

	void print( ostream & out )
	{
		for (int i=0;i<num_vertex;i++)
			out << i << " ";
    }

	~Graph( )
	{
		delete[] vertices;
	}
};