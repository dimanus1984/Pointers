#pragma once
//Прототипы функций выносятся в заголовочные файлы (*.h)
void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void pop_back(int*& arr, int& n); // Удаляет элемент с конца массива
void pop_front(int*& arr, int& n); //*& ссылка на указатель
void erase(int*& arr, int& n, int index);
