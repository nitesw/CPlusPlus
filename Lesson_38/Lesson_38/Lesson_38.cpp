#include <iostream>
using namespace std;

class Date
{
private:
    const int baseYear;
    int& currentYear;
    int day;
    int month;
    int year;
public:
    Date(int currentYear) :baseYear(2000), currentYear(currentYear), day(0), month(0), year(0) {}
    Date(int base, int currentYear) :baseYear(2000), currentYear(currentYear), day(0), month(0), year(0) {}
    /*Date(const Date &other)
    {

    }*/
    void setDay(int day)
    {
        this->day = day;
    }
    int getDay()
    {
        return day;
    }
    int getDay() const
    {
        return day;
    }
    void Show()
    {
        cout << "Base Year: " << baseYear << endl;
        cout << "Current Year: " << *&currentYear << endl;
        cout << "Day: " << day << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
    }
};

class Account
{
private: 
    double sum;
    const double rate;
public:
    Account(double sum, double rate) :rate(rate)
    {
        this->sum = sum;
        //this->rate = rate;
    }
    double getRate() const
    {
        return rate;
    }
    double getIncome()
    {
        return sum * rate / 100;
    }
    double getIncome() const
    {
        return sum * rate / 100;
    }
    double getSum() const
    {
        return sum;
    }
    double setSum()
    {
        sum += getIncome();
        return sum;
    }
};

void doSomething(long number) {}
float doSomething()
{
    return 1.04;
}

class Array
{
    int size;
    int* arr;
public:
    explicit Array(int size = 10)
    {
        this->size = size;
        arr = new int[size];
    }
    Array(const Array& other)
    {
        this->size = other.size;
        this->arr = new int[other.size];
        for (size_t i = 0; i < other.size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    ~Array()
    {
        delete[] arr;
    }
    int getSize()const
    {
        return size;
    }
    int getValue(int index)const
    {
        return arr[index];
    }
    void setValue(int index, int value)
    {
        arr[index] = value;
    }
    void Display(int index)const
    {
        cout << arr[index] << " ";
    }
};

void DisplayArr(const Array& arr)
{
    for (size_t i = 0; i < arr.getSize(); i++)
    {
        arr.Display(i);
    }
}

int main()
{
    /*const int size = 4;

    const string str{ "first day" };

    const char* filename{ "text.txt" };

    const int days[]{ 31, 31, 28 };
    //days[2] = 29;

    const Date date{ 15, 6, 2023 };
    //date.setDay(20); Error
    int day = date.getDay();

    Date newDate{ 1,1,2001 };
    cout << "New day: " << newDate.getDay() << endl;
    */

    /*int year = 2023;
    int base;
    cout << "Enter base year: "; cin >> base;
    Date day(base, year); // default ctor
    //day.setDay(10);
    //cout << "Date: " << day.getDay() << endl;
    day.Show();*/

    /*Account account1(2000, 5);
    const Account account2(5000, 8);

    cout << "Rate 1: " << account1.getRate() << endl;
    cout << "Rate 2: " << account2.getRate() << endl;

    cout << "Sum 1: " << account1.getSum() << endl;
    cout << "Sum 2: " << account2.getSum() << endl;

    cout << "Income 1: " << account1.getIncome() << endl;
    cout << "Income 2: " << account2.getIncome() << endl;

    cout << "Set sum 1: " << account1.setSum() << endl;
    //cout << "Set sum 2: " << account2.setSum() << endl;*/

    /*double a(10);
    cout << a << endl;
    a = 5;
    doSomething(5);

    double d = 5.0 / 4;*/

    int size = 4;
    Array arr(size); // explicit
    for (size_t i = 0; i < size; i++)
    {
        arr.setValue(i, size - i - 1);
    }
    DisplayArr(arr);
    cout << endl;
    cout << "----------" << endl;
    //DisplayArr(3); // implicit
    //Array arr2 = arr; // ctor copy - error
    Array arr2(arr);
    DisplayArr(arr2);
    cout << endl;
}