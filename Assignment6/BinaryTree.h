//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 8147
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstddef>
#include <iostream>
#include <exception>
#include <functional>
using namespace std;
struct binaryTreeNode
{
   int element;
   int key;
   binaryTreeNode *leftChild, *rightChild; 
   binaryTreeNode() {leftChild = rightChild = NULL; element = key = 0;}
   binaryTreeNode(const int& theElement, const int& theKey)
   {
      leftChild = rightChild = NULL;
      element = theElement;
      key = theKey;
   }
   binaryTreeNode(const int& theElement, binaryTreeNode *theLeftChild, binaryTreeNode *theRightChild)
   {
      leftChild = theLeftChild;
      rightChild = theRightChild;
      element = theElement;
   }
   binaryTreeNode(const int& theElement, const int& theKey, binaryTreeNode *theLeftChild, binaryTreeNode *theRightChild)
   {
	element = theElement;
	key = theKey;
	leftChild = theLeftChild;
	rightChild = theRightChild;
   }
};
class binarySearchTree
{
	public:
		binarySearchTree(){root = NULL; treeSize = 0;}
		~binarySearchTree(){}
		void insert(int theElement, int theKey);
		void erase(int theKey);
		binaryTreeNode* find(int theKey);
		binaryTreeNode* find2(int theKey);
		binaryTreeNode* root;
		int size();
		bool empty();
		void inOrder(binaryTreeNode* t);
		int treeSize;
};
#endif