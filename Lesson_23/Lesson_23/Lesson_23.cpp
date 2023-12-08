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

void pushBack(int* &arr, int &length, const int &value)
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
int* pushBack2(int* arr, int& length, const int& value)
{
    int* ptr_tmp = new int[length + 1];
    for (size_t i = 0; i < length; i++)
    {
        ptr_tmp[i] = arr[i];
    }
    ptr_tmp[length] = value;
    length++;
    delete[] arr;
    return ptr_tmp;
}

void popFront(int*& arr, int& length)
{
    length--;
    int* tmp = new int[length];
    for (size_t i = 0; i < length; i++)
    {
        tmp[i] = arr[i + 1];
    }
    delete[] arr;
    arr = tmp;
}

void pushFront(int*& arr, int& length, const int& value)
{
    int* ptr_tmp = new int[length + 1];
    for (size_t i = 0; i < length; i++)
    {
        ptr_tmp[i + 1] = arr[i];
    }
    ptr_tmp[0] = value;
    length++;
    delete[] arr;
    arr = ptr_tmp;
}

void popBack(int*& arr, int& length)
{
    length--;
    int* tmp = new int[length];
    for (size_t i = 0; i < length; i++)
    {
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
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

int main()
{
    /*int* pointer = new int;
    double* pointer_double = new double;

    *pointer = 12;
    *pointer_double = 58.3;

    cout << "Pointer Int [" << pointer << "] \t Value: " << *pointer << endl;
    cout << "Pointer Double [" << pointer_double << "] \t Value: " << *pointer_double << endl;

    delete pointer;
    delete pointer_double;*/

    //int arr[size]; const size
    /*int size;
    cout << "Enter size of array: "; cin >> size;
    int* ptr_arr = new int[size];

    fill(ptr_arr, size);
    print(ptr_arr, size);
    cout << ptr_arr[0] << endl;
    ptr_arr[0] = 333;
    cout << ptr_arr[0] << endl;
    print(ptr_arr, size);
    
    delete []ptr_arr;

    ptr_arr = nullptr;
    if (ptr_arr != nullptr)
    {
        print(ptr_arr, size);
    }*/
    
    /*int i = 1;
    double* ptr;
    while (true)
    {
        cout << i << endl;
        ptr = new double[100000];
    }*/

    int size = 5;
    /*cout << "Enter size of array: "; cin >> size;*/
    int* ptr_arr = new int[size];

    fill(ptr_arr, size);
    print(ptr_arr, size);
    cout << "------------------------------------------------" << endl;
    pushBack(ptr_arr, size, 333);
    print(ptr_arr, size);
    cout << "------------------------------------------------" << endl;
    popFront(ptr_arr, size);
    print(ptr_arr, size);
    cout << "------------------------------------------------" << endl;
    pushFront(ptr_arr, size, 222);
    print(ptr_arr, size);
    cout << "------------------------------------------------" << endl;
    popBack(ptr_arr, size);
    print(ptr_arr, size);
    cout << "------------------------------------------------" << endl;
    insert(ptr_arr, size, 1, 12);
    print(ptr_arr, size);
}