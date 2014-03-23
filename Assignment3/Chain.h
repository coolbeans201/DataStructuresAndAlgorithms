#include "Linearlist.h"
#include "ChainNode.h"
using namespace std;
class chain : public linearList
{
   public:
      // constructor, copy constructor and destructor
      chain(int initialCapacity = 10);
      chain(const chain&);
      ~chain();

      // ADT methods
      bool empty() const {return listSize == 0;}
      int size() const {return listSize;}
      int* get(int theIndex) const;
      int indexOf(const int& theElement) const;
      void erase(int theIndex);
      void insert(int theIndex, const int& theElement);
      void traverse();
      void MaxMin ();
   protected:
      void checkIndex(int theIndex) const;
            // throw illegalIndex if theIndex invalid
      chainNode* firstNode;  // pointer to first node in chain
      int listSize;             // number of elements in list
};
