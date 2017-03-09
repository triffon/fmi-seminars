#include <iostream>
#include <string>

// Това трябва да се избягва!
using namespace std;

class String
{

public:
	char *buf;

	int length () const
	{
		return strlen (buf);
	}

	String (char *s)
	{

		buf = new char [strlen (s)+1];
		strcpy (buf,s);

	}

	~String ()
	{
		delete buf;
	}

	void print () const
	{
		cout << buf << endl;
	}

	String (const String& original)
	{
		buf = new char [strlen (original.buf)+1];
		strcpy (buf,original.buf);		
	}

	void operator = (const String original)
	{
		if (this != &original)
		{
			delete buf;	
			buf = new char [strlen (original.buf)+1];
			strcpy (buf,original.buf);			
		}
	}

	void operator += (const String s)
	{

		//buf, s.buf

		char *newbuf = new char [strlen (buf) + s.length()+1];

		strcpy (newbuf,buf);

		strcat (newbuf,s.buf);

		delete buf;
		buf = newbuf;

	}


};



int main()
{


	char tmp[1000] = "Hello";

	String s1 (tmp),
	       s2 = s1;//s2 (s1);

	s2 = s1; //s2.operator = (s1);
	
	s1.print();
	s2.print();

	s1 += s2; //<=> s1.operator += (s2);

	s1.print ();

	cout << "\n\n\n";

	return 0;
}
