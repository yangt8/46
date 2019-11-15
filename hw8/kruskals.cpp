#include <iostream>
#include <fstream>
#include <queue>
#include "Graph.cpp"
using namespace std;  

struct SetNode
{
  SetNode(): parent(this),id(0),rank(0),size(0) {}
  SetNode* parent;
  int id;
  int rank;
  int size;
};

struct Set
{
  int count;
  SetNode* elements;

  Set(int N): count(N),elements(new SetNode[N]) {}
  ~Set()
  {
    delete[] elements;
  }

  void error(const char* msg)
  {
    cerr << "ERROR:" << msg << endl;
    exit(-1);
  }

  void verify_set_id(int x)
  {
    if (x<0 || x>=count)
      error("ID out of bounds");
  }

  SetNode* Find(SetNode* x)
  {
    if (x->parent != x)
      x->parent = Find(x->parent);
    return x->parent;
  }

  SetNode* Find(int x)
  {
    verify_set_id(x);
    SetNode& my_node = elements[x];
    return Find(&my_node);
  }

  void MakeSet(int x)
  {
    verify_set_id(x);
    SetNode& my_node = elements[x];
    my_node.parent = & my_node;
    my_node.rank = 0;
    my_node.size = 1;
  }

  void Union(int x, int y)
  {
    SetNode* xRoot = Find(x);
    SetNode* yRoot = Find(y);
    if (xRoot == yRoot)
      return;
    if (xRoot->size < yRoot->size)
      swap(xRoot,yRoot);
    yRoot->parent = xRoot;
    xRoot->size = xRoot->size + yRoot->size;
  }
};


vector<Edge> kruskals ( const Graph & g ) // O(N)=|V|log(|E|)
{
  unsigned int N = g.num_vertex;
  Set s(N);
  for (unsigned int i=0; i < N; i++)
  {
    s.MakeSet(i);
  }
  auto order = [](Edge left, Edge right) { return left.weight > right.weight;};
  priority_queue<Edge,vector<Edge>,decltype(order)> Q(order);
  for (unsigned int i=0; i < N; i++)
  {
    for (unsigned int j=0; j < g.vertices[i].edges.size(); j++)
    {
      Q.push(g.vertices[i].edges[j]);
    }
  }
  vector<Edge> T;
  while (T.size() < N-1)
  {
    Edge e = Q.top();
    Q.pop();
    if (s.Find(e.src) != s.Find(e.dst))
    {
      T.push_back(e);
      s.Union(e.src,e.dst);
    }
  }
  return T;
}


int main(int argc, char *argv[])
{
  const char * input_file; 
  if (argc == 2)
  {
    input_file = argv[1];
  }
  Graph g(input_file);
  vector<Edge> v = kruskals(g);
  int w =0;
  for (Edge e: v)
  {
    w+=e.weight;
  }
  cout << w << endl;
  for (Edge e: v)
  {
    cout << "[ " << e.src<< "-" << e.dst<< " ] ( " << e.weight<<" )" << endl;
  }
  return 0;
}