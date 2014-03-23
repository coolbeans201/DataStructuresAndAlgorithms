main: main.o
	g++ main.o -o main
main.o: main.cpp ArrayLinearList.h
	g++ -c main.cpp
tarfile:
	tar cvf "Matthew_Weingarten_8189_1861.tar" main.cpp ArrayLinearList.h Makefile
clean:
	rm main.o main
