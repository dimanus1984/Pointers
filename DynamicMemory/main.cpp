#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void pop_back(int*& arr, int& n); // ������� ������� � ����� �������
void pop_front(int*& arr, int& n); //*& ������ �� ���������
void erase(int*& arr, int& n, int index);

//���������� �����:
void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);

//�������� �����:
void pop_row_back(int**& arr, int& m, const int n);

//���������� ��������:
void push_col_back(int** arr, const int m, int& n);

//#define PUSH_BACK
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DEBUG_ARRAYS

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value; //����������� ��������
	cout << "������� ����������� ��������: "; cin >> value;
#ifdef PUSH_BACK
	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������:
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������:
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������:
	arr[n] = value;
	n++;
#endif // PUSH_BACK
	push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������ ������������ ��������:"; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	cout << "�������� ���������� ��������:" << endl;
	pop_back(arr, n);
	Print(arr, n);

	cout << "������� ������� ������� �� �������:" << endl;
	pop_front(arr, n);
	Print(arr, n);

	cout << "������� ������ ���������� ��������:"; cin >> index;
	erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	////////////////////////////////////////////////////////////////////////////
	/////////////   ���������� ���������� ������������� �������   //////////////
	////////////////////////////////////////////////////////////////////////////
	int m; //���������� �����
	int n; //���������� ��������� ������
	//1) ������� ������ ����������, � ��������� ��� ����� � ��������� �� ���������:
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������� ������ (��������): "; cin >> n;
	//1) ������� ������ ����������, � ��������� ��� ����� � ��������� �� ���������:
	int** arr = new int* [m] {};
	//2) �������� ������ ��� ������ ���������� �������:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	////////////////////////////////////////////////////////////////////////////
	/////////////   ������������� ���������� ������������� �������   ///////////
	////////////////////////////////////////////////////////////////////////////
	//cout << "������ �������� ��� ���������� ������" << endl;
	//system("pause");
	FillRand(arr, m, n);
	Print(arr, m, n);
	cout << "���������� ����� � ����� �������:\n";
	push_row_back(arr, m, n);
	Print(arr, m, n);
	//cout << "������ ���������" << endl;

	cout << "���������� ����� � ������ �������:\n";
	push_row_front(arr, m, n);
	Print(arr, m, n);

	cout << "�������� ����� � ����� �������:\n";
	pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "���������� ������� � �����:" << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);

	//cout << "������ ���������";

	////////////////////////////////////////////////////////////////////////////
	/////////////   �������� ���������� ������������� �������   ////////////////
	////////////////////////////////////////////////////////////////////////////
	//����������� � 2 �����:
	//1) �������� �����
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	//2) �������� ������� ����������:
	delete[] arr;
#endif // DYNAMIC_MEMORY_2

#ifdef DEBUG_ARRAYS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	Print(arr, n);
#endif //DEBUG_ARRAYS
}

void FillRand(int arr[], const int n)
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
	//1) ������� �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
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

void push_front(int*& arr, int& n, int value)
{
	//1) ������� �������� ������ ������� �������
	int* buffer = new int[n + 1/*�������, �����������*/]{};
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

void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
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

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n/*������*/]{}; //�������� ������ ��������� ���������� ������ ������
	// ��� ���� ����� ������� ������� �� �������,
	// � ��������� ������ ����� ����������� ��� �������� ����� ����������:
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

void push_row_back(int**& arr, int& m, const int n)
{
	//1) ������� �������� ������:
	int** buffer = new int* [m + 1]{};

	//for (int i = 0; i < m + 1; i++) // 'm + 1' - �� ���� ������ ������
	//{
	//	buffer[i] = new int[n] {};
	//}

	//2)�������� ��� �������� ��������� ������� � ��������
	for (int i = 0; i < m; i++)
	{
		/*for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}*/
		buffer[i] = arr[i]; //� �������� ������ ������ ��������� ����� ��������������� ������
	}
	//3) �������� ��������� �������
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	//�� ����� ������� ������, ���������� ������� ������ ������ ����������:
	delete[] arr;
	//4)�������������� ����� ������ ���������:
	arr = buffer;
	//5)������� ����������� ������:
	arr[m] = new int[n] {};
	m++;
}

void push_row_front(int**& arr, int& m, const int n)
{
	//1) ������� �������� ������ ��������� ������� �������:
	int** buffer = new int* [m + 1]{};
	//2)�������� ������ ����� � ����� ������:
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i]; //'i + 1' - ����������� �� ���������
	}
	//3) �������� ������ ������ ����������:
	delete[] arr;
	//4)��������� ����� �� ����� ������:
	arr = buffer;
	//5)������� ����������� ������:
	arr[0] = new int[n] {};
	//6)����������� ���������� ����:
	m++;
}

void pop_row_back(int**& arr, int& m, const int n)
{
	//1) ������� �������� ������ ���������� ������� �������:
	int** buffer = new int* [--m]{}; // m - ������ ������,
	//'--m' ���������� ��������� �������� ���������� ���� �� '1' � ������ ����� ���������� ������
	//2) �������� ������ � ����� ������:
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� ��������� ������:
	delete[] arr[m];
	//4) ������� ������ ������ ����������:
	delete[] arr;
	//5) ��������� ����� ������ �������:
	arr = buffer;
}

void push_col_back(int** arr, const int m, int& n)
{
	//�������� �� ������� � �������������� ������ ������:
	for (int i = 0; i < m; i++)
	{
		//1) ������� ������ ������� �������:
		int* buffer = new int[n + 1]{};
		//2) �������� �������� ������ � ����� ������
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		//3) ������� �������� ������:
		delete[] arr[i];
		//4) ��������� ����� ������ ������, ������� ����� ������:
		arr[i] = buffer;
	}
	//5) ����� ����, ��� �� �������������� ������ ������, ����������� ���������� ����� �� �������:
	n++;
}