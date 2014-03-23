//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 8147
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "BinPacking.h"
#include "BinaryTree.h"
using namespace std;
int main()
{
	BinPacking* b = new BinPacking();
	while (1)
	{
		cout<<"Please choose the algorithm for test (1 - Firstfit, 2 - Bestfit, 3 - Quit): "<<endl;
		string str1;
		getline(cin, str1);
		int choice;
		while (1)
		{
			if (stringstream(str1)>>choice)
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
		if (choice == 3)
		{
			cout<<"You have chose to quit the program."<<endl;
			break;
		}
		else if (choice == 1)
		{
			cout<<"Enter number of objects and bin capacity for Firstfit: "<<endl;
			string str2;
			getline(cin, str2);
			int numberOfObjects;
			while (1)
			{
				if (stringstream(str2)>>numberOfObjects)
                     	{
                           		break;
                     	}
                     	else
                     	{
                           		cout<<"Invalid value! Please enter a numerical value: ";
                           		cin.clear ();
                           		getline(cin, str2);
                           		cin.sync ();
				}
			}
			if (numberOfObjects < 2)
			{
				cout<<"Not enough objects. Program is quitting."<<endl;
				break;
			}
			string str3;
			int binCapacity;
			getline(cin, str3);
			while (1)
			{
				if (stringstream(str3)>>binCapacity)
                     	{
                           		break;
                     	}
                     	else
                     	{
                           		cout<<"Invalid value! Please enter a numerical value: ";
                           		cin.clear ();
                           		getline(cin, str3);
                           		cin.sync ();
				}
			}
			int* objectSize = new int [numberOfObjects + 1];
			int i;
			for (i = 1; i <= numberOfObjects; i++)
			{
				cout<<"Enter space requirement of object "<<i<<": "<<endl;
				string str4;
				getline(cin, str4);
				while (1)
				{
					if (stringstream(str4)>>objectSize[i])
                     		{
                           			break;
                     		}
                     		else
                     		{
                           			cout<<"Invalid value! Please enter a numerical value: ";
                           			cin.clear ();
                           			getline(cin, str4);
                           			cin.sync ();
					}
				}
				if (objectSize[i] > binCapacity)
				{
					cout<<"Object is too large to fit in a bin. Program is quitting."<<endl;
					exit(1);
				}
			}
			b->firstFitPack(objectSize, numberOfObjects, binCapacity);
		}
		else if (choice == 2)
		{
			cout<<"Enter number of objects and bin capacity for Bestfit: "<<endl;
			string str2;
			getline(cin, str2);
			int numberOfObjects;
			while (1)
			{
				if (stringstream(str2)>>numberOfObjects)
                     	{
                           		break;
                     	}
                     	else
                     	{
                           		cout<<"Invalid value! Please enter a numerical value: ";
                           		cin.clear ();
                           		getline(cin, str2);
                           		cin.sync ();
				}
			}
			if (numberOfObjects < 2)
			{
				cout<<"Not enough objects. Program is quitting."<<endl;
				break;
			}
			string str3;
			int binCapacity;
			getline(cin, str3);
			while (1)
			{
				if (stringstream(str3)>>binCapacity)
                     	{
                           		break;
                     	}
                     	else
                     	{
                           		cout<<"Invalid value! Please enter a numerical value: ";
                           		cin.clear ();
                           		getline(cin, str3);
                           		cin.sync ();
				}
			}
			int* objectSize = new int [numberOfObjects + 1];
			int i;
			for (i = 1; i <= numberOfObjects; i++)
			{
				cout<<"Enter space requirement of object "<<i<<": "<<endl;
				string str4;
				getline(cin, str4);
				while (1)
				{
					if (stringstream(str4)>>objectSize[i])
                     		{
                           			break;
                     		}
                     		else
                     		{
                           			cout<<"Invalid value! Please enter a numerical value: ";
                           			cin.clear ();
                           			getline(cin, str4);
                           			cin.sync ();
					}
				}
				if (objectSize[i] > binCapacity)
				{
					cout<<"Object is too large to fit in a bin. Program is quitting."<<endl;
					exit(1);
				}
			}
			b->bestFitPack(objectSize, numberOfObjects, binCapacity);
		}
		else
		{
			cout<<"You entered an invalid choice as your integer. Program is quitting."<<endl;
			break;
		}
	}
	return 0;
}