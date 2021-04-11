#include<iostream>
using namespace std;

#define tab "\t"
//define - ����������
//��������� #define ���������� �����������, ��� ��������, ��� ��������
//#define ������� ���������������� (������)
//identifier (�������������) - ��� ��� ����������, �������, �������, � �.�.

void Exchange(int &a, int &b); //������ ������� (���������� ������� - Function declaration)
//� ��������� � ���������� ������� �� �����������, ������ ��������� ������� ���������
void main()
{
	setlocale(LC_ALL, "Russiaan");
	int a = 2, b = 3;
	cout << a << tab << b << endl;
	Exchange(a, b); // ����� ������� - Function call. (������������ ���������)
	//����� �� �������� �������, �� �������� � ��� ���������.
	cout << a << tab << b << endl;
}
void Exchange(int &a, int &b) //���������� (�����������) ������� - Function definition
{
	int buffer = a;
	a = b;
	b = buffer;
	cout << a << tab << b << endl;
	/*a += b;
	b = a - b;
	a -= b;
	cout << a << tab << b << endl;*/
}

/*
�������� ����������!!!
���������� 3 ������� �������� ��������� � �������:
-�� �������� - By value;
-�� ��������� - By pointer;
-�� ������ - By reference;
--------------------------------------------------------
������ �� �������� ��������� � ������� �� ��������.
��� ���� �������� ������������ ���������� ���������� � �������,
� ���� �������� �������� ��� ��������, �� ��������� ����������� � ������� ����������
� �� � ������ �����������.
--------------------------------------------------------
��� ���� ����� �������� ����� �������� �������� ����������
�� ����� �������� �� ��������� ��� �� ������
--------------------------------------------------------
�������� ���������� �� ���������!!!
��� ���� ����� �������� ��������� � �������� �� ���������
����������� ��������� � ������� ������ ���� �����������
��� ��������� � ���� �������� ����� ��������������,
����� ��������� ������ � ��������� ���������� ����������.
����� ���� ��� ������ ������� ����� ����� ������ ������������ ����������.
*/