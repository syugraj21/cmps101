/*Yugraj Singh
 * 
 *List ADT 
 * 
 */ 
class List{
  
  private class Node{
    int data;
    Node next;
    Node previous;
    
    Node(int data){
      this.data = data;
      next = null;
      previous = null;
    }
  }
  
  private Node front;
  private Node back;
  private Node current;
  private int length;
  
  List(){
    front = null;
    back = null;
    length = 0;
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
    Node N = front;
    int count = 1;
    if( current != null){
      if(N.data == current.data){
        return count;
      }
      while( N != null){
        count++;
        if( N.next.data == current.data){
          return count; 
        }
        N = N.next;  
      }
    }
    return -1;
  }
  
  /* getFront()
   * Pre: list is not empty
   * Pos: returns value in the front of the list
   */ 
  int getFront(){
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
  int getBack(){
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
  int getCurrent(){
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
  boolean equals(List L){
    boolean boolVal= true;
    Node N = this.front;
    Node M = L.front;
    if ( this.length == L.length){
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
  
  /* makeEmpty()
   * makes the list empty
   */ 
  void makEmpty(){
    front = null;
    back = null;
    current = null;
    length = 0;
  }
  
  /* moveTo()
   * moves the current position to the index indicated 
   * by i
   */ 
  void moveTo(int i){
    Node N = front;
    if ( i >= 0 && i <= this.getLength()-1){
      if( i == 0){
        current = N;
      }
      else{
        for(int j = 0; j < i; j++){
          N = N.next;
        }
        current = N;
      }
    }
    else{
      current = null;
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
    }
  }
  
  /* insertFront()
   * Pre: 
   * Pos: inserts a value into the front of the list
   */ 
  void insertFront(int data){
    Node N;
    if ( front == null){
      front = new Node(data);
      back = front;
      current = front;
    }
    else{
      N = front;
      N.previous = new Node(data);
      front = N.previous;
      front.next = N;    
    }
    length++;
    
  }
  
  /* insertBack()
   * Pre: 
   * Pos: inserts a value into the back of the list
   */ 
  void insertBack(int data){
    Node N;
    if( back == null){
      back = new Node(data);
      front = back;
      current = back;
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
  void insertBeforeCurrent(int data){
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
  }
  
  /* insertAfterCurrent()
   * Pre: !offEnd() & !isEmpty()
   * Pos: inserts a value to the right of the current position
   */ 
  void insertAfterCurrent(int data){
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
    length--;
  }
  /* copy()
   * Pre: 
   * Pos: copys the list to a new list
   */ 
  List copy(){
    Node N = back;
    List T = new List();
    while( N != null){
      T.insertFront(N.data);
      N = N.previous;
    }
    return T; 
  }
  
  /* toString()
   * Pre:
   * Pos: overides the toString function to 
   *      print the list
   */ 
  public String toString(){
    Node N = front;
    String s="(";
    while( N != null){
      s+= N.data+" ";
      N = N.next;
    }
    s +=")";
    return s;
  }
}
