#include <iostream>
using namespace std;

void SwapBad(int a, int b) // getting numbers not addresses
{
    int tmp = a;
    a = b;
    b = tmp;
}
void Swap(int& a, int& b) //getting the address
{
    int tmp = a;
    a = b;
    b = tmp;
}

void calculate(double* a, double* b, char* s, double* res)
{
    cout << "Enter number symbol number (2 + 3): ";
    cin >> *a >> *s >> *b;
    switch (*s)
    {
    case '+': *res = *a + *b; break;
    case '-': *res = *a - *b; break;
    case '*': *res = *a * *b; break;
    case '/': 
    { 
        if (*b == 0)
        {
            cout << "Error!\n"; return;
        }
        *res = *a / *b; 
        break; 
    }
    case '%': 
    { 
        if((int)*a != *a || (int)*b != *b)
        {
            cout << "Error!\n"; return;
        }
        *res = (int)*a % (int)*b;
        break;
    }
    }
}

void print(int arr[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        cout << *(arr++) << "\t";
    }
    cout << endl;
}

int sum(int arr[], int length)
{
    int sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += *(arr++);
    }
    return sum;
}

void result(int* arr, int length, int* sum, int* mult)
{
    *sum = 0;
    *mult = 1;
    for (size_t i = 0; i < length; i++)
    {
        *sum += *(arr + i);
        *mult *= *(arr + i);
    }
}

int main()
{
    /*int a = 10;
    int b = 15;
    int c = 25;
    int* pointer_a = nullptr;
    int* pointer_b;

    pointer_a = &a;
    pointer_b = &b;

    cout << "a = " << a << "\t b = " << b << endl;
    Swap(a, b);
    cout << "a = " << a << "\t b = " << b << endl;

    cout << "\n============================\n\n" << endl;
    cout << "Pointer a: " << pointer_a << " = " << *pointer_a << endl;
    cout << "Pointer b: " << pointer_b << " = " << *pointer_b << endl;

    int* pointer_c = pointer_a;
    cout << "\n============================\n\n" << endl;
    cout << "Pointer a: " << pointer_a << " = " << *pointer_a << endl;
    cout << "Pointer b: " << pointer_b << " = " << *pointer_b << endl;
    cout << "Pointer c: " << pointer_c << " = " << *pointer_c << endl;

    *pointer_a = 33;
    cout << "\n============================\n\n" << endl;
    cout << "Pointer a: " << pointer_a << " = " << *pointer_a << endl;
    cout << "Pointer b: " << pointer_b << " = " << *pointer_b << endl;
    cout << "Pointer c: " << pointer_c << " = " << *pointer_c << endl;*/

    /*int num1 = 10;
    int num2 = 15;
    int* ptrNum1 = &num1;
    int* ptrNum2 = &num2;

    if (*ptrNum1 > *ptrNum2)
    {
        cout << "The bigger number is: " << *ptrNum1 << endl;
    }
    else
    {
        cout << "The bigger number is: " << *ptrNum2 << endl;
    }*/

    /*int number;
    cout << "Enter the number: "; cin >> number;

    int* ptr = &number;

    if (*ptr > 0)
    {
        cout << "Your number is positive!" << endl;
    }
    else if (*ptr < 0)
    {
        cout << "Your number is negative!" << endl;
    }
    else
    {
        cout << "Your number equal to zero!" << endl;
    }*/

    /*const int size = 10;
    int arr[size]{ 5,7,8,9,6,10,2,3,6,5 };
    print(arr, size);

    int* ptr = arr;
    cout << "1. " << " : " << *ptr << endl;
    cout << "2. " << " : " << *(ptr++) << endl;
    cout << "3. " << " : " << *(++ptr) << endl;
    cout << "4. " << " : " << *(ptr--) << endl;
    cout << "5. " << " : " << *ptr << endl;*/

    /*double number1, number2;
    char symbol;
    double result;

    calculate(&number1, &number2, &symbol, &result);
    cout << number1 << " " << symbol << " " << number2 << " = " << result << endl;*/

    /*const int size = 5;
    int arr[size]{ 1, 2, 1, 1, 3 };

    cout << "Sum of all elements in array: " << sum(arr, size) << endl;*/



    const int size = 5;
    int arr[size]{ 1,2,2,1,2 };
    int sum, mult;

    result(arr, size, &sum, &mult);

    cout << "Sum: " << sum << endl;
    cout << "Mult: " << mult << endl;
}