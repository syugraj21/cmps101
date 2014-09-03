/*Yugraj Singh
 *PA3
 *This program is a Graph ADT for the FindPath program
 */ 
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "List.h"
#include "Graph.h"
/* defining for adt methods*/
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define NILL -1
#define INF -2

/*creating Graph struct*/
typedef struct Graph{
	int order;
	int size;
	int source;
	int* color;
	int* distance;
	int* parent;
	ListRef* adj;
}Graph;

/* constructor for the ADT*/
GraphRef newGraph(int n){
	int i;
	GraphRef G = malloc(sizeof(Graph));
	assert(G!=NULL);
	G->order = n;
	G->size = 0;
	G->source = NILL;
	G->color = calloc(n+1,sizeof(int));
	G->distance = calloc(n+1,sizeof(int));
	G->parent = calloc(n+1,sizeof(int));
	G->adj = calloc(n+1,sizeof(ListRef));
	for( i=1; i<=n; i++){
		G->color[i] = WHITE;
		G->distance[i] = INF;
		G->parent[i] = NILL;
		G->adj[i] = newList();
	}
	return G;		
}
/* deconstructor for the ADT
 * deallocates the heap memory
 */
void freeGraph(GraphRef* pG){
	int i;
	if(pG != NULL && *pG !=NULL){
		free((*pG)->color);
		free((*pG)->distance);
		free((*pG)->parent);
		for(i=1; i<=(*pG)->order; i++){
			freeList(&(*pG)->adj[i]);
		}
		free(*pG);
		*pG = NULL;
	}
}

/* getOrder()
 * Pre: none
 * Pos: returns the number of vertices in the graph
 */ 
int getOrder(GraphRef G){
	if(G == NULL){
		fprintf(stderr,"Graph Error: getOrder() called on NULL Graph\n");
		exit(1);
	} 
	return G->order;
}
/* getSixe()
 * Pre: none
 * Pos: returns the number of edges in the graph
 */ 
int getSize(GraphRef G){
	if(G == NULL){
		fprintf(stderr,"Graph Error: getSize() called on NULL Graph\n");
		exit(1);
	}
	return G->size;
}
/* getSource()
 * Pre: none
 * Pos: returns the source(aka "head") of the graph
 */ 
int getSource(GraphRef G){
	if(G == NULL){
		fprintf(stderr,"Graph Error: getSource() called on NULL Graph\n");
		exit(1);
	}
	return G->source;
}

/* getParent()
 * Pre: u cannot be < 1 || u cannot be > order  
 * Pos: returns the parent of the u in the graph
 */ 
int getParent(GraphRef G, int u){
	if(G == NULL){
		fprintf(stderr,"Graph Error: getParent() called on NULL Graph\n");
		exit(1);
	}
	if(u<1 || u>getOrder(G)){
		fprintf(stderr,"getParent() Error: Graph index out of bounds\n");
		exit(1);
	}
	return G->parent[u];
}

/* getDist()
 * Pre: u cannont be < 1 || u cannot be > order
 * 	&& source != NILL
 * Pos: returns the Distance from the source to u
 */ 
int getDist(GraphRef G, int u){
	if(G == NULL){
		fprintf(stderr,"Graph Error: getDist() called on NULL Graph\n");
		exit(1);
	}
	if(u<1 || u>getOrder(G)){
		fprintf(stderr,"getDist() Error: Graph index out of bounds\n");
		exit(1);
	}
	return G->distance[u];
}
/* getPath()
 * Pre: u cannot be < 1 || u cannot be > order
 *	&& source != NILL
 * Pos: returns the path from the source to u	
 */
void getPath(ListRef L, GraphRef G, int u){
	if(G == NULL){
		fprintf(stderr,"Graph Error: getPath() called on NULL Graph\n");
		exit(1);
	}
	if(getSource(G) == NILL){
		fprintf(stderr,"getPath() Error: Graph Source is NILL\n");
		exit(1); 	
	}
	if(u<1 || u>getOrder(G)){
		fprintf(stderr,"getPath() Error: Graph index out of bounds\n");
		exit(1);
	}
	if( u == G->source){
		insertBack(L,G->source);
	}
	else if( G->parent[u] == NILL){
		insertBack(L,NILL);
	}
	else {
		getPath(L,G,G->parent[u]);
		insertBack(L,u);
	
	}
}
/* makeNull()
 * Pre: none
 * Pos: returns the G->adj to its orginial state
 */
void makeNull(GraphRef G){
	if(G == NULL){
		fprintf(stderr,"Graph Error: makeNull() called on NULL Graph\n");
		exit(1);
	}
	int i;
	for(i=1; i<=getOrder(G); i++){
		makeEmpty(G->adj[i]);
	}
}
/* addEdge()
 * Pre: v & u cannot be < 1 || v & u cannot be > order
 * Pos: adds a Edge to the Graph ADT
 */ 
void addEdge(GraphRef G, int u, int v){
	if(G == NULL){
		fprintf(stderr,"Graph Error: addEdge() called on NULL Graph\n");
		exit(1);
	}
	if(u<1 || u>getOrder(G)){
		fprintf(stderr,"addEdge() Error: Graph index out of bounds\n");
		exit(1);
	}
	if(v<1 || u>getOrder(G)){
		fprintf(stderr,"addEdge() Error: Graph index out of bounds\n");
		exit(1);
	}
	insertBack(G->adj[v],u);
	insertBack(G->adj[u],v);
	G->size++;
}
/* addArc()
 * Pre: v & u cannot be <1 || v & u cannot be > order
 * Pos: adds a one-way edge to the Graph ADT
 */ 
void addArc(GraphRef G, int u, int v){
	 if(G == NULL){
	 	fprintf(stderr,"Graph Error: addEdge() called on NULL Graph\n");
		exit(1);
	}
	if(u<1 || u>getOrder(G)){
		fprintf(stderr,"addArc() Error: Graph index out of bounds\n");
		exit(1);
	}
	if(v<1 || v>getOrder(G)){
		fprintf(stderr,"addArc() Error: Graph index out of bounds\n");
		exit(1);
	}
	insertBack(G->adj[u],v);
}
/* BFS()
 * Pre: none
 * Pos: finds the parent and distance of each Edge in the Graph ADT
 */ 
void BFS(GraphRef G, int s){
	if(G == NULL){
		fprintf(stderr,"Graph Error: BFS() called on NULL Graph\n");
		exit(1);
	}
	if( s<1 || s>getOrder(G)){
		fprintf(stderr,"BFS() error: source to of bounds");
	}
	ListRef Q;
	int u;
	for(u=1; u<= G->order; u++){
		G->color[u] = WHITE;
		G->distance[u] = INF;
		G->parent[u] = NILL;
	}
	G->color[s] = GRAY;
	G->distance[s] = 0;
	G->parent[s] = NILL;
	G->source = s;
	Q = newList();
	insertBack(Q,s);
	while(!isEmpty(Q)){
      		/*fprintf(stderr,"top of outer while loop\n");*/
		u = getFront(Q);
		/*fprintf(stderr,"behind getFront()\n");*/
		deleteFront(Q);
      		/*fprintf(stderr,"after deleteFront(Q)\n");*/
		int v=0;
		if(!isEmpty(G->adj[u])){
			moveTo(G->adj[u],0);
			/*fprintf(stderr,"in while && u,v is %d,%d\n",u,v);*/
			while(!offEnd(G->adj[u])){
				v = getCurrent(G->adj[u]);
				/*fprintf(stderr,"in the loop && u,v is %d,%d\n",u,v);*/
				if(G->color[v] == WHITE){
					G->color[v] = GRAY;
					G->distance[v] = G->distance[u]+1;
					G->parent[v] = u;
					insertBack(Q,v);
				}
				moveNext(G->adj[u]);
			}
			/*printList(stderr,Q);
			fprintf(stderr,"\nout while && u,v is %d,%d\n",u,v);
			fprintf(stderr,"\nQ front %d\n",getFront(Q));*/
			G->color[u] = BLACK;
      			/*fprintf(stderr,"after color[u]=BLACK;\n");*/
		}
	}
	freeList(&Q);
}
/* printGraph()
 * Pre: none
 * Pos: prints the Graph adj List
 */ 
void printGraph(FILE* out, GraphRef G){
	int i;
	for(i=1; i<= G->order; i++){
		fprintf(out,"%d:",i);
		printList(out,G->adj[i]);
		fprintf(out,"\n");
	}
}
