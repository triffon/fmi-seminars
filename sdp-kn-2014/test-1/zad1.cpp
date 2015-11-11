#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stack>
#include <assert.h>
#include <map>


using namespace std;

struct Employee {
    char name[128]; //трите именa
	unsigned short employmentYear; //година на постъпване на служителя на работа short departureYear; //година на напускане. -1 ако служителят е все още на работа
	short departureYear;


	Employee (){}
	Employee (char *n, unsigned short y, short dep):employmentYear(y), departureYear (dep)
	{
		strcpy (name,n);
	}
};

ostream& operator << (ostream& out, const Employee &e)
{
	return out << left 
	           << setw (40) 
	           << e.name  
	           << e.departureYear - e.employmentYear << endl;
}

void binToText (ostream& out)
{
	ifstream in ("data.bin",ios::binary | ios::in);

	Employee data;

	while (in.read ((char*)&data,sizeof(Employee)))
	{
		
		out << data;
	}
}

bool isDigit (char c)
{
	return c >= '0' && c <= '9';
}

string convert (string expr)
{
	stack<string> s;

	for (int i = 0; i < expr.size(); i++)
	{
		string tmp;
		tmp += expr[i];
		if (isDigit (expr[i]))
			s.push (tmp); 
		else
		{
			string rightOp = s.top ();
			s.pop();
			string leftOp = s.top ();
			s.pop();
			s.push ("(" + leftOp + expr[i] + rightOp + ")");
		}
	}

	return s.top();
}

typedef int (*pFunct) (int,int);

int _plus (int x, int y) {return x+y;}
int _minus (int x, int y) {return x-y;}
int _mult (int x, int y) {return x*y;}
int _divide (int x, int y) {return x/y;}
int _quot (int x, int y) {return x%y;}

int evaluate (string expr)
{

	map<char,pFunct> functions;

	functions['+'] = _plus;
	functions['-'] = _minus;
	functions['*'] = _mult;
	functions['/'] = _divide;
	functions['%'] = _quot;


	stack<int> s;

	for (int i = 0; i < expr.size(); i++)
	{
		if (isDigit (expr[i]))
			s.push (expr[i]-'0'); 
		else
		{
			int rightOp = s.top ();
			s.pop();
			int leftOp = s.top ();
			s.pop();
			s.push (functions[expr[i]](leftOp,rightOp));
		}
	}

	return s.top();
}


template <typename T>
class CircularBuffer {
	static const int CAPACITY = 3; //капацитет на буфера
	int size;
	T data[CAPACITY]; 
	int front;
public:
	CircularBuffer ():size(0),front(0){}

	void push_back(const T& element)
	{
		assert (size < CAPACITY);

		data[(front+size)%CAPACITY]=element;
		size++;

	}
	void pop()
	{
		assert (size > 0);
		size--;
		front++;
		if (front >= CAPACITY)
			front = 0;
	}
	T top ()
	{
		assert (size > 0);

		return data[front];
	}
};

template <typename T>
struct Node {
	T data;
    Node<T>* next;
    Node (const T&d, Node<T>*n = NULL):data(d),next(n){}
};

template <typename T>
class LinkedList {
public:
    Node<T>* start;
	LinkedList ():start(NULL){}

	
	void push (const T& element)
	{
		start = new Node<T> (element, start);
	}

	void insert_after(Node<T>* node, const T& element)
	{
		
		assert (node != NULL);

		Node<T> *newNode = new Node<T> (element);

		newNode->next = node->next;

		node->next = newNode;
	}

	void print ()
	{

		Node<T> *crr = start;
		while (crr)
		{
			cout << crr-> data << ";";
			crr = crr->next;
		}

		cout << endl;
	}
};


void textToBin ()
{

	ifstream inp ("data.txt");

	ofstream out ("data.bin",ios::binary);

	string name, tmp;

	Employee data;

	while (inp >> name)
	{
		inp >> tmp;
		name = name + " " + tmp;
		inp >> tmp;
		name = name + " " + tmp;

		strcpy (data.name,name.c_str());
		inp >> data.employmentYear >> data.departureYear;

		out.write ((char*)&data,sizeof(Employee));

	}
}


int main ()
{



	cout << convert ("32+81+*2*") << endl;

	CircularBuffer<int> b;

	b.push_back(1);
	b.push_back(2);
	b.pop ();
	b.push_back (3);
	b.push_back (4);

	cout << b.top (); b.pop();
	cout << b.top (); b.pop();
	cout << b.top () << endl;

	LinkedList<int> l;

	l.push (1);
	l.insert_after (l.start, 2);
	l.insert_after (l.start, 3);

	l.print();

	cout << "val=" << evaluate ("32+81+*2*") << endl;

	textToBin ();
	binToText (cout);

}