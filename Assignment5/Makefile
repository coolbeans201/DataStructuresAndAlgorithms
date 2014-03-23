main: main.o Arraylist.o myException.o BinaryTree.o MinHeap.o PriorityQueue.o
	g++ main.o Arraylist.o myException.o BinaryTree.o MinHeap.o PriorityQueue.o -o main
main.o: main.cpp PriorityQueue.h
	g++ -c main.cpp
Arraylist.o: Arraylist.cpp Arraylist.h myException.h
	g++ -c Arraylist.cpp
myException.o: myException.cpp myException.h
	g++ -c myException.cpp
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c BinaryTree.cpp
MinHeap.o: MinHeap.cpp MinHeap.h
	g++ -c MinHeap.cpp
PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h
	g++ -c PriorityQueue.cpp
tarfile: 
	tar cvf "Matthew_Weingarten_8189_1861.tar" main.cpp Arraylist.cpp Arraylist.h myException.h myException.cpp Linearlist.h BinaryTree.cpp BinaryTree.h MinHeap.cpp MinHeap.h PriorityQueue.cpp PriorityQueue.h Makefile
clean:
	rm main.o Arraylist.o myException.o BinaryTree.o MinHeap.o PriorityQueue.o main