#include <iostream>
#include <math.h>

using namespace std;


class A
{
public:
	double surface ()
	{
		return -12;
	}
};

class Figure : public A
{
protected:
	double x,y;
public:
	 virtual double surface()
	{
		return -1;
	}
};

class Rectangle : public Figure
{
private:
	double a,b;
public:
	Rectangle (double _x, double _y, double _a, double _b):a(_a),b(_b)
	{
		x = _x;
		y = _y;
	}

	double surface ()
	{
		return a*b;
	}

};

class Triangle : public Figure
{
private:
	double a,b,c;
public:
	Triangle (double _x, double _y, double _a, double _b, double _c):a(_a),b(_b),c(_c)
	{
		x = _x;
		y = _y;
	}

	double surface ()
	{


		double p = (a+b+c)/2;
		return sqrt (p*(p-a)*(p-b)*(p-c));
	}

};

class Circle : public Figure
{
private:
	double r;
public:

	Circle (double _x, double _y, double _r):r(_r)
	{
		x = _x;
		y = _y;

	}
	

	double surface ()
	{
		return 3.14*r*r;
	}

};


double sumSurfaces (Figure& f1, Figure& f2)
{
	return f1.surface() + f2.surface();
}



int main ()
{



	Rectangle r1 (1,2,3,4);
	Circle c1 (1,2,3);


	Figure* figures[2] = {&r1,&c1};

	cout << figures[0]->surface() << endl;

	cout << sumSurfaces (r1,c1);

}