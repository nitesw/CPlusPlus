#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    /*int a, b;
    cout << "Enter fist number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    cout << a << " + " << b << " = " << a + b << endl;*/

    /*int year;
    int FullYear = 365;

    cout << "Enter the year: ";
    cin >> year;

    bool f = year % 4 == 0 && year % 100 != 0;
    FullYear += f;

    cout << FullYear << " days" << endl;*/

    /* int height, width, lenght;

    cout << "Enter lenght: ";
    cin >> lenght;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;

    double volume = (double)height * (double)width * (double)lenght;

    cout << "Volume: " << volume << " centemiters cubic";*/

    /*double scale, dots;

    cout << "Enter the map scale (number of kilometers in one centimeter): ";
    cin >> scale;
    cout << "Enter the distance between points representing settlements (cm): ";
    cin >> dots;

    cout << "Distance between settlements: " << scale * dots << " Kilomiters";*/

    /*double radius;
    double volume;

    const double PI = 3.1415;

    cout << "Enter the radius of the sphere: ";
    cin >> radius;

    volume = ((4 / 3) * PI) * (pow(radius, 3));

    cout << "The volume of the sphere is: " << volume << endl;

    return 0;*/

    /*int h, m, s, sec;

    cout << "Enter seconds: ";
    cin >> sec;

    h = sec / 3600;
    m = sec % 3600 / 60;
    s = sec % 60;

    cout << (h < 10 ? "0" : "") << h << ":" << (m < 10 ? "0" : "") << m << ":" << s << (s < 10 ? "0" : "");*/

    /*int money;
    int coins;

    cout << "Enter amount of money: ";
    cin >> money;

    cout << "Enter amount of coins: ";
    cin >> coins;

    money = money + coins / 100;
    coins = coins % 100;

    cout << money << " uah " << coins << " coins" << endl;*/

    double coins, full;
    int money;

    cout << "Enter amount of money: ";
    cin >> full;

    money = full;
    coins = full % 100;

    cout << money << " UAH " << coins << "Cents";
}