#include <stdio.h>
#define INT_MAX 100

void printSolution(int *distance, int number_of_vertex){
    printf( "Vertex Distance from Source\n" );
    for (int i = 0; i < number_of_vertex; i++){
        printf( "%d\t\t%d\n", i, distance[i] );
    }
}

void BellmanFord(int graph[][3], 
                 int number_of_vertex, 
                 int number_of_edge, 
                 int vertex_src){
    // the weight list
    int distance[number_of_vertex];
    for (int i=0; i< number_of_vertex ; i++){
    distance[i] = INT_MAX;
    }
    
    // set vertex source of weight is 0
    distance[vertex_src] = 0;

    for (int vertex = 0; vertex < number_of_vertex-1; vertex++ ){
        for (int edge = 0; edge < number_of_edge; edge++ ){  
        if(distance[graph[edge][0]] != INT_MAX  &&
            distance[graph[edge][0]] + graph[edge][2]  <  distance[graph[edge][1]]
            ){
            distance[graph[edge][1]] = distance[graph[edge][0]] + graph[edge][2];
            }
        }
    }

    printSolution(distance, number_of_vertex);
}


int main()
{
    int number_of_vertex = 5; // Number of vertices in graph
    int number_of_edge = 8; // Number of edges in graph
 
    // Every edge has three values (u, v, w) where
    // the edge is from vertex u to v. And weight
    // of the edge is w.
    int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
                       { 1, 2, 3 }, { 1, 3, 2 }, 
                       { 1, 4, 2 }, { 3, 2, 5 }, 
                       { 3, 1, 1 }, { 4, 3, -3 } };
 
    BellmanFord(graph, number_of_vertex, number_of_edge, 0);
    return 0;
}