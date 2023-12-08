#include <iostream>
using namespace std;

class Employer
{
protected:
    string name;
    string surname;
    int age;
    int experience;
    int salary;
public:
    Employer() :name(""), surname(""), age(0), experience(0), salary(0) {}
    Employer(string n, string s, int a, int e) :name(n), surname(s), age(a), experience(e), salary(0) {}

    virtual void Print()const = 0;

    void SetSalary(int sal)
    {
        this->salary = sal;
    }
};

class President : public Employer
{
    int amountOfManagers;
public:
    President() :amountOfManagers(0), Employer() {}
    President(string n, string s, int a, int e, int m) :amountOfManagers(m), Employer(n, s, a, e) {}

    void Print()const override
    {
        cout << "President: " << name << " " << surname << ", " << age << ", " << experience << " (in years), " << salary << " USD" << endl;
        cout << "Amount of managers: " << amountOfManagers << endl << endl;
    }
};
class Manager : public Employer
{
    int amountOfWorkers;
public:
    Manager() :amountOfWorkers(0), Employer() {}
    Manager(string n, string s, int a, int e, int w) :amountOfWorkers(w), Employer(n, s, a, e) {}

    void Print()const override
    {
        cout << "Manager: " << name << " " << surname << ", " << age << ", " << experience << " (in years), " << salary << " USD" << endl;
        cout << "Amount of workers: " << amountOfWorkers << endl << endl;
    }
};
class Worker : public Employer
{
    int amountOfHours;
public:
    Worker() :amountOfHours(0), Employer() {}
    Worker(string n, string s, int a, int e, int h) :amountOfHours(h), Employer(n, s, a, e) {}

    void Print()const override
    {
        cout << "Worker: " << name << " " << surname << ", " << age << ", " << experience << " (in years), " << salary << " USD" << endl;
        cout << "Amount of hours: " << amountOfHours << endl << endl;
    }
};

int main()
{
    President president("Nick", "Bir", 46, 15, 10);
    president.SetSalary(40000);

    Manager manager("Devin", "Mar", 24, 3, 15);
    manager.SetSalary(3000);

    Worker worker("Jean", "Kolu", 18, 0, 12);
    worker.SetSalary(1000);

    president.Print();
    manager.Print();
    worker.Print();
}