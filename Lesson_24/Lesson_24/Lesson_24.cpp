#include <iostream>
using namespace std;

void fill(int*& arr, int& length)
{
    for (size_t i = 0; i < length; i++)
    {
        arr[i] = rand() % 21 - 10;
    }
}
void print(int*& arr, int& length)
{
    for (size_t i = 0; i < length; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void diffArr(int*& arr1, int*& arr2, int& size1, int& size2)
{
    int* new_arr = new int[size1];
    int step = 0;
    bool isUnique;

    for (size_t i = 0; i < size1; i++)
    {
        isUnique = true;
        for (size_t j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            bool isDuplicate = false;
            for (int k = 0; k < step; k++) 
            {
                if (arr1[i] == new_arr[k]) 
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) 
            {
                new_arr[step] = arr1[i];
                step++;
            }
        }
    }

    int* result = new int[step];
    for (int i = 0; i < step; i++)
    {
        result[i] = new_arr[i];
    }

    delete[] new_arr;
    arr1 = result;
    size1 = step;
}

void notArr(int*& arr1, int*& arr2, int& size1, int& size2)
{
    int* new_arr = new int[size1 + size2];
    int step = 0;
    bool isUnique;

    for (size_t i = 0; i < size1; i++)
    {
        isUnique = true;
        for (size_t j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            bool isDuplicate = false;
            for (int k = 0; k < step; k++)
            {
                if (arr1[i] == new_arr[k])
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate)
            {
                new_arr[step] = arr1[i];
                step++;
            }
        }
    }
    for (size_t i = 0; i < size2; i++)
    {
        isUnique = true;
        for (size_t j = 0; j < size1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            bool isDuplicate = false;
            for (int k = 0; k < step; k++)
            {
                if (arr2[i] == new_arr[k])
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate)
            {
                new_arr[step] = arr2[i];
                step++;
            }
        }
    }

    int* result = new int[step];
    for (int i = 0; i < step; i++)
    {
        result[i] = new_arr[i];
    }

    delete[] new_arr;
    arr1 = result;
    size1 = step;
}

bool isPrime(int n) 
{
    if (n <= 1) 
    {
        return false;
    }
    for (int i = 2; i <= n - 1; i++) 
    {
        if (n % i == 0) 
        {
            return false;
        }
    }
    return true;
}

void delPrimes(int*& arr, int& length)
{
    int counter = 0;
    int* new_arr = new int[length];

    for (size_t i = 0; i < length; i++)
    {
        if (!isPrime(arr[i]))
        {
            new_arr[counter] = arr[i];
            counter++;
        }
    }

    delete[] arr;
    length = counter;
    arr = new_arr;
}

void sort(int*& arr, int& length)
{
    int pos_co = 0;
    int* arrPos = new int[length];
    int neg_co = 0;
    int* arrNeg = new int[length];
    int null_co = 0;
    int* arrNull = new int[length];

    for (size_t i = 0; i < length; i++)
    {
        if (arr[i] > 0)
        {
            arrPos[pos_co] = arr[i];
            pos_co++;
        }
        else if (arr[i] < 0)
        {
            arrNeg[neg_co] = arr[i];
            neg_co++;
        }
        else
        {
            arrNull[null_co] = arr[i];
            null_co++;
        }
    }

    delete[] arr;
    cout << "Positive numbers: ";
    length = pos_co;
    print(arrPos, length);
    delete[] arrPos;

    cout << "Negative numbers: ";
    length = neg_co;
    print(arrNeg, length);
    delete[] arrNeg;

    cout << "Null numbers: ";
    length = null_co;
    print(arrNull, length);
    delete[] arrNull;
}

int main()
{
    srand(time(0));

    /*int size1, size2;
    cout << "Enter length of the first array: "; cin >> size1;
    cout << "Enter length of the second array: "; cin >> size2;

    int* ptr_arr1 = new int[size1];
    int* ptr_arr2 = new int[size2];

    cout << endl;
    fill(ptr_arr1, size1);
    print(ptr_arr1, size1);
    fill(ptr_arr2, size2);
    print(ptr_arr2, size2);
    cout << endl;

    cout << "New array: ";
    diffArr(ptr_arr1, ptr_arr2, size1, size2);
    print(ptr_arr1, size1);
    cout << endl;

    cout << "Anoter array: ";
    notArr(ptr_arr1, ptr_arr2, size1, size2);
    print(ptr_arr1, size1);*/

    int size = 5;
    int* ptr_arr = new int[size];

    fill(ptr_arr, size);
    print(ptr_arr, size);
    /*delPrimes(ptr_arr, size);
    print(ptr_arr, size);*/
    cout << endl;

    sort(ptr_arr, size);
}