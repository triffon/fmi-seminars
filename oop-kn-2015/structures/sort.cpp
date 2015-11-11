#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


struct Student
{
	int fn;
	char name[200];
};


void inputStudents (ifstream &in, Student students[], int &nStudents)
{

	in >> nStudents;

	for (int i = 0; i < nStudents; i++)
	{
		//students[i] <- това ще го четем
		in >> students[i].fn;
		in.getline (students[i].name,200);
	}

}

void outputStudents (Student students[], int nStudents)
{
	for (int i = 0; i < nStudents; i++)
	{
		cout << students[i].fn 
		     << "\t" 
		     << students[i].name
		     << endl;
	}
}

bool compareByFn (Student s1, Student s2)
{
	return s1.fn > s2.fn;
}

bool compareByName (Student s1, Student s2)
{
	return strcmp (s1.name,s2.name) > 0;
}

typedef bool (*studentComparator) (Student, Student);


void sortArrayOfStudents (Student students[], int nStudents, studentComparator compare)
{

	int currentMin = 0;

	for (int i = 0; i < nStudents-1; i++)
	{
		currentMin = i;
		for (int j = i+1; j < nStudents; j++)
		{
			if (compare (students[j],students[currentMin]))
				currentMin = j;
		}

		Student tmp = students[i];
		students[i] = students[currentMin];
		students[currentMin] = tmp;
			
	}

}

int main ()
{



	ifstream input ("students.txt");

	Student students[100];
	int nStudents;

	inputStudents (input,students,nStudents);

	sortArrayOfStudents (students,nStudents,compareByFn); 

	outputStudents (students,nStudents);

	cout << endl;

	sortArrayOfStudents (students,nStudents,compareByName); 

	outputStudents (students,nStudents);

}