#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;
public:
    Date() :day(0), month(0), year(0) {}
    Date(int day, int month, int year) :day(day), month(month), year(year) {}

    void Convert()
    {
        if (day <= 0)
        {
            int absMonths = (day / -31) + 1;
            month -= absMonths;
            day += absMonths * 31;
        }
        if (month <= 0)
        {
            int absYears = (month / -12) + 1;
            year -= absYears;
            month += absYears * 12;
        }
        if (day > 31)
        {
            month += (day / 31);
            day = day % 31;
        }
        if (month > 12)
        {
            year += (month / 12);
            month = month % 12;
        }
    }
    void Print()
    {
        Convert();
        cout << day << "." << month << "." << year << endl;
    }

    void setDay(int day)
    {
        this->day = day;
    }
    int getDay()const
    {
        return day;
    }

    friend bool operator >(const Date& dt1, const Date& dt2);
    friend bool operator <(const Date& dt1, const Date& dt2);
    friend bool operator ==(const Date& dt1, const Date& dt2);
    friend bool operator !=(const Date& dt1, const Date& dt2);

    void operator +=(int number)
    {
        this->day += number;
        Convert();
    }
    void operator -=(int number)
    {
        this->day -= number;
        Convert();
    }

    void operator()(int day)
    {
        this->day += day;
        Convert();
    }
    void operator()(int day, int month)
    {
        this->day += day;
        this->month += month;
        Convert();
    }
    void operator()(int day, int month, int year)
    {
        this->day += day;
        this->month += month;
        this->year += year;
        Convert();
    }
};

bool operator >(const Date& dt1, const Date& dt2)
{
    return (dt1.day + dt1.month + dt1.year) > (dt2.day + dt2.month + dt2.year);
}
bool operator <(const Date& dt1, const Date& dt2)
{
    return (dt1.day + dt1.month + dt1.year) < (dt2.day + dt2.month + dt2.year);
}
bool operator ==(const Date& dt1, const Date& dt2)
{
    return (dt1.day == dt2.day) && (dt1.month == dt2.month) && (dt1.year == dt2.year);
}
bool operator !=(const Date& dt1, const Date& dt2)
{
    return !(dt1 == dt2);
}

void operator ++(Date& date)
{
    date.setDay(date.getDay() + 1);
}
void operator ++(Date& date, int)
{
    date.setDay(date.getDay() + 1);
}
void operator --(Date& date)
{
    date.setDay(date.getDay() - 1);
}
void operator --(Date& date, int)
{
    date.setDay(date.getDay() - 1);
}

int main()
{
    Date dt1(3, 3, 2023);
    Date dt2(8, 5, 2023);
    cout << "First date: ";
    dt1.Print();
    cout << endl;
    cout << "Second date: ";
    dt2.Print();
    cout << endl;

    dt1++;
    dt1++;
    dt1.Print();
    dt1--;
    dt1.Print();
    cout << endl;

    ++dt2;
    dt2.Print();
    --dt2;
    --dt2;
    dt2.Print();
    cout << endl;

    cout << (dt1 > dt2) << endl;
    cout << (dt1 < dt2) << endl;
    cout << (dt1 == dt2) << endl;
    cout << (dt1 != dt2) << endl;
    cout << endl;

    dt1 += 5;
    dt1.Print();
    cout << endl;
    
    dt2 -= 7;
    dt2.Print();
    cout << endl;

    dt1(1);
    dt1.Print();
    cout << endl;

    dt2(5, 3);
    dt2.Print();
    cout << endl;

    dt1(32, 1, 1);
    dt1.Print();
    cout << endl;
}