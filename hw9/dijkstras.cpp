#include <iostream>
#include <fstream>
#include <queue>
#include <climits>
#include <stack>
#include "Graph.cpp"
#include "PriorityQueue.cpp"
using namespace std;  

void dijkstras (Graph & g,Vertex s,int dist[], int prev[]) //O((|E|+|V|)log|V|)
{
  int N = g.num_vertex;
  PriorityQueue Q(N);
  for (int i=0; i < N; i++)
  {
    prev[i] = -1; 
    if (i==s.id)
    {
      dist[i] = 0;
    }
    else
    { 
      dist[i] = INT_MAX;
    }
    Q.enqueue(g.vertices[i],dist[i]);
  }
  dist[s.id] = 0;
  while (!Q.isEmpty())
  {
    Vertex u = Q.dequeue();
    for (Edge edge:g.outgoingEdges(u))
    {
      int v = edge.dst;
      if (dist[v] > dist[u.id] + edge.weight)
      {
        dist[v] = dist[u.id]+ edge.weight;
        prev[v] = u.id;
        Q.id(v,dist[v]);
        Q.heapsort();
      }
    }
  }
}


int main(int argc, char *argv[])
{
  const char * input_file; 
  int s;
  if (argc == 3)
  {
    s = stoi(argv[1]);
    input_file = argv[2];
  }
  Graph g(input_file);
  int *dist = new int[g.num_vertex];
  int *prev = new int[g.num_vertex];
  dijkstras(g,s,dist,prev);
  for (int i=0;i < g.num_vertex; i++)
  {
    cout << i<<" [";
    int j = i;
    stack<int> s;
    int c = 0;
    while (prev[j]!=-1)
    {
      c++;
      s.push(prev[j]);
      j = prev[j];
    }
    while (c!=0)
    {
      c--;
      cout<< s.top() << "-";
      s.pop();
    }
    cout << i<<"] ("<<dist[i]<<")"<< endl;
  }
  delete[] dist;
  delete[] prev;
  return 0;
}



