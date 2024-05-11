#ifndef KRUSKALS_H_INCLUDED
#define KRUSKALS_H_INCLUDED

// Kruskal's algorithm in C++
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

#define edge pair<int, int>

class GRAPH_KRUSKALS {
    private:
        vector<pair<int, edge> > G;  // graph
        vector<pair<int, edge> > T;  // mst
        int *parent;
        int V;  // number of vertices/nodes in graph
    public:
        GRAPH_KRUSKALS(int V);
        void AddWeightedEdge(int u, int v, int w);
        void generate_random_edges(int max_weight);
        int find_set(int i);
        void add_edge(int u, int v, int weight);
        void union_set(int u, int v);
        void kruskal();
        void print();
};

GRAPH_KRUSKALS::GRAPH_KRUSKALS(int x)
{
    parent = new int[x];
    V = x;

    //i 0 1 2 3 4 5
    //parent[i] 0 1 2 3 4 5
    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}

void GRAPH_KRUSKALS::AddWeightedEdge(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u, v)));
}

int GRAPH_KRUSKALS::find_set(int i)
{
    // If i is the parent of itself
    if (i == parent[i])
    return i;
    else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void GRAPH_KRUSKALS::union_set(int u, int v)
{
    parent[u] = parent[v];
}

 void GRAPH_KRUSKALS::generate_random_edges(int max_weight)
 {
     srand(time(NULL));
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            int weight = (rand() % (max_weight -1));  // Generate random weight
            AddWeightedEdge(i, j, weight);
        }
    }
}

void GRAPH_KRUSKALS::kruskal()
{
    int i, uRep, vRep;
    sort(G.begin(), G.end());  // increasing weight
    for (i = 0; i < G.size(); i++)
    {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep)
        {
          T.push_back(G[i]);  // add to tree
          union_set(uRep, vRep);
        }
    }
}
void GRAPH_KRUSKALS::print()
{
    cout << "Edge :"
     << " Weight" << endl;
    for (int i = 0; i < T.size(); i++)
    {
        cout << T[i].second.first << " - " << T[i].second.second << " : "
           << T[i].first;
        cout << endl;
    }
}
#endif // KRUSKALS_H_INCLUDED
