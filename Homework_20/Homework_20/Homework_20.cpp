#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
using namespace std;

void unique(int arr[], int length, int min = 1, int max = 15) {
	for (size_t i = 0; i < length;)
	{
		int tmp = rand() % (max - min + 1) + min;
		bool flag = true;
		for (size_t j = 0; j < i; j++)
		{
			if (arr[j] == tmp) {
				flag = false;
				break;
			}
		}
		if (flag) {
			arr[i] = tmp;
			i++;
		}
	}
}

bool isComplete(int arr[][4], int size)
{
	int sortedArr[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 0}
	};

	for (int i = 0; i < size; i++) 
	{
		for (int j = 1; j < size; j++) 
		{
			if (arr[i][j] != sortedArr[i][j]) 
			{
				return false;
			}
		}
	}
	return true;
	
}

void fill(int arr[][4], int arr2[], size_t size) {
	int q = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (q == 15) { arr[i][j] = 0; break; }
			arr[i][j] = arr2[q++];
		}
	}
}
void print(int arr[][4], int size) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {

	double start = clock();
	srand(time(0));

	const int size = 4;
	int arr[size][size]{};
	int arr2[size * size - 1]{};
	int row = size - 1, col = size - 1;
	unique(arr2, size * size - 1);
	fill(arr, arr2, size);
	print(arr, size);

	

	int key, counter = 0;
	do {
		key = _getch();
		system("cls");
		print(arr, size);
		switch (key)
		{
		case 75: {
			counter++;
			if (col == 0) continue;
			arr[row][col] = arr[row][col - 1];
			col--;
			arr[row][col] = 0;
			system("cls");
			print(arr, size);
			break;
		}
		case 77:
		{
			counter++;
			if (col == size - 1) continue;
			arr[row][col] = arr[row][col + 1];
			col++;
			arr[row][col] = 0;
			system("cls");
			print(arr, size);
			break;
		}
		case 72:
		{
			counter++;
			if (row == 0) continue;
			arr[row][col] = arr[row - 1][col];
			row--;
			arr[row][col] = 0;
			system("cls");
			print(arr, size);
			break;
		}
		case 80:
		{
			counter++;
			if (row == size - 1) continue;
			arr[row][col] = arr[row + 1][col];
			row++;
			arr[row][col] = 0;
			system("cls");
			print(arr, size);
			break;
		}
		}
	} while (key != 27 && isComplete(arr, size) == false);

	double end = clock();
	double timeSum = double(end - start) / CLOCKS_PER_SEC / 60;

	if (isComplete(arr, size) == true)
	{
		cout << "\nYou solve the puzzle, you win!" << endl << endl;
		cout << "Here some of your statistics: " << endl;
		cout << "Attempt you spent to solve it: " << counter << endl;
		cout << "Time you spent to solve this puzzle (minutes): " << setprecision(2) << fixed << timeSum << endl;
	}
	else
	{
		cout << "\nYou don't finish the puzzle!" << endl << endl;
		cout << "But here some of your statistics: " << endl;
		cout << "Attempt you spent: " << counter << endl;
		cout << "Time you spent (minutes): " << setprecision(2) << fixed << timeSum << endl;
	}
}