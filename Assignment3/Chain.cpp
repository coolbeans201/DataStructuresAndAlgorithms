#include <iostream>
#include <sstream>
#include <exception>
#include "Myexception.h"
#include "Chain.h"
#include "ChainNode.h"
using namespace std;
chain::chain(int initialCapacity)
{// Constructor.
   try
	{
   		if (initialCapacity < 1)
   		{
			ostringstream s;
    			s << "Initial capacity = " 
      				<< initialCapacity << " Must be > 0";
    			throw illegalParameterValue(s.str());
		}
	}
	catch(illegalParameterValue& e){
		e.outputMessage();
		return;
	} 
   firstNode = NULL;
   listSize = 0;
}

chain::chain(const chain& theList)
{// Copy constructor.
   listSize = theList.listSize;

   if (listSize == 0)
   {// theList is empty
      firstNode = NULL;
      return;
   }

   // non-empty list
   chainNode* sourceNode = theList.firstNode;
                    // node in theList to copy from
   firstNode = new chainNode(sourceNode->element);
                    // copy first element of theList
   sourceNode = sourceNode->next;
   chainNode* targetNode = firstNode;
                    // current last node in *this
   while (sourceNode != NULL)
   {// copy remaining elements
      targetNode->next = new chainNode(sourceNode->element);
      targetNode = targetNode->next;
      sourceNode = sourceNode->next;
   }
   targetNode->next = NULL; // end the chain
}

chain::~chain()
{// Chain destructor. Delete all nodes in chain.
   while (firstNode != NULL)
   {// delete firstNode
      chainNode* nextNode = firstNode->next;
      delete firstNode;
      firstNode = nextNode;
   }
}


void chain::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
   if (theIndex < 0 || theIndex >= listSize){
		ostringstream s;
    		s << "index = " << theIndex << " size = " 
                    << listSize<<", the input index is invalid";
    		throw illegalIndex(s.str());
    }
}

int* chain::get(int theIndex) const
{// Return element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   try{
		checkIndex(theIndex);
	}
	catch(illegalIndex &e){
		e.outputMessage();
		return NULL;
	}
   // move to desired node
   chainNode* currentNode = firstNode;
   for (int i = 0; i < theIndex; i++)
      currentNode = currentNode->next;
   return &currentNode->element;
}

int chain::indexOf(const int& theElement) const
{// Return index of first occurrence of theElement.
 // Return -1 if theElement not in list.
   // search the chain for theElement
   chainNode* currentNode = firstNode;
   int index = 0;  // index of currentNode
   while (currentNode != NULL &&
          currentNode->element != theElement)
   {
      // move to next node
      currentNode = currentNode->next;
      index++;
   }
   // make sure we found matching element
   if (currentNode == NULL)
      return -1;
   else
      return index;
}

void chain::erase(int theIndex)
{// Delete the element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   try{
		checkIndex(theIndex);
	}
	catch(illegalIndex &e){
		e.outputMessage();
		return;
	}
   // valid index, locate node with element to delete
   chainNode* deleteNode;
   if (theIndex == 0)
   {// remove first node from chain
      deleteNode = firstNode;
      firstNode = firstNode->next;
   }
   else
   {  // use p to get to predecessor of desired node
      chainNode* p = firstNode;
      for (int i = 0; i < theIndex - 1; i++)
         p = p->next;

      deleteNode = p->next;
      p->next = p->next->next; // remove deleteNode from chain
   }
   listSize--;
   delete deleteNode;
}

void chain::insert(int theIndex, const int& theElement)
{// Insert theElement so that its index is theIndex.
   try{
   		if (theIndex < 0 || theIndex > listSize)
   		{// invalid index
    		// code to throw an exception comes here
			ostringstream s;
    			s << "index = " << theIndex << " size = " 
                    		<< listSize<<", the input index is invalid";
    			throw illegalIndex(s.str());
		}
	}
	catch(illegalIndex &e){
		e.outputMessage();
		return;
	}
   if (theIndex == 0)
      // insert at front
      firstNode = new chainNode(theElement, firstNode);
   else
   {  // find predecessor of new element
      chainNode* p = firstNode;
      for (int i = 0; i < theIndex - 1; i++)
         p = p->next;

      // insert after p
      p->next = new chainNode(theElement, p->next);
   }
   listSize++;
}

void chain::traverse ()
{
    if (listSize == 0)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    chainNode* p = firstNode;
    while (p != NULL)
    {
        cout<<p->element<<" ";
        p = p->next;
    }
    cout<<endl;
}

void chain::MaxMin ()
{
   if(listSize==0)
   {
    		cout<<"List is empty"<<endl;
   	   return;
	}
	int max=-100000;
	int min=100000;
	chainNode* p = firstNode;
	while (p != NULL)
	{
		if((p->element) > max)
		{
			max = p->element;
	   }
		if((p->element) <min)
		{
		   min = p->element;
		}
		p = p->next;
  	}
	cout<<"The maximum element in the list is "<<max<<endl;
	cout<<"The minimum element in the list is "<<min<<endl;
}


