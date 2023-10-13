#include <stdio.h>

// Number of vertices in the graph
#define V 9
#define INT_MAX 100

void printGraph( int graph[V][V] )
{
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++){
      printf ( "%d ", graph[i][j] );
    }
    printf ( "\n" );
  }

  
}
void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

int minDistance(int distance[], int status_vertex[]){
    int min = INT_MAX;
    int min_index = 0;

    for (int vertex = 0; vertex < V; vertex++){
      if(status_vertex[vertex] == 0 && distance[vertex] <= min){
        min = distance[vertex];
        min_index = vertex;
      }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src){
  // the weight list
  int distance[V];
  // mark pick out vertex
  int status_vertex[V];

  // create distance status_vertex
  for (int i=0; i<V ; i++){
    distance[i]      = INT_MAX;
    status_vertex[i] = 0;
  }
  distance[src] = 0; // the src vertex

  for (int checking_vertex = 0; checking_vertex < V-1; checking_vertex++ ){
    int min_index = minDistance(distance, status_vertex);
    status_vertex[min_index] = 1;
      for (int linked_vertex = 0; linked_vertex < V; linked_vertex++ ){  
        if(graph[min_index][linked_vertex] != 0 &&
           distance[min_index]             != INT_MAX  &&
           status_vertex[linked_vertex]    == 0 &&
           distance[min_index] + graph[min_index][linked_vertex] <  distance[linked_vertex]
          ){
            distance[linked_vertex] = distance[min_index] + graph[min_index][linked_vertex];
          }
      }
  }
    // print the constructed distance array
    printSolution(distance);
}

int main (){
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
                      };
 
    // Function call
    dijkstra(graph, 0);
//    printGraph(graph); 

    return 0;    
}

