#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


class A
{
private:
	static int count;
public:
	int x;
	A ()
	{
		count++;
	}

	int howManyA()
	{
		return count;
	}

	~A()
	{
		count--;
	}

};

int A::count = 0;


//	Singleton *k1 = Singleton::createSingleton ();
//	Singleton *k2 = Singleton::createSingleton ();
//	Singleton *k3 = Singleton::createSingleton ();

class Singleton
{
private:
	int x;
	static Singleton *theONE;
	Singleton ()
	{

	}
public:
	static Singleton* createSingleton ()
	{
		

		if (theONE == NULL)
			theONE = new Singleton();
		x = 5;
		return theONE;
	} 

};

Singleton *Singleton::theONE = NULL;


template <typename T>
T max (T arr[], int n)
{
	T result = arr[0];

	for (int i = 1; i < n; i++)
		if (result < arr[i])
			result = arr[i];

	return result;
}

template <typename T>
T sum (T arr[], int n)
{
	T result = 0;

	for (int i = 1; i < n; i++)
		result += arr[i];

	return result;
}

int main ()
{

	Singleton *k1 = Singleton::createSingleton ();
	Singleton *k2 = Singleton::createSingleton ();
	Singleton *k3 = Singleton::createSingleton ();


	A a,b,c;

	cout << "Counter = " << a.howManyA () << endl;
		
	int testi[] = {1,2,3,4,5,5,2,3,1};
	double testd[] = {1,2,6.23,4,5,5,2,3,1};

	cout << endl << "max I = " << max<int> (testi,9) << endl;
	cout << endl << "max D = " << max<double> (testd,9) << endl;


	ofstream myFile ("kalin.txt");

	cout << "Printing to screen\n";
	myFile << "Printing to File\n";

	return 0;
}