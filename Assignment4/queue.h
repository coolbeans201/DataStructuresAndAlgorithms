//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 1087
#include "Arraylist.h"
#include <exception>
#ifndef _QUEUE_H
#define _QUEUE_H
#ifndef _STACK_H
#endif
using namespace std;
class arrayQueue : public arrayList
{
   public:
      arrayQueue():arrayList(1000){}
      ~arrayQueue() {}
      bool empty() const {return arrayList::empty ();}
      int size() const
          {return arrayList::size();}
      int& front()
         {// return front element
            if (arrayList::empty())
               throw exception ();
            return *(arrayList::get(0));
         }
      int& back()
         {// return theBack element
            if (arrayList::empty())
               throw exception();
            return *(arrayList::get(arrayList::size() - 1));
         }
      void pop()
           {// remove theFront element
              if (arrayList::empty ())
                 throw exception();
              arrayList::erase(0); // destructor for T
           }
      void push(const int& theElement);
   private:
      int theFront;       // 1 counterclockwise from theFront element
      int theBack;        // position of theBack element
      int arrayLength;    // queue capacity
      int *queue;           // element array
};
#endif