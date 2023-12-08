#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Prototype
{
public:
    virtual T Clone()const = 0;
};

struct Date
{
    int year, month, day;
    string ToString()
    {
        return to_string(year) + " / " + to_string(month) + " / " + to_string(day);
    }
};

class Member : public Prototype<Member>
{
private:
    string name;
    int age;
public:
    Member() :name("no name"), age(0) {}
    Member(string name, int age) :name(name), age(age) {}
    string ToString()
    {
        return name + " " + to_string(age);
    }
    Member Clone()const override
    {
        return *this;
    }
};

class Event : public Prototype<Event>
{
    string name;
    Date date;
    string address;
    Member* members;
    int countMembers;
public:
    Event() :name("no name"), date(Date{0,0,0}), address("no address"), members(nullptr), countMembers(0) {}
    Event(string n, Date d, string a) :name(n), date(d), address(a), members(nullptr), countMembers(0) {}
    Event(const Event& other)
    {
        this->name = other.name;
        this->date = other.date;
        this->address = other.address;
        //this->members = other.members;
        this->members = new Member[other.countMembers];
        for (size_t i = 0; i < other.countMembers; i++)
        {
            this->members[i] = other.members[i];
        }
        this->countMembers = other.countMembers;
    }

    Event Clone()const override
    {
        Event clone = *this;
        clone.members = new Member[this->countMembers];
        for (size_t i = 0; i < this->countMembers; i++)
        {
            clone.members[i] = this->members[i].Clone();
        }
        return clone;
    }
    void AddTestMembers()
    {
        countMembers = 2;
        members = new Member[countMembers];
        members[0] = Member("Bob", 22);
        members[1] = Member("Tom", 35);
    }

    string ToString()
    {
        string res = name + ": " + date.ToString() + " \n" + address + " \n";
        for (size_t i = 0; i < countMembers; i++)
        {
            res += "\tMember [" + to_string(i + 1) + "] " + members[i].ToString() + " \n";
        }
        return res;
    }

    ~Event()
    {
        delete[] members;
    }
};

int main()
{
    Event event("Indenpendency day", Date {2024, 8, 24}, "Kyiv, Ukraine");
    event.AddTestMembers();
    cout << "Event: " << event.ToString() << endl;

    Event copy(event);
    cout << "Copy: " << copy.ToString() << endl;

    Event clone = event.Clone();
    cout << "Clone: " << clone.ToString() << endl;
}