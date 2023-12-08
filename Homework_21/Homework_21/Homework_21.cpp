#include <iostream>
using namespace std;

template <typename T>
void linear(T a, T b) {
    if (a == 0) {
        if (b == 0) {
            cout << "Infinite solutions" << endl;
        }
        else {
            cout << "No solutions" << endl;
        }
    }
    else {
        T x = -b / a;
        cout << "Solution: " << x << endl;
    }
}
template <typename T>
void quadratic(T a, T b, T c) {
    if (a == 0) {
        linear(b, c);
        return;
    }

    T discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        cout << "No real solutions" << endl;
    }
    else if (discriminant == 0) {
        T x = -b / (2 * a);
        cout << "Double solution: " << x << endl;
    }
    else {
        T x1 = (-b + sqrt(discriminant)) / (2 * a);
        T x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Solutions: " << x1 << " and " << x2 << endl;
    }
}

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    int counter = 0;
    for (int j = 2; j < num; j++)
    {
        if (num % j == 0 && num != 2)
        {
            return false;
        }
    }
    return true;
}
int primes(int arr[], int length)
{
    int counter = 0;
    

    cout << "Prime numbers in the array: ";
    for (int i = 0; i < length; ++i) {
        if (isPrime(arr[i])) {
            cout << arr[i] << " ";
            counter++;
        }
    }
    cout << "\n";
    return counter;
}

void twoArr(int arr1[], int arr2[], int arr3[], int length)
{
    for (size_t i = 0; i < length / 2; i++)
    {
        arr3[i * 2] = arr1[i];
    }
    for (size_t i = 0; i < length / 2; i++)
    {
        arr3[i * 2 + 1] = arr2[i];
    }
    for (size_t i = 0; i < length; i++)
    {
        cout << arr3[i] << "\t";
    }
    cout << endl;
}

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}
double max(double num1, double num2) {
    return (num1 > num2) ? num1 : num2;
}
int max3(int num1, int num2, int num3)
{
    return max(max(num1, num2), num3);
}
double max3(double num1, double num2, double num3)
{
    return max(max(num1, num2), num3);
}
int maxArr(int arr[], int length)
{
    int max_val = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}
double maxArr(double arr[], int length)
{
    double max_val = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}
int maxMat(int matrix[][3], int rows, int cols)
{
    int max_val = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
        }
    }
    return max_val;
}
double maxMat(double matrix[][3], int rows, int cols)
{
    double max_val = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
        }
    }
    return max_val;
}

string toRoman(int n) {
    string result;
    const int numbers[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    const string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    for (int i = 0; i < 13; ++i) {
        while (n >= numbers[i]) {
            result += symbols[i];
            n -= numbers[i];
        }
    }
    return result;
}

int fib(int n) {
    if (n == 0 || n == 1) 
    {
        return n;
    }
    else 
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    //Основна дз
    /*linear(0, 0); 
    linear(0, 5); 
    linear(2, 4); 
    linear(3.5, -7.0);
    cout << endl;
    quadratic(0, 2, 3);  
    quadratic(1, -6, 9); 
    quadratic(1, 2, 1);  
    quadratic(2, -5, -3);
    quadratic(1.5, 2.5, -3.0);*/

    //До самостійної роботи, так як мені 8, зробив з 8 завдання по 12 (замість 11, 14)
    /*const int SIZE = 10;
    int arr[SIZE]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int counter = primes(arr, SIZE);

    cout << "There are " << counter << " prime numbers in the array.\n";*/

    /*const int SIZE = 10;
    int arr1[SIZE / 2]{ 1, 2, 3, 4, 5 };
    int arr2[SIZE / 2]{ 6, 7, 8, 9, 10 };
    int arr3[SIZE]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    twoArr(arr1, arr2, arr3, SIZE);*/

    /*cout << "The biggest number is(int): " << max(2, 4) << endl;
    cout << "The biggest number is (double): " << max(2.1, 1.3) << endl << endl;
    
    cout << "The biggest number is(int): " << max3(1, 2, 3) << endl;
    cout << "The biggest number is (double): " << max3(4.2, 3.2, 5.5) << endl << endl;

    const int size = 3;
    int arr[size]{ 2,77,24, };
    cout << "The biggest number is(int): " << maxArr(arr, size) << endl;
    double arrD[size]{ 1.5,99.2,99.21 };
    cout << "The biggest number is (double): " << maxArr(arrD, size) << endl << endl;

    int matrix[size][size] =
    {
    { 1,5,8 },
    { 4,22,8 },
    { 51,90,2 }
    };
    cout << "The biggest number is(int): " << maxMat(matrix, size, size) << endl;
    double matrixD[size][size] =
    {
    { 1.2,5.3,8.2 },
    { 4.1,22.8,8.9 },
    { 51.4,90.99,2.01 }
    };
    cout << "The biggest number is(double): " << maxMat(matrixD, size, size) << endl;*/

    /*int n;
    cout << "Enter the number to convert it into roman: "; cin >> n;
    cout << "Number in roman: " << toRoman(n) << endl;*/

    int n;
    cout << "Enter the number: "; cin >> n;
    int result = fib(n);
    cout << "Number is: " << result << endl;
}