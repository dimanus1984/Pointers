#pragma once
//Прототипы функций выносятся в заголовочные файлы (*.h)
template<typename T>void push_back(T*& arr, int& n, int value);
template<typename T>void push_front(T*& arr, int& n, int value);
template<typename T>void insert(T*& arr, int& n, T value, int index);

template<typename T>void pop_back(T*& arr, int& n); // Удаляет элемент с конца массива
template<typename T>void pop_front(T*& arr, int& n); //*& ссылка на указатель
template<typename T>void erase(T*& arr, int& n, int index);
