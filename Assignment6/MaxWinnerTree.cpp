//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 8147
#include "MaxWinnerTree.h"
#include <exception>
using namespace std;
void maxWinnerTree::initialize(int *thePlayer, int theNumberOfPlayers)
{// Create winner tree for thePlayer[1:numberOfPlayers].
   int n = theNumberOfPlayers;
   if (n < 2)
      throw exception();

   player = thePlayer;
   numberOfPlayers = n;
   delete [] tree;
   tree = new int [n];

   // compute  s = 2^log (n-1)
   int i, s;
   for (s = 1; 2 * s <= n - 1; s += s);

   lowExt = 2 * (n - s);
   offset = 2 * s - 1;

   // play matches for lowest-level external nodes
   for (i = 2; i <= lowExt; i += 2)
      play((offset + i) / 2, i - 1, i);

   // handle remaining external nodes
   if (n % 2 == 1)
   {// special case for odd n, play internal and exteral node
      play(n/2, tree[n - 1], lowExt + 1);
      i = lowExt + 3;
   }
   else i = lowExt + 2;

   // i is left-most remaining external node
   for (; i <= n; i += 2)
      play((i - lowExt + n - 1) / 2, i - 1, i);
}

void maxWinnerTree::play(int p, int leftChild, int rightChild)
{// play matches beginning at tree[p]
 // leftChild is left child of p
 // rightChild is right child of p

   tree[p] = (player[leftChild] >= player[rightChild]) ? leftChild : rightChild;

   // more matches possible if at right child
   while (p % 2 == 1 && p > 1)
   {// at a right child
      tree[p / 2] = (player[tree[p - 1]] >= player[tree[p]]) ? tree[p - 1] : tree[p];
      p /= 2;  // go to parent
   }
}


void maxWinnerTree::rePlay(int thePlayer)
{// Replay matches for player thePlayer.
   int n = numberOfPlayers;
   if (thePlayer <= 0 || thePlayer > n)
      throw exception();

   int matchNode,       // node where next match is to be played
       leftChild,       // left child of matchNode
       rightChild;      // right child of matchNode

   // find first match node and its children
   if (thePlayer <= lowExt)
   {// begin at lowest level
      matchNode = (offset + thePlayer) / 2;
      leftChild = 2 * matchNode - offset;
      rightChild = leftChild + 1;
   }
   else
   {
      matchNode = (thePlayer - lowExt + n - 1) / 2;
      if (2 * matchNode == n - 1)
      {
         leftChild = tree[2 * matchNode];
         rightChild = thePlayer;
      }
      else
      {
         leftChild = 2 * matchNode - n + 1 + lowExt;
         rightChild = leftChild + 1;
      }
   }

   tree[matchNode] = (player[leftChild] >= player[rightChild]) ? leftChild : rightChild;

   // special case for second match
   if (matchNode == n - 1 && n % 2 == 1)
   {
      matchNode /= 2;   // move to parent
      tree[matchNode] = (player[tree[n - 1]] >= player[lowExt + 1]) ? tree[n - 1] : lowExt + 1;
   }

   // play remaining matches
   matchNode /= 2;  // move to parent
   for (; matchNode >= 1; matchNode /= 2)
      tree[matchNode] = (player[tree[2 * matchNode]] >= player[tree[2 * matchNode + 1]]) ? tree[2 * matchNode] : tree[2 * matchNode + 1];
}