//Name: Matthew Weingarten
//UFID: 8189-1861
//Gatorlink ID: coolbeans201
//Discussion Section: 1087
#include "RatinMaze.h"
using namespace std;
bool RatInMaze::isValid (int x, int y)
{
	if ((x < 0) || (x >= rows) || (y < 0) || (y >= cols))
	{
		return false;
	}
	return true;
}
bool RatInMaze:: isIntValid (int x, int y)
{
	if ((x < 0) || (x >= rows) || (y < 0) || (y >= cols))
	{
		return false;
	}
	else if ((mazeInt[x][y] == -1) || (mazeInt[x][y] > 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int RatInMaze::smallestNeighbor(int x, int y)
{
	int z = 100000;
	if (isValid(y + 1, x) && mazeInt[y + 1][x] >= 0 && mazeInt[y + 1][x] < z)
	{
		z = mazeInt[y + 1][x];
	}
	if (isValid(y, x + 1) && mazeInt[y][x + 1] >= 0 && mazeInt[y][x + 1] < z)
	{
		z = mazeInt[y][x + 1];
	}
	if (isValid(y - 1, x) && mazeInt[y - 1][x] >= 0 && mazeInt[y - 1][x] < z)
	{
		z = mazeInt[y - 1][x];
	}
	if (isValid(y, x - 1) && mazeInt[y][x - 1] >= 0 && mazeInt[y][x - 1] < z)
	{
		z = mazeInt[y][x - 1];
	}
	return z;
}
void RatInMaze:: makeIntArray ()
{
	mazeInt = new int*[rows];
	int x;
	for (x = 0; x < rows; x++)
	{
		mazeInt[x] = new int[cols];
	}
	int i, j;
	for (i = 0; i < rows; i ++)
	{
		for (j = 0; j < cols; j ++)
		{
			if (maze1[i][j] == '1')
			{
				mazeInt[i][j] = -2;
			}
			else
			{
				mazeInt[i][j] = -1;
			}
		}
	}
}
bool RatInMaze::searchStack(int fromX, int fromY, int toX, int toY)
{
	traveled = 1;
	pathLength = 1;
	xCoord = new derivedArrayStack();
	yCoord = new derivedArrayStack();
	if(!isValid(fromY, fromX))
	{
		cout<<"Starting point is not inside the maze!"<<endl;
		return false;
	}
	if(!isValid(toY, toX))
	{
		cout<<"Ending point is not inside the maze!"<<endl;
		return false;
	}
	maze1[fromY][fromX] = '2';
	xCoord->push(fromX);
	yCoord->push(fromY);
	while ((!xCoord->empty()) && (!yCoord->empty ()))
	{
		if ((isValid(yCoord->top (), xCoord->top () + 1)) && maze1[yCoord->top ()][xCoord->top () + 1] == '0')
		{
			if (((xCoord->top () + 1 == toX) && (yCoord->top () == toY)))
			{
				maze1[yCoord->top ()][xCoord->top() + 1] = '2';
				traveled++;
				pathLength++;
				delete xCoord;
				delete yCoord;
				return true;
			}
			traveled++;
			pathLength++;
			//cout<<"first"<<yCoord->top ()<<","<<xCoord->top () + 1<<endl;
			xCoord->push(xCoord->top () + 1);
			yCoord->push(yCoord->top ());
			maze1[yCoord->top ()][xCoord->top ()] = '2';
		}
		else if ((isValid(yCoord->top () + 1, xCoord->top ())) && maze1[yCoord->top () + 1][xCoord->top ()] == '0')
		{
			if (((xCoord->top () == toX) && (yCoord->top () + 1 == toY)))
			{
				maze1[yCoord->top () + 1][xCoord->top()] = '2';
				traveled++;
				pathLength++;
				delete xCoord;
				delete yCoord;
				return true;
			}
			traveled++;
			pathLength++;
			//cout<<"second"<<yCoord->top () + 1<<","<<xCoord->top ()<<endl;
			xCoord->push(xCoord->top ());
			yCoord->push(yCoord->top () + 1);
			maze1[yCoord-> top ()][xCoord->top ()] = '2';
		}
		else if (isValid(yCoord->top (), xCoord->top () - 1) && maze1[yCoord->top ()][xCoord->top () - 1] == '0')
		{
			if (((xCoord->top () - 1 == toX) && (yCoord->top () == toY)))
			{
				maze1[yCoord->top ()][xCoord->top() - 1] = '2';
				traveled++;
				pathLength++;
				delete xCoord;
				delete yCoord;
				return true;
			}
			traveled++;
			pathLength++;
			//cout<<"third"<<yCoord->top ()<<","<<xCoord->top () - 1<<endl;
			xCoord->push(xCoord->top () - 1);
			yCoord->push(yCoord->top ());
			maze1[yCoord->top ()][xCoord->top ()] = '2';
		}
		else if (isValid(yCoord->top () - 1, xCoord->top ()) && maze1[yCoord->top () - 1][xCoord->top ()] == '0')
		{
			if (((xCoord->top () == toX) && (yCoord->top () - 1 == toY)))
			{
				maze1[yCoord->top () - 1][xCoord->top()] = '2';
				traveled++;
				pathLength++;
				delete xCoord;
				delete yCoord;
				return true;
			}
			traveled++;
			pathLength++;
			xCoord->push(xCoord->top ());
			yCoord->push(yCoord->top () - 1);
			maze1[yCoord->top ()][xCoord->top ()] = '2';
			//cout<<"fourth"<<yCoord->top () - 1<<","<<xCoord->top ()<<endl;
		}
		else
		{
			//cout<<"fifth"<<yCoord->top ()<<","<<xCoord->top ()<<endl;
			maze1[yCoord->top ()][xCoord->top ()] = '3';
			pathLength --;
			xCoord->pop ();
			yCoord->pop ();
		}
	}
	delete xCoord;
	delete yCoord;
	return false;
}
bool RatInMaze::searchQueue(int fromX,int fromY,int toX,int toY)
{
	if(!isValid(fromY, fromX))
	{
		cout<<"Starting point is not inside the maze!"<<endl;
		return false;
	}
	if(!isValid(toY, toX))
	{
		cout<<"Ending point is not inside the maze!"<<endl;
		return false;
	}
	traveled = 1;
	pathLength = 1;
	makeIntArray ();
	xCoord1 = new arrayQueue ();
	yCoord1 = new arrayQueue ();
	maze1[fromY][fromX] = '2';
	xCoord1->push(fromX);
	yCoord1->push(fromY);
	mazeInt[fromY][fromX] = 1;
	while ((!xCoord1->empty ()) && (!yCoord1->empty ()) && ((xCoord1->front() != toX) || (yCoord1->front() != toY)))
	{
		//cout<<yCoord1->front()<<", "<<xCoord1->front()<<endl;
		if (isIntValid(yCoord1->front(), xCoord1->front() + 1) && mazeInt[yCoord1->front()][xCoord1->front() + 1] == -1)
		{
			int smallestNeighbor1 = smallestNeighbor(xCoord1->front() + 1, yCoord1->front());
			xCoord1->push(xCoord1->front() + 1);
			yCoord1->push(yCoord1->front());
			traveled++;
			if (mazeInt[yCoord1->front()][xCoord1->front() + 1] > smallestNeighbor1 + 1 || mazeInt[yCoord1->front()][xCoord1->front () + 1] < 0)
			{
				mazeInt[yCoord1->front()][xCoord1->front() + 1] = smallestNeighbor1 + 1;
			}	
		}
		if (isIntValid(yCoord1->front() + 1, xCoord1->front()) && mazeInt[yCoord1->front() + 1][xCoord1->front()] == -1)
		{
			int smallestNeighbor1 = smallestNeighbor(xCoord1->front(), yCoord1->front() + 1);
			xCoord1->push(xCoord1->front());
			yCoord1->push(yCoord1->front() + 1);
			traveled++;
			if (mazeInt[yCoord1->front() + 1][xCoord1->front()] > smallestNeighbor1 + 1 || mazeInt[yCoord1->front() + 1][xCoord1->front ()] < 0)
			{
				mazeInt[yCoord1->front() + 1][xCoord1->front()] = smallestNeighbor1 + 1;
			}	
		}
		if (isIntValid(yCoord1->front(), xCoord1->front() - 1) && mazeInt[yCoord1->front()][xCoord1->front() - 1] == -1)
		{
			int smallestNeighbor1 = smallestNeighbor(xCoord1->front() - 1, yCoord1->front());
			xCoord1->push(xCoord1->front() - 1);
			yCoord1->push(yCoord1->front());
			traveled++;
			if (mazeInt[yCoord1->front()][xCoord1->front() - 1] > smallestNeighbor1 + 1 || mazeInt[yCoord1->front()][xCoord1->front () - 1] < 0)
			{
				mazeInt[yCoord1->front()][xCoord1->front() - 1] = smallestNeighbor1 + 1;
			}	

		}
		if (isIntValid(yCoord1->front() - 1, xCoord1->front()) && mazeInt[yCoord1->front() - 1][xCoord1->front()] == -1)
		{
			int smallestNeighbor1 = smallestNeighbor(xCoord1->front(), yCoord1->front() - 1);
			xCoord1->push(xCoord1->front());
			yCoord1->push(yCoord1->front() - 1);
			traveled++;
			if (mazeInt[yCoord1->front() - 1][xCoord1->front()] > smallestNeighbor1 + 1 || mazeInt[yCoord1->front() - 1][xCoord1->front ()] < 0)
			{
				mazeInt[yCoord1->front() - 1][xCoord1->front()] = smallestNeighbor1 + 1;
			}	
		}
		xCoord1->pop();
		yCoord1->pop();
	}
	if (mazeInt[toY][toX] > 0)
	{
		pathLength = mazeInt[toY][toX];
		int currentX = toX;
		int currentY = toY;
		int currentCount = pathLength;
		maze1[toY][toX] = '2';
		for (int i = pathLength; i > 0; i --)
		{
			if (isIntValid(currentY + 1, currentX) && mazeInt[currentY + 1][currentX] < i && mazeInt[currentY + 1][currentX] >= 0)
			{
				currentY += 1;
				currentCount = mazeInt[currentY][currentX];
			}
			else if (isIntValid(currentY, currentX + 1) && mazeInt[currentY][currentX + 1] < i && mazeInt[currentY][currentX + 1] >= 0)
			{
				currentX += 1;
				currentCount = mazeInt[currentY][currentX];
			}
			else if (isIntValid(currentY - 1, currentX) && mazeInt[currentY - 1][currentX] < i && mazeInt[currentY - 1][currentX] >= 0)
			{
				currentY -= 1;
				currentCount = mazeInt[currentY][currentX];
			}
			else if (isIntValid(currentY, currentX - 1) && mazeInt[currentY][currentX - 1] < i && mazeInt[currentY][currentX - 1] >= 0)
			{
				currentX -= 1;
				currentCount = mazeInt[currentY][currentX];
			}
			maze1[currentY][currentX] = '2';
		}
		delete xCoord1;
		delete yCoord1;
		return true;
	}
	else
	{
		delete xCoord1;
		delete yCoord1;
		return false;
	}
}
bool RatInMaze::searchStackSmart(int fromX,int fromY,int toX,int toY)
{
	traveled = 1;
	pathLength = 1;
	xCoord = new derivedArrayStack ();
	yCoord = new derivedArrayStack ();
	if(!isValid(fromY, fromX))
	{
		cout<<"Starting point is not inside the maze!"<<endl;
		return false;
	}
	if(!isValid(toY, toX))
	{
		cout<<"Ending point is not inside the maze!"<<endl;
		return false;
	}
	maze1[fromY][fromX] = '2';
	xCoord->push(fromX);
	yCoord->push(fromY);
	while ((!xCoord->empty ()) && (!yCoord->empty ()))
	{
		int dx = toX - xCoord->top ();
		int dy = toY - yCoord->top ();
		if (dx > 0 && dy > 0)
		{
			      if ((isValid(yCoord->top () + 1, xCoord->top ())) && maze1[yCoord->top () + 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () + 1 == toY)))
					{
						maze1[yCoord->top () + 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"first"<<yCoord->top () + 1<<","<<xCoord->top ()<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () + 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if ((isValid(yCoord->top (), xCoord->top () + 1)) && maze1[yCoord->top ()][xCoord->top () + 1] == '0')
				{
					if (((xCoord->top () + 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () + 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"second"<<yCoord->top ()<<","<<xCoord->top () + 1<<endl;
					xCoord->push(xCoord->top () + 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord-> top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top () - 1, xCoord->top ()) && maze1[yCoord->top () - 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () - 1 == toY)))
					{
						maze1[yCoord->top () - 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"third"<<yCoord->top ()<<","<<xCoord->top () - 1<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () - 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top (), xCoord->top () - 1) && maze1[yCoord->top ()][xCoord->top () - 1] == '0')
				{
					if (((xCoord->top () - 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () - 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					xCoord->push(xCoord->top () - 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
					//cout<<"fourth"<<yCoord->top () - 1<<","<<xCoord->top ()<<endl;
				}
				else
				{
					//cout<<"fifth"<<yCoord->top ()<<","<<xCoord->top ()<<endl;
					maze1[yCoord->top ()][xCoord->top ()] = '3';
					pathLength --;
					xCoord->pop ();
					yCoord->pop ();
				}
		}
		else if (dx > 0 && dy < 0)
		{
				if ((isValid(yCoord->top () - 1, xCoord->top ())) && maze1[yCoord->top () - 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () - 1 == toY)))
					{
						maze1[yCoord->top () - 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"first"<<yCoord->top () - 1<<","<<xCoord->top ()<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () - 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if ((isValid(yCoord->top (), xCoord->top () + 1)) && maze1[yCoord->top ()][xCoord->top () + 1] == '0')
				{
					if (((xCoord->top () + 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () + 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"second"<<yCoord->top ()<<","<<xCoord->top () + 1<<endl;
					xCoord->push(xCoord->top () + 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord-> top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top () + 1, xCoord->top ()) && maze1[yCoord->top () + 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () + 1 == toY)))
					{
						maze1[yCoord->top () + 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"third"<<yCoord->top ()<<","<<xCoord->top () - 1<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () + 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top (), xCoord->top () - 1) && maze1[yCoord->top ()][xCoord->top () - 1] == '0')
				{
					if (((xCoord->top () - 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () - 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					xCoord->push(xCoord->top () - 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
					//cout<<"fourth"<<yCoord->top () + 1<<","<<xCoord->top ()<<endl;
				}
				else
				{
					//cout<<"fifth"<<yCoord->top ()<<","<<xCoord->top ()<<endl;
					maze1[yCoord->top ()][xCoord->top ()] = '3';
					pathLength --;
					xCoord->pop ();
					yCoord->pop ();
				}
		}
		else if (dx < 0 && dy > 0)
		{
				if ((isValid(yCoord->top () + 1, xCoord->top ())) && maze1[yCoord->top () + 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () + 1 == toY)))
					{
						maze1[yCoord->top () + 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"first"<<yCoord->top () + 1<<","<<xCoord->top ()<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () + 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if ((isValid(yCoord->top (), xCoord->top () - 1)) && maze1[yCoord->top ()][xCoord->top () - 1] == '0')
				{
					if (((xCoord->top () - 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () - 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"second"<<yCoord->top ()<<","<<xCoord->top () - 1<<endl;
					xCoord->push(xCoord->top () - 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord-> top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top () - 1, xCoord->top ()) && maze1[yCoord->top () - 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () - 1 == toY)))
					{
						maze1[yCoord->top () - 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"third"<<yCoord->top ()<<","<<xCoord->top () + 1<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () - 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top (), xCoord->top () + 1) && maze1[yCoord->top ()][xCoord->top () + 1] == '0')
				{
					if (((xCoord->top () + 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () + 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					xCoord->push(xCoord->top () + 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
					//cout<<"fourth"<<yCoord->top () + 1<<","<<xCoord->top ()<<endl;
				}
				else
				{
					//cout<<"fifth"<<yCoord->top ()<<","<<xCoord->top ()<<endl;
					maze1[yCoord->top ()][xCoord->top ()] = '3';
					pathLength --;
					xCoord->pop ();
					yCoord->pop ();
				}
		}
		else if (dx < 0 && dy < 0)
		{
				if ((isValid(yCoord->top () - 1, xCoord->top ())) && maze1[yCoord->top () - 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () - 1 == toY)))
					{
						maze1[yCoord->top () - 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"first"<<yCoord->top () - 1<<","<<xCoord->top ()<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () - 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if ((isValid(yCoord->top (), xCoord->top () - 1)) && maze1[yCoord->top ()][xCoord->top () - 1] == '0')
				{
					if (((xCoord->top () - 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () - 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"second"<<yCoord->top ()<<","<<xCoord->top () - 1<<endl;
					xCoord->push(xCoord->top () - 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord-> top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top () + 1, xCoord->top ()) && maze1[yCoord->top () + 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () + 1 == toY)))
					{
						maze1[yCoord->top () + 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"third"<<yCoord->top ()<<","<<xCoord->top () + 1<<endl;
					xCoord->push(xCoord->top () + 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top (), xCoord->top () + 1) && maze1[yCoord->top ()][xCoord->top () + 1] == '0')
				{
					if (((xCoord->top () + 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () + 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					xCoord->push(xCoord->top () + 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
					//cout<<"fourth"<<yCoord->top () + 1<<","<<xCoord->top ()<<endl;
				}
				else
				{
					//cout<<"fifth"<<yCoord->top ()<<","<<xCoord->top ()<<endl;
					maze1[yCoord->top ()][xCoord->top ()] = '3';
					pathLength --;
					xCoord->pop ();
					yCoord->pop ();
				}
		}
		else if (dx == 0 && dy > 0)
		{
				if ((isValid(yCoord->top () + 1, xCoord->top ())) && maze1[yCoord->top () + 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () + 1 == toY)))
					{
						maze1[yCoord->top () + 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"first"<<yCoord->top () + 1<<","<<xCoord->top ()<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () + 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if ((isValid(yCoord->top (), xCoord->top () + 1)) && maze1[yCoord->top ()][xCoord->top () + 1] == '0')
				{
					if (((xCoord->top () + 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () + 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"second"<<yCoord->top ()<<","<<xCoord->top () - 1<<endl;
					xCoord->push(xCoord->top () + 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord-> top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top (), xCoord->top () - 1) && maze1[yCoord->top ()][xCoord->top () - 1] == '0')
				{
					if (((xCoord->top () - 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () - 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"third"<<yCoord->top ()<<","<<xCoord->top () + 1<<endl;
					xCoord->push(xCoord->top () - 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top () - 1, xCoord->top ()) && maze1[yCoord->top () - 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () - 1 == toY)))
					{
						maze1[yCoord->top () - 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () - 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
					//cout<<"fourth"<<yCoord->top () - 1<<","<<xCoord->top ()<<endl;
				}
				else
				{
					//cout<<"fifth"<<yCoord->top ()<<","<<xCoord->top ()<<endl;
					maze1[yCoord->top ()][xCoord->top ()] = '3';
					pathLength --;
					xCoord->pop ();
					yCoord->pop ();
				}
		}
		else if (dx == 0 && dy < 0)
		{
				if ((isValid(yCoord->top () - 1, xCoord->top ())) && maze1[yCoord->top () - 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () - 1 == toY)))
					{
						maze1[yCoord->top () - 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"first"<<yCoord->top () - 1<<","<<xCoord->top ()<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () - 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if ((isValid(yCoord->top (), xCoord->top () + 1)) && maze1[yCoord->top ()][xCoord->top () + 1] == '0')
				{
					if (((xCoord->top () + 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () + 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"second"<<yCoord->top ()<<","<<xCoord->top () - 1<<endl;
					xCoord->push(xCoord->top () + 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord-> top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top (), xCoord->top () - 1) && maze1[yCoord->top ()][xCoord->top () - 1] == '0')
				{
					if (((xCoord->top () - 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () - 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"third"<<yCoord->top ()<<","<<xCoord->top () + 1<<endl;
					xCoord->push(xCoord->top () - 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top () + 1, xCoord->top ()) && maze1[yCoord->top () + 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () + 1 == toY)))
					{
						maze1[yCoord->top () + 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () + 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
					//cout<<"fourth"<<yCoord->top () + 1<<","<<xCoord->top ()<<endl;
				}
				else
				{
					//cout<<"fifth"<<yCoord->top ()<<","<<xCoord->top ()<<endl;
					maze1[yCoord->top ()][xCoord->top ()] = '3';
					pathLength --;
					xCoord->pop ();
					yCoord->pop ();
				}
		}
		else if (dx < 0 && dy == 0)
		{
				if ((isValid(yCoord->top (), xCoord->top () - 1)) && maze1[yCoord->top ()][xCoord->top () - 1] == '0')
				{
					if (((xCoord->top () - 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () - 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"first"<<yCoord->top ()<<","<<xCoord->top () - 1<<endl;
					xCoord->push(xCoord->top () - 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if ((isValid(yCoord->top () + 1, xCoord->top ())) && maze1[yCoord->top () + 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () + 1 == toY)))
					{
						maze1[yCoord->top () + 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"second"<<yCoord->top () + 1<<","<<xCoord->top ()<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () + 1);
					maze1[yCoord-> top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top () - 1, xCoord->top ()) && maze1[yCoord->top () - 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () - 1 == toY)))
					{
						maze1[yCoord->top () - 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"third"<<yCoord->top () - 1<<","<<xCoord->top ()<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () - 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top (), xCoord->top () + 1) && maze1[yCoord->top ()][xCoord->top () + 1] == '0')
				{
					if (((xCoord->top () + 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () + 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					xCoord->push(xCoord->top () + 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
					//cout<<"fourth"<<yCoord->top ()<<","<<xCoord->top () + 1<<endl;
				}
				else
				{
					//cout<<"fifth"<<yCoord->top ()<<","<<xCoord->top ()<<endl;
					maze1[yCoord->top ()][xCoord->top ()] = '3';
					pathLength --;
					xCoord->pop ();
					yCoord->pop ();
				}
		}
		else
		{
			if ((isValid(yCoord->top (), xCoord->top () + 1)) && maze1[yCoord->top ()][xCoord->top () + 1] == '0')
				{
					if (((xCoord->top () + 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () + 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"first"<<yCoord->top ()<<","<<xCoord->top () + 1<<endl;
					xCoord->push(xCoord->top () + 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if ((isValid(yCoord->top () + 1, xCoord->top ())) && maze1[yCoord->top () + 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () + 1 == toY)))
					{
						maze1[yCoord->top () + 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"second"<<yCoord->top () + 1<<","<<xCoord->top ()<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () + 1);
					maze1[yCoord-> top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top () - 1, xCoord->top ()) && maze1[yCoord->top () - 1][xCoord->top ()] == '0')
				{
					if (((xCoord->top () == toX) && (yCoord->top () - 1 == toY)))
					{
						maze1[yCoord->top () - 1][xCoord->top ()] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					//cout<<"third"<<yCoord->top () - 1<<","<<xCoord->top ()<<endl;
					xCoord->push(xCoord->top ());
					yCoord->push(yCoord->top () - 1);
					maze1[yCoord->top ()][xCoord->top ()] = '2';
				}
				else if (isValid(yCoord->top (), xCoord->top () - 1) && maze1[yCoord->top ()][xCoord->top () - 1] == '0')
				{
					if (((xCoord->top () - 1 == toX) && (yCoord->top () == toY)))
					{
						maze1[yCoord->top ()][xCoord->top () - 1] = '2';
						traveled++;
						pathLength++;
						delete xCoord;
						delete yCoord;
						return true;
					}
					traveled++;
					pathLength++;
					xCoord->push(xCoord->top () - 1);
					yCoord->push(yCoord->top ());
					maze1[yCoord->top ()][xCoord->top ()] = '2';
					//cout<<"fourth"<<yCoord->top ()<<","<<xCoord->top () - 1<<endl;
				}
				else
				{
					//cout<<"fifth"<<yCoord->top ()<<","<<xCoord->top ()<<endl;
					maze1[yCoord->top ()][xCoord->top ()] = '3';
					pathLength --;
					xCoord->pop ();
					yCoord->pop ();
				}
		}
	}
	delete xCoord;
	delete yCoord;
	return false;
}

void RatInMaze::load (char maze[][15], int row, int col)
{
	rows = row;
	cols = col;
	maze1 = new char*[row];
	int x;
	for (x = 0; x < rows; x++)
		maze1[x] = new char[cols];
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			maze1[i][j] = maze[i][j];
		}
	}
}

void RatInMaze::print(bool search)
{
	if (!search)
	{
		cout<<"Search canceled."<<endl;
		return;
	}
	else
	{
		int i, j;
		for (i = 0; i < rows; i ++)
		{
			for (j = 0; j < cols; j++)
			{
				if (maze1[i][j] == '3')
				{
					maze1[i][j] = '0';
				}
				cout<<maze1[i][j]<<" ";
			}
			cout<<endl;
		}	
		cout<<"I've traveled through "<<traveled<<" square(s). The path contains "<<pathLength<<" square(s)."<<endl;
	}	
}