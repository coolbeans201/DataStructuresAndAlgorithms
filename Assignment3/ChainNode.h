#ifndef CHAINNODE_H
#define CHAINNODE_H
using namespace std;
struct chainNode 
{
   // data members
   int element;
   chainNode *next;

   // methods
   chainNode() {}
   chainNode(const int& element);
   chainNode(const int& element, chainNode* next);
};
#endif
