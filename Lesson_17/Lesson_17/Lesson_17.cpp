#include <iostream>
#include <ctime>
#include <iomanip>
#include "calculate.h"
#include "arrays.h"
using namespace std;

/*void fillArray(int arr[], int length, int min = 1, int max = 10)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = rand() % (max - min - 1) + min;
	}
}
void fillArray(double arr[], int length, int min = 1, int max = 10)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = rand() % ((max - min - 1) + min) / 3.0;
	}
}
void printArray(int arr[], int length, string help = "\nPrinted Array: ")
{
	cout << help;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void printArray(double arr[], int length, string help = "\nPrinted Array: ")
{
	cout << help;
	for (size_t i = 0; i < length; i++)
	{
		cout << fixed;
		cout << setprecision(2);
		cout << arr[i] << "\t";
	}
	cout << endl;
}*/

int main()
{
	/*cout << calculate(5, 6, '/') << endl;

	cout << "Sum int: " << sum(1, 2) << endl;
	cout << "Sum double: " << sum(1.3, 2.6) << endl;
	cout << "Sum char: " << sum('A', 3) << endl;
	cout << "Sum str: " << sum("Hello ", "World!") << endl;*/

	const int SIZE = 10;
	char symbol;
	string str;
	int num;

	int arrInt[SIZE];
	double arrDouble[SIZE];
	char arrChar[SIZE];
	string arrString[SIZE];

	cout << "Enter the symbol: "; cin >> symbol;
	cout << "Enter the string: "; cin >> str;
	cout << "Enter the number to see the position of it: "; cin >> num;
	cout << endl;

	fillArray(arrInt, SIZE);
	printArray(arrInt, SIZE);

	cout << "\nThe position of the number: " << searchNum(arrInt, SIZE, num) << endl;
	cout << "\nThe position of min number: " << minNumPos(arrInt, SIZE) << endl;
	cout << "\nThe position of max number: " << maxNumPos(arrInt, SIZE) << endl;

	reverseArray(arrInt, SIZE);

	filteredArray(arrInt, SIZE);

	cout << "\nMin number: " << minNum(arrInt, SIZE) << endl;
	cout << "\nMax number: " << maxNum(arrInt, SIZE) << endl;

	cout << endl;

	fillArray(arrDouble, SIZE);
	printArray(arrDouble, SIZE);

	cout << "\nThe position of min number: " << minNumPos(arrDouble, SIZE) << endl;
	cout << "\nThe position of max number: " << maxNumPos(arrDouble, SIZE) << endl;

	reverseArray(arrDouble, SIZE);

	filteredArray(arrDouble, SIZE);

	cout << "\nMin number: " << minNum(arrDouble, SIZE) << endl;
	cout << "\nMax number: " << maxNum(arrDouble, SIZE) << endl;

	cout << endl;

	fillArray(arrChar, SIZE, symbol);
	printArray(arrChar, SIZE);

	cout << endl;

	fillArray(arrString, SIZE, str);
	printArray(arrString, SIZE);

	cout << endl;
}