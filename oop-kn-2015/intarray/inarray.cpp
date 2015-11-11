#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;

template <class T>
class DynArray
{

public:

	T *arr;
	int size;


	void copy (const DynArray& a)
	//preconditions: expects arr to be a properly initialized array
	//postconditions:
	//side effects: the array priviosly pointed by arr will be released

	{//a.copy(a)???

	  T* newbuf = new T [a.size];
	  for(int i=0; i<a.size; i++)
	  {
	  	newbuf[i]=a.arr[i];
	  }	
	  delete arr;
	  arr=newbuf;
	  size=a.size;

	}

public:

	
	DynArray (const DynArray<T> &original)
	{
		arr=NULL;
		copy (original);
	}


	DynArray ()
	{
		size = 0;
		arr = NULL;
	}

	void toEnd(const T& newelement)
	{
		T* newbuf = new T[size+1];
		for(int i=0;i<size;i++)
		{
			newbuf[i]=arr[i];
			
		}
		newbuf[size]=newelement;
		size++;

		delete arr;

		arr=newbuf;

	}


	/*
	main:
	int x[100];

	x[5] = 5;
	cout << x[5];

	int i = 3;
	
	cout << arr.getAt (3);

	arr[3] = 8;
	arr.operator[](3) = 8;
	*/
	
	//int& getAt(int index)
	T& operator [] (int index)
	{	
		assert (index >= 0 && index < size);
		return arr[index];
	}


	~DynArray()
	{
		delete [] arr;
	}


	DynArray (T x)
	{
		arr = new T [1];
		arr[0] = x;	
		size = 1;
	}

	//a=b=c
	//a.operator = (b.operator = (c));
	//(c = a).print();
	//a = b = c;
	DynArray<T>& operator = (const DynArray<T>& original)
	{
		if (this != &original)
		{
			delete arr;
			arr = NULL;
		}
		copy (original);

		return *this;
	}


	//c = a + a

	DynArray<T> operator + (const DynArray<T>& other)
	{
		DynArray<T> result;
		for (int i = 0; i < min (size,other.size); i++)
		{
			result.toEnd (arr[i] + other.arr[i]);
		}

		return result;
	}

	//a = 5
	void operator = (T x)
	{
		delete arr;
		arr = new T [1];
		arr[0] = x;
		size = 1;
	}

    //friend void operator << (ostream& outStream, const DynArray<T>& darr);

};

template <class T>
ostream& operator << (ostream& outStream, const DynArray<T>& darr)
//cout << a;
{
	for(int i=0;i<darr.size;i++)
	{
		outStream << darr.arr[i] << " ";
	}
	outStream << endl;

	return outStream;
}



int main ()
{

	DynArray<int> a;

	a.toEnd (1);
	a.toEnd (2);
	a.toEnd (3);
	a.toEnd (4);


	cout << "My aray is: \n" << a << endl;


	cout << endl;


	cout << a[2]; //cout << a[2];


	cout << endl;


	a[2] = 10;


	cout << a[2]; //cout << a[2];


	cout << endl;

	DynArray<int> b;

	//b.copy (a);

	//cout << b.getAt(0);
	a[0] = 100;
	//cout << b.getAt(0);

	DynArray<int> c = a;

	//(c = a).print();

	//a.print();
	//c.print();

	a = a + a;

	//a.print();


	//->2,10

	DynArray<DynArray<int> > arrayOfArrays;

	arrayOfArrays.toEnd (a);
	arrayOfArrays.toEnd (b);
	arrayOfArrays.toEnd (c);

	cout << arrayOfArrays;



	// stringArray.toEnd ("hellp");



}