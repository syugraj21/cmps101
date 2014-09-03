#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"List.h"
#include"Graph.h"

int main(void){
	GraphRef G = newGraph(7);
	ListRef L = newList();

	printf("%d\n",getOrder(G));
	printf("%d\n",getSource(G));
	printf("%d\n",getParent(G,1));
	printf("%d\n",getDist(G,1));
	
	addEdge(G,1,4);
	addEdge(G,1,5);
	addEdge(G,4,5);
	addEdge(G,2,3);
	addEdge(G,2,6);
	addEdge(G,3,7);
	addEdge(G,6,7);
 	
	printGraph(stdout,G);	
	
	BFS(G,2);
	printf("after BFS\n");	
	getPath(L,G,7);
	printf("after getPath\n");	
	printList(stdout,L);
	printf("\n");
	return(0);
}
