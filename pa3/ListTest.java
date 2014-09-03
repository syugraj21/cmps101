
class ListTest{
	public static void main(String[] args){
		
		List L = new List();
		System.out.println(L.getLength());
		System.out.println(L.isEmpty());
		System.out.println(L.offEnd());
		System.out.println(L.getIndex());
		
						
		/*L.insertFront((int)10);
		System.out.println(L);
		System.out.println(L.getCurrent());
		*/
		L.insertBack((int)9);
		System.out.println(L);
		System.out.println(L.getCurrent());
		L.insertBack((int) 8);
		
		System.out.println(L.getLength());
		System.out.println(L.isEmpty());
		System.out.println(L);
		System.out.println(L.getFront()); 
		System.out.println(L.getBack());
		System.out.println(L.getCurrent());
		System.out.println("index" + L.getIndex());
		
		L.insertBeforeCurrent((int)1);
		L.insertAfterCurrent((int) 2);

		System.out.println(L);
		System.out.println(L.getCurrent());
                System.out.println("index" + L.getIndex());
		
		L.moveTo(3);
		System.out.println(L.getCurrent());
		System.out.println("index"+L.getIndex());
		
		L.moveTo(0);
		System.out.println(L.getCurrent());
		System.out.println("index"+L.getIndex());
	
	}
}
