#include "FillRand.h"

//Рефлизация функций выносится в *.cpp файлы. 

void FillRand(int arr[], const int n) //Рефлизация функции - Определение функции
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}