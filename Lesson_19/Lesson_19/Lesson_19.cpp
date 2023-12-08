#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0 or n == 1) return 1;
    return n * fact(n - 1);
}

double Pow(double n, int step)
{
    if (step == 1) return n;
    if (step == 0) return 1;

    return n * Pow(n, step - 1);
}

void stars(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << "* ";
        stars(n - 1);
    }
}

int sum(int a, int b)
{

    if (b == a)
    {
        return a;
    }
    else
    {
        return a + sum(a + 1, b);
    }
}

int maxDivider(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return maxDivider(b, a % b);
    }
}

int maxNum(int a)
{
    if (a < 10)
    {
        return a;
    }
    else
    {
        int last = a % 10;
        int rest = a / 10;
        int maxRest = maxNum(rest);
        return last > maxRest ? last : maxRest;
    }
}

bool simpleNum(int n, int i = 2)
{
    if (n <= 2) {
        return (n == 2) ? true : false;
    }
    if (n % i == 0) {
        return false;
    }
    if (i * i > n) {
        return true;
    }
    return simpleNum(n, i + 1);
}

int main()
{
    cout << "Result: " << fact(5) << endl;
    cout << "Pow: " << pow(2, 4) << endl;

    int n;
    cout << "Enter the number: "; cin >> n;
    stars(n);
    cout << endl;

    int a, b;
    cout << "Enter the range: "; cin >> a >> b;
    cout << "Sum: " << sum(a, b) << endl;

    cout << "Enter two numbers: "; cin >> a >> b;
    cout << "Max divider: " << maxDivider(a, b) << endl;

    cout << "Enter the number: "; cin >> a;
    cout << "Max number: " << maxNum(a) << endl;

    cout << "Enter the number: "; cin >> n;
    int simple = simpleNum(n);
    if (simple == 1)
    {
        cout << "Your number is simple" << endl;
    }
    else if (simple == 0)
    {
        cout << "Your number is not simple" << endl;
    }
}