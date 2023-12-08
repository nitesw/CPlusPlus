#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int age;
public:
    Animal() :name(""), age(0) {}
    explicit Animal(int a) :age(a) {}
    Animal(int a, string n) :age(a), name(n) {}
    virtual void Print()const
    {
        cout << name << " " << age << endl;
    }
};
class Bird : public Animal
{
    string place;
public:
    void Print()const override
    {
        Animal::Print();
        cout << place << endl;
    }
};

int main()
{
    //Animal a = 100, "line";
    Animal a2;
    
}