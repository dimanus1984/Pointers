#pragma once
//Добавление строк:
void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);

//Удаление строк:
void pop_row_back(int**& arr, int& m, const int n);

//Добавление столбцов:
void push_col_back(int** arr, const int m, int& n);
