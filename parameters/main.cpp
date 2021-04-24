#include<iostream>
using namespace std;

#define tab "\t"

//identifier (идентификатор) - это имя переменной, массива, функуии, и т.д.

void Exchange(int &a, int &b); //Протип функции (Объявление функции - Function declaration)
//В прототипе и реализации функции мы ппоказываем, какием параметры функция ПРИНИМАЕТ
void main()
{
	setlocale(LC_ALL, "Russiaan");
	int a = 2, b = 3;
	cout << a << tab << b << endl;
	Exchange(a, b); // Вызов функции - Function call. (передаваемые параметры)
	//Когда мы вызываем функцию, мы ПЕРЕДАЕМ в нее параметры.
	cout << a << tab << b << endl;
}
void Exchange(int &a, int &b) //Реализация (Определение) функции - Function definition
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