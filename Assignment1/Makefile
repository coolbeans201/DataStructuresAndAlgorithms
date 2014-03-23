main: main.o
	g++ main.o -o main
main.o: main.cpp header.h
	g++ -c main.cpp
tarfile:
	tar cvf "Matthew_Weingarten_8189_1861.tar" main.cpp header.h Makefile
clean:
	rm main.o main
