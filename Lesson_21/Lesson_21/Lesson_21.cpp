#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

bool isPlus(int num)
{
    if (num >= 0) return true;
    return false;
}
double avg(int arr[10], int length)
{
    double counter = 0;
    double number = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (arr[i] > 0) 
        {
            number += arr[i];
            counter++;
        }
    }
    return number / counter;
}

int max(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    return num2;
}
int min(int num1, int num2)
{
    if (num1 < num2)
    {
        return num1;
    }
    return num2;
}

bool isPrime(int num1)
{
    for (int j = 2; j < num1; j++) 
    {
        if (num1 % j == 0 && num1 != 2)
            return false;
    }
    return true;
}

int number() 
{
    return rand() % 6 + 1;
}

int arrPair(int arr[], int length)
{
    int count = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

void Array(int arr[], int length) {
    for (size_t i = 0; i < length; i++)
    {
        arr[i] = rand() % 5 + 1;
        cout << " " << arr[i] << " ";
    }
}
void reversedArr(int arr[], int length) {
    for (size_t i = length - 1; i >= 0 and i < -1; i--)
    {
        cout << " " << arr[i] << " ";
    }
}
void sortedArr(int arr[], int length) {
    int tmp = arr[0];
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < length - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (size_t i = 0; i < length; i++)
    {
        cout << " " << arr[i] << " ";
    }
}
int binaryFind(int arr[], int left, int right, int key) {
    int middle = (left + right) / 2;
    if (arr[middle] == key) return middle;
    if (left > right) return -1;
    if (key > arr[middle]) return binaryFind(arr, middle + 1, right, key);
    else if (key < arr[middle]) return binaryFind(arr, left, middle - 1, key);
}

int main()
{
    srand(time(0));

    /*const int SIZE = 10;
    
    int num;
    cout << "Enter the number: "; cin >> num;
    if (isPlus(num)) cout << "Your number is positive" << endl;
    else cout << "Your number is negative" << endl;

    int arr[SIZE]{ 0,5,1,-1,-7,2,7,9,-3,-6 };
    cout << "Avarage of positive numbers is: " << avg(arr, SIZE);*/

    /*int num1, num2, num3;
    cout << "Enter two numbers: "; cin >> num1 >> num2;
    cout << "The biggest number is: " << max(num1, num2) << endl;
    cout << "The smallest number is: " << min(num1, num2) << endl;
    cout << "Enter the other number: "; cin >> num3;

    cout << "Value of something: " << min(num1, num2) + max(num2 - num1, num3 + 1) + min(pow(num2, 2) + num1, pow(num3, 3));*/

    /*int num1, num2;
    cout << "Enter two number to create a range: "; cin >> num1 >> num2;
    for (size_t i = num1; i <= num2; i++)
    {
        cout << i << ": " << isPrime(i) << "\n";
    }*/

    /*int bal_user = 0, bal_bot = 0;
    const int size = 5;
    string go;
    bool step = true;
    for (size_t i = 0; i < 10; i++)
    {
        if (step == true) {
            cout << "User:: " << endl;
            for (size_t i = 0; i < size; i++)
            {
                for (size_t j = 0; j < size; j++)
                {
                    if (i == 0 or i == size - 1) cout << "*";
                    else if (j == 0 or j == size - 1) cout << "*";
                    else if (i == 2 and j == 2) cout << number();
                    else cout << " ";
                }
                cout << endl;
            }
            bal_user += number();
            step = false;
            cout << "Enter any symbol:: "; cin >> go;
        }
        else {
            cout << "Bot:: " << endl;
            for (size_t i = 0; i < size; i++)
            {
                for (size_t j = 0; j < size; j++)
                {
                    if (i == 0 or i == size - 1) cout << "*";
                    else if (j == 0 or j == size - 1) cout << "*";
                    else if (i == 2 and j == 2) cout << number();
                    else cout << " ";
                }
                cout << endl;
            }
            bal_bot += number();
            step = true;
        }
    }
    if (bal_user > bal_bot) {
        cout << "Win User" << endl;
        cout << bal_user / 5;
    }
    else if (bal_user < bal_bot) {
        cout << "Win Bot" << endl;
        cout << bal_user / 5;
    }
    else if (bal_user == bal_bot)cout << "Draw" << endl;*/

    /*double number;
    int end_num;
    cout << "Enter num :: ";
    cin >> number;
    cout << "Enter the number after the period:: ";
    cin >> end_num;
    cout << fixed << setprecision(end_num) << number;*/

    /*const int SIZE = 7;
    int arr[SIZE]{ 1,2,3,4,5,6,7 };

    cout << "All pair numbers in array: ";
    cout << arrPair(arr, SIZE);*/

    const int SIZE = 5;
    int arr[SIZE];
    int key;
    cout << "Enter key: "; cin >> key;
    cout << "Arry: ";
    Array(arr, SIZE);
    cout << endl;

    cout << "Revurs: ";
    reversedArr(arr, SIZE);
    cout << endl;

    cout << "Sort: ";
    sortedArr(arr, SIZE);
    cout << endl;

    cout << "Key: " << binaryFind(arr, 0, SIZE, key);
    
}