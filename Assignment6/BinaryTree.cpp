//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 8147
#include "BinaryTree.h"
bool binarySearchTree::empty()
{
	if (treeSize == 0)
	{
		return true;
	}
	return false;
}
int binarySearchTree::size()
{
	return treeSize;
}
void binarySearchTree::inOrder(binaryTreeNode *t)
{
	if (t != NULL)
	{
		inOrder(t->leftChild);
		cout<<t->element<<" "<<t->key<<" ";
		inOrder(t->rightChild);
	}
}
void binarySearchTree::insert(int theElement, int theKey)
{
	binaryTreeNode *p = root;
	binaryTreeNode *pp = NULL;
	while (p != NULL)
	{
		pp = p;
		if (theKey <= p->key)
		{
			p = p->leftChild;
		}
		else
		{
			p = p->rightChild;
		}
	}
	binaryTreeNode *newNode = new binaryTreeNode(theElement, theKey);
	if (root != NULL)
	{
		if (theKey <= pp->key)
		{
			pp->leftChild = newNode;
		}
		else
		{
			pp->rightChild = newNode;
		}
	}
	else
	{
		root = newNode;
	}
	treeSize++;
}
void binarySearchTree::erase(int theKey)
{
	binaryTreeNode* p = root;
	binaryTreeNode* pp = NULL;
	while (p != NULL && p->key != theKey)
	{
		pp = p;
		if (theKey < p->key)
		{
			p = p->leftChild;
		}
		else
		{
			p = p->rightChild;
		}
	}
	if (p == NULL)
	{
		return;
	}
	if (p->leftChild != NULL && p->rightChild != NULL)
	{
		binaryTreeNode* s = p->leftChild;
		binaryTreeNode* ss = p;
		while (s->rightChild != NULL)
		{
			ss = s;
			s = s->rightChild;
		}
		binaryTreeNode *q = new binaryTreeNode(s->element, s->key, p->leftChild, p->rightChild);
		if (pp == NULL)
		{
			root = q;
		}
		else if (p == pp->leftChild)
		{
			pp->leftChild = q;
		}
		else
		{
			pp->rightChild = q;
		}
		if (ss == p)
		{
			pp = q;
		}
		else
		{
			pp = ss;
		}
		delete p;
		p = s;
	}
	binaryTreeNode* c;
	if (p->leftChild != NULL)
	{
		c = p->leftChild;
	}
	else
	{
		c = p->rightChild;
	}
	if (p == root)
	{
		root = c;
	}
	else
	{
		if (p == pp->leftChild)
		{
			pp->leftChild = c;
		}
		else
		{
			pp->rightChild = c;
		}
	}
	treeSize--;
	delete p;
}
binaryTreeNode* binarySearchTree::find2(int theKey)
{
	binaryTreeNode* currentNode = root;
	while (currentNode != NULL)
	{
		if (theKey < currentNode->key)
		{
			currentNode = currentNode->leftChild;
		}
		else if (theKey > currentNode->key)
		{
			currentNode = currentNode->rightChild;
		}
		else
		{
			return currentNode;
		}
	}
	return NULL;
}
binaryTreeNode* binarySearchTree::find(int theKey)
{// Return pointer to pair with smallest key >= theKey.
 // Return NULL if no element has key >= theKey.
   binaryTreeNode *currentNode = root;
   binaryTreeNode *bestElement = NULL; // element with smallest key
                                         // >= theKey found so far
   // search the tree
   if (find2(theKey) == NULL)
   {
   	while (currentNode != NULL)
   	{
      	// is currentNode->element a candidate?
      		if (currentNode->key >= theKey)
      		{
			// yes, currentNode->element is
       		// a better candidate than bestElement
	  		bestElement = new binaryTreeNode(currentNode->element, currentNode->key, currentNode->leftChild, currentNode->rightChild);
         		// smaller keys in left subtree only
         		currentNode = currentNode->leftChild;
	 	}
      		else{
         		// no, currentNode->element.first is too small
         		// try right subtree
         		currentNode = currentNode->rightChild;
      		}
   	}
   }
   else
   {
	bestElement = find2(theKey);
   }
   return bestElement;
}
