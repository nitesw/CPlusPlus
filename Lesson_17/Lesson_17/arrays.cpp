#include "arrays.h"

void fillArray(int arr[], int length, int min, int max)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = rand() % (max - min - 1) + min;
	}
}
void fillArray(double arr[], int length, int min, int max)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = rand() % ((max - min - 1) + min) / 3.0;
	}
}
void fillArray(char arr[], int length, char symbol)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = symbol;
	}
}
void fillArray(string arr[], int length, string str)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = str;
	}
}

void printArray(int arr[], int length, string help)
{
	cout << help;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void printArray(double arr[], int length, string help)
{
	cout << help;
	for (size_t i = 0; i < length; i++)
	{
		cout << fixed;
		cout << setprecision(2);
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void printArray(char arr[], int length, string help)
{
	cout << help;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void printArray(string arr[], int length, string help)
{
	cout << help;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void reverseArray(int arr[], int length, string reverse)
{
	for (size_t i = 0; i < length / 2; i++)
	{
		int tmp = arr[i];
		arr[i] = arr[length - i - 1];
		arr[length - i - 1] = tmp;
	}
	cout << reverse;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void reverseArray(double arr[], int length, string reverse)
{
	for (size_t i = 0; i < length / 2; i++)
	{
		double tmp = arr[i];
		arr[i] = arr[length - i - 1];
		arr[length - i - 1] = tmp;
	}
	cout << reverse;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void filteredArray(int arr[], int length, string filtered)
{
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	cout << filtered;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void filteredArray(double arr[], int length, string filtered)
{
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				double tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	cout << filtered;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int searchNum(int arr[], int length, int num)
{
	int counter;

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

int minNum(int arr[], int length)
{
	int min = 10;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			return min;
		}
	}
}
double minNum(double arr[], int length)
{
	double min = 10;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			return min;
		}
	}
}

int maxNum(int arr[], int length)
{
	int max = 1;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
double maxNum(double arr[], int length)
{
	double max = 1;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int minNumPos(int arr[], int length)
{
	int counter;

	int min = 10;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] < min)
		{
			counter = i;
		}
	}
	return counter + 1;
}
int minNumPos(double arr[], int length)
{
	int counter;

	int min = 10;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] < min)
		{
			counter = i;
		}
	}
	return counter + 1;
}

int maxNumPos(int arr[], int length)
{
	int counter;

	int max = 1;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] > max)
		{
			counter = i;
		}
	}
	return counter;
}
int maxNumPos(double arr[], int length)
{
	int counter;

	int max = 1;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] > max)
		{
			counter = i;
		}
	}
	return counter;
}