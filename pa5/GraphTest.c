/* Yugraj Singh
 *
 *
 */ 

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "List.h"
#include "Graph.h"

int main(void){
	GraphRef G = newGraph(8);
	GraphRef Tran;
	GraphRef Copy;
	ListRef S = newList();
	printf("%d\n",getOrder(G));
	printf("%d\n",getSize(G));
	printf("****************\n");	
	addArc(G,1,2);
	addArc(G,2,3);
	addArc(G,2,5);
	addArc(G,2,6);
	addArc(G,3,4);
	addArc(G,3,7);
	addArc(G,4,3);
	addArc(G,4,8);
	addArc(G,5,1);
	addArc(G,5,6);
        addArc(G,6,7);
        addArc(G,7,6);
        addArc(G,7,8);
        addArc(G,8,8);
	
	printf("%d\n",getOrder(G));
	printf("%d\n",getSize(G));
	printGraph(stderr,G);
	printf("****************\n");
	
	Tran = transpose(G);
	printf("tranpose of G\n");
	printGraph(stderr,Tran);
	printf("****************\n");
	
	Copy = copyGraph(G);
	printf("copy of G\n");
	printGraph(stderr,Copy);
	printf("****************\n");
	
	int i;
	for( i =1;i<=getOrder(G);i++){
		insertBack(S,i);
	}
	printf("List S\n");
	printList(stderr,S);
	printf("\n****************\n");

	
	DFS(G,S);
	printf("after DFS\n");
	printf("List S\n");
	printList(stderr,S);
	printf("\n****************\n");

	i = getBack(S);
	printf("Back of List S: %d\n",i);
	i = getFront(S);
	printf("Front of List S: %d\n",i);

	moveTo(S,getLength(S)-1);
	i = getCurrent(S);
	printf("Current last elemet: %d\n",i);

	printf("********************\n");
	printf("DFS with Tranpose(G)\n");
	DFS(Tran,S);
	printf("after DFS\n");
	printf("List S\n");
	printList(stderr,S);
	printf("\n******************\n");
	
	return 0;
}
