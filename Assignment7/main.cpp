//Name: Matthew Weingarten
//UFID:8189-1861
//Gatorlink: coolbeans201
//Discussion Section: 8147
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int getClosestUnmarkedNode(int n, int* dist, bool* marked)
{
	int minDistance = 100000;
	int closestUnmarkedNode;
	for (int i = 0; i < n; i ++)
	{
		if(!marked[i] && minDistance >= dist[i])
		{
			minDistance = dist[i];
			closestUnmarkedNode = i;
		}
	}
	return closestUnmarkedNode;
}
void printPath(int i, int s, int* predecessor)
{
	if (i == s)
	{
		cout<<i + 1<<"..";
	}
	else if (predecessor[i] == -1)
	{
		cout<<"No path from vertex "<<s + 1<<" to vertex "<<i + 1;
	}
	else
	{
		printPath(predecessor[i], s, predecessor);
		cout<<i + 1<<"..";
	}
}
void dijkstra(int s, int** distances, int n)
{
	int* predecessor = new int [n];
	int* dist = new int [n];
	bool* marked = new bool [n];
	for (int i = 0; i < n; i ++)
	{
		marked[i] = false;
		predecessor[i] = -1;
		dist[i] = 100000;
	}
	dist[s] = 0;
	int minDistance = 100000;
	int closestUnmarkedNode;
	int count = 0;
	while(count < n)
	{
		closestUnmarkedNode = getClosestUnmarkedNode(n, dist, marked);
		marked[closestUnmarkedNode] = true;
		for (int i = 0; i < n; i ++)
		{
			if(!marked[i] && distances[closestUnmarkedNode][i] > 0)
			{
				if (dist[i] > dist[closestUnmarkedNode] + distances[closestUnmarkedNode][i])
				{
					dist[i] = dist[closestUnmarkedNode] + distances[closestUnmarkedNode][i];
					predecessor[i] = closestUnmarkedNode;
				}
			}
		}
		count++;
	}
	for (int i = 0; i < n; i ++)
	{
		if (i == s)
		{
			cout<<s + 1<<".."<<s + 1;
		}
		else
		{
			printPath(i, s, predecessor);
		}
		cout<<"->"<<dist[i]<<endl;
	}
}
int main()
{
	int n;
	string str1;
	cout<<"Enter number of vertices in graph:"<<endl;
	getline(cin, str1);
	while (1)
	{
		if (stringstream(str1)>>n && n >= 1)
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
	int** distances = new int*[n];
	for (int i = 0; i < n; i ++)
	{
		distances[i] = new int [n];
	}
	bool** reachable = new bool*[n];
	for (int j = 0; j < n; j ++)
	{
		reachable[j] = new bool [n];
	}
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			reachable[i][j] = false;
			if (i != j)
			{
				distances[i][j] = 100000;
			}
			else
			{
				distances[i][j] = 0;
			}
		}
	}
	for (int k = 0; k < n; k ++)
	{
		int size;
		cout<<"Enter number of vertices reachable from vertex "<<k + 1<<": "<<endl;
		string str2;
		getline(cin, str2);
		while (1)
		{
			if (stringstream(str2)>>size && size >= 0)
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
		for (int l = 0; l < size; l ++)
		{
			cout<<"Enter vertex reachable from vertex "<<k + 1<<": "<<endl;
			int vertex;
			string str3;
			getline(cin, str3);
			while (1)
			{
				if (stringstream(str3)>> vertex && vertex <= n && vertex > 0 && vertex != k + 1 && (reachable[k][vertex - 1] == false))
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
			reachable[k][vertex - 1] = true;
			cout<<"Enter distance from vertex "<<k + 1<<" to vertex "<<vertex<<": "<<endl;
			int distance;
			string str4;
			getline(cin, str4);
			while (1)
			{
				if (stringstream(str4)>> distance && distance > 0 && distance < 100000)
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
		       distances[k][vertex - 1] = distance;	
		}
	}
	cout<<"Pick a source vertex: "<<endl;
	string str5;
	int source;
	getline(cin, str5);
	while (1)
	{
		if (stringstream(str5)>> source && source > 0 && source <= n)
              {
              		break;
              }
              else
              {
                    	cout<<"Invalid value! Please enter a numerical value: ";
                     cin.clear ();
                     getline(cin, str5);
                    	cin.sync ();
		}
	}
	cout<<endl;
	cout<<"Results of algorithm will be printed in the format of source vertex .. vertex it connects to .. -> distance of path"<<endl;
	cout<<endl;
	dijkstra(source - 1, distances, n);
	return 0;
}
