#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
//Matthew Weingarten, 8189-1861
using namespace std;
int factorial (int n)
{
    if (n < 0)
    {
          cout<<"Incorrect argument: must be non-negative"<<endl;
          exit(1);
    }
    else if ((n == 0) || (n == 1))
    {
         return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

void print_factorial ()
{
     while (1)
     {
           string mystring;
           int x;
           cout<<"Please enter a number (or \'q\' to quit): ";
           getline(cin, mystring);
           if (mystring.compare("q") == 0)
           {
                                     break;
           }
           else
           {
               stringstream(mystring) >> x;
               cout<<x<<"! = "<<factorial(x)<<endl;
           }
     }
     cout<<"You have left the game!"<<endl;
}
#endif
