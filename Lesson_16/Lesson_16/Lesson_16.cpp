#include <iostream>
using namespace std;

/*void printSum()
{
    int a, b;
    for (size_t i = 1; i <= 2; i++)
    {
        cout << "Enter two numbers: "; cin >> a >> b;
        cout << "Example " << i << ": " << a + b << endl << endl;
    }
}

int sum()
{
    int a, b;
    cout << "Enter two numbers: "; cin >> a >> b;
    int sum = a + b;
    return sum;
}

double sub(double a, double b)
{
    if (a > b)
    {
        return a - b;
    }
    return b - a;
}

char upChar(char s)
{
    if (s >= 'a' && s <= 'z')
    {
        return s - 32;
    }
    return s;
}

string test(int a)
{
    if (a % 2 == 0)
    {
        return "even";
    }
    return "odd";
}*/



/*void rectangle()
{
    int n, k;
    cout << "Enter two numbers: "; cin >> n >> k;
    cout << endl;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}*/

/*int num;
int factorial(int fact)
{
    for (size_t i = 1; i < num; i++)
    {
        fact *= i;
    }
    return fact;
}*/

/*bool isPrime(int num)
{
    for (size_t i = 2; i * i <= num; i++)
    {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}*/

/*int cubedNum(int num)
{
    int cube;
    
    cube = num * num * num;

    cout << "Cubed number: " << cube << endl;

    return cube;
}*/

/*int twoNums(int num1, int num2)
{
    if (num1 > num2)
    {
        cout << num1 << endl;
        return num1;
    }
    cout << num2 << endl;
    return num2;
}*/

/*bool isNum(int num)
{
    if (num >= 0) return true;
    return false;
}*/



/*int twoNums(int num1, int num2)
{
    if (num1 < num2)
    {
        cout << num1 << endl;
        return num1;
    }
    cout << num2 << endl;
    return num2;
}*/

/*int powerNum(int num, int power)
{
    int sum = 1;
    for (size_t i = 0; i < power; i++)
    {
        sum *= num;
    }
    return sum;
}*/

/*int miniCalc(int num1, int num2, char ent)
{
    int equal;

    if (ent == '*') equal = num1 * num2;
    if (ent == '/') equal = num1 / num2;
    if (ent == '+') equal = num1 + num2;
    if (ent == '-') equal = num1 - num2;

    return equal;
}*/



int main()
{
    /*int res_sum = sum();

    cout << "Avg: " << res_sum / 2.0 << endl;*/

    /*cout << "Example: " << sub(2.5, 5.7) << endl;*/

    /*char res = upChar('w');
    cout << res << endl;

    int num;
    cout << "Enter the number: "; cin >> num;
    cout << test(num) << endl;
    cout << test(4) << endl;*/




    //rectangle();

    /*cout << "Enter the number: "; cin >> num;

    int res_fact = factorial(num);

    cout << "Factorial of the number is: " << res_fact << endl;*/

    /*int num;

    cout << "Enter the number: "; cin >> num;

    int res_isPrime = isPrime(num);

    cout << res_isPrime << endl;*/

    /*int num;
    cout << "Enter the number: "; cin >> num;

    cubedNum(num);*/

    /*int num1, num2;

    cout << "Enter the first number: "; cin >> num1;
    cout << "Enter the second number: "; cin >> num2;

    twoNums(num1, num2);*/

    /*int num;

    cout << "Enter the number: "; cin >> num;

    int res_is = isNum(num);

    cout << res_is << endl;*/



    /*int num1, num2;

    cout << "Enter the first number: "; cin >> num1;
    cout << "Enter the second number: "; cin >> num2;

    twoNums(num1, num2);*/

    /*int num, power;

    cout << "Enter the number: "; cin >> num;
    cout << "Enter the power: "; cin >> power;

    int res_sum = powerNum(num, power);

    cout << "Your number powered by " << power << " : " << res_sum << endl;*/

    /*int num1, num2;
    char ent;

    cout << "Enter two numbers: "; cin >> num1 >> num2;
    cout << "Enter what to do (/, *, +, -): "; cin >> ent;

    int res_equal = miniCalc(num1, num2, ent);

    cout << num1 << " " << ent << " " << num2 << " = " << res_equal;*/


}