#pragma once
#include <iostream>
#include <ctime>
using namespace std;



template <typename T>
void inputArray(T arr[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << "Enter value [" << i + 1 << "] : ";
		cin >> arr[i];
	}
}
template <typename T>
void printArray(T arr[], size_t length, std::string text = "")
{
	cout << "Array: " << endl;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

template <typename T>
auto firstNum(T arr[], size_t length)
{
	int counter, num;

	cout << "Enter the number: "; cin >> num;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == num)
		{
			counter = i;
			return counter + 1;
		}
		else
		{
			counter = -1;
		}
	}
	return counter;
}
template <typename T>
auto lastNum(T arr[], size_t length)
{
	int counter, num;

	cout << "\nEnter the number: "; cin >> num;

	for (size_t i = length; i > 0; i--)
	{
		if (arr[i] == num)
		{
			return counter = i + 1;
		}
	}
	return -1;
}

template <typename T>
auto randomArray(T arr[], size_t length)
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			auto random_index = rand() % length;
			auto tmp = arr[j];
			arr[j] = arr[random_index];
			arr[random_index] = tmp;
		}
	}
}

template <typename T>
void sameNum(T arr[], size_t length)
{
	char symbol;
	cout << "Enter symbol: "; cin >> symbol;
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = symbol;
	}
}

template <typename T>
void filteredArray(T arr[], size_t length)
{
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				auto tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void filteredArray2(T arr[], size_t length)
{
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1]) {
				auto tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void inputArry(T arr[], int ROW, int COL) {
	for (size_t i = 0; i < ROW; i++)
	{
		for (size_t j = 0; j < COL; j++)
		{
			cout << "Enter arr[" << i << "]" << "[" << j << "]: ";
			cin >> arr[i][j];
		}
	}
}
template <typename T>
void coutArry(T arr[], int ROW, int COL) {
	cout << "Arry: " << endl;
	for (size_t i = 0; i < ROW; i++)
	{
		for (size_t j = 0; j < COL; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
template <typename T, int COLS>
T maxInMatrix(T arr[][COLS], int ROW, int COL)
{
	T max = arr[0][0];
	for (size_t i = 0; i < ROW; i++)
	{
		for (size_t j = 0; j < COL; j++)
		{
			if (max < arr[i][j]) {
				max = arr[i][j];
			}
		}
	}
	return max;
}
template <typename T>
bool isRowSorted(T arr[], int ROW, int COL, int row_index) {
	if (row_index < 0 || row_index >= ROW) {
		return false;
	}

	for (int j = 0; j < COL - 1; j++) {
		if (arr[row_index][j] > arr[row_index][j + 1]) {
			return false;
		}
	}

	return true;
}
template <typename T>
bool isMatrixSorted(T arr[], int ROW, int COL) {
	for (int i = 0; i < ROW; i++) {
		if (!isRowSorted(arr, ROW, COL, i)) {
			return false;
		}
	}
	return true;
}