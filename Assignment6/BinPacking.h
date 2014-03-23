//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 8147
#ifndef BINPACKING_H
#define BINPACKING_H
#include "BinaryTree.h"
#include "MaxWinnerTree.h"
class BinPacking
{
	public:
		BinPacking(){}
		void bestFitPack(int*, int, int);
		void firstFitPack(int*, int, int);
};
#endif