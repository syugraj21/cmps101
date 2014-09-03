/*Yugraj Sing
 * 
 * Main shuffle class that performs the permutations on the list
 * 
 */

import java.io.*;
import java.util.Scanner;

class Shuffle{
  public static void main(String args[]) throws IOException{
    Scanner input = null;
    PrintWriter out = null;
    String line = null;
    List[] P;
    List[] L;
    int n=0;
    
    /*exits the program if the command line args arn't met*/
    if(args.length < 2){
      System.err.println("Usage: Shuffle infile outfile");
      System.exit(1);
    }
    //initialising input and out
    input = new Scanner(new File(args[0]));
    out = new PrintWriter(new FileWriter(args[1]));
    
    input.useDelimiter("\n");
    n = input.nextInt();//get the number of permutations P
    //creates the list array 
    P = new List[n];
    L = new List[n];
    //initialize the array List
    for(int i=0; i<n; i++){
      P[i] = new List();
      L[i] = new List();
    }
    
    //insert the values from the file to the List
    for (int i=0; i<n;i++){
      line = input.next();
      insertPer(P[i],line);
      initializeList(L[i],P[i].getLength()); 
    }
    
    //main loop
    for(int i =0; i<n; i++){
      int order = 1; 
      List originalList = L[i].copy(); 
      shuffle(L[i],P[i]);
      out.print(L[i]);
      //shuffles the list L unit it back to the original L
      while( !originalList.equals(L[i])){
        shuffle(L[i],P[i]);
        order++;
      }
      out.println( " order = " + order);
    }
    
    input.close();
    out.close();    
  }
  
  /* Shuffle
   * Pre: two arguments ( Lists)
   * Pos: performs the permutation on the list L
   */ 
  public static void shuffle(List L, List P){
    int index =2;
    P.moveTo(0);
    while( P.offEnd() != true){
      L.moveTo(L.getLength()+P.getCurrent()-index);
      L.insertAfterCurrent(L.getFront());
      L.deleteFront();
      index++;
      P.moveNext(); 
    }
  }
  
  /* insertPer()
   * Inserts the values from the input file into the 
   * List
   */ 
  public static void insertPer(List P,String Line){
    int n;
    Scanner in = new Scanner(Line);
    while(in.hasNextInt()){
      P.insertBack(in.nextInt());
    }
  }
  
  /* initializeList()
   * initializes a List L with values 1...P.length
   */ 
  public static void initializeList(List L, int temp){
    for(int i = 1; i<=temp; i++){
      L.insertBack(i);
    }
  }
  
}
