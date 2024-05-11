#include <bits/stdc++.h>
#include "bfs.h"
#include "dfs.h"

using namespace std;

void copyArr(int*, int*, int);
void AssignRandomEdges(BFS_Graph, int**, int);
void AssignRandomEdges(DFS_Graph, int**, int);
int** randomEdges(int, double);

int main()
{
    srand(time(NULL));
    clock_t start, end;

    ofstream file("file.txt");

    int n[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};

    for(int i=0; i<10; i++)
    {
    	double start = 0, end = 0, bfsTime, dfsTime;

    	int** edged;
    	edged = randomEdges(n[i],0.5);

    	start = clock();
        BFS_Graph g(n[i]);
        AssignRandomEdges(g, edged, n[i]);
        g.BFS(100);
        end = clock();
        bfsTime = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        DFS_Graph gr(n[i]);
        AssignRandomEdges(gr, edged, n[i]);
        gr.DFS(100);
        end = clock();
        dfsTime = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout << bfsTime << "," << dfsTime << endl;
        if(file.is_open())
			file << n[i] << "," << bfsTime << "," << dfsTime << "\n";
    }
    file.close();
}

int** randomEdges(int numVertices, double edgeProbability)
{
    int** arr = new int*[numVertices];
    for(int i=0; i<numVertices; i++)
        arr[i] = new int[2];

    int ctr = 0;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = i + 1; j < numVertices; j++)
        {
          double randomValue = (double)rand() / RAND_MAX;
          if (randomValue < edgeProbability)
          {
            arr[i][0] = i;
            arr[i][1] = j;
          }
        }
    }
    return arr;
}

void AssignRandomEdges(BFS_Graph g,int** arr, int n)
{
    for(int i=0; i<n; i++)
    {
        g.addEdge(arr[i][0], arr[i][1]);
    }
}

void AssignRandomEdges(DFS_Graph g,int** arr, int n)
{
    for(int i=0; i<n; i++)
    {
        g.addEdge(arr[i][0], arr[i][1]);
    }
}

void copyArr(int *org, int *arr, int n)
{
	for(int i=0; i<n; i++)
		org[i] = arr[i];
}
