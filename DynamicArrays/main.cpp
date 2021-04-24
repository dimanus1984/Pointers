#include<iostream>
using namespace std;
/*
���� ������ arr �� 10-�� ���������, ����������� ���������� �������.
����� ������� ��� ��� ������� even � odd ���������� ���������� �������,
� ������ even ����� ����������� ��� ������ �������� �� ��������� �������,
� � ������ odd - ��������. ������� even � odd ������� �� �����.
������� � ��������� �������� � ������������ ������???
*/

#define tab "\t"

void FillRand(int arr[], const int n); //�������� �������
void Print(int* arr, const int n); //�������� �������

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "�������� ������ �������: "; cin >> n;
	//1: ���������� ������������� �������:
	int* arr = new int[n] { 3, 5, 8, 13, 21 };
	//2: ������������� ������������� �������:
	Print(arr, n);
	FillRand(arr, n);
	Print(arr, n);
	//3: ��������� ������������� �������:
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//������ � ��������� ������� ����� ���������� ����������
		//� �������� �������������:
		*(arr + i) = rand();
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		//������ � ��������� ������� ����� �������� �������������� (Subscript operator)
		cout << arr[i] << tab;
	}
	cout << endl;
}
