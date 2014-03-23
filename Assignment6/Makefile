main: main.o BinPacking.o myException.o BinaryTree.o MaxWinnerTree.o
	g++ main.o BinPacking.o myException.o BinaryTree.o MaxWinnerTree.o -o main
main.o: main.cpp BinPacking.h
	g++ -c main.cpp
myException.o: myException.cpp myException.h
	g++ -c myException.cpp
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c BinaryTree.cpp
BinPacking.o: BinPacking.cpp BinPacking.h
	g++ -c BinPacking.cpp
MaxWinnerTree.o: MaxWinnerTree.cpp MaxWinnerTree.h
	g++ -c MaxWinnerTree.cpp
tarfile: 
	tar cvf "Matthew_Weingarten_8189_1861.tar" main.cpp myException.h myException.cpp BinaryTree.cpp BinaryTree.h BinPacking.h BinPacking.cpp MaxWinnerTree.h MaxWinnerTree.cpp Makefile
clean:
	rm main.o myException.o BinaryTree.o BinPacking.o MaxWinnerTree.o main