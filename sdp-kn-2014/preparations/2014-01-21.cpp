#include <iostream>


using namespcase std;


//да се построи множество от непресичащи се 
//покриващи дървета такива, че всеки връх на
//графа се съдържа в някое от тях
//да се отпечата суата на елементите на всяко
//от намерените дървета
bool sumOfVertices(const Graph<int>& g)
{

  vector<int> visited;
  LList<int> allVert = g.vertexes();

  elem_link1<int> *currentVert;

  while (visited.size() != allVert.length())
  {
  	
  	allVert.IterStart();
  	currentVert = allVert.Iter();

  	//цикъл за намиране на първия НЕПОСЕТЕН
  	//връх в g
  	while (currentVert != NULL && 
  		   visited.find() != visited.end())
  	{
  		currentVert = currentVert->next;
  	}

//  	cout << dfs (g,currentVert->inf, visited);
  		cout << bfs (g,currentVert->inf, visited);
  }

}

int bfs (const Graph<int> &g,T current,vector<int>& visited)
{
	Queue<int> q;

	visited.push_back (current);
	q.push_back (current);

	int sum = current;

	while (!q.empty())
	{
		current = q.top();
		q.pop();

		elem_link1<int> *p = g.point(current)->next;

		while (p != NULL)
		{
			if (visited.find(p->inf) == visited.end())
			{
				visited.push_back (p->inf);
				q.push_back (p->inf);
				sum += p->inf;
			}
			p = p->next;
		}		

	}

	return sum;
}

int dfs (const Graph<int> &g,int current,vector<int>& visited)
{
	visited.push_back (current);

	
	//намираме списък ит вс. съседи
	elem_link1<int> *p = g.point(current)->next;

	int sum = current;

	while (p != NULL)
	{
		if (visited.find(p->inf) == visited.end())
		{
			sum += dfs (g,p->current,visited);
		}
		p = p->next;
	}

	return sum;


}


struct TreeNode
{
	int a,b; //[a,b]
	TreeNode *left, *right;
	TreeNode (int _a, 
		      int _b, 
		      TreeNode *_left, 
		      TreeNode *_right):a(_a), 
								b(_b), 
								left (_left), 
								right (_right){}
};

void insert (TreeNode *& root, int a, int b)
{
	if (!root)
	{
		root = new TreeNode (a,b,NULL,NULL);
		return;
	}

	if (b-a < root->b - root->a)
	{
		insert (root->left,a,b);
	}

	insert (root->right,a,b);
}


TreeNode* insert2 (TreeNode *root, int a, int b)
{
	if (!root)
	{
		return new TreeNode (a,b,NULL,NULL);
	}

	if (b-a < root->b - root->a)
	{
		
		return new TreeNode (root->a, root->b,
							 insert2 (root->left,a,b),
							 root->right);

	}

	return new TreeNode (root->a, root->b,
						 root->left,
						 insert2 (root->right,a,b);
}


//приемаме, че дървото е непразно
Pair<int,int> minMax (TreeNode *root)
{
	assert (root != NULL);

	Pair result (root->a, root->b);

	Pair cResult; //child result

	if (root->left != NULL)
	{
		cResult = minMax (root->left);

		result.first = min (result.first, cResult.first);
		result.second = max (result.second, cResult.second);

	}

	if (root->right != NULL)
	{
		cResult = minMax (root->right);

		result.first = min (result.first, cResult.first);
		result.second = max (result.second, cResult.second);

	}

	return result;

}

int commonVert (LList<LList<int> >g,int a, int b)
{


}

vector<vector<int> > 
			findAllWays (LList<LList<int> >g,
				  		 int a, 
				  		 int b, vector<int> visited)
{

	vector<vector<int> >result;

	visited.push_back (a);

	if (a == b)
	{
		vector<int> pathAB;
		pathAB.push_back(a);
		result.push_back (pathAB);
		return result;
	}

	//намираме списък от вс. съседи
	elem_link1<int> *p = g.point(a)->next;

	while (p != NULL)
	{
		if (visited.find(p->inf) == visited.end())
		{
			vector<vector<int> >subPaths 
			       = findAllWays (g,p->inf,b,visited);

			for (int i = 0; i < subPaths.size(); i++)
			{
				subPaths[i].push(a);
				result.push_back (subPaths[i]);
			}

		}
		p = p->next;
	}

	return result;	

}


