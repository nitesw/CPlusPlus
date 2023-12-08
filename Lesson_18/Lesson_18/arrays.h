#pragma once
#include <iostream>
using std::cin;
using std::cout;
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
	cout << text << " ";
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}