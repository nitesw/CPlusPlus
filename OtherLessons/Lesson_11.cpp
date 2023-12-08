#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	/*srand(time(0));

	const int SIZE = 6;
	int arr[SIZE];*/

	/*arr[0] = rand() % 20 + 1;
	arr[1] = rand() % 20 + 1;
	arr[2] = rand() % 20 + 1;
	arr[3] = rand() % 20 + 1;
	arr[4] = rand() % 20 + 1;
	arr[5] = rand() % 20 + 1;*/

	/*int min = 78, max = 102, num = min;
	cout << "Array #1: ";
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % (max - min + 1) + min; // (0 + 78) - (24 + 78) 78......102
		//rand() % (max - min + 1) + min
		//rand() % (102 - 78 + 1) + 78
		if (arr[i] > num)
		{
			num = arr[i];
		}
		cout << arr[i] << "\t";
	}
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\nMaximum number is: " << num;
	cout << "\n-----------------------------------------------------------------" << endl;
	
	min = -202, max = 1;
	num = max;
	cout << "Array #2: ";
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % (max - min + 1) + min; // (0 + 78) - (24 + 78) 78......102
		//rand() % (max - min + 1) + min
		//rand() % (1 - -202 + 1) + -202	// 0 - 202 ........
		if (arr[i] < num)
		{
			num = arr[i];
		}
		cout << arr[i] << "\t";
	}
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\nMinimum number is: " << num;
	cout << "\n-----------------------------------------------------------------" << endl;

	min = 400, max = 500;
	cout << "Array #3: ";
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % (max - min + 1) + min; // (0 + 78) - (24 + 78) 78......102
		//rand() % (max - min + 1) + min
		//rand() % (102 - 78 + 1) + 78
		cout << arr[i] << "\t";
	}
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n-----------------------------------------------------------------" << endl;

	/*cout << "Reverse Array: " << endl;
	for (int i = SIZE - 1; i >= 0; i--)
	{
		cout << arr[i] << "\t";
	}*/

	/*cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl;
	cout << arr[5] << endl;*/

	/*cout << sizeof(arr) / sizeof(int) << endl;*/

	/*const int SIZE = 6;
	int sum = 0, num;

	cout << "Profit calculator" << endl;
	cout << "Profit of the months" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << " month: "; cin >> num;
		sum += num;
	}

	cout << "Porfit of the company is: " << sum << endl;*/

	/*srand(time(0));

	const int SIZE = 6;
	int arr[SIZE], min = 1, max = 30;

	cout << "Array: " << endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
		cout << arr[i] << "\t";
	}
	
	cout << "\nReverse Array: " << endl;
	for (int i = SIZE - 1; i >= 0; i--)
	{
		cout << arr[i] << "\t";
	}*/

	/*const int SIZE = 1;
	int sum = 0, side, sides[SIZE];

	cout << "Enter the side of pentagon: "; cin >> side;

	for (int i = 0; i < SIZE; i++)
	{
		sides[0] = side;
	}

	cout << "Perimetr of pentagon is: " << sides[0] * 5 << endl;*/

	const int SIZE = 12;
	double price[SIZE]{};
	string month[]{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Enter profit of the " << month[i] << " : "; cin >> price[i];
	}
	cout << endl;

	double min = price[0], max = price[0];
	int minID = 0, maxID = 0;
	for (size_t i = 0; i < SIZE; i++)
	{
		if (price[i] < min) { min = price[i]; minID = i; }
		if (price[i] > max) { max = price[i]; maxID = i; }
	}

	cout << "Max profit: " << max << " in " << month[maxID] << endl;
	cout << "Min profit: " << min << " in " << month[minID] << endl;
}