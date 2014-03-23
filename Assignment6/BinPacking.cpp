//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 8147
#include "BinPacking.h"
using namespace std;
void BinPacking::firstFitPack(int* objectSize, int numberOfObjects, int binCapacity)
{
	int n = numberOfObjects;             // number of objects

   // initialize n bins and winner tree
   int *bin = new int [n + 1];  // bins
   for (int j = 1; j <= n; j++)
   {
      bin[j]= binCapacity;
   }
   maxWinnerTree tree(bin, n);
   
   // pack objects into bins
   for (int l = 1; l <= n; l++)
   {      
      int child = 2;  // start search at left child of root
      while (child < n)
      {
         int winner = tree.winner(child);
         if (bin[winner] < objectSize[l])
	  {
            child++ ;  // first bin is in right subtree
         }
         child *= 2;   // move to left child
      }

      int binToUse;          // will be set to bin to use
      child /= 2;            // undo last left-child move
      if (child < n)
      {// at a tree node
         binToUse = tree.winner(child);
         if (binToUse > 1 && bin[binToUse - 1] >= objectSize[l])
	  {
            binToUse--;
         }
       }
       else  // arises when n is odd
          binToUse = tree.winner(child / 2);
 
       cout << "Pack object " << l << " in bin "
            << binToUse << endl;
       bin[binToUse] -= objectSize[l];
       tree.rePlay(binToUse);
   }
}
void BinPacking::bestFitPack(int* objectSize, int numberOfObjects, int binCapacity)
{
	int n = numberOfObjects;
	binarySearchTree* t = new binarySearchTree();
	int binsUsed = 0;
	int binNumber;
	int binCapacity1;
	for (int i = 1; i <= n; i ++)
	{
		binaryTreeNode* bestBin = t->find(objectSize[i]);
		if (bestBin == NULL)
		{
			binNumber = ++binsUsed;
			binCapacity1 = binCapacity;
		}
		else
		{
			binNumber = bestBin->element;
			binCapacity1 = bestBin->key;
			t->erase(binCapacity1);
		}
		binCapacity1 -= objectSize[i];
		t->insert(binNumber, binCapacity1);
		cout<<"Pack object "<<i<<" in bin "<<binNumber<<endl;
	}
}