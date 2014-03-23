//Name: Matthew Weingarten
//Gatorlink ID: coolbeans201
//UFID: 8189-1861
//Discussion Section: 8147
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "MinHeap.h"
class PriorityQueue 
{
   public:
	PriorityQueue() {}
	~PriorityQueue() {}
	void heapify(int);
	void initialize(arrayList*&, int);
       void inOrder(int);
	void preOrder(int);
	void postOrder(int);
	void inOrder1(int);
	void preOrder1(int);
	void postOrder1(int);
	int remove();
	void sort();
   protected:
	arrayList* a;
	int listSize;
};
#endif