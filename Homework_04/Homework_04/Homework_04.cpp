#include <iostream>
using namespace std;

int main()
{
    int input_num;

    cout << "Enter the number: "; cin >> input_num;
    
    if (input_num > 99999 && input_num < 1000001)
    {
        int a = input_num % 10;
        input_num /= 10;
        int b = input_num % 10;
        input_num /= 10;
        int c = input_num % 10;
        input_num /= 10;
        int d = input_num % 10;
        input_num /= 10;
        int e = input_num % 10;
        input_num /= 10;
        int f = input_num % 10;
        input_num /= 10;
        if (a + b + c == d + e + f)
        {
            cout << "Your number is lucky!";
        }
        else
        {
            cout << "Your number isn't lucky!";
        }
    }
    else
    {
        cout << "Sorry, your number isn't six digits.";
    }
}