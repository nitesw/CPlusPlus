#include <iostream>
#include <map>
using namespace std;

class RecordBook
{
    multimap<string, string> people;
public:
    void Print()const
    {
        for (auto pair : people)
        {
            cout << "Name: " << pair.first << endl;
            cout << "Phone Number: " << pair.second << endl;
            cout << "------------------------------" << endl << endl;
        }
    }
    void AddPerson(string name, string phone)
    {
        people.insert(pair<string, string>(name, phone));
    }
    void DeletePerson(string phone)
    {
        auto it = people.begin();
        while (it != people.end())
        {
            if (it->second == phone)
                it = people.erase(it);
            else
                it++;
        }
    }
    void FindByNum(string num)
    {
        for (auto it = people.begin(); it != people.end(); it++)
        {
            if (it->second == num)
            {
                cout << "Name: " << it->first << endl;
                cout << "Phone Number: " << it->second << endl;
                cout << "------------------------------" << endl;
            }
        }
    }
};

int main()
{
    RecordBook people;
    people.AddPerson("Misha", "556");
    people.AddPerson("Misha", "218");
    people.AddPerson("Olya", "091");
    people.AddPerson("Andrew", "331");
    people.Print();
    cout << "\n\nAfter deleted person: " << endl;
    people.DeletePerson("218");
    people.Print();
    cout << "\n\nFound by phone number: " << endl;
    people.FindByNum("331");
}