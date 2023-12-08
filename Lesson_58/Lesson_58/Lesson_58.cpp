#include <iostream>
#include <map>
using namespace std;

class RecordBook
{
    string name;
    int year;
public:
    RecordBook() :name(""), year(0) {}
    RecordBook(string n, int y) :name(n), year(y) {}

    void Print()const
    {
        cout << "Name: " << name << endl;
        cout << "Birth Year: " << year << endl;
    }
    bool operator < (const RecordBook& other) const
    {
        return this->name < other.name;
    }
    friend ostream& operator << (ostream& out, const RecordBook& r);
};
ostream& operator << (ostream& out, const RecordBook& r)
{
    out << "Name: " << r.name << endl;
    out << "Birth Year: " << r.year << endl;
    return out;
}

void Print(multimap<RecordBook, string> people)
{
    for (auto pair : people)
    {
        cout << pair.first;
        cout << "Phone Number: " << pair.second << endl;
        cout << "------------------------------" << endl << endl;
    }
}
void AddPerson(multimap<RecordBook, string>& people, string name, int year, string num)
{
    people.insert(make_pair(RecordBook(name, year), num));
}
void DeleteByNum(multimap<RecordBook, string>& people, string num)
{
    auto it = people.begin();
    while (it != people.end())
    {
        if (it->second == num)
            it = people.erase(it);
        else
            it++;
    }
}
void FindByNum(multimap<RecordBook, string> people, string num)
{
    for (auto it = people.begin(); it != people.end(); it++)
    {
        if (it->second == num)
        {
            cout << it->first;
            cout << "Phone Number: " << it->second << endl;
            cout << "------------------------------" << endl;
        }
    }
}

int main()
{
    multimap<RecordBook, string> people;

    AddPerson(people, "Misha", 2000, "331");
    AddPerson(people, "Misha", 2003, "586");
    AddPerson(people, "Olya", 2008, "210");
    AddPerson(people, "Olya", 2005, "009");
    AddPerson(people, "Oleg", 2004, "552");
    AddPerson(people, "Oleg", 2001, "702");

    Print(people);

    cout << "\n\nAfter deleted person: " << endl;
    DeleteByNum(people, "331");
    Print(people);

    cout << "\n\nFound person: " << endl;
    FindByNum(people, "009");
}