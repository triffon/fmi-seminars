#include <iostream>
#include <stack>
#include <queue>

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


vector<pair<int, int> > findWayRec (int x, int y, int targetX, int targetY)
{
	vector<pair<int, int> > result;

	if (!correct (x,y))
		//return an empty path: no path exists
		return result;
	
	result.push_back (pair<int,int>(x,y));

	if (x == targetX && y == targetY)
		return result;

	maze[x][y] = 2;

	vector<pair<int, int> > nextSteps;

	nextSteps = findWayRec (x,y-1,targetX,targetY);
	if (nextSteps.size () == 0)
		nextSteps = findWayRec (x-1,y,targetX, targetY); 	
	if (nextSteps.size () == 0)
		nextSteps = findWayRec (x+1,y,targetX,targetY);
	if (nextSteps.size () == 0)
		nextSteps = findWayRec (x,y+1,targetX,targetY);

	if (nextSteps.size() > 0)
	{
		nextSteps.push_back (pair<int,int>(x,y)); 
		return nextSteps;
	}
	
	return nextSteps;  
    
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


bool wayBfs (int x, int y, int targetX, int targetY)
{
	queue <pair<int,int> > q;

	q.push (pair<int,int> (x,y));

	while (!q.empty() && 
		   (q.front().first != targetX ||
		   	q.front().second != targetY))
	{
		pair<int,int> current = q.front();
		q.pop();

		if (correct (current.first,current.second-1))
		{
			q.push (pair<int,int> (current.first,current.second-1));
			maze[current.first][current.second-1]=10;
		}
		if (correct (current.first-1,current.second))
		{
			q.push (pair<int,int> (current.first-1,current.second));
			maze[current.first-1][current.second]=11;
		}
		if (correct (current.first+1,current.second))
		{
			q.push (pair<int,int> (current.first+1,current.second));
			maze[current.first+1][current.second]=12;
		}
		if (correct (current.first,current.second+1))
		{
			q.push (pair<int,int> (current.first,current.second+1));
			maze[current.first][current.second+1]=13;
		}

	}

	return !q.empty();
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

template <class T>
vector<T> tail (const vector<T> &v)
{
	vector<T> result = v;
	result.erase (result.begin());
	return result;
}

void printWay (const vector<pair<int, int> > &way)
{
	if (way.size() == 0) //(null? way)
		return;
	
	cout << "[" 
	     << way[0].first 
	     << "," 
	     << way[0].second 
	     << "]"; //car way
	
	printWay (tail(way)); //cdr way
}

void walkBack (int tx, int ty, int x, int y)
//намира кой е БИЛ пътят между x,y и tx,ty
{
	while (tx != x || ty != y)
	{
		cout << "[" << tx << "," << ty << "]";
		switch (maze[tx][ty])
		{
			case 10: ty++; break;
			case 11: tx++; break;
			case 12: tx--; break;
			case 13: ty--; break;
		}
	}
}

void cleanup ()
{
	for (int i = 0; i < MAZE_H; i++)
		for (int j = 0; j < MAZE_W; j++)
			if (maze[i][j] > 1)
				maze[i][j] = 0;
}

int main ()
{
	cout << wayIter (0,0,4,4) << endl;

	cleanup();

	cout << wayBfs (0,0,4,4) << endl;
	walkBack(4,4,0,0);

	cout << endl;

	cleanup();

	printWay (findWayRec (0,0,4,4));

	cout << endl;

	//hanoi (1,2,3,3);
}	

