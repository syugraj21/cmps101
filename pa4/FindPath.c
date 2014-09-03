/* Yugraj Singh
 * FindPath
 * This Program reads input from a file and puts the input into the adj listRef
 * inorder to find the shortest path between a target and source
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
#define INF -2
int main(int argc, char* argv[]){
	FILE* in;
	FILE* out;
	char* token;
	char line[MAX_LEN];
	char* nullChar = "0 0\n";
	GraphRef G;
	ListRef L = newList();
	int graphSize;
	int u;
	int v;
  
	/*checking command line args*/
	if(argc != 3){
		fprintf(stderr,"Usage: FindPath inFile outFile\n");
		exit(1);
	}
	/*opening the file for reading and writing*/
	in = fopen(argv[1],"r");
	out = fopen(argv[2],"w");
	if(in == NULL){
		fprintf(stderr,"Error: couldn't open in file  %s\n",argv[1]);
		exit(1);
	}
	if(out == NULL){
		fprintf(stderr,"Error: couldn't open out file  %s\n",argv[2]);
		exit(1);
	}

	/*reads the firs line of input to get graph size*/
	if(fgets(line,MAX_LEN,in) == NULL){
		fprintf(stderr,"Error: file input error");
		exit(1);
	}
	else{
		token = strtok(line," \n");
		graphSize = atoi(token);
		G = newGraph(graphSize);
		token = strtok(NULL,"\n");	
	}

	/* reading the vertices from the input file
	 */
	fgets(line,MAX_LEN,in);
	while(strcmp(line,nullChar) != true){
		token = strtok(line," \n");
		u = atoi(token);
		token = strtok(NULL," \n");
		v = atoi(token);
		token = strtok(NULL," \n");
		addEdge(G,u,v);
		fgets(line,MAX_LEN, in);
	}
	printGraph(out,G);
	
	fgets(line,MAX_LEN,in);
	while(strcmp(line,nullChar) != true){
		token = strtok(line," \n");
		u = atoi(token);
		token = strtok(NULL," \n");
		v = atoi(token);
		token = strtok(NULL," \n");
	
		BFS(G,u);
		getPath(L,G,v);
	 	/*prints the shorest path*/
		fprintf(out,"\n");
		if(getFront(L) == INF){
			fprintf(out,"The distance from %d to %d is infinity\n",u,v);
			fprintf(out,"No %d-%d path exist\n",u,v);
		}
		else{
			fprintf(out,"The distance from %d to %d is %d\n",u,v,getDist(G,v));
			fprintf(out,"A shortest %d-%d path is: ",u,v);
			printList(out,L);
			fprintf(out,"\n");
		}
		makeEmpty(L);
		fgets(line,MAX_LEN,in);
	}

	freeList(&L);
	freeGraph(&G);
	
	fclose(in);
	fclose(out);
	
	return(0);
			
}
