//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 1087
using namespace std;
#ifndef _RATINMAZE_H
#define _RATINMAZE_H	
#include "stack.h"
#include "queue.h"
class RatInMaze
{
	public:
	       RatInMaze () {};
		bool searchStack(int fromX,int fromY,int toX,int toY);
              bool searchQueue(int fromX,int fromY,int toX,int toY); 
              bool searchStackSmart(int fromX,int fromY,int toX,int toY);
		void load (char maze[][15], int row, int col);
		void print (bool search);
		bool isValid (int x, int y);
		void makeIntArray ();
		bool isIntValid(int x, int y);
		int smallestNeighbor(int x, int y);
	protected:
		int traveled;
		int pathLength;
		int rows;
		int cols;
		derivedArrayStack* xCoord;
		derivedArrayStack* yCoord;
		arrayQueue* xCoord1;
		arrayQueue* yCoord1;
		char**  maze1;
		int** mazeInt;
};
#endif

