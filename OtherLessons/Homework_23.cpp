#include <iostream>
using namespace std;

void fill(int* arr, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        arr[i] = rand() % 21 - 10;
    }
}
void print(int* arr, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void deleteArr(int*& arr)
{
    delete[] arr;
    arr = nullptr;
}

void pushBack(int*& arr, int& length, const int& value)
{
    int* ptr_tmp = new int[length + 1];
    for (size_t i = 0; i < length; i++)
    {
        ptr_tmp[i] = arr[i];
    }
    ptr_tmp[length] = value;
    length++;
    delete[] arr;
    arr = ptr_tmp;
}

void insert(int*& arr, int& length, const int& index, const int& value)
{
    length++;
    int* tmp = new int[length];
    for (size_t i = 0; i < length; i++)
    {
        tmp[i] = arr[i];
    }
    tmp[index] = value;
    for (size_t i = index + 1; i < length; i++)
    {
        tmp[i] = arr[i - 1];
    }
    delete[] arr;
    arr = tmp;
}

void deleteIns(int*& arr, int& length, const int& index)
{
    length--;
    int* tmp = new int[length];
    for (size_t i = 0, j = 0; i < length; i++)
    {
        if (i == index)
        {
            tmp[i] = arr[i + 1];
        }
        else
        {
            tmp[i] = arr[i];
        }
    }
    delete[] arr;
    arr = tmp;
}

int main()
{
    int size = 5;
    int* ptr_arr = new int[size];

    fill(ptr_arr, size);
    print(ptr_arr, size);
    //deleteArr(ptr_arr);
    pushBack(ptr_arr, size, 1);
    print(ptr_arr, size);
    insert(ptr_arr, size, 5, 8);
    print(ptr_arr, size);
    deleteIns(ptr_arr, size, 5);
    print(ptr_arr, size);
}