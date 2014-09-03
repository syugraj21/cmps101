
#include<stdlib.h>
#include<stdio.h>
#include"List.h"

int main(void){
	int x, y, c, j;
	ListRef L = newList();
	
	printf("befor printf\n");
	x = getLength(L);
	y = isEmpty(L);
	c = offEnd(L);
	j = getIndex(L);
	printf("%d\n",x);
	printf("%d\n",y);
	printf("%d\n",c);
	printf("%d\n",j);
	
	insertFront(L,1);
	insertFront(L,2);
 	
	printf("first List print\n");	
	printList(stdout,L);
	
	insertBack(L,10);
	insertBack(L,9);
	printf("second List print\n");
	printList(stdout,L);

	x=getFront(L);
	y=getBack(L);
	c=getCurrent(L);
        j= getIndex(L);
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", c);
	printf("%d\n", j);
 	      
 	printf("move first\n");
       	movePrev(L);
	x = getCurrent(L);
	y = getIndex(L);
	printf("%d\n", x);
	printf("%d\n", y);
	printf("move next\n");
	moveNext(L);
	printf("%d\n",getCurrent(L));
	printf("%d\n",getIndex(L));
	
	printf("before current\n");
	insertBeforeCurrent(L,100);
	insertBeforeCurrent(L,99);
	printf("%d\n",getCurrent(L));
	printf("%d\n",getIndex(L));
 	printList(stdout,L);
        
	printf("\nafter current\n");
	insertAfterCurrent(L,1000);
	insertAfterCurrent(L,999);
	printf("%d\n",getCurrent(L));
	printf("%d\n",getIndex(L));
	printList(stdout,L);

	printf("\nmoveTo\n");
	moveTo(L,6);
	printList(stdout,L);
	printf("\n%d\n", getCurrent(L));
	printf("%d\n", getIndex(L));
	
	moveTo(L,0);
	printf("%d\n",getCurrent(L));
	printf("%d\n",getIndex(L));
	
	ListRef copy = copyList(L);
	printList(stdout,copy);
	freeList(&L);	
	return(0);
}
