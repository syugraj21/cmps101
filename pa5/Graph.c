/* Yugraj Singh
 * Graph.c 
 * This program creates a Graph ADT
 */
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "List.h"
#include "Graph.h"

/* Visit()
 * Pre: DFS()
 * Pos: Discovers the connected components of G
 */ 
void Visit(GraphRef G, ListRef S, int u);

/* tranposeHelp
 * Pre:none;
 * Pos:transposes the L to T->adj
 */ 
void transposeHelp(GraphRef T, ListRef L, int i);
/*create Graph Struct*/
typedef struct Graph{
	int order;
	int size;
	int time;
	int* color;
	int* discover;
	int* finish;
	int* parent;
	ListRef* adj;
}Graph;

/*constructor*/
GraphRef newGraph(int n){
	int i;
	GraphRef G = malloc(sizeof(Graph));
	assert(G!=NULL); 
	G->order = n;
	G->size = 0;
	G->time = 0;
	G->color = calloc(n+1,sizeof(int));
	G->discover = calloc(n+1,sizeof(int));
	G->finish = calloc(n+1,sizeof(int));
	G->parent = calloc(n+1,sizeof(int));
	G->adj = calloc(n+1,sizeof(ListRef));
	for(i=1; i<=n; i++){
		G->color[i] = WHITE;
		G->discover[i] = UNDF;
		G->finish[i] = UNDEF;
		G->parent[i] = NIL;
		G->adj[i] = newList();
	}
	return G;
}

/*deconstructor*/
void freeGraph(GraphRef* pG){
	int i;
	if(pG != NULL && *pG != NULL){
		free((*pG)->color);
		free((*pG)->discover);
		free((*pG)->finish);
		free((*pG)->parent);
		for(i=1; i<=(*pG)->order; i++){
			freeList(&(*pG)->adj[i]);
		}
		free((*pG)->adj);
		free(*pG);
		*pG = NULL;
	}
}

/* getOrder()
 * Pre:none
 * Pos:returns the value number of vertices in G
 */ 	
int getOrder(GraphRef G){
	if(G == NULL){
		fprintf(stderr,"Graph Error: calling getOrder on NULL Graph");
		exit(1);
	}
	return G->order;
}

/* getSize()
 * Pre:none
 * Pos: returns the number of edges in the Graph 
 */
int getSize(GraphRef G){
	if(G == NULL){
		fprintf(stderr,"Graph Error: calling getSize on NULL Graph");
		exit(1);
	}
	return G->size;
}
/* getParent
 * Pre: u>0 && u<=getOrder(G)
 * Pos: returns the parent to the vertex
 */ 
int getParent(GraphRef G, int u){
	if(G == NULL){
		fprintf(stderr,"Graph Error: calling getParent on NULL Graph");
		exit(1);
	}
	if(u<1 || u>getOrder(G)){
		fprintf(stderr,"getParent Error: index out of range of parent");
		exit(1);
	}
	return G->parent[u]; 
}

/* getDiscover()
 * Pre: u>0 && u<=getOrder(G)
 * Pos: returns the discover time of the vertex
 */ 
int getDiscover(GraphRef G, int u){
	if(G == NULL){
		fprintf(stderr,"Graph Error: calling getDiscover on NULL Graph");
		exit(1);
	}
	if(u<1 || u>getOrder(G)){
		fprintf(stderr,"getDiscover Error: index out of range of discover");
		exit(1); 
	}
	return G->discover[u];	
}

/* getFinish()
 * Pre: u>0 && u<=getOrder(G)
 * Pos: gets the finish time of the Vertex
 */ 
int getFinish(GraphRef G, int u){
	if(G == NULL){
		fprintf(stderr,"Graph Error: calling getFinish on NULL Graph");
		exit(1);
	}
	if(u<1 || u>getOrder(G)){
		fprintf(stderr,"getFinish Error: index out of range of finish");
		exit(1);
	}
	return G->finish[u];
}

/* addArc()
 * Pre: (u&v)>0 && (u&v)<=getOrder()
 */ 
void addArc(GraphRef G, int u, int v){
	if(G == NULL){
		fprintf(stderr,"Graph Error: calling addArc on NULL Graph");
		exit(1);
	}
	if(u<1 || u>getOrder(G)){
		fprintf(stderr,"addArc Error: addArc(P1,P2,P3) P2 index out of range");
		exit(1);
	}
	if(v<1 || v>getOrder(G)){
		fprintf(stderr,"addArc Error: addArc(P1,P2,P3) P3 index out of range");
		exit(1);
	}
	insertBack(G->adj[u],v);
	G->size++;
}

/* DFS()
 * Pre: List S length == Number of vetices in G
 * Pos: finds the strongly connected components
 */ 
void DFS(GraphRef G, ListRef S){
	if(G == NULL){
		fprintf(stderr,"Graph Error: calling DFS on NULL Graph");
		exit(1);
	}
	if(getLength(S) != getOrder(G)){
		fprintf(stderr,"DFS Error: ListRef size != Graph size");
		exit(1);
	}
	int i;
	int u;
	int j;
	
	for(i=1; i<=getOrder(G);i++){
		G->color[i] = WHITE;
		G->parent[i] = NIL;
	}
	j =1;
	moveTo(S,getLength(S)-1);
	while(!offEnd(S) && j<=getOrder(G)){
		u = getFront(S);

		if(G->color[u] == WHITE){
			Visit(G,S,u);
		}
		deleteFront(S);
		j++;
	} 
}
/*above*/
void Visit(GraphRef G, ListRef S, int u){
	int v;	
	G->color[u] = GREY;
	G->time++;
	G->discover[u] = G->time; 
	moveTo(G->adj[u],0);
	while(!offEnd(G->adj[u])){
		v = getCurrent(G->adj[u]);
		if(G->color[v] == WHITE){
			G->parent[v] = u;
			Visit(G,S,v);
		}
		moveNext(G->adj[u]);
	}
	G->color[u] = BLACK;
	G->time++;
	G->finish[u] = G->time;
	insertAfterCurrent(S,u);		
}
/* transpose()
 * Pos: none
 * Pre: transfers the tranpose of G  to Graph T
 */
GraphRef transpose(GraphRef G){
	int i;
	GraphRef T = newGraph(getOrder(G));
	for(i=1; i<=getOrder(G); i++){
		if(!isEmpty(G->adj[i])){
			transposeHelp(T,G->adj[i],i);
		}
	}
	return T;
} 
/* above
 */
void transposeHelp(GraphRef T, ListRef L, int i){
	int v;
	moveTo(L,0);
	while(!offEnd(L)){
		v = getCurrent(L);
		insertBack(T->adj[v],i);
		moveNext(L);
	}
}
/* copyGraph()
 * Pre: none
 * Pos: calls ListCopy to copy the adj list to a new graph
 */
GraphRef copyGraph(GraphRef G){
	int i;
	GraphRef C = newGraph(getOrder(G));
	for(i=1; i <= getOrder(G); i++){
		if(!isEmpty(G->adj[i])){
			C->adj[i] = copyList(G->adj[i]);
		}
	}
	return C;
}
/* printGraph
 * Pre: none
 * Pos: prints the adj repsentation of the Graph G
 */ 
void printGraph(FILE* out, GraphRef G){
	int i;
	for(i=1; i<=getOrder(G); i++){
		fprintf(out,"%d:", i);
		printList(out,G->adj[i]);
		fprintf(out,"\n");
	}		
}
 
