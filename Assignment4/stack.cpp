//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 1087
#include "stack.h"
#include <exception>
using namespace std;
bool derivedArrayStack::empty () const
{
   return arrayList::empty ();
}

int derivedArrayStack::size () const
{
	return arrayList::size ();
}

int& derivedArrayStack::top()
{
	if (arrayList::empty())
	{
		throw exception();
       }
    return *(arrayList::get(size() - 1));
}

void derivedArrayStack::pop ()
{
	if (arrayList::empty())
	{
                 throw exception();
	}
     arrayList::erase(size() - 1);
}

void derivedArrayStack::push (const int& theElement)
{
	arrayList::insert(size(), theElement);
}
