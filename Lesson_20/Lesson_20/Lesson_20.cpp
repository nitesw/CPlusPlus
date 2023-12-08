#include <iostream>
#include <ctime>
using namespace std;

void fill(int arr[], size_t length, int min = 1, int max = 30)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void quickSort(int arr[], int left, int right)
{
	int pivot = arr[left];
	int tmp_left = left;
	int tmp_right = right;
	while (left < right)
	{
		while (arr[right] >= pivot && left < right) right--;
		if (left != right)
		{
			arr[left] = arr[right];
			left++;
		}
		while (arr[left] <= pivot && left < right) left++;
		if (left != right)
		{
			arr[right] = arr[left];
		}
	}
	arr[left] = pivot;
	pivot = left;
	left = tmp_left;
	right = tmp_right;
	if (left < pivot)
	{
		quickSort(arr, left, pivot - 1);
	}
	if (right > pivot)
	{
		quickSort(arr, pivot + 1, right);
	}
}

void print(int arr[], size_t length, string text = "")
{
	cout << text;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int findFirst(int arr[], size_t length, int value)
{
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == value) return i;
	}
	return -1;
}

int binaryFind(int arr[], int left, int right, int key)
{
	int middle = (left + right) / 2;
	if (arr[middle] == key) return middle;
	if (left > right) return -1;
	if (key > arr[middle]) return binaryFind(arr, middle + 1, right, key);
	if (key < arr[middle]) return binaryFind(arr, left, middle - 1, key);

}

int main()
{
    srand(time(0));

	const size_t SIZE = 10;
	int arr[SIZE];

	fill(arr, SIZE);
	print(arr, SIZE, "\n\n\tPrint array before sorting: \t ");
	quickSort(arr, 0, SIZE - 1);
	print(arr, SIZE, "\n\n\tPrint array after sorting: \t ");

	int key;
	cout << "\n\n\tEnter searching value: "; cin >> key;
	cout << "\n\n\tPosition of element: " << binaryFind(arr, 0, SIZE, key) << endl;
}