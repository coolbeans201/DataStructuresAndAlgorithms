#include "ChainNode.h"
using namespace std;
 chainNode::chainNode(const int& element)
 {
     this->element = element;
 }
 chainNode::chainNode(const int& element, chainNode* next)
 {
     this->element = element;
     this->next = next;
 }
