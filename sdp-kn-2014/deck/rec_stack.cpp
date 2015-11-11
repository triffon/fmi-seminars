#include <iostream>
#include <stack>

using namespace std;

#define MAZE_W 5
#define MAZE_H 5

int maze[MAZE_W][MAZE_H] = {0,1,0,0,0,
             	      		0,1,0,1,0,
			                0,1,0,1,0,
		                	0,0,0,1,0,
		                	1,1,1,1,0};
bool correct (int x, int y)
{
	return x >=0 && x < MAZE_W &&
	       y >=0 && y < MAZE_H &&
	       maze[x][y] == 0;
}
bool way (int x, int y, int targetX, int targetY)
{
	if (!correct (x,y))
		return false;

	if (x == targetX && y == targetY)
		return true;

	maze[x][y] = 2;

	return way (x,y-1,targetX,targetY) ||
		   way (x-1,y,targetX, targetY) ||
		   way (x+1,y,targetX,targetY) ||
		   way (x,y+1,targetX,targetY);
}

bool wayIter (int x, int y, int targetX, int targetY)
{

	stack<pair<int,int> >s;

	s.push (pair<int,int> (x,y));

	while (!s.empty() && 
		   (s.top().first != targetX ||
		   	s.top().second != targetY))
	{
		pair<int,int> current = s.top();
		s.pop();

		maze[current.first][current.second]=2;

		if (correct (current.first,current.second-1))
			s.push (pair<int,int> (current.first,current.second-1));
		if (correct (current.first-1,current.second))
			s.push (pair<int,int> (current.first-1,current.second));
		if (correct (current.first+1,current.second))
			s.push (pair<int,int> (current.first+1,current.second));
		if (correct (current.first,current.second+1))
			s.push (pair<int,int> (current.first,current.second+1));

	}

	return !s.empty();
}

void hanoi (int fromPile, int toPile, int tempPile, int k)
{

	if (k == 1)
	{
		cout << "Please move the top disk from " << fromPile << " to " << toPile << endl;
		return;
	}

	hanoi (fromPile,tempPile,toPile,k-1);
	hanoi (fromPile,toPile,tempPile,1);
	hanoi (tempPile,toPile,fromPile,k-1);

}


int main ()
{
	//cout << wayIter (0,0,4,4) << endl;

	hanoi (1,2,3,3);
}	

