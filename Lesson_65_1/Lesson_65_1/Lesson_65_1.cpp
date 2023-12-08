#include <iostream>
using namespace std;

class Pool
{
public:
    int OneHour()
    {
        return 120;
    }
    int OneEvening()
    {
        return 480;
    }
    int OneNight()
    {
        return 560;
    }
    int OneHoliday()
    {
        return 970;
    }
};
class Bar
{
public:
    int OneHour()
    {
        return 70;
    }
    int OneEvening()
    {
        return 160;
    }
    int OneNight()
    {
        return 320;
    }
    int OneHoliday()
    {
        return 480;
    }
};
class Restaurant
{
public:
    int OneHour()
    {
        return 90;
    }
    int OneEvening()
    {
        return 220;
    }
    int OneNight()
    {
        return 450;
    }
    int OneHoliday()
    {
        return 670;
    }
};
class Billiard
{
public:
    int OneHour()
    {
        return 50;
    }
    int OneEvening()
    {
        return 130;
    }
    int OneNight()
    {
        return 220;
    }
    int OneHoliday()
    {
        return 350;
    }
};
class Massage
{
public:
    int OneHour()
    {
        return 100;
    }
    int OneEvening()
    {
        return 230;
    }
    int OneNight()
    {
        return 460;
    }
    int OneHoliday()
    {
        return 780;
    }
};

class ObarivResort
{
    Pool pool;
    Bar bar;
    Restaurant rest;
    Billiard billiard;
    Massage massage;
public:
    void Start()
    {
        int choice;
        do
        {
            cout << "What you want as your resort?" << endl;
            cout << "1. Pool" << endl;
            cout << "2. Bar" << endl;
            cout << "3. Restaurant" << endl;
            cout << "4. Billiard" << endl;
            cout << "5. Massage" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: "; cin >> choice;
            switch (choice)
            {
            case 1:
            {
                system("cls");
                cout << "For how long you wanna take the pool?" << endl;
                cout << "1. One Hour" << endl;
                cout << "2. One Evening" << endl;
                cout << "3. One Night" << endl;
                cout << "4. One Holiday" << endl;
                cout << "Enter your choice: "; cin >> choice;
                switch (choice)
                {
                case 1:
                    system("cls"); cout << "It will cost: " << pool.OneHour() << endl; break;
                case 2:
                    system("cls"); cout << "It will cost: " << pool.OneEvening() << endl; break;
                case 3:
                    system("cls"); cout << "It will cost: " << pool.OneNight() << endl; break;
                case 4:
                    system("cls"); cout << "It will cost: " << pool.OneHoliday() << endl; break;
                }
                break;
            }
            case 2:
            {
                system("cls");
                cout << "For how long you wanna take the bar?" << endl;
                cout << "1. One Hour" << endl;
                cout << "2. One Evening" << endl;
                cout << "3. One Night" << endl;
                cout << "4. One Holiday" << endl;
                cout << "Enter your choice: "; cin >> choice;
                switch (choice)
                {
                case 1:
                    system("cls"); cout << "It will cost: " << bar.OneHour() << endl; break;
                case 2:
                    system("cls"); cout << "It will cost: " << bar.OneEvening() << endl; break;
                case 3:
                    system("cls"); cout << "It will cost: " << bar.OneNight() << endl; break;
                case 4:
                    system("cls"); cout << "It will cost: " << bar.OneHoliday() << endl; break;
                }
                break;
            }
            case 3:
            {
                system("cls");
                cout << "For how long you wanna take the restaurant?" << endl;
                cout << "1. One Hour" << endl;
                cout << "2. One Evening" << endl;
                cout << "3. One Night" << endl;
                cout << "4. One Holiday" << endl;
                cout << "Enter your choice: "; cin >> choice;
                switch (choice)
                {
                case 1:
                    system("cls"); cout << "It will cost: " << rest.OneHour() << endl; break;
                case 2:
                    system("cls"); cout << "It will cost: " << rest.OneEvening() << endl; break;
                case 3:
                    system("cls"); cout << "It will cost: " << rest.OneNight() << endl; break;
                case 4:
                    system("cls"); cout << "It will cost: " << rest.OneHoliday() << endl; break;
                }
                break;
            }
            case 4:
            {
                system("cls");
                cout << "For how long you wanna take the billiard?" << endl;
                cout << "1. One Hour" << endl;
                cout << "2. One Evening" << endl;
                cout << "3. One Night" << endl;
                cout << "4. One Holiday" << endl;
                cout << "Enter your choice: "; cin >> choice;
                switch (choice)
                {
                case 1:
                    system("cls"); cout << "It will cost: " << billiard.OneHour() << endl; break;
                case 2:
                    system("cls"); cout << "It will cost: " << billiard.OneEvening() << endl; break;
                case 3:
                    system("cls"); cout << "It will cost: " << billiard.OneNight() << endl; break;
                case 4:
                    system("cls"); cout << "It will cost: " << billiard.OneHoliday() << endl; break;
                }
                break;
            }
            case 5:
            {
                system("cls");
                cout << "For how long you wanna take the massage?" << endl;
                cout << "1. One Hour" << endl;
                cout << "2. One Evening" << endl;
                cout << "3. One Night" << endl;
                cout << "4. One Holiday" << endl;
                cout << "Enter your choice: "; cin >> choice;
                switch (choice)
                {
                case 1:
                    system("cls"); cout << "It will cost: " << massage.OneHour() << endl; break;
                case 2:
                    system("cls"); cout << "It will cost: " << massage.OneEvening() << endl; break;
                case 3:
                    system("cls"); cout << "It will cost: " << massage.OneNight() << endl; break;
                case 4:
                    system("cls"); cout << "It will cost: " << massage.OneHoliday() << endl; break;
                }
                break;
            }
            }
        } while (choice != 0);
        
    }
};

int main()
{
    ObarivResort oS;
    oS.Start();
}