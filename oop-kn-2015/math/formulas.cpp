#include <iostream>
#include <assert.h>

using namespace std;

class Formula
{
public:
	virtual int value () = 0;
	virtual ~Formula ()
	{
	}
};

class Id : public Formula{

	int id;
public:
    Id (int a){
        id = a;
    }
   
   int value(){
   		return id;
   }
};


class Sum : public Formula {

	Formula * x;
	Formula * y;

public:
    Sum (Formula * a, Formula * b)
	{
	    x = a;
	    y = b;
	}

	int value(){
    	return x->value() + y->value();
	}

	~Sum(){
    	delete x;
    	delete y;
    }
};

class Product : public Formula{
    
    Formula *x;
    Formula *y;

public:

    Product (Formula * a, Formula * b){
	    x = a;
	    y = b;
    }

    int value(){
	    return x->value()*y->value();
    }

    ~Product(){
	    delete x;
	    delete y;
	}

};



/*

	            Sum
	        /         \
          /             \
     Product           Sum
     /     \          /   \
   Id (2) Id (4)    Id(5)  Id (7)



	Figure *f = new Sum (new Id (1), new Id (2))

	f->value();
	delete f;


<Expr> ::= <Sum> | <Prod> | <Id>

<Sum> ::= + <Expr> <Expr>
<Prod> ::= * <Expr> <Expr>
<Id> := 0..9


int fib (int x)
{
	if (x <= 1)
		return x;

	return fib (x-2) + fib (x-1);
}

*/


Formula* parse ()
{
	char c = cin.get();

	if (c >= '0' && c <= '9')
	{
		return new Id (c-'0');	
	}

	if (c == '+')
	{
		Formula *leftOperand = parse();
		Formula *rightOperand = parse();

		return new Sum (leftOperand,rightOperand);

	}

	if (c == '*')
	{
		Formula *leftOperand = parse();
		Formula *rightOperand = parse();

		return new Product (leftOperand,rightOperand);

	}


	assert (false);
	return NULL;
}

int main ()
{

	Formula *f = new Sum (new Product 
		     					(new Id (2), new Id (4)),
		     			  new Sum 
		     			        (new Id (5), new Id (7)));


	cout << "Value=" << f->value();

	cout << "\n===========\n";

	Formula *parsedTree = parse();

	cout << "value = " << parsedTree->value() << endl;


}