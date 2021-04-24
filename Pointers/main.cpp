﻿#include<iostream>
using namespace std;

#define PI 3.14
//#define POINTERS_BASICS	    //Основы указателей
//#define POINTERS_AND_ARRAYS	//Указатели и массивы

/*
define - определить
definietion - определение
Директива #define создает макроопределение (макрос), и показывает что заменить, и чем заменить.
#define ЧТО_ЗАМЕНИТЬ ЧЕМ_ЗАМЕНИТЬ
#define ИМЯ ЗНАЧЕНИЕ

Директива - это указание компилятору на выполнение некоторых действий.
*/

void main()
{
	setlocale(LC_ALL, "Russian");
#if defined POINTERS_BASICS
//если определено POINTERS_BASICS, то нижеследующий код будет виден компилятору.
	int a = 2;		//Объявление переменной
	int* pa = &a;	//Объявление указателя
	cout << a << endl;	//Выводим на экран значение переменной 'a'
	cout << *&a << endl;	//Получаем адрес переменной 'a' прямо привыводе
	cout << pa << endl;	//Вывод адреса переменной 'a' хранящегося в указателе 'pa'
	cout << *pa << endl;//Разыменовываем указатель 'pa' и получаем значение по адресу

	int* pb;
	int b = 3;
	pb = &b;
	cout << *pb << endl;
	/*
	-----------------------------------------
	int - int
	int* - Указатель на 'int'
	char - char
	char* - Указатель на 'char'
	-----------------------------------------
	*/
	cout << PI << endl;
#endif // POINTERS_BASICS

#if defined POINTERS_AND_ARRAYS
	/*
	------------------------------------------------------
	Имя массива является указателем на массив, 
	поскольку содержит адрес нулевого элемента массива,
	а следовательно и всего массива.
	Используя Арифметику указателей можно вычислить адрес любого элемента массива
	------------------------------------------------------
					АРИФМЕТИКА УКАЗАТЕЛЕЙ
	Компилятор всегда должен знать на какой тип данных указывает указатель,
	это нужно для того, чтобы понимать сколько байт памяти нужно считать или записать по адресу.
	Так же это нужно для арифметики указателей.
	Над указателями можно применять арифметические операции:+, -, ++, --
	и результат операции будет зависеть от типа данных, на который указывает указатель:
	Если к указателю на char прибавить 1, то адрес измениться на 1 Байт
	Если к указателю на int прибавить 1, то адрес измениться на 4 Байта
	Если к указателю на double прибавить 1, то адрес измениться на 8 Байта
	------------------------------------------------------
	*/
	const int n = 5;
	short arr[n] = { 3, 5, 8, 13, 21 };
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
		cout << *(arr + i) << "\t";
	}
	cout << endl;
	/*
	------------------------------------------------------
	Доступ к элементам массива осуществляется за константное время, 
	поскольку сводится к операции сложения, а операция сложения 
	всегда выполняется за константное время, 
	то есть, процессор на операцию сложения всегда тратит одно и то же количество тактов
	------------------------------------------------------
	*/
	for (int i = 0; i < n; i++)
	{
		//[] - Оператор индексирования. Он так же вычисляет адрес элемента массива, 
		//и разыменовывает его.
		cout << arr[i] << "\t";
	}
	cout << endl;
#endif
}