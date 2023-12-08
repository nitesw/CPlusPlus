#include <iostream>
using namespace std;

class Car
{
public:
    void Drive()
    {
        cout << "I am a car. I can drive" << endl;
    }
    void Use()
    {
        cout << "I drive in my car" << endl;
    }
};
class Airplane
{
public:
    void Fly()
    {
        cout << "I am an airplane. I can fly" << endl;
    }
    void Use()
    {
        cout << "I fly in my airplane" << endl;
    }
};
class FlyCar : public Car, public Airplane
{

};

class A
{
public:
    int value;
};
class B : public A {};
class C : public A {};
class D : public B, public C 
{
public:
    int getVal()
    {
        return B::value;
        return C::value;
        return B::A::value;
        return C::A::value;
    }
};

class Person
{
    string name;
    string surname;
public:
    Person() :name(""), surname("") {}
    Person(string n, string s) :name(n), surname(s) {}
    string getName() { return name; }
    string getSurname() { return surname; }
    void SetName(string name)
    {
        this->name = name;
    }
    virtual void Show()
    {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
    }
};
class Gamer : public Person
{
    int score;
public:
    Gamer()
    {
        score = 100;
        Person::SetName("Gamer");
    }
    void Show()
    {
        cout << "Score in this game: " << score << endl;
    }
};
class Student : public Person
{
    int mark;
public:
    Student()
    {
        mark = 10;
        Person::SetName("Student");
    }
    void Show()
    {
        cout << "Mark in this subject: " << mark << endl;
    }
};
class BadStudent : public Student, public Gamer
{
public:
    void Show()
    {
        //cout << Person::getName() << endl;
        //cout << Student::getName() << endl;
        //cout << Student::Person::getName() << endl;
        //cout << Gamer::getName() << endl;
        cout << Gamer::Person::getName() << endl; 
    }
};

int main()
{
    Car car;
    car.Drive();

    Airplane air;
    air.Fly();

    FlyCar flyCar;
    flyCar.Drive();
    flyCar.Fly();

    ((Car)flyCar).Use();
    ((Airplane)flyCar).Use();

    BadStudent badSt;
    badSt.Show();
    badSt.Gamer::SetName("Dude");
    badSt.Show();

    badSt.Student::SetName("Not Dude");
    badSt.Show();
}