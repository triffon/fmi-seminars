#include <iostream>
#include <vector>
#include <fstream>
#include <assert.h>


using namespace std;

	/*
		Дърво е:
		1/ Празното дърво е дърво
		2/ Нека t1,...,tk са дървета, а x e елемент, тогава
		   структурата от данни
		          x
		      / | ... \
		     t1 t2 ..  tk

		   наричам дърво с корен x и поддървета t1,...tk
	*/
template <class ElemType>
struct TreeNode
{
	ElemType x;
	vector<TreeNode<ElemType>* > children;
	int uid;
	TreeNode ()
	{
		static int currentId = 0;
		uid = currentId;
		currentId++;
	}
};

template <class T>
class Tree
{

private:
	TreeNode<T> *root;
public:
	Tree ():root (NULL)
	{}

	Tree (const Tree<T>& t)
	{
		root = copyTree (t.root);
	}

	Tree<T>& operator = (const Tree<T> &t)
	{
		if (this != &t)
		{
			destroy (root);
			root = copyTree (t.root);		
		}

		return *this;
	}

	~Tree ()
	{
		destroy (root);
	}

	bool empty ()
	{
		return root == NULL;
	}

	void setRoot (const T& newRoot)
	{	
		/*
			Tree<int> t;
			t.setRoot (2);
			t.setRoot (3);
		*/

		if (root == NULL)
		{
			root = new TreeNode<T>;
		}
		root->x = newRoot;
	}

	void addSubTree (const Tree<T>& t)
	{
		assert (root != NULL);

		root->children.push_back (copyTree(t.root));
	}

	void print (ostream &out)
	{
		out << "digraph{" << endl;
		printNode (out,root);
		out << "}";
	}

private:

	void printNode (ostream &out,const TreeNode<T> *currentNode)
	{
		if (currentNode == NULL)
			return;

		out << currentNode->uid 
		    << "[label=\"val=" 
		    << currentNode->x
		    << "\"];" 
		    << endl; 

		for (int i = 0; i < currentNode->children.size(); i++)
			if (currentNode->children[i] != NULL)
			{
				out << currentNode->uid 
				    << " -> " 
				    << currentNode->children[i]->uid 
				    << endl;

				printNode (out, currentNode->children[i]);	
			}


	}

	void destroy (const TreeNode<T> *currentNode)
	{
		if (currentNode == NULL)
			return;

		for (int i = 0; i < currentNode->children.size(); i++)
		{
			destroy (currentNode->children[i]);
		}
		
		delete currentNode;

	}


	TreeNode<T> *copyTree (const TreeNode<T> *currentNode)
	{
		if (currentNode == NULL)
			return NULL;

		TreeNode<T> *newNode = new TreeNode<T>;

		newNode->x = currentNode->x;

		for (int i = 0; i < currentNode->children.size(); i++)
		{
			newNode->children.push_back (copyTree(currentNode->children[i]));
		}	

		return newNode;
	}
};


int main ()
{



	Tree<int> t,t1,t2,t3;

	
	t1.setRoot (1);
	t2.setRoot (2);
	t3.setRoot (1);
	t2.addSubTree (t3);

	if (t.empty())
		cout << "empty" << endl;


	t.setRoot (7);

	t.addSubTree (t1);
	t.addSubTree (t2);

	ofstream dotfile ("result.dot");

	t3.setRoot (2000);

	t.print (dotfile);



}