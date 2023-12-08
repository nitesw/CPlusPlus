#include <iostream>
using namespace std;

void time_con(int num) {
    if (num < 10)
    {
        cout << "0" << num;
    }
    else {
        cout << num;
    }
}

class Time
{
    int hours;
    int minutes;
    int seconds;
public:
    Time() :hours(0), minutes(0), seconds(0) {}
    Time(int hours, int minutes, int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    explicit Time(int seconds)
    {
        this->hours = seconds / 3600;
        this->minutes = (seconds % 3600) / 60;
        this->seconds = (seconds % 3600) % 60;
    }
    void Print()
    {
        Convert();
        time_con(hours); cout << ":";
        time_con(minutes); cout << ":";
        time_con(seconds); cout << endl;
    }
    void Convert()
    {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = (totalSeconds % 3600) % 60;
    }
    void addOneSecond()
    {
        seconds += 1;
    }
    Time operator +(const Time& other)
    {
        Time res(this->hours + other.hours, this->minutes + other.minutes, this->seconds + other.seconds);
        return res;
    }
    Time operator -(const Time& other)
    {
        Time res(this->hours - other.hours, this->minutes - other.minutes, this->seconds - other.seconds);
        return res;
    }
    Time operator /(const Time& other)
    {
        Time res(this->hours / other.hours, this->minutes / other.minutes, this->seconds / other.seconds);
        return res;
    }
    Time operator *(const Time& other)
    {
        Time res(this->hours * other.hours, this->minutes * other.minutes, this->seconds * other.seconds);
        return res;
    }
    bool operator <(const Time& other)
    {
        return (this->hours + this->minutes + this->seconds) < (other.hours + other.minutes + other.seconds);
    }
    bool operator >(const Time& other)
    {
        return (this->hours + this->minutes + this->seconds) > (other.hours + other.minutes + other.seconds);
    }
    bool operator <=(const Time& other)
    {
        return (this->hours + this->minutes + this->seconds) <= (other.hours + other.minutes + other.seconds);
    }
    bool operator >=(const Time& other)
    {
        return (this->hours + this->minutes + this->seconds) >= (other.hours + other.minutes + other.seconds);
    }
    bool operator ==(const Time& other)
    {
        return (this->hours == other.hours) == (this->minutes == other.minutes) == (this->seconds == other.seconds);
    }
    bool operator !=(const Time& other)
    {
        return !(*this == other);
    }
};

int main()
{
    Time time1(5579);
    cout << "Time 1: ";
    time1.Print();
    time1.addOneSecond();
    time1.addOneSecond();
    cout << "Time 1: ";
    time1.Print();
    cout << endl;

    Time time2(0, 0, 5);
    cout << "Time 2: ";
    time2.Print();
    cout << endl;

    Time res = time1 + time2;
    res.Print();
    res = time1 - time2;
    res.Print();
    //res = time1 / time2;
    //res.Print();
    res = time1 * time2;
    res.Print();
    cout << endl;


}