//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 1087
#include "Arraylist.h"
#ifndef _STACK_H
#define _STACK_H
#ifndef _QUEUE_H
#endif
using namespace std;

class derivedArrayStack : public arrayList
{
   public:
      derivedArrayStack(): arrayList(1000){}
      ~derivedArrayStack(){}
      bool empty() const;
      int size() const;
      int& top();
      void pop();
      void push(const int& theElement);
};

#endif
