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

void dijkstra(int graph[V][V], int src){

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
    printGraph(graph); 

    return 0;    
}

