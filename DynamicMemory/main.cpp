#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

//Прототипы функций выносятся в заголовочные файлы (*.h)
void FillRand(int arr[], const int n); //Прототип функции - Объявление функции (Function declaration)
void FillRand(int** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void pop_back(int*& arr, int& n); // Удаляет элемент с конца массива
void pop_front(int*& arr, int& n); //*& ссылка на указатель
void erase(int*& arr, int& n, int index);

//Добавление строк:
void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);

//Удаление строк:
void pop_row_back(int**& arr, int& m, const int n);

//Добавление столбцов:
void push_col_back(int** arr, const int m, int& n);

//#define PUSH_BACK
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DEBUG_ARRAYS

void main()
{
	setlocale(LC_ALL, "Russian");
	//cout << "Hello" << endl;
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value; //Добавляемое значение
	cout << "Введите добавляемое значение: "; cin >> value;
#ifdef PUSH_BACK
	//1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1]{};
	//2) Копируем все значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) После того как данные скопированы, исходный массив можно удалить:
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив:
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в конец массива:
	arr[n] = value;
	n++;
#endif // PUSH_BACK
	push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс добавляемого элемента:"; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	cout << "Удаление последнего элемента:" << endl;
	pop_back(arr, n);
	Print(arr, n);

	cout << "Удаляет нулевой элемент из массива:" << endl;
	pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого элемента:"; cin >> index;
	erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	////////////////////////////////////////////////////////////////////////////
	/////////////   ОБЪЯВЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА   //////////////
	////////////////////////////////////////////////////////////////////////////
	int m; //Количество строк
	int n; //Количество элементов строки
	//1) Создаем массив указателей, и сохраняем его адрес в указатель на указатель:
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки (столбцов): "; cin >> n;
	//1) Создаем массив указателей, и сохраняем его адрес в указатель на указатель:
	int** arr = new int* [m] {};
	//2) Выделяем память под строки двумерного массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	////////////////////////////////////////////////////////////////////////////
	/////////////   ИСПОЛЬЗОВАНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА   ///////////
	////////////////////////////////////////////////////////////////////////////
	//cout << "Память выделена для добавления строки" << endl;
	//system("pause");
	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление стоки в конец массива:\n";
	push_row_back(arr, m, n);
	Print(arr, m, n);
	//cout << "Строка добавлена" << endl;

	cout << "Добавление стоки в начало массива:\n";
	push_row_front(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление стоки в конце массива:\n";
	pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление столбца в конец:" << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);

	//cout << "Строка добавлена";

	////////////////////////////////////////////////////////////////////////////
	/////////////   УДАЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА   ////////////////
	////////////////////////////////////////////////////////////////////////////
	//Выполняется в 2 этапа:
	//1) Удаление строк
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	//2) Удаление массива указателей:
	delete[] arr;
#endif // DYNAMIC_MEMORY_2

#ifdef DEBUG_ARRAYS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	Print(arr, n);
#endif //DEBUG_ARRAYS
}

//Реализация функций выносятся в *.cpp файлы.
void FillRand(int arr[], const int n)//Реализация функции - Определение функции (Function definition)
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

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

void push_back(int*& arr, int& n, int value)
{
	//1) Создаем буферный массив нужного размера
	int* buffer = new int[n + 1]{};
	//2) Копируем все значения из исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i]; // Копируем элементы СООТВЕТСТВЕННО
	}
	//3) После того как данные скопированы, исходный массив можно удалить
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в конец массива
	arr[n] = value;
	n++;
}

void push_front(int*& arr, int& n, int value)
{
	//1) Создаем буферный массив нужного размера
	int* buffer = new int[n + 1/*Сложить, суммировать*/]{};
	//2) Копируем все значения из исходного массива в буферный
	//СО СМЕЩЕНИЕМ НА ОДИН ЭЛЕМЕНТ ВПРАВО
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i]; // Копируем элементы СО СМЕЩЕНИЕМ НА ОДИН ЭЛЕМЕНТ ВПРАВО
	}
	//3) После того как данные скопированы, исходный массив можно удалить
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в конец массива
	arr[0] = value;
	n++; //Прибавить
}

void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	//1 способ
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}*/
	//2 способ
	for (int i = 0; i < n; i++)
	{
		true;
		if (i < index)buffer[i] = arr[i]; else buffer[i + 1] = arr[i];
		//3 способ
		//(i < index) ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		//4 способ
		//(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
		//5 способ
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n/*Отнять*/]{}; //Фигурные скобки заполняют выделяемую память нулями
	// Для того чтобы удалить елемент из массива,
	// в буфферный массив нужно скопировать все элементы кроме удаляемого:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}

void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[--n]{};
	// 1 способ
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}*/
	// 2 способ
	for (int i = 0; i < n; i++)
	{
		//buffer[i] = i < index ? arr[i] : arr[i + 1];
		// 3 способ
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	arr = buffer;
}

void push_row_back(int**& arr, int& m, const int n)
{
	//1) Создаем буферный массив:
	int** buffer = new int* [m + 1]{};
	//for (int i = 0; i < m + 1; i++) // 'm + 1' - на одну строку больше
	//{
	//	buffer[i] = new int[n] {};
	//}

	//2)Копируем все значения исходного массива в буферный
	for (int i = 0; i < m; i++)
	{
		/*for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}*/
		buffer[i] = arr[i]; //В буферный массив просто переносим адрес соответствующей строки
	}
	//3) Удаление исходного массива
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	//Не нужно удалять строки, достаточно удалить старый массив указателей:
	delete[] arr;
	//4)Переопределяем новый массив уазателей:
	arr = buffer;
	//5)Создаем добавляемую строку:
	arr[m] = new int[n] {};
	m++;
}

void push_row_front(int**& arr, int& m, const int n)
{
	//1) Создаем буферный массив уазателей нужного размера:
	int** buffer = new int* [m + 1]{};
	//2)копируем адреса строк В новый массив:
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i]; //'i + 1' - Скопировать со смещением
	}
	//3) Удаление старый массив указателей:
	delete[] arr;
	//4)Подменяем адрес на новый массив:
	arr = buffer;
	//5)Создаем добавленную строку:
	arr[0] = new int[n] {};
	//6)Увеличиваем количество сток:
	m++;
}

void pop_row_back(int**& arr, int& m, const int n)
{
	//1) Создаем буферный массив указателей нужного размера:
	int** buffer = new int* [--m]{}; // m - размер строки,
	//'--m' префиксный дикремент уменьшит количество сток на '1' и только потом выделяется память
	//2) Копируем строки в новый массив:
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем последнюю строку:
	delete[] arr[m];
	//4) Удаляем старый массив указателей:
	delete[] arr;
	//5) Сохраняем адрес нового массива:
	arr = buffer;
}

void push_col_back(int** arr, const int m, int& n)
{
	//Проходим по строкам и переопределяем каждую строку:
	for (int i = 0; i < m; i++)
	{
		//1) Создаем строку нужного размера:
		int* buffer = new int[n + 1]{};
		//2) Копируем исходную строку в новую строку
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		//3) Удаляем исходную строку:
		delete[] arr[i];
		//4) Подменяем адрес старой строки, адресом новой строки:
		arr[i] = buffer;
	}
	//5) После того, как мы переопределили каждую строку, увеличиваем количество строк на единицу:
	n++;
}