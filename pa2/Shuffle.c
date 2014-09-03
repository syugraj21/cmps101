/*Yugraj Singh
 *Shuffle.c
 *Main program that performs the permutations
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"

#define MAX_LEN 300
/*shuffle
 *Pre: takes to ListRef
 *Pos: shuffles the list L by the permutations listed in List P
 */ 
void shuffle(ListRef L, ListRef P){
	int index = 2;
	int holdIndex;
	moveTo(P,0);
	while( offEnd(P) != 1){
		holdIndex = getLength(L) + getCurrent(P)-index;
		moveTo(L,holdIndex);
		insertAfterCurrent(L,getFront(L));
		deleteFront(L);
		index++;
		moveNext(P);
	}
}


int main(int argc, char* argv[]){
	FILE* in;
	FILE* out;
	char line[MAX_LEN];
	char* token;
	int order, size;
	
	
	if (argc !=3){
		printf("Usage: %s infile outfile\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	/*opens the input and output files*/
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
        /* check to make sure the input and output files are functioning*/
	if ( in == NULL){
		printf("Unable to open file %s for reading\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	if ( out == NULL){
		printf("Unable to open file %s for writing\n",argv[2]);
		exit(EXIT_FAILURE);
	}
	
	/*reads the first line in file and assigns the value to size*/ 
	if( fgets(line,MAX_LEN,in) != NULL){
		token = strtok(line," \n");
		while(token!= NULL){
			size = atoi(token);
			token = strtok(NULL, " \n");
		}
	}
	
	/* main loop*/
	int i;
	for( i=0; i< size; i++){
		fgets(line,MAX_LEN,in);
		token = strtok(line," \n");

		ListRef P = newList();
		ListRef L = newList();
		
		/*inserts the data values from input file*/
		while(token!=NULL){
			insertBack(P,atoi(token));
			token = strtok(NULL," \n");
		}

		/* creates a List to perform the permutations on*/
		int j = 0;
		while( j<getLength(P)){
			insertBack(L,j+1);
		j++;
		}
		
		/*copys the list*/
		ListRef listCopy = copyList(L);
		shuffle(L,P);
		printList(out,L);
		order = 1;
		
		/*counts the number of permutations being performed*/
		while( !equals(listCopy,L)){
			shuffle(L,P);
			order++;
		}
	
		/*print the order, and frees the Heap memory from the list*/
		fprintf(out," order = %d\n", order);
		freeList(&listCopy);
		freeList(&L);
		freeList(&P);		
	}
	
	
	
       /* closes the input and output files*/
	fclose(in);
	fclose(out);
	
	return(0);
}
