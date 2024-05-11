#ifndef PRIMS_H_INCLUDED
#define PRIMS_H_INCLUDED
// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
#include <ctime>
using namespace std;

#define INF 9999999

// number of vertices in grapj


// create a 2d array of size 5x5
//for adjacency matrix to represent graph
class GRAPH_PRIMS {
    private:
        int V;  // number of vertices/nodes in graph
        vector<vector<int>> matrix;
    public:
        GRAPH_PRIMS(int V);
        void generate_random_adjacency_matrix(int max_weight);
        void prims();
        void print();
};

GRAPH_PRIMS::GRAPH_PRIMS(int x)
{
    V = x;

    vector <int> vec;
    for(int i=0; i<x; i++)
        vec.push_back(0);
    for(int i=0; i<x; i++)
    {
        matrix.push_back(vec);
    }
}
void GRAPH_PRIMS::generate_random_adjacency_matrix(int max_weight)
{
    srand(time(NULL));
    int **temp = new int*[V];
    for(int i=0; i<V; i++)
        temp[i] = new int[V];
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            int weight = (rand() % (max_weight -1)) + max_weight;
            if(i!=j)
            {
                temp[i][j] = weight;
                temp[j][i] = weight;
            }
        }
    }
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
}
void GRAPH_PRIMS::prims()
{
    int no_edge;  // number of edge

    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[V];

    // set selected false initially
    memset(selected, false, sizeof(selected));

    // set number of edge to 0
    no_edge = 0;

    // the number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in
    //graph

    // choose 0th vertex and make it true
    selected[0] = true;

    int x;  //  row number
    int y;  //  col number

    while (no_edge < V - 1)
    {
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && matrix[i][j])
                    {  // not in selected and there is an edge
                        if (min > matrix[i][j])
                        {
                            min = matrix[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = true;
        no_edge++;
    }
}

#endif // PRIMS_H_INCLUDED
