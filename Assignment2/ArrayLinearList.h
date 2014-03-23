#ifndef ARRAYLINEARLIST_H
#define ARRAYLINEARLIST_H
#include <iterator>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <exception>
using namespace std;
template<class T>
class linearList
{
      public:
             virtual ~linearList() {}
             virtual bool empty () const = 0;
             virtual int size() const = 0;
             virtual T& get(int theIndex) const = 0;
             virtual int indexOf(const T& theElement) const = 0;
             virtual void erase (int theIndex) = 0;
             virtual void insert(const T& theElement, int theIndex) = 0;
             virtual void output(ostream& out) const = 0;
};

template<class T>
class arrayList: public linearList<T>
{
      public:
             arrayList(int initialCapacity = 10000);
             arrayList(const arrayList<T>&);
             ~arrayList() {delete [] element;}
             bool empty() const{return listSize == 0;}
             int size() const {return listSize;}
             T& get(int theIndex) const;
             int indexOf(const T& theElement) const;
             void erase (int theIndex);
             void insert(const T& theElement, int theIndex);
             void output(ostream& out) const;
             void maxAndMin();
             int capacity() const {return arrayLength;}
      protected:
                void checkIndex (int theIndex) const;
                T* element;
                int arrayLength;
                int listSize;
};

template<class T>
arrayList<T>:: arrayList(int initialCapacity)
{
              if (initialCapacity < 1)
              {
                  throw exception ();
              }
              arrayLength = initialCapacity;
              element = new T[arrayLength];
              listSize = 0;
}

template<class T>
arrayList<T>:: arrayList(const arrayList<T>& theList)
{
               arrayLength = theList.arrayLength;
               listSize = theList.listSize;
               element = new T[arrayLength];
               copy (theList.element, theList.element + listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{
     if (theIndex < 0 || theIndex >= listSize)
     {
         throw exception ();
     }
}

template<class T>
T& arrayList<T>::get (int theIndex) const
{
                     checkIndex(theIndex);
                     return element[theIndex];
}

template <class T>
int arrayList<T>::indexOf(const T& theElement) const
{
    int theIndex = (int) (find(element, element + listSize, theElement) - element);
    if (theIndex == listSize)
    {
                 return -1;
    }
    else
    {
        return theIndex;
    }
}
template <class T>
void arrayList<T>::maxAndMin ()
{
     if (empty ())
     {
        cout<<"Empty list"<<endl;
        return;
     }
     int temp = element[0];
     int i;
     for (i = 1; i < listSize; i ++)
     {
         if (element [i] > temp)
         {
                     temp = element[i];
         }
     }
     cout<<"The max element is "<<temp<<endl;
     int temp2 = element[0];
     int j;
     for (j = 1; j < listSize; j ++)
     {
         if (element[j] < temp2)
         {
                        temp2 = element[j];
         }
     }
     cout<<"The min element is "<<temp2<<endl;
}

template <class T>
void arrayList<T>::erase (int theIndex)
{
     checkIndex(theIndex);
     copy(element + theIndex + 1, element + listSize, element + theIndex);
     element[--listSize].~T();
}

template <class T>
void arrayList<T>:: insert(const T& theElement, int theIndex)
{
     if (theIndex < 0 || theIndex > listSize)
     {
         throw exception ();
     }
     if (listSize == arrayLength)
     {
                  changeLength1D(element, arrayLength, 2 * arrayLength);
                  arrayLength *= 2;
     }
     copy_backward(element + theIndex, element + listSize, element + listSize + 1);
     element[theIndex] = theElement;
     listSize ++;
}

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
   if (newLength < 0)
   {
      throw exception ();
   }
   T* temp = new T[newLength];
   int number = min(oldLength, newLength);
   copy(a, a + number, temp);
   delete [] a;
   a = temp;
}

template<class T>
void arrayList<T>:: output(ostream& out) const
{
     copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}

template<class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
         x.output(out);
         return out;
}  
#endif
