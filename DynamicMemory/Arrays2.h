#pragma once
//Добавление строк:
template<typename T>void push_row_back(T**& arr, int& m, const int n);
template<typename T>void push_row_front(T**& arr, int& m, const int n);

//Удаление строк:
template<typename T>void pop_row_back(T**& arr, int& m, const int n);

//Добавление столбцов:
template<typename T>void push_col_back(T** arr, const int m, int& n);
