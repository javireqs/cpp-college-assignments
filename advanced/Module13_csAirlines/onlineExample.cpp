#include <stdio.h>
#include <limits.h>

// defining the number of vertices in the given graph
#define V 6

//funtion to find the shortest distance
int min_Distance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_Index;

    for (int v = 0; v < V; v++)
    if (sptSet[v] == false && dist[v] <= min)
    min = dist[v], min_Index = v;

    return min_Index;
}

// function to print the constructed distance array
void print_Solution(int dist[], int n)
{
    printf("Vertex----Distance from Source\n");
    for (int i = 0; i < V; i++)
    printf("%d \t\t %d\n", i, dist[i]);
}

//function implementing dijkstra algorithm
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; /* This is the output array. dist[i] will hold the shortest distance from src to i */

    bool sptSet[V]; /* sptSet[i] will true if vertex i is included in shortest path tree or shortest distance from src to i is finalized*/

    // Initializing all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        /* Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in first iteration.*/
        int u = min_Distance(dist, sptSet);

        // Marking the picked vertex as processed
        sptSet[u] = true;

        // Updating dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

        // Updating dist[v] only if is not in sptSet, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]*/
        if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
        && dist[u]+graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    print_Solution(dist, V);
}

// driver program to test above function
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 120, 150, 0, 0, 500},
    {120, 0, 0, 75, 0, 350},
    {150, 0, 0, 0, 250, 0},
    {0, 75, 0, 0, 150, 0},
    {0, 0, 250, 150, 0, 0},
    {500, 350, 0, 0, 0, 0}
    };

    dijkstra(graph, 0);

    return 0;
}