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
	/*for (int i = 0; i < n; i++)
	{
		if (i < index)
			buffer[i] = arr[i];
		else
			buffer[i + 1] = arr[i];
	}*/
	//3 способ
	/*for (int i = 0; i < n; i++)
	{
		(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	}*/
	//4 способ
	for (int i = 0; i < n; i++)
	{
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
	/*for (int i = 0; i < n; i++)
	{
		buffer[i] = i < index ? arr[i] : arr[i + 1];
	}*/
	// 3 способ
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	arr = buffer;
}