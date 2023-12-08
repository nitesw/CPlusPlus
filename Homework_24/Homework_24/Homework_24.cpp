#include <iostream>
#include <ctime>
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

void twoArr(int*& arr1, int*& arr2, int& size1, int& size2)
{
    int* new_arr = new int[size1 + size2];
    int step = 0;

    for (size_t i = 0; i < size1; i++)
    {
        new_arr[i] = arr1[i];
        step++;
    }
    for (size_t i = 0; i < size2; i++)
    {
        new_arr[i + size1] = arr2[i];
        step++;
    }

    delete[] arr1, arr2;
    arr1 = new_arr;
    size1 = step;
}

void numArr(int*& arr1, int*& arr2, int& size1, int& size2)
{
    int* new_arr = new int[size1 + size2];
    int step = 0;
    bool isUnique;

    for (size_t i = 0; i < size1; i++)
    {
        isUnique = false;
        for (size_t j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                isUnique = true;
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
        isUnique = false;
        for (size_t j = 0; j < size1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                isUnique = true;
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

void deleteSome(int*& arr, int& size, char choice)
{
    int* new_arr = new int[size];
    int step = 0;

    if (choice == 'o')
    {
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] % 2 == 0)
            {
                new_arr[step++] = arr[i];
            }
        }
    }
    else if (choice == 'e')
    {
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] % 2 != 0)
            {
                new_arr[step++] = arr[i];
            }
        }
    }

    delete[] arr;
    arr = new_arr;
    size = step;
}

int main()
{
    srand(time(0));

    int size1 = 5;
    int size2 = 7;
    int* ptr_arr1 = new int[size1];
    int* ptr_arr2 = new int[size2];

    fill(ptr_arr1, size1);
    print(ptr_arr1, size1);
    /*fill(ptr_arr2, size2);
    print(ptr_arr2, size2);*/
    cout << endl << endl;
    //twoArr(ptr_arr1, ptr_arr2, size1, size2);
    //numArr(ptr_arr1, ptr_arr2, size1, size2);
    char choice;
    do
    {
        cout << "What would you like to do - delete odds or even num? (o / e): "; cin >> choice;
    } while (choice != 'o' && choice != 'e');
    deleteSome(ptr_arr1, size1, choice);
    cout << endl << endl;
    cout << "New array: ";
    print(ptr_arr1, size1);
}