#include <iostream>
//#include "arrays.h"
#include "functions.h"
using namespace std;

/*template <typename T>
T sum(T first, T second)
{
    T result = first + second;
    return result;
}
template <typename T>
T Pow(T number, int pow)
{
    T mult = 1;
    for (size_t i = 0; i < pow; i++)
    {
        mult *= number;
    }
    return mult;
}
template <typename T, typename T2>
auto sub(T first, T2 second)
{
    auto res = first - second;
    return res;
}

inline int mult(int a, int b)
{
    return a * b;
}*/

int main()
{
    srand(time(0));

    /*string arr[10];
    inputArray(arr, 10);
    printArray(arr, 10);

    cout << endl;

    cout << "Int \t : " << sum(1, 5) << endl;
    cout << "Double \t : " << sum(5.9, 5.5) << endl;
    cout << "Char \t : " << sum('a', 'A') << endl;
    cout << "Bool \t : " << sum(true, false) << endl;
    string line = "Red", line2 = " Blue";
    cout << "String \t : " << sum(line, line2) << endl;

    cout << "\n\n=====================\n\n";
    cout << "Int \t : " << Pow(1, 5) << endl;
    cout << "Double \t : " << Pow(5.9, 5) << endl;
    cout << "Char \t : " << Pow('a', 2) << endl;
    cout << "Bool \t : " << Pow(true, false) << endl;

    cout << "\n\n=====================\n\n";
    cout << "Int \t : " << sub(10, 5.5) << endl;
    cout << "Double \t : " << sub(5.9, 5.5) << endl;
    cout << "Char \t : " << sub('a', 32) << endl;
    cout << "Bool \t : " << sub(true, false) << endl;

    cout << "\n\n=====================\n\n";
    cout << "Int \t : " << Pow(1, 5) << endl;
    cout << "Double \t : " << Pow(5.9, 5) << endl;
    cout << "Char \t : " << Pow('a', 2) << endl;
    cout << "Bool \t : " << Pow(true, false) << endl;*/

    const int SIZE = 10;
    int arr[SIZE];
    double arrD[SIZE];
    char arrC[SIZE];
    string arrS[SIZE];

    /*cout << "Int: " << endl;
    inputArray(arr, SIZE);
    printArray(arr, SIZE);

    cout << endl;
    int res_num = firstNum(arr, SIZE);
    cout << "First index of your number: " << res_num;
    res_num = lastNum(arr, SIZE);
    cout << "Last index of your number: " << res_num;
    cout << endl << endl;

    cout << "Randomed array: ";
    randomArray(arr, SIZE);
    printArray(arr, SIZE);

    cout << endl;
    sameNum(arrC, SIZE);
    printArray(arrC, SIZE);

    cout << "\nFiltered array: ";
    filteredArray(arr, SIZE);
    cout << "Second filtered array: ";
    filteredArray2(arr, SIZE);*/

    /*cout << "Double: " << endl;
    inputArray(arrD, SIZE);
    printArray(arrD, SIZE);

    cout << "\nRandomed array: ";
    randomArray(arrD, SIZE);
    printArray(arrD, SIZE);

    cout << endl;
    sameNum(arrC, SIZE);
    printArray(arrC, SIZE);

    cout << "\nFiltered array: ";
    filteredArray(arrD, SIZE);
    cout << "Second filtered array: ";
    filteredArray2(arrD, SIZE);*/

    /*cout << "Char: " << endl;
    inputArray(arrC, SIZE);
    printArray(arrC, SIZE);

    cout << "\nRandomed array: ";
    randomArray(arrC, SIZE);
    printArray(arrC, SIZE);

    cout << endl;
    sameNum(arrC, SIZE);
    printArray(arrC, SIZE);*/

    /*cout << "String: " << endl;
    inputArray(arrS, SIZE);
    printArray(arrS, SIZE);

    cout << "\nRandomed array: ";
    randomArray(arrS, SIZE);
    printArray(arrS, SIZE);

    cout << endl;
    sameNum(arrS, SIZE);
    printArray(arrS, SIZE);*/

    const int ROW = 3, COL = 3;
    int matrix[ROW][COL], index;

    inputArry(matrix, ROW, COL);
    coutArry(matrix, ROW, COL);
    int max = maxInMatrix(matrix, ROW, COL);
    cout << "Max: " << max << endl;

    cout << "Enter the row index to check if it's sorted: "; cin >> index;
    if (isRowSorted(matrix, ROW, COL, index)) {
        cout << "Row " << index << " is sorted in ascending order." << endl;
    }
    else {
        cout << "Row " << index << " is not sorted in ascending order or the row index is invalid" << endl;
    }
    if (isRowSorted(matrix, ROW, COL, index))
    {
        cout << "Matrix is sorted in ascending order" << endl;
    }
    else
    {
        cout << "Matrix is not sorted in ascending order" << endl;
    }
}