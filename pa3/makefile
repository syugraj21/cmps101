# Makefile for CMPS 101 
# pa3

MAINCLASS = Sparse
JAVAC = javac
JAVASRC = $(wildcard *.java)
SPARSECLASS = Sparse.class
MATRIXCLASSES = Matrix*.class
LISTCLASSES = List*.class
JARFILE = $(MAINCLASS)

all: Sparse MatrixTest ListTest

Sparse:
	javac Sparse.java Matrix.java List.java
	echo Main-class: ${MAINCLASS} > Manifest
	jar cvfm ${MAINCLASS} Manifest ${SPARSECLASS}  ${MATRIXCLASSES} ${LISTCLASSES}
	chmod +x Sparse
	rm Manifest

MatrixTest:
	javac MatrixTest.java Matrix.java List.java
	echo Main-class: MatrixTest > Manifest
	jar cvfm MatrixTest Manifest ${MATRIXCLASSES} ${LISTCLASSES}
	chmod +x MatrixTest
	rm Manifest

ListTest:
	javac ListTest.java List.java
	echo Main-class: ListTest > Manifest
	jar cvfm ListTest Manifest ${LISTCLASSES}
	chmod +x ListTest
	rm Manifest

clean:
	rm -f *.class $(JARFILE) ListTest MatrixTest

