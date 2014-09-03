/*Yugraj Singh
 *This Program reads from the input file and does 
 *matrix manipuation to get the out
 *
 */ 
import java.io.*;
import java.util.Scanner;

class Sparse{
	public static void main(String[] args) throws IOException{
		Scanner in = null;
		PrintWriter out = null;
		String line = null;
		String[] token = null;

		/* checks the command line args*/
		if( args.length<2){
			System.err.println("Usage: Sparse infile outfile");
			System.exit(1);
		}

		/*initialising in and out*/
		in = new Scanner(new File(args[0]));
		out = new PrintWriter(new FileWriter(args[1]));
		int mSize=0;
		int entry1=0;
		int entry2=0;
		int row = 0;
		int column = 0;
		double val =0;
		
		/*reads the first line*/
		if(in.hasNextLine()){
			line = in.nextLine()+" ";
			token = line.split("\\s+");
			mSize = Integer.parseInt(token[0]);
			entry1 = Integer.parseInt(token[1]);
			entry2 = Integer.parseInt(token[2]);
		}
		//creates matrix
		Matrix A = new Matrix(mSize);
		Matrix B = new Matrix(mSize);
		/*matrix A initialising*/
		for( int i =0; i< entry1; i++){
			if ( in.hasNextLine()){
				line = in.nextLine();
				while ( line.isEmpty() && in.hasNextLine()){
					line = in.nextLine();
				}
				line  += " ";
				token = line.split("\\s+");
				row = Integer.parseInt(token[0]);
				column = Integer.parseInt(token[1]);
				val = Double.parseDouble(token[2]);
			}
			A.changeEntry(row,column,val);	
		}
		/*matrix B initialising*/
		for ( int i =0; i<entry2; i++){
			if(in.hasNextLine()){
				line = in.nextLine();
				while(line.isEmpty() && in.hasNextLine()){
					line = in.nextLine();
				}
				line += "";
				token = line.split("\\s+");
				row = Integer.parseInt(token[0]);
				column = Integer.parseInt(token[1]);
				val = Double.parseDouble(token[2]);
			}
			B.changeEntry(row,column,val);
		}
		/*prints to the output file in the order*/
		Matrix temp;
		out.println("A has "+A.getNNZ()+" non-zero entries:");
		out.println(A.toString());
                if(A.getNNZ() != 0){
			out.println();
		}

	        out.println("B has "+B.getNNZ()+" non-zero entries:");
	        out.println(B.toString());
	        if(B.getNNZ() != 0){
			out.println();
		}

	        out.println("(1.5)*A =");
		temp = A.scalarMult(1.5);
		out.println(temp.toString());
		if(temp.getNNZ() != 0){
			out.println();
		} 

		out.println("A+B =");
		temp = A.add(B);
		out.println(temp.toString());
		if(temp.getNNZ() != 0){
			out.println();
		}

		out.println("A+A =");
	  	Matrix copy = A.copy();
		temp = A.add(copy);
		out.println(temp.toString());
		if(temp.getNNZ() != 0){
			out.println();
		}

		out.println("B-A =");
		temp = B.sub(A);
		out.println(temp.toString());
		if(temp.getNNZ() != 0){
			out.println();
		} 

		out.println("A-A =");
		temp = A.sub(copy);
		out.println(temp.toString());
		if(temp.getNNZ() != 0){
			out.println();
		}

		out.println("Transpose(A) =");
		temp = A.transpose();
		out.println(temp.toString());
		if(temp.getNNZ() != 0){
			out.println();
		}

		out.println("A*B =");
		temp = A.mult(B);
		out.println(temp.toString());
		if(temp.getNNZ() != 0){
			out.println();
		}

		out.println("B*B =");
		copy = B.copy();
		temp = A.mult(copy);
		out.println(temp.toString());
		if(temp.getNNZ() != 0){
			out.println();
		}
		//close files
		in.close();
		out.close();
	}	
}
