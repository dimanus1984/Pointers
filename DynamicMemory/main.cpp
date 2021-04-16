//��������� ������� ��������� � ������������ ����� (*.h)

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