/*Yugraj Singh
 * 
 *List ADT 
 * 
 */ 
class List{
  
  private class Node{
    Object data;
    Node next;
    Node previous;
    
    Node(Object data){
      this.data = data;
      next = null;
      previous = null;
    }
  }
  
  private Node front;
  private Node back;
  private Node current;
  private int curr;
  private int length;
  
  List(){
    front = null;
    back = null;
    length = 0;
    curr = -1;
  } 
  /* getLength()
   * returns the size of the ADT
   */
  int getLength(){
    return length;
  }
  /* isEmpty()
   * returns a boolean if the list is empty
   */ 
  boolean isEmpty(){
    return (length == 0);
  }
  
  /* offEnd()
   * returns a boolean if current is null
   */
  boolean offEnd(){
    return (current == null);
  }
  
  /* getIndex()
   * returns the index of current in the list or -1
   */ 
  int getIndex(){
    return curr;
  }
  
  /* getFront()
   * Pre: list is not empty
   * Pos: returns value in the front of the list
   */ 
  Object getFront(){
    Node N = front;
    if( this.isEmpty()){
      throw new RuntimeException("List Error: getFront() called on empty List");
    }
    else{
      return N.data;
    }
  }
  
   /* getBack()
   * Pre: list is not empty
   * Pos: returns value in the back of the list
   */ 
  Object getBack(){
    Node B = back;
    if( this.isEmpty()){
      throw new RuntimeException("List Error: getBack() called on empty List"); 
    }
    else{
      return B.data;
    } 
  }
  
   /* getCurrent()
   * Pre: list is not empty and current isnt off the list
   * Pos: returns value in the current position of the list
   */ 
  Object getCurrent(){
    Node C = current;
    if( this.offEnd() || this.isEmpty() ){
      throw new RuntimeException("List Error: getCurrent() called on empty List");
    }
    else{
      return C.data;
    }
  }
  
  /* equals()
   * compares two list to see if there equal
   */ 
  public boolean equals(Object x){
    if( x == null){
	return false;
    }else if(getClass() != x.getClass()){
	return false;
    }else{
    List temp = (List) x;
    boolean boolVal= true;
    Node N = this.front;
    Node M = temp.front;
    if ( this.length == temp.length){
      while ( boolVal && N != null){
        boolVal = (N.data == M.data);
        N = N.next;
        M = M.next;
      }
      return boolVal; 
    }
    else{
      return false;
    }
  }
  }
  /* makeEmpty()
   * makes the list empty
   */ 
  void makeEmpty(){
    front = null;
    back = null;
    current = null;
    length = 0;
    curr = -1;
  }
  
  /* moveTo()
   * moves the current position to the index indicated 
   * by i
   */ 
  void moveTo(int i){
    Node N = front;
    if ( i >= 0 && i <= this.getLength()-1){
      if( i == 0){
        current = front;
      }
      else{
        for(int j = 0; j < i; j++){
          N = N.next;
        }
        current = N;
      }
      curr = i;
    }
    else{
      current = null;
      curr = -1;
    }
  }
  
  /* movePre()
   * Pre: !offEnd() & !isEmpty()
   * Pos: moves the current position to the left       
   */ 
  void movePrev(){
    Node N;
    if( this.offEnd() || this.isEmpty()){
      throw new RuntimeException("List Error: movePre() called on empty or offend list");
    }
    else{
      N = current;
      current = N.previous;
      curr--;
    }
  }
  
  /* moveNext()
   * Pre: !offEnd() & !isEmpty()
   * Pos: moves the current position to the right
   */ 
  void moveNext(){
    Node N;
    if ( this.offEnd() || this.isEmpty()){
      throw new RuntimeException("List Error: moveNext() called on empty or offend list");
    }
    else{
      N = current;
      current = N.next;
      curr++;
    }
  }
  
  /* insertFront()
   * Pre: 
   * Pos: inserts a value into the front of the list
   */ 
  void insertFront(Object data){
    Node N;
    if ( front == null){
      front = new Node(data);
      back = front;
      current = front;
      curr = 0;
    }
    else{
      N = front;
      N.previous = new Node(data);
      front = N.previous;
      front.next = N;
      curr++;
    }
    length++;
    
  }
  
  /* insertBack()
   * Pre: 
   * Pos: inserts a value into the back of the list
   */ 
  void insertBack(Object data){
    Node N;
    if( back == null){
      back = new Node(data);
      front = back;
      current = back;
      curr = 0;
    }
    else{
      N = back;
      N.next = new Node(data);
      back = N.next;
      back.previous = N;
    } 
    length++;
  }
  /* insertBeforeCurrent()
   * Pre: !offEnd() & !isEmpty()
   * Pos: inserts a value to the left of the current position
   */ 
  void insertBeforeCurrent(Object data){
    Node N = current;
    Node M, P;
    if ( this.offEnd() || this.isEmpty()){
      throw new RuntimeException("List Error: insertBeforCurrent() called on empty or offend list"); 
    }
    if ( N.data == front.data){
      N.previous = new Node(data);
      front  = N.previous;
      front.next = N;
    }
    else{
      P = new Node(data);
      M = N.previous;
      N.previous = P;
      M.next = P;
      P.next = N;
      P.previous = M;
    }
    length++;
    curr++;
  }
  
  /* insertAfterCurrent()
   * Pre: !offEnd() & !isEmpty()
   * Pos: inserts a value to the right of the current position
   */ 
  void insertAfterCurrent(Object data){
    Node N = current;
    Node M, P;
    if ( this.offEnd() || this.isEmpty()){
      throw new RuntimeException("List Error: insertBeforeCurrent() called on empty of offend list");
    }
    if( N.data == back.data){
      N.next = new Node(data);
      back = N.next;
      back.previous = N;
    }
    else{
      P = new Node(data);
      M = N.next;
      N.next = P;
      M.previous = P;
      P.previous = N;
      P.next = M;
    }
    length++;
  }
  /* deletFront()
   * Pre: !isEmpty()
   * Pos: deletes a value at the front of the list
   */ 
  void deleteFront(){
    Node N = front;
    if ( this.isEmpty()){
      throw new RuntimeException("List Error: deleteFront() called on empty List");
    }
    else{
      front = N.next;
      front.previous = null;
      N.next = null;
    }
    length--;
    curr--;
  }
  /* deletBack()
   * Pre: !isEmpty()
   * Pos: deletes a value at the back of the list
   */ 
  void deleteBack(){
    Node N = back;
    if ( this.isEmpty()){
      throw new RuntimeException("List Error: deleteBack() called on empty list");
    }
    else{
      back = N.previous;
      back.next = null;
      N.previous = null;
    }
    length--;
  }
  /* deletFront()
   * Pre: !isEmpty()
   * Pos: deletes a value at the current position of the list
   */ 
  void deleteCurrent(){
    Node N, M, P;
    if ( this.offEnd() || this.isEmpty()){
      throw new RuntimeException("List Error: deleteCurrent() called on empty or offend list");
    }
    if ( current.data == front.data){
      N = front;
      front = N.next;
      front.previous = null;
      N.next = null;
      current = null;
    }
    else if ( current.data == back.data){
      N = back;
      back = N.previous;
      back.next = null;
      N.previous = null;
      current = null;
    }
    else{
      N = current.previous;
      M = current.next;
      N.next = M;
      M.previous = N;
      current = null;
    }
    curr = -1;
    length--;
  } 
  /* toString()
   * Pre:
   * Pos: overides the toString function to 
   *      print the list
   */ 
  public String toString(){
    Node N = front;
    int count =0;
    String s="";
    while( N != null){
      if(count ==0){
	s += N.data;
      } else{
        s+= " "+ N.data;
      }
      count++;
      N = N.next;
    }
    s +="";
    return s;
  }
}
