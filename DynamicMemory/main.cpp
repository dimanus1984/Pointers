//Прототипы функций выносятся в заголовочные файлы (*.h)

#include"FillRand.h"
#include"Print.h"
#include"Print.cpp"
#include"Arrays1.h"
#include"Arrays1.cpp"
#include"Arrays2.h"
#include"Arrays2.cpp"

//#define PUSH_BACK
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DEBUG_ARRAYS

void main()
{
	setlocale(LC_ALL, "Russian");
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