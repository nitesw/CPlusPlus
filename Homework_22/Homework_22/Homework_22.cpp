#include <iostream>
using namespace std;

void print(int* arr, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        cout << *(arr++) << "\t";
    }
    cout << endl;
}

void copyArr(int* arr1, int* arr2, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr2 + i) = *(arr1 + i);
    }
}
void reverse(int* arr, int size)
{
    int* ptr_start = arr;
    int* ptr_end = arr + size - 1;

    for (int i = 0; i < size / 2; i++) {
        int tmp = *(ptr_start + i);
        *(ptr_start + i) = *(ptr_end - i);
        *(ptr_end - i) = tmp;
    }
}

int main()
{
    const int size = 5;
    int arr1[size]{ 1,2,3,4,5 };
    int arr2[size];

    copyArr(arr1, arr2, size);
    cout << "Array 1: ";
    print(arr1, size);
    cout << "Array 2: ";
    print(arr2, size);
    cout << endl;

    reverse(arr1, size);
    cout << "Reversed array: ";
    print(arr1, size);
    cout << endl;

    copyArr(arr1, arr2, size);
    reverse(arr2, size);
    cout << "Copied and reversed array: ";
    print(arr2, size);
}