#include <iostream>
using namespace std;

void fill(int** arr, const int& row, const int& col, int min = 1, int max = 20)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}
void print(int** arr, const int& row, const int& col, string text = "")
{
	cout << "\t " << text << endl;
	for (size_t i = 0; i < row; i++)
	{
		cout << "\t\t";
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

//Rows
void insertRow(int**& arr, int& row, const int& col, const int& index)
{
	if (index < 0 || index > row) return;
	int** tmp = new int* [row + 1];
	for (size_t i = 0; i < row; i++)
	{
		if (i < index)
		{
			tmp[i] = arr[i];
		}
		else
		{
			tmp[i + 1] = arr[i];
		}
	}
	tmp[index] = new int[col] {};
	row++;
	delete[] arr;
	arr = tmp;
}
void deleteRow(int**& arr, int& row, const int& index)
{
	if (index < 0 || index >= row) return;
	int** tmp = new int* [--row];
	for (size_t i = 0; i < row; i++)
	{
		if (i < index)
		{
			tmp[i] = arr[i];
		}
		else
		{
			tmp[i] = arr[i + 1];
		}
	}
	delete[] arr[index];
	delete[] arr;
	arr = tmp;
}

void firstRow(int**& arr, int& row, const int& col)
{
	int** tmp = new int* [row + 1];
	for (size_t i = 0; i < row; i++)
	{
		tmp[i + 1] = arr[i];
	}
	tmp[0] = new int[col] {};
	row++;
	delete[] arr;
	arr = tmp;
}
void lastRow(int**& arr, int& row, const int& col)
{
	int** tmp = new int* [row + 1];
	for (size_t i = 0; i < row; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[row] = new int[col] {};
	row++;
	delete[] arr;
	arr = tmp;
}

void deleteFirstRow(int**& arr, int& row, const int& col)
{
	int** tmp = new int* [--row];
	for (size_t i = 0; i < row; i++)
	{
		tmp[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	arr = tmp;
}
void deleteLastRow(int**& arr, int& row, const int& col)
{
	int** tmp = new int* [--row];
	for (size_t i = 0; i < row; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr[row];
	delete[] arr;
	arr = tmp;
}

//Cols
void insertCol(int** arr, const int& row, int& col, const int& index)
{
	if (index < 0 || index > col) return;
	for (size_t i = 0; i < row; i++)
	{
		int* tmp = new int[col + 1] {};
		for (size_t j = 0; j < col; j++)
		{
			if (j < index)
			{
				tmp[j] = arr[i][j];
			}
			else
			{
				tmp[j + 1] = arr[i][j];
			}
		}
		tmp[index] = 33;
		delete[] arr[i];
		arr[i] = tmp;
	}
	col++;
}
void deleteCol(int** arr, const int& row, int& col, const int& index)
{
	if (index < 0 || index >= col) return;
	col--;
	for (size_t i = 0; i < row; i++)
	{
		int* tmp = new int[col] {};
		for (size_t j = 0; j < col; j++)
		{
			if (j < index)
			{
				tmp[j] = arr[i][j];
			}
			else
			{
				tmp[j] = arr[i][j + 1];
			}
		}
		delete[] arr[i];
		arr[i] = tmp;
	}
}

void firstCol(int** arr, const int& row, int& col)
{
	for (size_t i = 0; i < row; i++)
	{
		int* tmp = new int[col + 1]{};
		for (size_t j = 0; j < col; j++)
		{
			tmp[j + 1] = arr[i][j];
		}
		tmp[0] = 33;
		delete[] arr[i];
		arr[i] = tmp;
	}
	col++;
}
void lastCol(int** arr, const int& row, int& col)
{
	for (size_t i = 0; i < row; i++)
	{
		int* tmp = new int[col + 1]{};
		for (size_t j = 0; j < col; j++)
		{
			tmp[j] = arr[i][j];
		}
		tmp[col] = 33;
		delete[] arr[i];
		arr[i] = tmp;
	}
	col++;
}

void deleteFirstCol(int**& arr, const int& row, int& col)
{
	col--;
	for (size_t i = 0; i < row; i++)
	{
		int* tmp = new int[col] {};
		for (size_t j = 0; j < col; j++)
		{
			tmp[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = tmp;
	}
}
void deleteLastCol(int**& arr, const int& row, int& col)
{
	col--;
	for (size_t i = 0; i < row; i++)
	{
		int* tmp = new int[col] {};
		for (size_t j = 0; j < col; j++)
		{
			tmp[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = tmp;
	}
}

int main()
{
    int row = 3, col = 3;
    int** ptr = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		ptr[i] = new int[col] {};
	}
	fill(ptr, row, col);
	print(ptr, row, col, "Array:");
	cout << endl;


	firstRow(ptr, row, col);
	print(ptr, row, col, "Array with added first row:");
	lastRow(ptr, row, col);
	print(ptr, row, col, "Array with added last row:");

	deleteFirstRow(ptr, row, col);
	print(ptr, row, col, "Array with deleted first row:");
	deleteLastRow(ptr, row, col);
	print(ptr, row, col, "Array with deleted last row:");

	cout << endl;
	insertRow(ptr, row, col, 1);
	print(ptr, row, col, "Array with inserted row:");
	deleteRow(ptr, row, 1);
	print(ptr, row, col, "Array with deleted row:");
	cout << endl;

	firstCol(ptr, row, col);
	print(ptr, row, col, "Array with added first col:");
	lastCol(ptr, row, col);
	print(ptr, row, col, "Array with added last col:");

	deleteFirstCol(ptr, row, col);
	print(ptr, row, col, "Array with deleted first col:");
	deleteLastCol(ptr, row, col);
	print(ptr, row, col, "Array with deleted last col:");

	cout << endl;
	insertCol(ptr, row, col, 2);
	print(ptr, row, col, "Array with inserted col:");
	deleteCol(ptr, row, col, 2);
	print(ptr, row, col, "Array with deleted col:");

	for (size_t i = 0; i < row; i++)
	{
		delete[] ptr[i];
	}
	delete[] ptr;
}