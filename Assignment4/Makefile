main: main.o Arraylist.o myException.o stack.o queue.o RatinMaze.o
	g++ main.o Arraylist.o myException.o stack.o queue.o RatinMaze.o -o main
main.o: main.cpp RatinMaze.h 
	g++ -c main.cpp
Arraylist.o: Arraylist.cpp Arraylist.h myException.h
	g++ -c Arraylist.cpp
myException.o: myException.cpp myException.h
	g++ -c myException.cpp
stack.o: stack.cpp stack.h
	g++ -c stack.cpp
queue.o: queue.cpp queue.h
	g++ -c queue.cpp
RatinMaze.o: RatinMaze.cpp RatinMaze.h
	g++ -c RatinMaze.cpp
tarfile: 
	tar cvf "Matthew_Weingarten_8189_1861.tar" main.cpp Arraylist.cpp Arraylist.h myException.cpp myException.h stack.cpp stack.h queue.cpp queue.h Linearlist.h RatinMaze.cpp RatinMaze.h Makefile
clean:
	rm main.o Arraylist.o myException.o stack.o queue.o RatInMaze.o main
