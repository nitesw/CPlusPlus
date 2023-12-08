#include <iostream>
using namespace std;

//enum Color
//{
//    RED = 1, GREEN, BLUE, YELLOW
//};


int main()
{
    /*int day;

    cout << "Enter the number of the day: "; cin >> day;
    switch (day)
    {
    case 1:
    {
        cout << "Monday!" << endl;
        break;
    }
    case 2:
    {
        cout << "Tuesday!" << endl;
        break;
    }
    case 3:
    {
        cout << "Wednsday!" << endl;
        break;
    }
    case 4:
    {
        cout << "Thursday!" << endl;
        break;
    }
    case 5:
    {
        cout << "Friday!" << endl;
        break;
    }
    case 6:
    {
        cout << "Saturday!" << endl;
        break;
    }
    case 7:
    {
        cout << "Sunday!" << endl;
        break;
    }
    default:
    {
        cout << "Error!" << endl;
        break;
    }
    }*/

    /*char key;
    cout << "Enter key: "; cin >> key;

    switch (key)
    {
    case 'w':
    {
        cout << "Up";
        break;
    }
    case 's':
    {
        cout << "Down";
        break;
    }
    case 'a':
    {
        cout << "Left";
        break;
    }
    case 'd':
    {
        cout << "Right";
        break;
    }
    default:
    {
        cout << "Incorrect key!";
        break;
    }
    }*/

    /*int color;

    cout << "\t 1 - Red;\n\t 2 - Green;\n\t 3 - Blue;\n\t 4 - Yellow;\n\t Select color: "; cin >> color;

    switch (color)
    {
    case Color::RED:
    {
        system("color 04");
        break;
    }
    case Color::GREEN:
    {
        system("color 02");
        break;
    }
    case Color::BLUE:
    {
        system("color 01");
        break;
    }
    case Color::YELLOW:
    {
        system("color 06");
        break;
    }
    default:
    {
        cout << "Incorrect digit!";
    }
    }*/

    /*int s_day, s_month, s_year; // first date
    int e_day, e_month, e_year; // second date

    cout << "Enter first date: "; cin >> s_day >> s_month >> s_year; // 26.03.2022 (02 [28],01 [31])
    cout << "Enter second date: "; cin >> e_day >> e_month >> e_year;

    int startNumbersOfDays = 0;

    switch (s_month - 1)
    {
    case 11: startNumbersOfDays += 30;
    case 10: startNumbersOfDays += 31;
    case 9: startNumbersOfDays += 30;
    case 8: startNumbersOfDays += 31;
    case 7: startNumbersOfDays += 31;
    case 6: startNumbersOfDays += 30;
    case 5: startNumbersOfDays += 31;
    case 4: startNumbersOfDays += 30;
    case 3: startNumbersOfDays += 31;
    case 2:
    {
        if (s_year % 4 == 0 || s_year % 400 == 0 && s_year % 100 != 0)
        {
            startNumbersOfDays += 29;
        }
        else
        {
            startNumbersOfDays += 28;
        }
    }
    case 1: startNumbersOfDays += 31;
    }
    startNumbersOfDays += s_day;
    cout << startNumbersOfDays << endl;

    int endNumbersOfDays = 0;

    switch (e_month - 1)
    {
    case 11: endNumbersOfDays += 30;
    case 10: endNumbersOfDays += 31;
    case 9: endNumbersOfDays += 30;
    case 8: endNumbersOfDays += 31;
    case 7: endNumbersOfDays += 31;
    case 6: endNumbersOfDays += 30;
    case 5: endNumbersOfDays += 31;
    case 4: endNumbersOfDays += 30;
    case 3: endNumbersOfDays += 31;
    case 2:
    {
        if (e_year % 4 == 0 || e_year % 400 == 0 && e_year % 100 != 0)
        {
            endNumbersOfDays += 29;
        }
        else
        {
            endNumbersOfDays += 28;
        }
    }
    case 1: endNumbersOfDays += 31;
    }
    endNumbersOfDays += e_day;
    cout << endNumbersOfDays << endl;
    cout << endNumbersOfDays - startNumbersOfDays << endl;*/

    /*int month;

    cout << "Enter number of the month: "; cin >> month;

    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: cout << "31 days"; break;
    case 2: 
    {
        int year;
        cout << "Enter year: "; cin >> year;
        cout << (year % 4 == 0 || year % 400 == 0 && year % 100 != 0 ? "29 " : "28 ") << " days";
        break;
    }
    case 4:
    case 6:
    case 9:
    case 11: cout << "30 days"; break;
    default:
        cout << "Wrong digit!";
        break;
    }*/

    /* Користувач вводить свій рік народження. Вивести в консолі знак зодіаку (китайськи) під яким він народився*/

    int year;

    cout << "Enter year when you born: "; cin >> year;

    year = year % 12;

    switch (year)
    {
    case 4:
    {
        cout << "Rat";
        break;
    }
    case 5:
    {
        cout << "Bull";
        break;
    }
    case 6:
    {
        cout << "Tiger";
        break;
    }
    case 7:
    {
        cout << "Rabbit";
        break;
    }
    case 8:
    {
        cout << "Dragon";
        break;
    }
    case 9:
    {
        cout << "Snake";
        break;
    }
    case 10:
    {
        cout << "Horse";
        break;
    }
    case 11:
    {
        cout << "Goat";
        break;
    }
    case 0:
    {
        cout << "Monkey";
        break;
    }
    case 1:
    {
        cout << "Cock";
        break;
    }
    case 2:
    {
        cout << "Dog";
        break;
    }
    case 3:
    {
        cout << "Pig";
        break;
    }
    default: break;
    }
}