#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	/*const int SIZE = 5;
	int arr1[SIZE]{ 1,-5,3,0,8 }, arr2[SIZE]{ -3,6,0,-4,-1 }, result[SIZE * 2];

	int resultIndex = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr1[i] > 0)
		{
			result[resultIndex] = arr1[i];
			resultIndex++;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (arr2[i] > 0)
		{
			result[resultIndex] = arr2[i];
			resultIndex++;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (arr1[i] == 0)
		{
			result[resultIndex] = arr1[i];
			resultIndex++;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (arr2[i] == 0)
		{
			result[resultIndex] = arr2[i];
			resultIndex++;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (arr1[i] < 0)
		{
			result[resultIndex] = arr1[i];
			resultIndex++;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (arr2[i] < 0)
		{
			result[resultIndex] = arr2[i];
			resultIndex++;
		}
	}

	cout << "Resulting array: ";
	for (int i = 0; i < 2 * SIZE; i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;*/

	/*const int SIZE = 10;
	int arr[SIZE]{}, newMark, index; 
	float sum = 0;
	char enter;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter the " << i + 1 << " grade: "; cin >> arr[i];
	}

	for (;;)
	{
		cout << "\nWould you like to correct a grade? (y/n): "; cin >> enter;
		if (enter == 'y')
		{
			cout << "\nEnter index of which grade would you like to change?: "; cin >> index;
			if (index > 0)
			{
				cout << "Enter the new mark: "; cin >> newMark;
				if (newMark > 0)
				{
					arr[index - 1] = newMark;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		else if (enter == 'n')
		{
			break;
		}
	}

	cout << "\nGrades of the student: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
	}

	if (sum / SIZE > 10.7)
	{
		cout << "\nThe student will receive scholarship." << endl;
	}
	else
	{
		cout << "\nThe student won't receive scholarship." << endl;
	}*/

	srand(time(0));

	const int SIZE = 9;
	int arr[SIZE]{};

	int min = -50, max = 50, sum = 0;
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
		sum += arr[i];
	}
	cout << "Your numbers: ";
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}

	int start = 2 * (SIZE / 3);
	int end = SIZE - 1;

	while (start < end) {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}

	cout << "\n\nSum is: " << sum;
	if (sum / 9 > 0)
	{
		int one_third = SIZE / 3;
		int two_thirds = 2 * one_third;
		for (size_t i = 0; i < two_thirds; i++)
		{
			for (size_t j = 0; j < two_thirds - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
	else
	{
		int one_third = SIZE / 3;

		for (int i = 0; i < one_third - 1; i++)
		{
			for (int j = 0; j < one_third - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	cout << "\n\nRight array: ";
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}