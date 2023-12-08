#include <iostream>
using namespace std;

class Driver
{
private:
    string name;
    string surname;
    int age;
public:
    Driver() :name(""), surname(""), age(0) {}
    Driver(string n, string s, int a) :name(n), surname(s) 
    {
        this->age = a > 0 ? a : 0;
    }

    void ShowInfo()const
    {
        cout << "Driver: " << name << " " << surname << ", " << age << endl;
    }
};

class Body
{
private:
    int weight;
public:
    Body() :weight(0) {}
    Body(int w) :weight(w) {}

    void ShowInfo()const
    {
        cout << "Weight of car's body: " << weight << endl;
    }
};
class Wheel
{
private:
    int sizeOfWheel;
public:
    Wheel() :sizeOfWheel(0) {}
    Wheel(int s) :sizeOfWheel(s) {}

    void ShowInfo()const
    {
        cout << "Size of the wheel: " << sizeOfWheel << endl;
    }
};
class Engine
{
private:
    int enginePower;
public:
    Engine() :enginePower(0) {}
    Engine(int e) :enginePower(e) {}

    void ShowInfo()const
    {
        cout << "Engine power: " << enginePower << endl;
    }
};
class Door
{
private:
    string color;
public:
    Door() :color("") {}
    Door(string c) :color(c) {}

    void ShowInfo()const
    {
        cout << "Door' color: " << color << endl;
    }
};
class Headlight
{
private:
    int powerOfHeadlight;
public:
    Headlight() :powerOfHeadlight(0) {}
    Headlight(int p) :powerOfHeadlight(p) {}

    void ShowInfo()const
    {
        cout << "Headlight' power: " << powerOfHeadlight << endl;
    }
};

class Car
{
private:
    string brand;
    Body body;
    Wheel* wheels;
    int countWheels;
    Engine engine;
    Door* doors;
    int countDoors;
    Headlight* headlights;
    int countHeadlights;
    const Driver* driver;
public:
    Car() :brand(""), wheels(nullptr), countWheels(0), doors(nullptr), countDoors(0), headlights(nullptr), countHeadlights(0), driver(nullptr) {}
    Car(string brand, int w, int p) 
    {
        driver = nullptr;
        this->brand = brand;
        body = Body(w);
        engine = Engine(p);

        countWheels = 4;
        wheels = new Wheel[countWheels];
        for (size_t i = 0; i < countWheels; i++)
        {
            wheels[i] = Wheel(40);
        }
        countDoors = 4;
        doors = new Door[countDoors];
        for (size_t i = 0; i < countDoors; i++)
        {
            doors[i] = Door("Black");
        }
        countHeadlights = 2;
        headlights = new Headlight[countHeadlights];
        for (size_t i = 0; i < countHeadlights; i++)
        {
            headlights[i] = Headlight(55);
        }
    }
    Car(string brand, int w, int p, const Driver& driver)
    {
        this->driver = &driver;
        this->brand = brand;
        body = Body(w);
        engine = Engine(p);

        countWheels = 4;
        wheels = new Wheel[countWheels];
        for (size_t i = 0; i < countWheels; i++)
        {
            wheels[i] = Wheel(40);
        }
        countDoors = 4;
        doors = new Door[countDoors];
        for (size_t i = 0; i < countDoors; i++)
        {
            doors[i] = Door("Black");
        }
        countHeadlights = 2;
        headlights = new Headlight[countHeadlights];
        for (size_t i = 0; i < countHeadlights; i++)
        {
            headlights[i] = Headlight(55);
        }
    }

    void BodyInfo()const
    {
        cout << "Body Info: " << endl;
        body.ShowInfo();
        cout << endl;
    }
    void EngineInfo()const
    {
        cout << "Engine Info: " << endl;
        engine.ShowInfo();
        cout << endl;
    }
    void WheelsInfo()const
    {
        cout << "Wheels Info: " << endl;
        for (size_t i = 0; i < countWheels; i++)
        {
            wheels[i].ShowInfo();
        }
        cout << endl;
    }
    void DoorsInfo()const
    {
        cout << "Doors Info: " << endl;
        for (size_t i = 0; i < countDoors; i++)
        {
            doors[i].ShowInfo();
        }
        cout << endl;
    }
    void HeadlightsInfo()const
    {
        cout << "Headlights Info: " << endl;
        for (size_t i = 0; i < countHeadlights; i++)
        {
            headlights[i].ShowInfo();
        }
        cout << endl;
    }
    void DriverInfo()const
    {
        if (driver == nullptr)
        {
            cout << "No driver to print" << endl;
        }
        else 
        {
            cout << "Driver Info: " << endl;
            driver->ShowInfo();
            cout << endl;
        }
    }
    void AddDriver(const Driver& driver)
    {
        this->driver = &driver;
    }
    ~Car()
    {
        delete[] wheels;
        delete[] doors;
        delete[] headlights;
    }
};

int main()
{
    Driver driver("Dominique", "Wilkins", 34);
    Driver driver2("Marc", "Gasol", 37);

    Car car("Toyota", 1800, 180, driver);
    
    car.DriverInfo();
    car.BodyInfo();
    car.EngineInfo();
    car.WheelsInfo();
    car.DoorsInfo();
    car.HeadlightsInfo();
    car.AddDriver(driver2);
    car.DriverInfo();
}