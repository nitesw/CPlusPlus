#include <iostream>
using namespace std;


int main()
{
    /*int age;
    cout << "Enter your age: "; cin >> age;

    if (age >= 0 && age <= 11)
    {
        cout << "You are a child!";
    }
    else if (age >= 12 && age <= 18)
    {
        cout << "You are a teenager!";
    }
    else if (age >= 19 && age <= 60)
    {
        cout << "You are an adult!";
    }
    else if (age >= 61)
    {
        cout << "You are a retired person!";
    }
    else
    {
        cout << "Error!";
    }*/

    /*int number;

    cout << "Enter three digits number: "; cin >> number;

    if (number > 99 && number < 1000)
    {
        int a = number % 10;
        number /= 10;
        int b = number % 10;
        number /= 10;
        int c = number % 10;
        number /= 10;

        if (a == b || a == c || c == b)
        {
            cout << "You have the same digits in your number.";
        }
        else
        {
            cout << "Sorry, you don't have the same digits in your number.";
        }
    }*/

    /*int year;

    cout << "Enter the year: "; cin >> year;

    if (year > 0)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            cout << "A leap year.";
        }
        else
        {
            cout << "Not a leap year.";
        }
    }
    else
    {
        cout << "Error.";
    }*/

    /*int number;

    cout << "Enter 5 digits number: "; cin >> number;

    if (number > 9999 && number < 100000)
    {
        int a = number % 10;
        number /= 10;
        int b = number % 10;
        number /= 100;
        int d = number % 10;
        number /= 10;
        int e = number % 10;
        number /= 10;

        if (a == e && b == d)
        {
            cout << "Your number is palindrome.";
        }
        else
        {
            cout << "Your number is not palindrome.";
        }
    }
    else
    {
        cout << "Error.";
    }*/

    /*double circle, square;

    cout << "Enter perimetr of the square: "; cin >> square;
    cout << "Enter lenght of the circle: "; cin >> circle;

    double circle_diam = 2 * circle;
    double squar_diag = square / (2 * sqrt(2));

    if (circle_diam <= squar_diag)
    {
        cout << "The circle can fit inside the square.";
    }
    else
    {
        cout << "The circle cannot fit inside the square.";
    }*/

    /*int score = 0, question_01, question_02, question_03;

    cout << "How many days in not a leap year?: "; cin >> question_01;
    
    if (question_01 == 365)
    {

        score += 2;
    }

    cout << "2 + 2 * 2 = ?: "; cin >> question_02;

    if (question_02 == 6)
    {
        score += 2;
    }

    cout << "In what year did the Baptism of Kyivan Rus take place?: "; cin >> question_03;

    if (question_03 == 988)
    {
        score += 2;
    }

    cout << "Here is your score: " << score;*/

    /*int hours, minutes, seconds;

    cout << "Enter hours, minutes, seconds: "; cin >> hours; cin >> minutes; cin >> seconds;

    if (hours >= 0 && hours <= 24)
    {
        cout << "You enter RIGHT number of hours." << endl;
    }
    else
    {
        cout << "You enter WRONG number of hours." << endl;
    }

    if (minutes >= 0 && minutes <= 60)
    {
        cout << "You enter RIGHT number of minutes." << endl;
    }
    else
    {
        cout << "You enter WRONG number of minutes." << endl;
    }
    if (seconds >= 0 && seconds <= 60)
    {
        cout << "You enter RIGHT number of seconds.";
    }
    else
    {
        cout << "You enter WRONG number of seconds.";
    }*/

    /*int x, y;

    cout << "Enter the x-axis coordinate: "; cin >> x;
    cout << "Enter the y-axis coordinate: "; cin >> y;

    if (x > 0 && y > 0)
    {
        cout << "Your coordinates belong to I group";
    }
    else if (x < 0 && y > 0)
    {
        cout << "Your coordinates belong to II group";
    }
    else if (x < 0 && y < 0)
    {
        cout << "Your coordinates belong to III group";
    }
    else if (x > 0 && y < 0)
    {
        cout << "Your coordinates belong to IV group";
    }
    else if (x == 0 && y > 0)
    {
        cout << "Your coordinates belong to I group and to II group";
    }
    else if (x == 0 && y < 0)
    {
        cout << "Your coordinates belong to III group and to IV group";
    }
    else if (x > 0 && y == 0)
    {
        cout << "Your coordinates belong to I group and to IV group";
    }
    else if (x < 0 && y == 0)
    {
        cout << "Your coordinates belong to II group and to III group";
    }
    else if (x == 0 && y == 0)
    {
        cout << "Your coordinates are not belong to any of groups";
    }*/

    /*int month;

    cout << "Enter the number of the month: "; cin >> month;

    switch (month)
    {
    case 1:
    {
        cout << "January";
        break;
    }
    case 2:
    {
        cout << "February";
        break;
    }
    case 3:
    {
        cout << "March";
        break;
    }
    case 4:
    {
        cout << "April";
        break;
    }
    case 5:
    {
        cout << "May";
        break;
    }
    case 6:
    {
        cout << "June";
        break;
    }
    case 7:
    {
        cout << "July";
        break;
    }
    case 8:
    {
        cout << "August";
        break;
    }
    case 9:
    {
        cout << "September";
        break;
    }
    case 10:
    {
        cout << "October";
        break;
    }
    case 11:
    {
        cout << "November";
        break;
    }
    case 12:
    {
        cout << "December";
        break;
    }
    default:
    {
        cout << "Error!";
        break;
    }
    }*/

    /*int day, month, year;

    cout << "Enter DD.MM.YYYY: "; cin >> day >> month >> year;
    int fullDay = 0;

    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
    {
        fullDay = 31; break;
    }
    case 4: case 6: case 9: case 11: 
    {
        fullDay = 30; break;
    }
    case 2:
    {
        if (year % 4 == 0 || year % 400 == 0 && year % 100 != 0) 
        {
            fullDay = 29;
        }
        else 
        {
            fullDay = 28;
        }
        break;
    }
    default:
        break;
    }

    day++;

    if (day > fullDay) 
    {
        day = 1;
        month++;
    }
    if (month > 12) 
    {
        month = 1;
        year++;
    }

    cout << (day < 10 ? "0" : "") << day << "." << (month < 10 ? "0" : "") << month << "." << year << endl;*/
}