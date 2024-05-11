#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

// DFS algorithm in C++

#include <iostream>
#include <list>
using namespace std;

class DFS_Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

   public:
  DFS_Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};

// Initialize graph
DFS_Graph::DFS_Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void DFS_Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}

// DFS algorithm
void DFS_Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];


  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}

#endif // DFS_H_INCLUDED
