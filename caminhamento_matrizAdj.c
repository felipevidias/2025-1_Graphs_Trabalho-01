#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define max_vertex 100

// graph structure 
typedef struct{
  int numVertex;
  int matrix[max_vertex][max_vertex];
}Graph;

// inicializing the graph with 0 (no edges)
void startGraph(Graph *g, int vertex){
  g->numVertex = vertex;
  for(int i = 0; i < vertex; i++){
    for(int j = 0; j < vertex; j++){
      g->matrix[i][j] = 0;
    }
  }
}

// add edge to a graph 
void addEdge(Graph *g, int origin, int dest, int direction){
  g->matrix[origin][dest] = 1;
  if(!direction)
    g->matrix[dest][origin] = 1; // to a non-directional graph 
}

void printGraph(Graph *g){
  printf("GRAPH: \n");
  printf("\t  ");
  for(int i = 0; i < g->numVertex; i++){
    printf("%c ", 'a' + i);
  }
  printf("\n");
  for(int i = 0; i < g->numVertex; i++){
    printf("\t");
    printf("%c ", 'a' + i);
    for(int j = 0; j < g->numVertex; j++){
      printf("%d ", g->matrix[i][j]);
    } 
    printf("\n");
  }
}

int main(){
  int vertex = 5;
  Graph g;
  
  startGraph(&g, vertex);

  // adding some edges (0 for a non-directional graph)
  addEdge(&g, 0,1,0);
  addEdge(&g,0,4,0); 
  addEdge(&g,1,2,0);
  addEdge(&g,1,3,0);

  printGraph(&g);

  return 0; 
}

