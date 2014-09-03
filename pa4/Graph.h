/* Yugraj Singh
 * Graph ADT header file
 *
 */ 

#if !defined(_GRAPH_H_INCLUDE_)
#define _GRAPH_H_INCLUDE_

/*
 *
 */ 
typedef struct Graph* GraphRef;

/*
 *
 */
GraphRef newGraph(int n);

/*
 *
 */
void freeGraph(GraphRef* pG);

/*
 *
 */
int getOrder(GraphRef G);

/*
 *
 */
int getSize(GraphRef G);

/*
 *
 */
int getSource(GraphRef G);

/*
 *
 */
int getParent(GraphRef G, int u);

/*
 *
 */
int getDist(GraphRef G, int u);

/*
 *
 */
void getPath(ListRef L, GraphRef G, int u);

/*
 *
 */
void makeNULL(GraphRef G);

/*
 *
 */
void addEdge(GraphRef G, int u, int v);

/*
 *
 */
void addArc(GraphRef G, int u, int v);

/*
 *
 */
void BFS(GraphRef G, int s);

/*
 *
 */
void printGraph(FILE* out,GraphRef G);

#endif        
