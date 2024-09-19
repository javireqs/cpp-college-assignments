// Javier Hernandez Requena
// CS 110 C
// Module 13 HW - CS Airlines
// This program implements Dijkstra's algorithm in order to determine the cheapest flights
// from San Francisco to other cities for a fictitous airline, CS Airlines.

#include <stdio.h>
#include <limits.h>
#define V 6    // Vertices


// minDist - function to find minimum distances
int minDist(int distances[], bool pathFound[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (pathFound[v] == false && distances[v] <= min)
            min = distances[v], min_index = v;

    return min_index;
} // end shortestPath

// printArray - function to print array
void printArray(int distances[], int n)
{
    printf("Vertex      Distance From Source\n");
    
    for (int i = 0; i < V; i++)
     printf("   %d \t\t %d\n", i, distances[i]);
} // end printArray

// djikstra - implementation of djikstra's algorithm
void dijkstra(int graph[V][V], int source)
{
    int distances[V];   // output array
    bool pathFound[V];   // test condition for shortest path found, true if found, false otherwise

    // initialize distances to infinity & shortestPath[] as false
    for (int i = 0; i < V; i++)
        distances[i] = INT_MAX, pathFound[i] = false;

    distances[source] = 0;  // distance from source to source = 0

    for (int i = 0; i < V-1; i++)
    {
        int u = minDist(distances, pathFound); // pick vertex with minimum distance from remaining vertices, equal to source in first iteration

        pathFound[u] = true; // mark path

        // update array with shortest path if and only if;
        // path is not in pathFound, an edge from u to v exists, and 
        // the total weight of path from source to v through u is smaller than current smallest weight
        for (int v = 0; v < V; v++)
            if ((!pathFound[v] && graph[u][v] && distances[u] != INT_MAX) && (distances[u] + graph[u][v] < distances[v]))
                distances[v] = distances[u] + graph[u][v];
    }

    printArray(distances, V);
} // end dijkstra

int main()
{
    // creating graph
    int graph[V][V] = 
    {
        {0, 120, 150, 0, 0, 500},
        {120, 0, 0, 75, 0, 350},
        {150, 0, 0, 0, 250, 0},
        {0, 75, 0, 0, 150, 0},
        {0, 0, 250, 150, 0, 0},
        {500, 350, 0, 0, 0, 0}
    };

    // find shortest path using dijkstra & print
    dijkstra(graph, 0);

    return 0;
}


/* 

    SAMPLE OUTPUT

Vertex      Distance From Source
   0             0
   1             120
   2             150
   3             195
   4             345
   5             470

*/