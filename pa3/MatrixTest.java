
class MatrixTest{
	public static void main(String[] args){
		Matrix x = new Matrix(3);
		
		x.changeEntry(1,1,4);
		x.changeEntry(1,3,4);
		x.changeEntry(2,3,1);
		x.changeEntry(1,2,3);
		x.changeEntry(2,1,3);
		//x.changeEntry(1,2,0);

		Matrix y = new Matrix(3);
		y.changeEntry(1,1,1);
                y.changeEntry(1,3,1);
                y.changeEntry(2,3,0);
                y.changeEntry(1,2,2);
                y.changeEntry(2,1,3);
                y.changeEntry(1,2,0);
		y.changeEntry(3,1,2);
		y.changeEntry(3,2,3);
		y.changeEntry(3,3,1);

		System.out.println(x.toString());
		System.out.println();
		System.out.println(y.toString());
		
		Matrix M = x.copy();
		
		System.out.println("**************");
		System.out.println(M);


		M = x.add(y);
		System.out.println();
		System.out.println("**************");
		System.out.println(M);
		System.out.println();	
		/*
		x = x.scalarMult(-1);
		System.out.println(x);
		System.out.println();
		Matrix temp = y;
		y = y.scalarMult(3);
		System.out.println(y);
		System.out.println();
		*/

		Matrix sub = x.sub(y);
		System.out.println(sub+ "\n");
		
		Matrix T = x.transpose();
		System.out.println(T+"\n");
	
		Matrix times = x.mult(y);
		System.out.println(times);
	}
}
