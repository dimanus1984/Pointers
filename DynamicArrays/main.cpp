#include<iostream>
using namespace std;
/*
Есть массив arr из 10-ти элементов, заполненный случайными числами.
Нужно создать еще два массива even и odd минимально возможного размера,
в массив even нужно скопировать все четные значения из исходного массива,
а в массив odd - нечетные. Массивы even и odd вывести на экран.
Удалять и добавлять значения в динамический массив???
*/

#define tab "\t"

void FillRand(int arr[], const int n); //Прототип функции
void Print(int* arr, const int n); //Прототип функции

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введиите размер массива: "; cin >> n;
	//1: Объявление динамического массива:
	int* arr = new int[n] { 3, 5, 8, 13, 21 };
	//2: Использование динамического массива:
	Print(arr, n);
	FillRand(arr, n);
	Print(arr, n);
	//3: Удалениие динамического массива:
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Доступ к элементам массива через арифметику указателей
		//и оператор разыменования:
		*(arr + i) = rand();
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Доступ к элементам массива через оператор индексирования (Subscript operator)
		cout << arr[i] << tab;
	}
	cout << endl;
}
