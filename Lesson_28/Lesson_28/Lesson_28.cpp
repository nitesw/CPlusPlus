#include <iostream>
#include <ctime>
using namespace std;

int** createJuggedArray(const int row, const int* col)
{
	int** arr = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new int[col[i]];
	}
	return arr;
}
void fillJuggedArray(int** arr, const int row, const int* col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col[i]; j++)
		{
			arr[i][j] = rand() % 30 + 1;
		}
	}
}
void printJuggedArray(int** arr, const int row, const int* col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col[i]; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
		cout << endl;
	}
}

void fill(int** arr, const int row, const int col, int min = -1, int max = 3)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}
void print(int** arr, const int row, const int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void deleteRow(int**& arr, int& row, const int col)
{
	int** new_arr = new int* [row];
	int counter = 0;
	for (size_t i = 0; i < row; i++)
	{
		bool has_zero = false;
		for (size_t j = 0; j < col; j++)
		{
			if (arr[i][j] == 0)
			{
				has_zero = true;
				break;
			}
		}
		if (!has_zero)
		{
			new_arr[counter] = new int[col];
			for (size_t j = 0; j < col; j++)
			{
				new_arr[counter][j] = arr[i][j];
			}
			counter++;
		}
	}
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	row = counter;
	arr = new_arr;
}

void addTwo(int**& arr1, int**& arr2, const int row, const int col)
{
	int** new_arr = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		new_arr[i] = new int[col];
		for (size_t j = 0; j < col; j++)
		{
			new_arr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr1[i];
		delete[] arr2[i];
	}
	delete[] arr1;
	delete[] arr2;
	arr1 = new_arr;
}

void multMatrix(int**& arr1, int**& arr2, const int row, const int col)
{
	int** new_arr = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		new_arr[i] = new int[col];
		for (size_t j = 0; j < col; j++)
		{
			int sum = 0;
			for (size_t q = 0; q < col; q++)
			{
				sum += arr1[i][q] * arr2[q][j];
			}
			new_arr[i][j] = sum;
		}
	}
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr1[i];
		delete[] arr2[i];
	}
	delete[] arr1;
	delete[] arr2;
	arr1 = new_arr;
}

int main()
{
	srand(time(0));

    /*int r = 5, c = 4, b = 3;
    int*** arr = new int** [b];
	for (size_t i = 0; i < b; i++)
	{
		arr[i] = new int* [r];
		for (size_t j = 0; j < r; j++)
		{
			arr[i][j] = new int[c];
		}
	}

	for (size_t i = 0; i < b; i++)
	{
		for (size_t j = 0; j < r; j++)
		{
			for (size_t q = 0; q < c; q++)
			{
				arr[i][j][q] = rand() % 20 + 1;
			}
		}
	}
	for (size_t i = 0; i < b; i++)
	{
		for (size_t j = 0; j < r; j++)
		{
			for (size_t q = 0; q < c; q++)
			{
				cout << arr[i][j][q] << "\t";
			}
			cout << endl;
		}
		cout << "\n\n\n";
	}

	for (size_t i = 0; i < b; i++)
	{
		for (size_t j = 0; j < r; j++)
		{
			delete[] arr[i][j];
		}
	}
	for (size_t i = 0; i < b; i++)
	{
		delete[] arr[i];
	}
	delete arr;*/

	/*int** arr;
	int row = 5;
	int col[]{ 4,2,5,8,10 };
	arr = createJuggedArray(row, col);
	fillJuggedArray(arr, row, col);
	printJuggedArray(arr, row, col);*/

	/*int row = 3, col = 4;
	int** arr = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new int[col] {};
	}
	fill(arr, row, col);
	cout << "Before: " << endl;
	print(arr, row, col);
	cout << "\nAfter: " << endl;
	deleteRow(arr, row, col);
	print(arr, row, col);*/

	/*int row, col;
	cout << "Enter the number of rows and columns: "; cin >> row >> col;
	int** arr1 = new int* [row];
	int** arr2 = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		arr1[i] = new int[col] {};
		arr2[i] = new int[col] {};
	}

	fill(arr1, row, col);
	fill(arr2, row, col);
	cout << "Array #1: " << endl;
	print(arr1, row, col);
	cout << "\nArray #2: " << endl;
	print(arr2, row, col);

	addTwo(arr1, arr2, row, col);
	cout << "\n\nArray with added numbers: " << endl;
	print(arr1, row, col);*/

	int row = 3, col = 3;
	int** arr1 = new int* [row];
	int** arr2 = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		arr1[i] = new int[col] {};
		arr2[i] = new int[col] {};
	}

	fill(arr1, row, col);
	fill(arr2, row, col);
	cout << "Matrix #1: " << endl;
	print(arr1, row, col);
	cout << "\nMatrix #2: " << endl;
	print(arr2, row, col);

	cout << "\nMultiplied matrix: " << endl;
	multMatrix(arr1, arr2, row, col);
	print(arr1, row, col);
}