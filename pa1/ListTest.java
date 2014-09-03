/*Yugraj Singh
 * 
 * This Program is a test class for the List ADT
 * 
 */
class ListTest{
 public static void main(String[] args){
  int x, y, z, a;
  List T = new List();
  List P = new List();
  System.out.println(T.getLength());
  System.out.println(T.isEmpty());
  System.out.println(T.offEnd());
  System.out.println(T.getIndex());
  //x = T.getFront();
  //y = T.getBack();
  T.insertFront(1);
  T.insertFront(2);
  System.out.println(T);
  T.insertBack(10);
  T.insertBack(9);
  System.out.println(T);
  System.out.println("front "+ T.getFront());
  System.out.println("back "+ T.getBack());
  System.out.println("1 current " +T.getCurrent());
  System.out.println("1 index" +T.getIndex());
  T.movePrev();
  System.out.println("2 current "+T.getCurrent());
  System.out.println("2 index "+T.getIndex());
  T.moveNext();
  System.out.println("3 current "+T.getCurrent());
  System.out.println("3 index "+T.getIndex());
  T.insertBeforeCurrent(100);
  T.insertBeforeCurrent(99);
  System.out.println(T);
  T.insertAfterCurrent(1000);
  T.insertAfterCurrent(999);
  System.out.println(T);
  T.moveTo(6);
  System.out.println("4 current "+T.getCurrent());
  System.out.println("4 index " + T.getIndex());
  T.moveTo(8);
  System.out.println(T.offEnd());
  //System.out.println("5 current "+T.getCurrent());
  System.out.println("5 index "+T.getIndex());
  T.moveTo(4);
  System.out.println(T.offEnd());
  System.out.println("6 current "+T.getCurrent());
  System.out.println("6 index "+T.getIndex());
  System.out.println(T);
  T.deleteFront();
  T.deleteBack();
  System.out.println(T);
  T.deleteCurrent();
  System.out.println(T.offEnd());
  //System.out.println("7 current "+T.getCurrent());
  System.out.println("7 index "+T.getIndex());
 }
}
