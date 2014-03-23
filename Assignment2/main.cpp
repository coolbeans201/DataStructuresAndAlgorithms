#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include "ArrayLinearList.h"
using namespace std;
int main()
{
    arrayList<int> x;
    cout<<"Welcome! Please enter a command (I, D, E, P, S, M, Q to quit): ";
    string str;
    getline(cin, str);
    while ((str.compare("Q") != 0) || (str.compare("q") != 0))
    {
          if ((str.compare("I") == 0) || (str.compare("i") == 0))
          {
                                cout<<"Enter the value: ";
                                string str1;
                                getline(cin, str1);
                                int x1;
                                while (1)
                                {
                                		if (stringstream(str1)>>x1)
                                		{
                                		    break;
                                		}
                                		else
                                		{
                                			 cout<<"Invalid value! Please enter a numerical value: ";
                                			 cin.clear ();
                                			 getline(cin, str1);
                                	       cin.sync ();
                                	   }
                                }
                                cout<<"Enter the index: ";
                                string str2;
                                getline(cin, str2);
                                int x2;
                                while (1)
                                {
                                		if (stringstream(str2)>>x2)
                                		{
                                		    break;
                                		}
                                		else
                                		{
                                			 cout<<"Invalid index. Please enter a numerical value: ";
                                			 cin.clear ();
                                			 getline(cin, str2);
                                	       cin.sync ();
                                	   }
                                }
                                try
                                {
                                    x.insert (x1, x2);
                                    cout<<"You have inserted "<<x1<<" at position "<<x2<<endl;
                                    cout<<"The updated linear list is: ";
                                    x.output(cout);
                                    cout<<"\n";
                                }
                                catch (exception e)
                                {
                                    cout<<"Invalid index."<<endl;
                                }
          }
          else if ((str.compare("D") == 0) || (str.compare("d") == 0))
          {
                                cout<<"Enter the index: ";
                                string str1;
                                getline(cin, str1);
                                int x1;
                                while (1)
                                {
                                		if (stringstream(str1)>>x1)
                                		{
                                		    break;
                                		}
                                		else
                                		{
                                			 cout<<"Invalid index! Please enter a numerical value: ";
                                			 cin.clear ();
                                			 getline(cin, str1);
                                	       cin.sync ();
                                	   }
                                }
                                try
                                {
                                    x.erase (x1);
                                    cout<< "You have deleted index "<<x1<<endl;
                                    if (x.size () != 0)
                                    {
                                        cout<<"The updated linear list is: ";
                                        x.output(cout);
                                        cout<<endl;
                                    }
                                    else
                                    {
                                        cout<<"The linear list is now empty."<<endl;
                                    }
                                }
                                catch (exception e)
                                {
                                    cout<<"Invalid index."<<endl;
                                }
          }
          else if ((str.compare("P") == 0) || (str.compare("p") == 0))
          {
                                cout<<"The linear list is: ";
                                x.output(cout);
                                cout<<"\n";

          }
          else if ((str.compare("E") == 0) || (str.compare("e") == 0))
          {
                                cout<<"Enter the index: ";
                                string str1;
                                getline(cin, str1);
                                int x1;
                                while (1)
                                {
                                		if (stringstream(str1)>>x1)
                                		{
                                		    break;
                                		}
                                		else
                                		{
                                			 cout<<"Invalid index! Please enter a numerical value: ";
                                			 cin.clear ();
                                			 getline(cin, str1);
                                	       cin.sync ();
                                	   }
                                }
                                try
                                {
                                    int x2 = x.get(x1);
                                    cout<<"The element at index "<<x1<<" is "<<x2<<endl;
                                }
                                catch (exception e)
                                {
                                    cout<<"Invalid index."<<endl;
                                }
          }
          else if ((str.compare("S") == 0) || (str.compare("s") == 0))
          {
                                cout<<"The size of the linear list is: ";
                                cout<<x.size ()<<endl;
          }
          else if ((str.compare("M") == 0) || (str.compare("m") == 0))
          {
                                x.maxAndMin();
          }
          else if ((str.compare("Q") == 0) || (str.compare("q") == 0))
          {
                  cout<< "You have quit the program"<<endl;
                  break;
          }
          else
          {
          	      cout<<"You have entered an invalid command"<<endl;
          }
          cout<<"Please enter a command(I, D, E, P, S, M, Q to quit): ";
          string str1;
          getline(cin, str1);
          str = str1;     
    }
    getchar ();
    return 0;
}
