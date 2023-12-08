#include <iostream>
using namespace std;

int rightWay(int a, int b)
{
    if (b == a)
    {
        return a;
    }
    else
    {
        cout << a << " ";
        rightWay(a + 1, b);
    }
}
int backWay(int a, int b)
{
    if (b == a)
    {
        return b;
    }
    else
    {
        cout << b << " ";
        backWay(a, b - 1);
    }
}

int reverseNum(int num)
{
    if (num == 0)
    {
        return num;
    }
    else
    {
        int a = num % 10;
        num /= 10;
        cout << a;
        reverseNum(num);
    }
}

int sumNum(int num)
{
    if (num < 10) {
        return num;
    }
    else {
        int firstDigit = num % 10;
        int restOfDigits = num / 10;
        return firstDigit + sumNum(restOfDigits);
    }
}

void brackets(int num)
{
    char bracket1 = '(';
    char bracket2 = ')';
    

    if (num == 0)
    {
        return;
    }
    cout << '(';
    brackets(num - 1);
    cout << ')';
}

int main()
{
    int firstNum, secondNum;
    cout << "Enter two numbers to make a range: "; cin >> firstNum >> secondNum;
    if (firstNum > secondNum)
    {
        int tmp = firstNum;
        secondNum = firstNum;
        firstNum = tmp;
    }
    rightWay(firstNum, secondNum + 1);
    cout << endl << endl;

    cout << "Enter two numbers to make a range: "; cin >> firstNum >> secondNum;
    if (firstNum > secondNum)
    {
        int tmp = firstNum;
        secondNum = firstNum;
        firstNum = tmp;
    }
    backWay(firstNum - 1, secondNum);
    cout << endl << endl;

    int num;
    cout << "Enter the number to reverse it: "; cin >> num;
    reverseNum(num);
    cout << endl << endl;

    cout << "Enter the number to sum digits: "; cin >> num;
    int res_sum = sumNum(num);
    cout << "Sum of the number: " << res_sum;
    cout << endl << endl;

    cout << "Enter the number: "; cin >> num;
    brackets(num);
    cout << endl << endl;
}