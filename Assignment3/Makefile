main1: main1.o IOcode.o Arraylist.o Myexception.o 
	g++ main1.o IOcode.o Arraylist.o Myexception.o  -o main1
main2: main2.o IOcode.o Chain.o ChainNode.o Myexception.o
	g++ main2.o IOcode.o Chain.o ChainNode.o Myexception.o -o main2
main1.o: main1.cpp IOcode.h Arraylist.h
	g++ -c main1.cpp
main2.o: main2.cpp IOcode.h Chain.h
	g++ -c main2.cpp
IOcode.o: IOcode.cpp IOcode.h Linearlist.h
	g++ -c IOcode.cpp
Chain.o: Chain.cpp Chain.h ChainNode.h
	g++ -c Chain.cpp
ChainNode.o: ChainNode.cpp ChainNode.h
	g++ -c ChainNode.cpp
Arraylist.o: Arraylist.cpp Arraylist.h Myexception.h
	g++ -c Arraylist.cpp
Myexception.o: Myexception.cpp Myexception.h
	 g++ -c Myexception.cpp
tarfile:
	tar cvf "Matthew_Weingarten_8189_1861.tar" main1.cpp main2.cpp Arraylist.cpp Arraylist.h Myexception.cpp Myexception.h IOcode.cpp IOcode.h Chain.cpp Chain.h ChainNode.cpp ChainNode.h Makefile
clean:
	rm main1.o main2.o IOcode.o Chain.o ChainNode.o Arraylist.o Myexception.o
