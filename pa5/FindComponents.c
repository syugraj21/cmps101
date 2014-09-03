/* Yugraj Singh
 * FindComponents
 *
 * This Program reads directed Graph input from the command line,
 * and finds the strongly connected components of the directed Graph	
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "List.h"
#include "Graph.h"
#define MAX_LEN 300
#define true 0
#define false 1

/* getComponent()
 * Pre:none
 * Pos:seperates and connectes the strongly connected
 *     componenets from S
 */ 
void getComponent(GraphRef T, ListRef L, ListRef S){
	while(getParent(T,getBack(S)) != NIL){
		insertFront(L,getBack(S));
		deleteBack(S);
	}
	if(getParent(T,getBack(S)) == NIL){
		insertFront(L,getBack(S));
		deleteBack(S);
	}
}

int main(int argc, char* argv[]){
	FILE* in;
	FILE* out;
	char* token;
	char line[MAX_LEN];
	char* nullChar = "0 0\n";
	GraphRef G;
	GraphRef T;
	ListRef S = newList(); 
	ListRef* connectComp;
	int components = 0;
	int graphSize; 
	/*checking command line args*/
	if(argc != 3){
		fprintf(stderr,"Usage: FindComponents infile outfile\n");
		exit(1);
	}
	/*opening files for reading and writing*/
	in = fopen(argv[1],"r");
	out = fopen(argv[2],"w");
	if(in == NULL){
		fprintf(stderr,"Error: couldn't open infile %s\n",argv[1]);
		exit(1);
	}
	if(out == NULL){
		fprintf(stderr,"Error: couldn't open outfile %s\n",argv[2]);
	}
	/*reads first line of input from infile to get Graph size*/
	if(fgets(line,MAX_LEN,in) == NULL){
		fprintf(stderr,"Error: file input error");
		exit(1);
	} else {
		token = strtok(line," \n");
		graphSize = atoi(token);
		G = newGraph(graphSize);
		token = strtok(NULL,"\n");
	}
	/*reading the directed edges from the input file
 	  and assigning the values to u & v */ 
	int u; 
	int v;
	fgets(line,MAX_LEN,in);
	while(strcmp(line,nullChar) != true){
		token = strtok(line," \n");
		u = atoi(token);
		token = strtok(NULL," \n");
		v = atoi(token);
		token = strtok(NULL," \n");
		addArc(G,u,v);
		fgets(line,MAX_LEN,in);
	}
	/*creating the list S for DFS*/
	int i;
	for(i=1; i<=graphSize;i++){
		insertBack(S,i);
	}

	
	fprintf(out,"Adjacency list representation of G:\n");
 	printGraph(out,G);	
	DFS(G,S); 
	T = transpose(G);
	DFS(T,S);
	
	 /*getting the number of strongly connected components*/
	for(i=1;i<=graphSize;i++){
		if( getParent(T,i) == NIL){
			components++;
		}
	}
	/*ListRef to store the strongly connected components*/
	connectComp = calloc(components+1,sizeof(ListRef));
	for(i=1; i<=components; i++){
		connectComp[i] = newList();
	}

	fprintf(out,"\nG contains %d strongly connected components:\n",components);
	/*stores the strongly connected components to the ListRef Array*/
	for(i =1; i<=components; i++){
		getComponent(T,connectComp[i],S);
	}

	for(i=1; i<=components; i++){
		fprintf(out,"Component %d:",i);
		printList(out,connectComp[i]);
		fprintf(out,"\n");
	}
	
	for(i=0; i<=components; i++){
		freeList(&connectComp[i]);
	}
	free(connectComp);	
	freeList(&S);
	freeGraph(&G);
	freeGraph(&T);
	fclose(in);
	fclose(out);
	return(0);
}



