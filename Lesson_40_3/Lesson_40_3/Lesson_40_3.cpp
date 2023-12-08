#include <iostream>
using namespace std;

class Airplane
{
    string model;
    string type;
    int amountOfPassangers;
    int maxAmountOfPassangers;
public:
    Airplane() :model("no model"), type("no type"), amountOfPassangers(0), maxAmountOfPassangers(0) {}
    Airplane(string model, string type, int amountOfPassangers, int maxAmountOfPassangers)
    {
        this->model = model;
        this->type = type;
        this->amountOfPassangers = amountOfPassangers;
        this->maxAmountOfPassangers = maxAmountOfPassangers;
    }

    void Print()
    {
        cout << model << ": " << type << ", passangers: " << amountOfPassangers << ", max passangers: " << maxAmountOfPassangers << endl;
    }
    Airplane operator++()
    {
        if(amountOfPassangers < maxAmountOfPassangers)
            ++this->amountOfPassangers;
            return *this;
    }
    Airplane operator--()
    {
        if (amountOfPassangers > 0)
            --this->amountOfPassangers;
            return *this;
    }
    void operator()(int number)
    {
        if (amountOfPassangers < maxAmountOfPassangers && amountOfPassangers + number < maxAmountOfPassangers)
            amountOfPassangers += number;
    }
    friend bool operator>(const Airplane& airplane1, const Airplane& airplane2);
    friend bool operator==(const Airplane& airplane1, const Airplane& airplane2);
};

bool operator==(const Airplane& airplane1, const Airplane& airplane2)
{
    return (airplane1.type == airplane2.type);
}
bool operator>(const Airplane& airplane1, const Airplane& airplane2)
{
    return (airplane1.maxAmountOfPassangers) > (airplane2.maxAmountOfPassangers);
}

int main()
{
    Airplane airplane1("Model1", "AA2", 20, 25);
    Airplane airplane2("Model2", "AA2", 20, 28);

    airplane1.Print();
    airplane2.Print();
    cout << endl;
    airplane1(8);
    airplane1.Print();
    cout << endl;
    cout << (airplane1 == airplane2) << endl;
    cout << endl;
    ++airplane1;
    ++airplane1;
    --airplane2;
    --airplane2;
    airplane1.Print();
    airplane2.Print();
    cout << endl;
    cout << (airplane1 > airplane2) << endl;
    cout << endl;
    airplane2(5);
    airplane2.Print();
}