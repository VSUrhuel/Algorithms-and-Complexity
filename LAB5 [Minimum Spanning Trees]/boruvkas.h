#ifndef BORUVKAS_H_INCLUDED
#define BORUVKAS_H_INCLUDED
// Boruvka's algorithm to find Minimum Spanning
// Tree of a given connected, undirected and weighted graph
#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class GRAPH_BORUVKAS
{
	int V; // No. of vertices
	vector<vector<int> >graph; // default dictionary to store graph

	// A utility function to find set of an element i
	// (uses path compression technique)
	int find(vector<int>& parent, int i)
	{
		if (parent[i] == i) {
			return i;
		}
		return find(parent, parent[i]);
	}

	// A function that does union of two sets of x and y
	// (uses union by rank)
	void unionSet(vector<int>& parent, vector<int>& rank,
				int x, int y)
	{
		int xroot = find(parent, x);
		int yroot = find(parent, y);

		// Attach smaller rank tree under root of high rank
		// tree (Union by Rank)
		if (rank[xroot] < rank[yroot]) {
			parent[xroot] = yroot;
		}
		else if (rank[xroot] > rank[yroot]) {
			parent[yroot] = xroot;
		}
		// If ranks are same, then make one as root and
		// increment its rank by one
		else {
			parent[yroot] = xroot;
			rank[xroot]++;
		}
	}

public:
	GRAPH_BORUVKAS(int vertices)
	{
		V = vertices;
		graph = vector<vector<int> >();
	}

	// function to add an edge to graph
	void addEdge(int u, int v, int w)
	{
		graph.push_back({ u, v, w });
	}

	void generate_random_edges(int max_weight)
     {
         srand(time(NULL));
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                int weight = (rand() % (max_weight -1));  // Generate random weight
                addEdge(i, j, weight);
            }
        }
    }

	// The main function to construct MST using Kruskal's
	// algorithm
	void boruvkaMST()
	{
		vector<int> parent(V);

		// An array to store index of the cheapest edge of
		// subset. It store [u,v,w] for each component
		vector<int> rank(V);
		vector<vector<int> > cheapest(V,
									vector<int>(3, -1));

		// Initially there are V different trees.
		// Finally there will be one tree that will be MST
		int numTrees = V;
		int MSTweight = 0;

		// Create V subsets with single elements
		for (int node = 0; node < V; node++) {
			parent[node] = node;
			rank[node] = 0;
		}

		// Keep combining components (or sets) until all
		// components are not combined into single MST
		while (numTrees > 1) {

			// Traverse through all edges and update
			// cheapest of every component
			for (int i = 0; i < graph.size(); i++) {

				// Find components (or sets) of two corners
				// of current edge
				int u = graph[i][0], v = graph[i][1],
					w = graph[i][2];
				int set1 = find(parent, u),
					set2 = find(parent, v);

				// If two corners of current edge belong to
				// same set, ignore current edge. Else check
				// if current edge is closer to previous
				// cheapest edges of set1 and set2
				if (set1 != set2) {
					if (cheapest[set1][2] == -1
						|| cheapest[set1][2] > w) {
						cheapest[set1] = { u, v, w };
					}
					if (cheapest[set2][2] == -1
						|| cheapest[set2][2] > w) {
						cheapest[set2] = { u, v, w };
					}
				}
			}

			// Consider the above picked cheapest edges and
			// add them to MST
			for (int node = 0; node < V; node++) {

				// Check if cheapest for current set exists
				if (cheapest[node][2] != -1) {
					int u = cheapest[node][0],
						v = cheapest[node][1],
						w = cheapest[node][2];
					int set1 = find(parent, u),
						set2 = find(parent, v);
					if (set1 != set2) {
						MSTweight += w;
						unionSet(parent, rank, set1, set2);
						numTrees--;
					}
				}
			}
			for (int node = 0; node < V; node++) {

				// reset cheapest array
				cheapest[node][2] = -1;
			}
		}

	}
};
// This code is contributed by prajwal kandekar

#endif // BORUVKAS_H_INCLUDED
