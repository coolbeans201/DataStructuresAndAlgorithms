//Name: Matthew Weingarten
//Gatorlink ID: coolbeans201
//UFID: 8189-1861
//Discussion Section: 8147
#include "PriorityQueue.h"
#include <iostream>
using namespace std;
void PriorityQueue::initialize(arrayList*& a1, int size)
{
	a = new arrayList(size + 1);
	listSize = size + 1;
	int i;
	a->insert(0, -1);
	for(i = 1; i < listSize; i ++)
	{
		a->insert(i, *(a1->get(i - 1)));
	}
	for (i = listSize / 2; i >= 0; i--)
	{
		heapify(i);
	}
}
void PriorityQueue::heapify(int location)
{
	int left, right, min;
	left = 2 * location;
	right = 2 * location + 1;
	min = 0;
	if (left < listSize && (*(a->get(left)) <= *(a->get(location))))
	{
		min = left;
	}
	else
	{
		min = location;
	}
	if (right < listSize && (*(a->get(right)) <= *(a->get(min))))
	{
		min = right;
	}
	if (min != location)
	{
		int t = *(a->get(min));
		a->changeValue(min, *(a->get(location)));
		a->changeValue(location, t);
		heapify(min);
	}
}
void PriorityQueue::inOrder(int location)
{
	inOrder1(location + 1);
}
void PriorityQueue::inOrder1(int location)
{
	if (location < listSize)
	{
		inOrder1(2 * location);
		cout<<*(a->get(location))<<" ";
		inOrder1(2 * location + 1);
	}
}
void PriorityQueue::preOrder(int location)
{
	preOrder1(location + 1);
}
void PriorityQueue::preOrder1(int location)
{
	if (location < listSize)
	{
		cout<<*(a->get(location))<<" ";
		preOrder1(2 * location);
		preOrder1(2 * location + 1);
	}
}
void PriorityQueue::postOrder(int location)
{
	postOrder1(location + 1);
}
void PriorityQueue::postOrder1(int location)
{
	if (location < listSize)
	{
		postOrder1(2 * location);
		postOrder1(2 * location + 1);
		cout<<*(a->get(location))<<" ";
	}
}
int PriorityQueue::remove()
{
	if (listSize > 0)
	{
		int tmp = *(a->get(1));
		a->changeValue(1, *(a->get(listSize - 1)));
		listSize--;
		heapify(1);
		return tmp;
	}
}
void PriorityQueue::sort()
{
	int* temp = new int[listSize];
	int i;
	temp[0] = 0;
	int size = listSize;
	for(i = 1; i < size; i++)
	{
		temp[i] = remove();
	}
	for (i = 1; i < size; i++)
	{
		a->changeValue(i, temp[i]);
	}
	for (i = 1; i < size; i++)
	{
		cout<<*(a->get(i))<<" ";
	} 
}