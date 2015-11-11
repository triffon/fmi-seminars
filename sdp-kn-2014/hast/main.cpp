#include <string>
#include <iostream>
#include "hasht.cpp"

using namespace std;

int stringHash1 (string s, int htcapacity)
{
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		sum += s[i];
	}

	return sum % htcapacity;
}


int main ()
{
	HashMap<string,int> hm (5,stringHash1);

	hm["Sandra"] = 1;
	hm["Peter"] = 2;
	hm["Sandra"] = 3;

	hm["Third"] = 4;
	hm["Fourth"] = 5;
	hm["Fifth"] = 6;
	hm["Ivan"] = 7;

	cout << hm["Sandra"] << endl; //3
	cout << hm["Peter"] << endl; //2

	cout << hm["Third"] << endl; //4
	cout << hm["Fourth"] << endl; //5
	cout << hm["Fifth"] << endl; //6
	cout << hm["Ivan"] << endl; //7

	//3,2,4,5,6,7

	return 0;
}