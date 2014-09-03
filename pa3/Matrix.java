/*Yugraj Singh
 *Matrix ADT 
 *
 *
 */ 
class Matrix{

	/*pirvate inner class
	 *creates and stores the pair values
	 */ 
	private class Entry{
		int column;
		double val;

		Entry(int column, double val){
			this.column = column;
			this.val = val;
		}
		/*toSting()
		 *overrides the Object classes to String Method
		 */ 
		public String toString(){ 
			return "("+ column + ", " + val +")"; 
		}
		/*equals()
		 *overrides the Object classes  equals Method;
		 */ 
		public boolean equals(Object x){
			if( x == null){
				return false;
			} else if( getClass() != x.getClass()){
				return false;
			} else{
				Entry temp = (Entry) x;
				return ( this.column == temp.column && this.val == temp.val);
			}
		}
		/* returns the column of the matrix
		 */ 
		int getColumn(){
			return column;
		}
		/* returns the value assocaited with the column
		 */
		double getVal(){
			return val;
		}
	}
	/*pirvate variables*/
	private List row[];
	private int matrixSize;
	private int NNZ;
	
	/*constructor*/
	Matrix(int n){
		if ( n < 1){
			throw new RuntimeException("Invalid size for matrix");
		}	
		row = new List[n];
		matrixSize = n;
		NNZ = 0;
		for (int i=0; i<n; i++){
			row[i] = new List();
		}
	
	}
	
	/* getSize()
	 * returns size of the matrix
	 */ 
	int getSize(){
		return matrixSize;
	}
	/* getNNZ()
	 * returns the number non zero values 
	 */ 
	int getNNZ(){
		for ( int i = 0; i < matrixSize; i++){
			if(!row[i].isEmpty()){
				NNZ += row[i].getLength(); 
			} 
		}
		return NNZ;
	}
	/* equals()
	 * overrides the Object class equal method
	 */ 
	public boolean equals(Object x){
		boolean boolVal = true;
		if ( x == null){
			return false;
		} else if (getClass() != x.getClass()){
			return false;
		} else{
			Matrix temp = (Matrix) x;
			int i = 0;
			while ( i < matrixSize && boolVal){
				boolVal = this.row[i].equals(temp.row[i]);
			}
			return boolVal;
		}
	}
	
	/* makeZero
	 * empties the List
	 */ 
	void makeZero(){
		for(int i=0; i<matrixSize; i++){
			if (row[i] == null){
				continue;
			} else{
				row[i].makeEmpty();
			}	
		}
	}
	/* copy()
	 * returns a copy of the Matrix
	 */ 
	Matrix copy(){
		Matrix newMatrix = new Matrix(matrixSize);
		for( int i=0; i < matrixSize; i++){
			if( row[i] == null){
				continue;
			} else {
				newMatrix.row[i] = copyMatrixRow(row[i]);
			}
		}
		return newMatrix;
	}
	
	/* changeEntry
	 * Pre: i & j must be >1 and <getSize()
	 * Pos: inserts a entry into the Matrix
	 */ 
	void changeEntry(int i, int j, double x){
		if (i<1 || i>this.getSize()){
			throw new RuntimeException("changeEntry() error: invalid parameter in function");
		}
		if(j<1 || j>this.getSize()){
			throw new RuntimeException("changeEntry() error: invalid parameter in function");
		}
		Entry hold;
		/* if statesments check the four cases for changeEntry()*/
		if (row[i-1].isEmpty() && x != 0){
			row[i-1].insertBack(new Entry(j,x));
		} else{
			row[i-1].moveTo(0);;
			if ( x != 0){
				while (!row[i-1].offEnd()){
					hold =(Entry)row[i-1].getCurrent();
					if ( hold.getColumn() < j){
						row[i-1].moveNext();
					} else if ( hold.getColumn() == j){
						row[i-1].insertAfterCurrent(new Entry(j,x));
						row[i-1].deleteCurrent();
						return;
					} else {
						row[i-1].insertBeforeCurrent(new Entry(j,x));
						return;
					}
				}
				if( row[i-1].offEnd()){
					row[i-1].insertBack( new Entry(j,x));
				}
			} else {
				while (!row[i-1].offEnd()){
					hold = (Entry)row[i-1].getCurrent();
					if ( hold.getColumn() < j){
						row[i-1].moveNext();
					} else if ( hold.getColumn() == j){
						row[i-1].deleteCurrent();
						return;
					} else {
						return;
					}
				}	
			}
		} 
	}
	
	/*scalarMult()
	 *returns a matrix that is the scalar product of this.Matrix
	 */ 
	Matrix scalarMult(double x){
		Matrix scalarMatrix = new Matrix(matrixSize);
		for( int i=0; i<matrixSize; i++){
			if( this.row[i] == null){
				continue;
			} else{	
				scalarMatrix.row[i] = scalarMatrixRow(row[i],x);
			}
		}
		scalarMatrix.noZero();
		return scalarMatrix;
	}
	/* add()
	 * returns a matrix that is the addition of two matries 
	 */
	Matrix add(Matrix M){
		if( getSize() != M.getSize() ){ 
			throw new RuntimeException("add() error: unequal Matrix size");
		}

		Matrix temp = new Matrix(matrixSize);
		for(int i=0; i<matrixSize; i++){
			if (row[i] == null && M.row[i] == null){
				continue;
			} else {
				temp.row[i] = addMatrixRow(row[i],M.row[i]);
			}	
		}
		temp.noZero();
		return temp;
	}
	
	/* sub()
	 * returns a matrix that is the subtration of two matries
	 */ 
	Matrix sub(Matrix M){
		if (getSize() != M.getSize()){
			throw new RuntimeException("sub() error: unqual Matrix size");
		}
		Matrix hold = M.scalarMult(-1);
		Matrix temp = this.add(hold);
		temp.noZero();
		return temp;
	}
	
	/* transpose()
	 * returns a matrix that is the transpose of this.Matrix
	 */ 
	Matrix transpose(){
		Matrix temp = new Matrix(matrixSize);
		Entry e;
		for ( int i = 0; i< matrixSize; i++){
			//trans(i,temp);
			if( row[i] == null){
				continue;
			} else {
				row[i].moveTo(0);
				while (!row[i].offEnd()){
					e = (Entry) row[i].getCurrent();
					temp.changeEntry( e.getColumn(), i+1, e.getVal());
					row[i].moveNext();
				}
			}
		}
		temp.noZero();
		return temp;
	}
		
	/* mult()
	 * returns  a matrix that is the product of two matries
	 *
	 */ 
	Matrix mult(Matrix M){	
		Matrix P;
		Matrix Q;
		if ( getSize() != M.getSize()){
			throw new RuntimeException("mult() error: unequal matrix size");
		}

		P = new Matrix(matrixSize);
		Q = M.transpose();

		for( int i = 0; i < matrixSize; i++){
			if (row[i] == null){
				continue;
			} else {
				P.row[i] = multMatrixRow(row[i],Q); 
			}
		}
		P.noZero();
		return P;
	
	}
	/* toString()
	 * overrides the toString() method in Object
	 */ 
	public String toString(){
		String s = "";
		int temp = 0;
		for(int i=0; i< matrixSize; i++){
			if (row[i] != null && !row[i].isEmpty()){
				if(temp == 1){
					s += "\n";
				}	
				s += (i+1) + ": ";
				s += row[i].toString();
				temp = 1;
			}
		}
		return s;
	}
	//Helper Methods
	
	/*copys the values row by row, is helper fuction to 
	 *copy()
	 */ 
	private List copyMatrixRow(List P){
		List temp = new List();
		if(!P.isEmpty()){
			P.moveTo(0);
			while( !P.offEnd()){
				temp.insertBack(P.getCurrent());
				P.moveNext();
			}
		}
		return temp;
	}
	/* helper function to scalarMult()
	 * times all vals in the list by x
	 */ 
	private List scalarMatrixRow(List P, double x){
		List temp = new List();
		Entry e;
		if(!P.isEmpty()){
			P.moveTo(0);
			while ( !P.offEnd()){
				e = (Entry)P.getCurrent();
				e.val = e.val*x;
				temp.insertBack(e);
				P.moveNext();
			}
		}
		return temp;
	}

	/* Helper funtion for add()
	 * goes row by row to add the values of two list 
	 */ 
	private  List addMatrixRow(List P, List Q){
		List temp = new List();
		Entry hold_P;
		Entry hold_Q;
		Entry add;
		if( !P.isEmpty() && Q.isEmpty() ){
			return P;
		} else  if ( P.isEmpty() && !Q.isEmpty()){
			return Q;
		} else {
			P.moveTo(0);
			Q.moveTo(0);
			while ( !P.offEnd() && !Q.offEnd()){
				hold_P =(Entry) P.getCurrent();
				hold_Q =(Entry) Q.getCurrent();
				if ( hold_P.getColumn() == hold_Q.getColumn() ){
					add = new Entry(hold_P.getColumn(),(hold_P.getVal()+hold_Q.getVal()));
					temp.insertBack(add);
					P.moveNext();
					Q.moveNext();
				} else if ( hold_P.getColumn() < hold_Q.getColumn()){
					add = new Entry(hold_P.getColumn(),hold_P.getVal());
					temp.insertBack(add);
					P.moveNext();
				} else if ( hold_P.getColumn() > hold_Q.getColumn()){
					add = new Entry(hold_Q.getColumn(), hold_Q.getVal());
					temp.insertBack(add);
					Q.moveNext();
				}
			}
			/* Q is bigger the P*/
			for(;!Q.offEnd(); Q.moveNext()){
				hold_Q =(Entry) Q.getCurrent();
				add = new Entry(hold_Q.getColumn(), hold_Q.getVal());
				temp.insertBack(add);
		
			}
			/* P is bigger then Q*/
			for(;!P.offEnd(); P.moveNext()){
				hold_P =(Entry) P.getCurrent();
				add = new Entry(hold_P.getColumn(), hold_P.getVal());
				temp.insertBack(add);
			}
		}
		return temp;
	}
	
	/* eliminates zeros in the matris*/
	private void noZero(){
		int i =0;
		int hold;
		Entry e;
		while ( i < matrixSize){
			if( row[i] == null){
				continue;
			} else {
				row[i].moveTo(0);
				while (!row[i].offEnd()){
					e = (Entry)row[i].getCurrent();
					if ( e.getVal() == 0){
						hold = row[i].getIndex();
						row[i].deleteCurrent();
						row[i].moveTo(hold);
					} else {
						row[i].moveNext();
					}
				}
			}
			i++;
		}
	}
        
	/*
	private void trans(int i, Matrix temp){
		//Matrix tran = new Matrix(Matrix Size);
		int hold;
		Entry e;
		row[i].moveTo(0);
		while ( !row[i].offEnd() ){
			e  = (Entry)row[i].getCurrent();
			temp.changeEntry(e.getColumn(), i, e.getVal());
			row[i].moveNext();
		}

	}*/
	/*  helper fuction for mult()
	 * adds the values in P and Q
	 */ 
	private  double dot(List P, List Q){
		Entry x;
		Entry y;
		double temp=0;
		if ( Q==null){
			return 0;
		}
		P.moveTo(0);
		Q.moveTo(0);
		while ( !P.offEnd() && !Q.offEnd()){
			x = (Entry) P.getCurrent();
			y = (Entry) Q.getCurrent();

			if ( x.getColumn() < y.getColumn()){
				P.moveNext();
			} else if ( x.getColumn() == y.getColumn()){
				temp += x.getVal()*y.getVal();
				P.moveNext();
				Q.moveNext();
			} else {
				Q.moveNext();
			}
		}
		return temp;
	}
	/* helper function for mult()
	 * multipies row by row
	 */ 
	private List multMatrixRow(List P, Matrix M){
		List temp = new List();
		double val;
		for ( int i=0; i< matrixSize; i++){
			val = dot(P,M.row[i]);
			temp.insertBack(new Entry(i, val));
		}
		return temp;
	}
	
}
