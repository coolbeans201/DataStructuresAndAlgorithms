//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 8147
#ifndef MAXWINNERTREE_H
#define MAXWINNERTREE_H
#include <cstddef>
using namespace std;
class maxWinnerTree
{
   public:
      maxWinnerTree(int *thePlayer, int theNumberOfPlayers)
         {
            tree = NULL;
            initialize(thePlayer, theNumberOfPlayers);
         }
      ~maxWinnerTree() {delete [] tree;}
      void initialize(int*, int);
      int winner() const
         {return tree[1];}
      int winner(int i) const
         {return (i < numberOfPlayers) ? tree[i] : 0;}
         // return winner of match at node i
      void rePlay(int);
      int lowExt;           // lowest-level external nodes
      int offset;           // 2^log(n-1) - 1
      int *tree;            // array for winner tree
      int numberOfPlayers;
      int *player;            // array of players
      void play(int, int, int);
};
#endif