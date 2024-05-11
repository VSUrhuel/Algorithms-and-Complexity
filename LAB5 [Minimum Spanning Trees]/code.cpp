#include "kruskals.h"
#include "prims.h"
#include "boruvkas.h"
using namespace std;
int main()
{
    srand(time(NULL));
    clock_t start, end;

    ofstream file("file.txt");

    int n[] = {700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700};
    int max_weight = 10;
    for(int i=0; i<10; i++)
    {
    	double kruskalTime, primsTime, boruvkasTime;

        start = clock();
        GRAPH_KRUSKALS graph_kruskals(n[i]);
        graph_kruskals.generate_random_edges(max_weight);
        graph_kruskals.kruskal();
        end = clock();
        kruskalTime = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        GRAPH_PRIMS graph_prims(n[i]);
        graph_prims.generate_random_adjacency_matrix(max_weight);
        graph_prims.prims();
        end = clock();
        primsTime = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        GRAPH_BORUVKAS graph_boruvkas(n[i]);
        graph_boruvkas.generate_random_edges(max_weight);
        graph_boruvkas.boruvkaMST();
        end = clock();

        boruvkasTime = ((double) (end - start)) / CLOCKS_PER_SEC;
        //cout << kruskalTime << ", " << primsTime << ", " << boruvkasTime << endl;
         if(file.is_open())
			file << n[i] << ", " << kruskalTime << ", " << primsTime << ", " << boruvkasTime << "\n";
    }
    file.close();
}

