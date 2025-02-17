#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//=======Пузырькавая сортировка и ее улучшения==================================//
// Сортировка пузырьком
void BubbleSort(vector<int>& values);

// Сортировка перемешиванием (шейкерная сортировка)
void ShakerSort(vector<int>& values);

// Сортировка расчёской
void CombSort(vector<int>& values);


//=======Простые сортировки=====================================================//
//Сортировка вставками
void InsertionSort(vector<int>& values);

// Сортировка выбором
void SelectionSort(vector<int>& values);


//=======Эффективные сортировки=================================================//
// Быстрая сортировка
void QuickSort(vector<int>& values);

// Сортировка слиянием
void MergeSort(vector<int>& values);

// Пирамидальная сортировка
void HeapSort(vector<int>& values);