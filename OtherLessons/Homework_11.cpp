#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	/*const int SIZE = 12;
	int firstRange, secondRange;
	double price[SIZE]{};
	string month[]{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Enter profit of the " << month[i] << ": "; cin >> price[i];
	}
	cout << endl;

	double min = price[0], max = price[0];
	int minID = 0, maxID = 0;
	do
	{
		cout << "First range: ";
		cin >> firstRange;
		cout << "Second range: ";
		cin >> secondRange;
		if (secondRange <= firstRange)
		{
			cout << "Error when entering periods. Be careful." << endl;
			cout << "Please, enter the range." << endl;
		}
	} while (secondRange <= firstRange);

	max = price[firstRange - 1];
	min = price[firstRange - 1];

	for (int j = firstRange - 1; j <= secondRange - 1; j++)
	{
		if (min > price[j]) { min = price[j]; minID = j; }
		if (max < price[j]) { max = price[j]; maxID = j; }
	}

	cout << "Max profit: " << max << " in " << month[maxID] << endl;
	cout << "Min profit: " << min << " in " << month[minID] << endl;*/

	srand(time(0));

	const int SIZE = 10;
	int arr[SIZE];
	int arrNegatives[SIZE];

	int min = -20, max = 20, enterNum, fullSum = 0, minNum = max, maxNum = min, sum = 1;
	int	twinNum = 1, sumBetween = 0, negativeIndex = 0;

	cout << "Enter amount of numbers (less or equal to 10): ";
	cin >> enterNum;
	if (enterNum <= 10)
	{
		for (size_t i = 0; i < enterNum; i++)
		{
			arr[i] = rand() % (max - min + 1) + min;

			if (arr[i] < 0)
			{
				fullSum += arr[i];
			}
			if (arr[i] < minNum)
			{
				minNum = arr[i];
			}
			if (arr[i] > maxNum)
			{
				maxNum = arr[i];
			}
			if (arr[i] % 2 == 0)
			{
				twinNum = twinNum * arr[i];
			}
			if (arr[i] < 0)
			{
				arrNegatives[negativeIndex++] = arr[i];
			}
			cout << arr[i] << "\t";
		}

		for (int j = minNum; j <= maxNum; j++) {
			sum *= j;
		}
		for (int i = 0; i < negativeIndex - 1; i++) {
			sumBetween += arrNegatives[i + 1] - arrNegatives[i];
		}

		cout << "\n-----------------------------------------------------------------" << endl;

		cout << "The sum of all negative numbers: " << fullSum << endl;
		cout << "The product from " << minNum << " to " << maxNum << ": " << sum << endl;
		cout << "The product of all even numbers: " << twinNum << endl;
		cout << "Sum of elements between the first and last negative elements: " << sumBetween << endl;
	}
	else
	{
		cout << "\nError!" << endl;
	}
}