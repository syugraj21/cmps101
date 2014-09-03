/*Yugraj Singh
 *List.h
 *Header file for List ADT
 */

#if !defined(_LIST_H_INCLUDE_)
#define _LIST_H_INCLUDE_

#define UNDEF -1

/*ListRef
 *exports reference type to List struct
 */
typedef struct List* ListRef;

/*newList
 *allocated and initializes memory for the list
 */ 
ListRef newList(void);

/*freeList
 *pre: none
 *pos: frees all heap memory assocaited with *pL
 */ 
void freeList(ListRef* pL);

/*getLength
 *pre: none
 *pos: returns the size of the list
 */ 
int getLength(ListRef L);

/*isEmpty
 *pre: none
 *pos: returns boolean
 */ 
int isEmpty(ListRef L);

/*offEnd
 *pre: none
 *pos: returns boolean
 */ 
int offEnd(ListRef L);

/*getIndex
 *pre: none
 *pos: returns the position of current
 */ 
int getIndex(ListRef L);

/*getFront
 *pre: !isEmpty
 *pos: returns the front element
 */ 
int getFront(ListRef L);

/*getBack
 *pre: !isEmpty
 *pos: returns the back element
 */ 
int getBack(ListRef L);

/*getCurrent
 *pre: !isEmpty && !offEnd
 *pos: returns the current element
 */ 
int getCurrent(ListRef L);

/*equals
 *pre: none
 *pos: return true if list A = list B
 */ 
int equals(ListRef A, ListRef B);

/*makeEmpty
 *pre: none
 *pos: makes the list empty
 */ 
void makeEmpty(ListRef L);

/*moveTo
 *pre: none
 *pos: moves current to position i in the list
 */ 
void moveTo(ListRef L, int i);

/*movePrev
 *pre: !isEmpty && !offEnd
 *pos: moves the current to current->previous
 */ 
void movePrev(ListRef L);

/*moveNext
 *pre: !isEmpty && !offEnd
 *pos: moves the current to current->next
 */ 
void moveNext(ListRef L);

/*insertFront
 *pre: none
 *pos: insert new data value in front 
 */ 
void insertFront(ListRef L, int data);

/*insertBack
 *pre: none
 *pos: insert new data value after back
 */ 
void insertBack(ListRef L, int data);

/*insertBeforeCurrent
 *pre: !isEmpty && !offEnd
 *pos: inserts new data value before current; 
 */ 
void insertBeforeCurrent(ListRef L, int data);

/*insertAfterCurrent
 *pre: !isEmpty && !offEnd
 *pos: inserts new data value after current
 */ 
void insertAfterCurrent(ListRef L, int data);

/*deleteFront
 *pre: !isEmpty
 *pos: deletes the element in the front of the list
 */ 
void deleteFront(ListRef L);

/*deleteBack
 *pre: !isEmpty 
 *pos: deletes the element in the back of the list
 */ 
void deleteBack(ListRef L);

/*deleteCurrent
 *pre: !isEmpty && !offEnd
 *pos: deletes the current element in the list
 */ 
void deleteCurrent(ListRef L);

/*printList
 *pre: none
 *pos: prints the List to the output file
 */ 
void printList(FILE* in, ListRef L);

/*copyList
 *pre: none 
 *pos: copys the list L 
 */ 
ListRef copyList(ListRef L);

#endif
