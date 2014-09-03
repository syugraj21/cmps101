/*Yugraj Singh
 *Pa2 
 *List ADT in C
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "List.h"
/**************** Private Functions *********************/
/* creating Node struct */ 
typedef struct Node{
	int data;
	struct Node* next;
	struct Node* previous;
} Node;

typedef Node* NodeRef;
/*newNode()
 *Constructor for the Node Struct, and
 *allocates memory
 */
NodeRef newNode(int data){
	NodeRef N = malloc(sizeof(Node));
	assert( N != NULL);
	N->data = data;
	N->next = NULL;
	N->previous = NULL;
	return N;
}
/*freeNode
 *Frees the Heap memory from the Node
 */
void freeNode(NodeRef* pN){
	if( pN != NULL && *pN != NULL){
		free(*pN);
		*pN = NULL;
	}
}
/****************** Public Functions **********************/
/*Struct for List ADT
 *
 */
typedef struct List{
	NodeRef front;
	NodeRef back;
	NodeRef current;
	int length;
	int curr;
} List;


/*newList
 *Constructor for the List ADT, and 
 *allocates Heap memory
 */
ListRef newList(void){
	ListRef L = malloc(sizeof(List));
	assert(L!=NULL);
	L->front = NULL;
	L->back = NULL;
	L->current = NULL;
	L->length = 0;
	L->curr = -1;
	return L;
}
/*freeList
 *Frees the Heap memory allocated for the list ADT
 */
void freeList(ListRef* pL){
	if(pL != NULL && *pL != NULL){
	while( !isEmpty(*pL)){
		deleteFront(*pL);
	}
		free(*pL);
		*pL = NULL;
	}
}
/*getLength
 *Pre: none
 *Pos: returns the length of the list
 */ 
int getLength(ListRef L){
	if(L == NULL){
		fprintf(stderr,"List Error: calling getLength() on NULL ListRef\n");
		exit(EXIT_FAILURE);
	}
	return (L->length);
}
/*isEmpty
 *Pre: none
 *Pos: checks if the list is empty or not
 */
int isEmpty(ListRef L){
	if( L == NULL){
		fprintf(stderr,"List Error: calling isEmpty() on NULL ListRef\n");
		exit(EXIT_FAILURE);
	}
	return (L->length == 0);
}
/*offEnd
 *Pre: none
 *Pos: checks if the current element is off the list
 */ 
int offEnd(ListRef L){
	if (L == NULL){
		fprintf(stderr,"List Error: calling offEnd() on NULL ListRef\n");
		exit(EXIT_FAILURE);
	}
	return (L->current == NULL);
}
/*getIndex
 *Pre: none
 *Pos: returns the position of the current element 
 */
int getIndex(ListRef L){
	if( L == NULL){
		fprintf(stderr,"List Error: calling getIndex on NULL ListRef\n");
		exit(EXIT_FAILURE);
	}
	return (L->curr);
	
}
/*getFront
 *Pre: list cannot be empty
 *Pos: returns the data value in the front element
 */
int getFront(ListRef L){
	if ( L == NULL){
		fprintf(stderr,"List Error: calling getFront on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if ( isEmpty(L)){
		fprintf(stderr,"getFront() called on empty List");
		exit(EXIT_FAILURE);
	}
	return L->front->data;
} 
/*getBack
 *Pre: list cannot be empty
 *Pos: returns the data value in the back element
 */
int getBack(ListRef L){
	if(L == NULL){
		fprintf(stderr,"List Error: calling getBack on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if(isEmpty(L) ){
                fprintf(stderr,"getBack() called on empty List");
		exit(EXIT_FAILURE);
        }
        return L->back->data;
}
/*getCurrent
 *Pre: list cannot be empty && current element can't be off the list
 *Pos: returns the data value in the current element
 */ 
int getCurrent(ListRef L){
	if( L == NULL){
		fprintf(stderr,"List Error: calling getCurrent on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if( offEnd(L) || isEmpty(L) ){
		fprintf(stderr,"getCurrent() called on empty List");
		exit(EXIT_FAILURE);
	}
	return L->current->data;
}
/*equals
 *Pre: none
 *Pos: compares the two list to see if there equal
 */ 
int equals(ListRef A, ListRef B){
	int boolVal = 1;
	NodeRef M = A->front;
	NodeRef N = B->front;
	if( A == NULL && B == NULL){
		fprintf(stderr,"List Error: calling equals() on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if( A->length == B->length){
		while( boolVal && N != NULL){
			boolVal = (N->data == M->data);
			N = N->next;
			M = M->next;
		}
		return boolVal;
	}
	else{
		return 0;
	}
}
/*makeEmpty
 *Pre: none
 *Pos: emptys the list of all data values
 */ 
void makeEmpty(ListRef L){
	if( L == NULL){
		fprintf(stderr,"List Error: calling makeEmpty() on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	while( !isEmpty(L)){
		deleteFront(L);
	}
}
/*moveTo
 *Pre: i >=0 && 1<=length-1
 *Pos: moves the current element to index i
 */ 
void moveTo(ListRef L, int i){
	int j;
	if(L== NULL){
		fprintf(stderr,"List Error: calling moveTo() on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	NodeRef N = L->front;
	if ( i >= 0 && i <= getLength(L)-1){
		if ( i == 0){
			L->current = L->front;
		}
		else{
			for(j=0; j<i;j++){
				N = N->next;
			}
			L->current = N;
		}
		L->curr = i;
	}
	else{
		L->current = NULL;
		L->curr = -1;
	}
}
/*movePrev
 *Pre: !isEmpty && !offEnd
 *Pos: moves the current element to the previous element in the list
 */
void movePrev(ListRef L){
	if (L == NULL){
		fprintf(stderr,"List Error: calling movPrev() on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if ( offEnd(L) || isEmpty(L) ){
		fprintf(stderr,"movePre() called on offEnd current");
		exit(EXIT_FAILURE); 
	}
	L->current = L->current->previous;
	L->curr--;
}
/*moveNext
 *Pre: !isEmpty && !offEnd
 *Pos: moves the curret element to the next element in the list
 */
void moveNext(ListRef L){
	if(L==NULL){
		fprintf(stderr,"List Error: calling moveNext() on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if( offEnd(L)  || isEmpty(L) ){
		fprintf(stderr,"moveNext() called on offEnd current");
		exit(EXIT_FAILURE);
	}
	L->current = L->current->next;
	L->curr++;
}
/*insertFront
 *Pre: none
 *Pos: inserts a data value in the front of the list
 */
void insertFront(ListRef L, int data){
	NodeRef N = L->front;
	if( L == NULL){
		fprintf(stderr,"List Error: calling insertFront() on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if( L->front == NULL){
		L->front = newNode(data);
		L->back = L->front;
		L->current = L->front;
		L->curr = 0;
	}
	else{
		N->previous = newNode(data);
		L->front = N->previous;
		L->front->next = N;
		L->curr++;
	}
	L->length++;
}
/*insertBack
 *Pre: none
 *Pos: inserts a data value in the back of the list
 */
void insertBack(ListRef L, int data){
	NodeRef N = L->back;
	if(L == NULL){
		fprintf(stderr,"List Error: calling insertBack() on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if( L->back == NULL){
		L->back = newNode(data);
		L->front = L->back;
		L->current = L->back;
		L->curr = 0;
	}
	else{
		N->next = newNode(data);
		L->back = N->next;
		L->back->previous = N;
		L->curr++;
	}
	L->length++;
}
/*insertBeforeCurrent
 *Pre: !isEmpty && !offEnd
 *Pos: inserts a data value before the current element
 */
void insertBeforeCurrent(ListRef L, int data){
	NodeRef C = L->current;
	NodeRef M;
	NodeRef P;
	if(L == NULL){
		fprintf(stderr,"List Error: calling insertBeforeCurrent() on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if( offEnd(L) || isEmpty(L)){
		fprintf(stderr,"calling insertBeforeCurrent() on empty list");
		exit(EXIT_FAILURE);
	}
	if( getIndex(L) == 0){
		C->previous = newNode(data);
		L->front = C->previous;
		L->front->next = C;
	}
	else{
		P = newNode(data);
		M = C->previous;
		C->previous = P;
		M->next = P;
		P->next = C;
		P->previous = M;		
	}
	L->curr++;
	L->length++;
}
/*insertAfterCurrent
 *Pre: !isEmpty && !offEnd
 *Pos: inserts a data value after the current element
 */
void insertAfterCurrent(ListRef L, int data){
	NodeRef C = L->current;
	NodeRef M;
	NodeRef P;
	if(L == NULL){
		fprintf(stderr,"List Error: calling insertAfterCurrent() on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if( offEnd(L) || isEmpty(L)){
		fprintf(stderr,"calling insertAfterCurrent() on empty list");
		exit(EXIT_FAILURE);
	}
	if ( getLength(L) == 1){
		C->next = newNode(data);
		L->back = C->next;
		L->back->previous = C;
	}
	else if( getIndex(L) == getLength(L)-1){
		C->next = newNode(data);
		L->back = C->next;
		L->back->previous = C;
	}
	else{
		P = newNode(data);
		M = C->next;
		C->next = P;
		M->previous = P;
		P->previous = C;
		P->next = M;
	}
	L->length++;
}
/*deletFront
 *Pre: !isEmpty
 *Pos: deletes the data value from the front element of the list
 */
void deleteFront(ListRef L){
	NodeRef N = L->front;
	NodeRef C = L->current;
	if( L == NULL){
		fprintf(stderr,"List Error: calling deleteFront() on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	if ( isEmpty(L)){
		fprintf(stderr,"calling deleteFront() on empty List");
		exit(EXIT_FAILURE);
	}
	if(getLength(L) == 1){
		L->front = NULL;
		L->back = NULL;
		L->current = NULL;
		freeNode(&N);
		L->curr = -1;
	}
	else if(getIndex(L) == 0){
		L->front = L->front->next;
		L->current = NULL;
		freeNode(&C);
		L->curr = -1;
	}
	else {
		L->front = N->next;
		freeNode(&N);
		L->curr--;
	}
	L->length--;
}
/*deleteBack
 *Pre: !isEmpty
 *Pos: delete the data value from the back element of the list 
 */
void deleteBack(ListRef L){
	NodeRef N = L->back;
	NodeRef C = L->current;
	if( L == NULL){
                fprintf(stderr,"List Error: calling deleteBack() on NULL ListRef");
		exit(EXIT_FAILURE);
        }
        if ( isEmpty(L) == 1){
                fprintf(stderr,"calling deleteBack() on empty List");
		exit(EXIT_FAILURE);
        }
	if(getLength(L) == 1){
		L->back = NULL;
		L->front = NULL;
		L->current = NULL;
		freeNode(&N);
		L->curr = -1;
	}
	else if(getIndex(L) == (getLength(L)-1)){
		L->back = L->back->previous;
		L->current = NULL;
		freeNode(&C);
		L->curr = -1;
	}
	else{
       		L->back = N->previous;
       		freeNode(&N);
	}
    	L->length--;
}
/*deleteCurrent
 *Pre: !isEmpty && !offEnd
 *Pos: deletes the data value from the current element and current falls of the list
 */
void deleteCurrent(ListRef L){
	NodeRef N;
	NodeRef M;
	NodeRef P;
	if( L == NULL){
                fprintf(stderr,"List Error: calling deleteFront() on NULL ListRef");
		exit(EXIT_FAILURE);
        }
        if ( offEnd(L) || isEmpty(L) ){
                fprintf(stderr,"calling deleteFront() on empty List");
		exit(EXIT_FAILURE);
	}
	if(getLength(L) == 1){
		P = L->current;
		L->current = NULL;
		L->front = NULL;
		L->back = NULL;
		freeNode(&P);
	}
	else if (getIndex(L) == 0){
		N = L->front;
		L->front = L->front->next;
		L->current = NULL;
		freeNode(&N);
	}
	else if(getIndex(L) == getLength(L)-1){
		N = L->back;
		L->back = L->back->previous;
		L->current = NULL;
		freeNode(&N);
	}
	else{
		P = L->current;
		N = L->current->previous;
		M = L->current->next;
		N->next = M;
		M->previous = N;
		freeNode(&P);
		L->current = NULL;
	}
	L->curr = -1;
	L->length--;
}
/*printList
 *Pre: none
 *Pos: prints the list to the output file
 */
void printList(FILE* in,ListRef L){
	if (L == NULL){
		fprintf(stderr,"List Error: calling printList on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	NodeRef N = L->front;
	/*fprintf(in,"(");*/
	while( N!=NULL){
		fprintf(in," %d",N->data);
		N = N->next;
	}
	/*fprintf(in," )");*/
}
/*copyList
 *Pre: none
 *Pos: copys the list to another list
 */ 
ListRef copyList(ListRef L){
	if(L == NULL){
		fprintf(stderr,"List Error: calling copyList on NULL ListRef");
		exit(EXIT_FAILURE);
	}
	NodeRef N = L->back;
	ListRef T = newList();
	while ( N != NULL){
		insertFront(T,N->data);
		N = N->previous;
	}
	return T;
}
