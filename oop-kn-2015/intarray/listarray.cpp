#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;


struct ListNode
{
	int data;
	ListNode* next;

	ListNode (int _d, ListNode *_n):data(_d), next (_n)
	{
		//!!!
		//data = _d;
		//next = _n;
	}


};

class ListIntArray
{

private:

	ListNode *first;

public:

	
	IntArray (const IntArray &original)
	{
	}

	IntArray ()
	{
		first = NULL;
	}

	void push (int newelement)
	{
		first = new ListNode (newelement,first);
	}

	void toEnd(int newelement)
	{
	}

	void print()
	{
	}


	int& operator [] (int index)
	{	
	}


	~IntArray()
	{
	}


	IntArray operator + (const IntArray other)
	{
	}


	IntArray& operator = (const IntArray other)
	{
	}
};



int main ()
{



}