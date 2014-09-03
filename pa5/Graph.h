/* Yugraj Singh
 * Graph.h
 */  

#if !defined(_GRAPH_H_INCLUDE)
#define _GRAPH_H_INCLUDE

#define NIL -1
#define UNDF -2
#define WHITE -3
#define GREY -4
#define BLACK -5

typedef struct Graph* GraphRef;
 
/*creates a new Graph ADT*/
GraphRef newGraph(int n);

/*deallocates heap memory from Graph*/
void freeGraph(GraphRef* pG);

/*return the number of vetices in the graph*/
int getOrder(GraphRef G);

/*returns number of connected compoenets*/
int getSize(GraphRef G);

/*returns the parent of the vetice*/
int getParent(GraphRef G, int u);

/*returns the discovery time of the vertice*/
int getDiscover(GraphRef G, int u);

/*returns the finish time of the vertice*/
int getFinish(GraphRef G, int u);

/*adds an vetice to the adj list*/
void addArc(GraphRef G, int u, int v);

/*runs Depth First Search on the Graph*/
void DFS(GraphRef G, ListRef S);

/*returns the transpose of the graph G*/
GraphRef transpose(GraphRef G);

/*returns a copy of the Graph G*/
GraphRef copyGraph(GraphRef G);

/*prints the Graph*/
void printGraph(FILE* out, GraphRef G);

#endif
