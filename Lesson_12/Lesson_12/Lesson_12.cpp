#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	const int SIZE = 10;
	int arr[SIZE]{ 1,0,2,-5,8,0,4,1,4,5 }; 
	/*for (size_t i = 0; i < SIZE; )
	{
		bool flag = true;
		int number = rand() % 10 + 1;
		for (size_t j = 0; j < i; j++)
		{
			if (arr[j] == number) {
				flag = false;
				break;
			}
		}
		if (flag) {
			arr[i] = number;
			i++;
		}
	}*/
	cout << "Print Array : ";
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	/*for (size_t i = 0; i < SIZE; i++)
	{
		if (arr[i] == 0)
		{
			for (size_t j = i + 1; j < SIZE; j++)
			{
				arr[j - 1] = arr[j];
			}
			arr[SIZE - 1] = -1;
		}
	}*/
	/*for (size_t i = 0; i < SIZE - 1; i++)
	{
		for (size_t j = 0; j < SIZE - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}*/

	for (size_t i = 0; i < SIZE; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

	cout << "Sorted Array: ";
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}