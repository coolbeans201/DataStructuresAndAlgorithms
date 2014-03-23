//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 1087
#include "queue.h"
using namespace std;
void arrayQueue::push(const int& theElement)
{// Add theElement to queue.
	arrayList::insert(size(), theElement);
}
