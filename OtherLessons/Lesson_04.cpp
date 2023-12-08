#include <iostream>
using namespace std;

int main()
{
    /*int sec;
    int workTime = 8 * pow(60,2);

    cout << "Enter seconds: "; cin >> sec;
    workTime -= sec;
    cout << "Work will end in: " << workTime / 3600 << ":" << (workTime % 3600) / 60 << ":" << workTime % 60 << endl;*/

    /*int day;

    cout << "Enter the day of the week: "; cin >> day;

    if (day == 1)
    {
        cout << "Today is Monday";
    }
    else if (day == 2)
    {
        cout << "Today is Tuesday";
    }
    else if (day == 3)
    {
        cout << "Today is Wednesday";
    }
    else if (day == 4)
    {
        cout << "Today is Thursday";
    }
    else if (day == 5)
    {
        cout << "Today is Friday";
    }
    else if (day == 6)
    {
        cout << "Today is Saturday";
    }
    else if (day == 7)
    {
        cout << "Today is Sunday";
    }
    else
    {
        cout << "Where do you live?";
    }*/

    /*int number;

    cout << "Enter number: "; cin >> number;

    if (number >= 0 && number <= 20)
    {
        cout << "Yeah, that's right!";
    }
    else if (number < 0 || number > 20)
    {
        cout << "I don't think so...";
    }*/

    /*string enter_pass, enter_log;

    cout << "Enter login: "; cin >> enter_log;

    if (enter_log == "admin" || enter_log == "Admin" || enter_log == "ADMIN")
    {
        cout << "Enter password: "; cin >> enter_pass;

        if (enter_pass == "itstep")
        {
            cout << "Congrats! You're in!" << endl;
        }
        else if (enter_pass == "exit")
        {
            cout << "Bye!" << endl;
        }
        else
        {
            cout << "Error!" << endl;
        }
    }
    else if (enter_log == "exit")
    {
        cout << "Bye!" << endl;
    }
    else
    {
        cout << "Error!" << endl;
    }*/

    /*double temperature;

    cout << "Enter your temperature: "; cin >> temperature;

    if (temperature < 20 || temperature > 46)
    {
        cout << "You're dead...";
    }
    else if (temperature >= 20 && temperature <= 27)
    {
        cout << "You're in coma...";
    }
    else if (temperature >= 27 && temperature < 36 || temperature > 37 && temperature < 42)
    {
        cout << "You're ill...";
    }
    else if (temperature >= 36 && temperature <= 37)
    {
        cout << "You're in good health!";
    }
    else if (temperature >= 42 && temperature <= 46)
    {
        cout << "You're lost consciousness...";
    }
    else
    {
        cout << "You're dead.";
    }*/

    /*int enter_number;
    double enter_usd, enter_uah, equal;

    cout << "Enter the number (1 - convert UAH to USD; 2 - convert USD to UAH): "; cin >> enter_number;

    if (enter_number == 1)
    {
        cout << "Enter amount of UAH: "; cin >> enter_uah;
        equal = enter_uah / 36, 94;
        cout << "You have " << equal << " USD";
    }
    else if (enter_number == 2)
    {
        cout << "Enter amount of USD: "; cin >> enter_usd;
        equal = enter_usd * 36, 94;
        cout << "You have " << equal << " UAH";
    }
    else
    {
        cout << "Error!";
    }*/

    /*string enter_sex;
    int age;

    cout << "Enter your sex: "; cin >> enter_sex;

    if (enter_sex == "woman" || enter_sex == "Woman" || enter_sex == "WOMAN")
    {
        cout << "Enter your age: "; cin >> age;

        if (age >= 60)
        {
            cout << "Your age is retirement age!";
        }
        else
        {
            cout << "Your age is not retirement age!";
        }
    }
    else if (enter_sex == "man" || enter_sex == "Man" || enter_sex == "MAN")
    {
        cout << "Enter your age: "; cin >> age;

        if (age >= 65)
        {
            cout << "Your age is retirement age!";
        }
        else
        {
            cout << "Your age is not retirement age!";
        }
    }
    else
    {
        cout << "Error!";
    }*/

    /*double enter_lenght, lenght;
    int enter_num;

    cout << "Choose value (1 - mm; 2 - cm; 3 - dm; 4 - m): "; cin >> enter_num;
    if (enter_num == 1)
    {
        cout << "Enter lenght in meters: "; cin >> enter_lenght;
        if (enter_lenght > 0)
        {
            lenght = enter_lenght / 1000;
            cout << "You have " << lenght << " mm.";
        }
        else
        {
            cout << "Error";
        }
    }
    else if (enter_num == 2)
    {
        cout << "Enter lenght in meters: "; cin >> enter_lenght;
        if (enter_lenght > 0)
        {
            lenght = enter_lenght / 100;
            cout << "You have " << lenght << " cm.";
        }
        else
        {
            cout << "Error";
        }
    }
    else if (enter_num == 3)
    {
        cout << "Enter lenght in meters: "; cin >> enter_lenght;
        if (enter_lenght > 0)
        {
            lenght = enter_lenght / 10;
            cout << "You have " << lenght << " dm.";
        }
        else
        {
            cout << "Error";
        }
    }
    else if (enter_num == 4)
    {
        cout << "Enter lenght in meters: "; cin >> enter_lenght;
        if (enter_lenght > 0)
        {
            lenght = enter_lenght;
            cout << "You have " << lenght << " m.";
        }
        else
        {
            cout << "Error!";
        }
    }
    else
    {
        cout << "Error!" << endl;
    }*/

    /*string question;
    int birthYear, weight, height;
    const int year = 2022;

    cout << "Do you wanna know you ideal weight?: "; cin >> question;

    if (question == "Yes" || question == "yes" || question == "YES")
    {
        cout << "Enter your height in cm: "; cin >> height;
        if (height > 0)
        {
            cout << "Enter your year of birth: "; cin >> birthYear;
            if (birthYear < 40)
            {
                weight = (height - 100) * 1.15;
                cout << "Your ideal weight is: " << weight;
            }
            else if (birthYear >= 40)
            {
                weight = (height - 90) * 1.15;
                cout << "Your ideal weight is: " << weight;
            }
            else
            {
                cout << "Error";
            }
        }
    }
    else if (question == "No" || question == "no" || question == "NO")
    {
        cout << "Bye!";
    }
    else
    {
        cout << "Error";
    }*/

    /*int number;

    cout << "Enter the number: "; cin >> number;

    if (number % 3 == 0)
    {
        cout << "Number a multiple of 3" << endl;
    }
    if (number % 5 == 0)
    {
        cout << "Number a multiple of 5" << endl;
    }
    if (number % 7 == 0)
    {
        cout << "Number a multiple of 7" << endl;
    }
    if (number % 9 == 0)
    {
        cout << "Number a multiple of 9" << endl;
    }
    if (number % 11 == 0)
    {
        cout << "Number a multiple of 11" << endl;
    }
    if (number % 3 != 0 && number % 5 != 0 && number % 7 != 0 && number % 9 != 0 && number % 11 != 0)
    {
        cout << "Number isn't multiple by any of numbers.";
    }*/

    /*int number;

    cout << "Enter the number: "; cin >> number;

    if (number % 2 == 0)
    {
        cout << "Your number is multiple by 2";
    }
    else
    {
        cout << "Your number isn't multiple by 2";
    }*/

    /*double leg, leg2, hypotenuse;

    cout << "Enter first katet: "; cin >> leg;
    cout << "Enter second katet: "; cin >> leg2;
    cout << "Enter hypotenuse: "; cin >> hypotenuse;

    if (pow(leg, 2) + pow(leg2, 2) == pow(hypotenuse, 2) || pow(leg, 2) - pow(hypotenuse, 2) == pow(leg2, 2) || pow(leg2, 2) - pow(hypotenuse, 2) == pow(leg, 2))
    {
        cout << "Triangle is rectangular.";
    }
    else
    {
        cout << "Triangle isn't rectangular.";
    }*/

    int number;

    cout << "Enter the number: "; cin >> number;
    cout << "Your number is raised to the 3rd power: " << pow(number, 3);
}