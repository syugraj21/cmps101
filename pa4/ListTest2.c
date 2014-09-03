#include<stdlib.h>
#include<stdio.h>
#include "List.h"

int main(void){
	ListRef L = newList();

	insertFront(L,1);
	printf("%d\n",getFront(L));
	printf("%d\n",getBack(L));
	printf("%d\n",getCurrent(L));
	printf("%d\n",getIndex(L));
	printList(stdout,L);
	printf("\n");	
	deleteBack(L);
	/*deleteFront(L);*/
	printList(stdout,L);
	printf("\n");
	freeList(&L);
	return(0);
}
