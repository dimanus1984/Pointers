template<typename T>void push_back(T*& arr, int& n, int value)
{
	//1) Создаем буферный массив нужного размера
	T* buffer = new T[n + 1]{};
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

template<typename T>void push_front(T*& arr, int& n, int value)
{
	//1) Создаем буферный массив нужного размера
	T* buffer = new T[n + 1/*Сложить, суммировать*/]{};
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

template<typename T>void insert(T*& arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};
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

template<typename T>void pop_back(T*& arr, int& n)
{
	T* buffer = new T[--n/*Отнять*/]{}; //Фигурные скобки заполняют выделяемую память нулями
	// Для того чтобы удалить елемент из массива,
	// в буфферный массив нужно скопировать все элементы кроме удаляемого:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

template<typename T>void pop_front(T*& arr, int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}

template<typename T>void erase(T*& arr, int& n, int index)
{
	T* buffer = new T[--n]{};
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