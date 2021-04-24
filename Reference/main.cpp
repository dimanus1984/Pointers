#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra = a;
	ra += 3;
	cout << a << endl;
}

/*
----------------------------------------------------
int - Int
int* - ”казатель на int
int& - —сылка на int
----------------------------------------------------
*/