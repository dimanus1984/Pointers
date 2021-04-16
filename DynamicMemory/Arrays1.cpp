template<typename T>void push_back(T*& arr, int& n, int value)
{
	//1) ������� �������� ������ ������� �������
	T* buffer = new T[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i]; // �������� �������� ��������������
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������
	arr[n] = value;
	n++;
}

template<typename T>void push_front(T*& arr, int& n, int value)
{
	//1) ������� �������� ������ ������� �������
	T* buffer = new T[n + 1/*�������, �����������*/]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i]; // �������� �������� �� ��������� �� ���� ������� ������
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������
	arr[0] = value;
	n++; //���������
}

template<typename T>void insert(T*& arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};
	//1 ������
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}*/
	//2 ������
	/*for (int i = 0; i < n; i++)
	{
		if (i < index)
			buffer[i] = arr[i];
		else
			buffer[i + 1] = arr[i];
	}*/
	//3 ������
	/*for (int i = 0; i < n; i++)
	{
		(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	}*/
	//4 ������
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
	T* buffer = new T[--n/*������*/]{}; //�������� ������ ��������� ���������� ������ ������
	// ��� ���� ����� ������� ������� �� �������,
	// � ��������� ������ ����� ����������� ��� �������� ����� ����������:
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
	// 1 ������
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}*/
	// 2 ������
	/*for (int i = 0; i < n; i++)
	{
		buffer[i] = i < index ? arr[i] : arr[i + 1];
	}*/
	// 3 ������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	arr = buffer;
}