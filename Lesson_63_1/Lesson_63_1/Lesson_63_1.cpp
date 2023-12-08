#include <iostream>
using namespace std;

class Car
{
    string body;
    string engine;
    string wheels;
    string paint;
    string salon;
public:
    void SetBody(string v) { body = v; }
    void SetEngine(string v) { engine = v; }
    void SetWheels(string v) { wheels = v; }
    void SetPaint(string v) { paint = v; }
    void SetSalon(string v) { salon = v; }
    void Show()const
    {
        cout << "Body: " << body << endl;
        cout << "Engine: " << engine << endl;
        cout << "Wheels: " << wheels << endl;
        cout << "Paint color: " << paint << endl;
        cout << "Salon: " << salon << endl;
    }
};

class AutoTechnology
{
protected:
    Car* car;
public:
    void CreateCar()
    {
        car = new Car();
    }
    Car* GetCar()
    {
        return car;
    }

    virtual void SetBody() = 0;
    virtual void SetEngine() = 0;
    virtual void SetWheels() = 0;
    virtual void SetPaint() = 0;
    virtual void SetSalon() = 0;
};
class MiniAutoTechnology : public AutoTechnology
{
    void SetBody() override
    {
        car->SetBody("Mini Body");
    }
    void SetEngine() override
    {
        car->SetEngine("Mini Engine");
    }
    void SetWheels() override
    {
        car->SetWheels("Mini Wheels");
    }
    void SetPaint() override
    {
        car->SetPaint("Pink Paint");
    }
    void SetSalon() override
    {
        car->SetSalon("Pink Salon");
    }
};
class SportsAutoTechnology : public AutoTechnology
{
    void SetBody() override
    {
        car->SetBody("Sport Body");
    }
    void SetEngine() override
    {
        car->SetEngine("Sport Engine");
    }
    void SetWheels() override
    {
        car->SetWheels("Sport Wheels");
    }
    void SetPaint() override
    {
        car->SetPaint("Grey Paint");
    }
    void SetSalon() override
    {
        car->SetSalon("Grey Salon");
    }
};
class SUVAutoTechnology : public AutoTechnology
{
    void SetBody() override
    {
        car->SetBody("SUV Body");
    }
    void SetEngine() override
    {
        car->SetEngine("SUV Engine");
    }
    void SetWheels() override
    {
        car->SetWheels("SUV Wheels");
    }
    void SetPaint() override
    {
        car->SetPaint("White Paint");
    }
    void SetSalon() override
    {
        car->SetSalon("White Salon");
    }
};


class Conveyor
{
    AutoTechnology* technology;
public:
    Conveyor(AutoTechnology* technology = nullptr) :technology(technology) {}
    ~Conveyor()
    {
        delete technology;
    }
    void SetTechnology(AutoTechnology* technology)
    {
        if (this->technology != nullptr) delete this->technology;
        this->technology = technology;
    }
    Car* GetCar()
    {
        return technology->GetCar();
    }
    void Configuration()
    {
        technology->CreateCar();
        technology->SetBody();
        technology->SetEngine();
        technology->SetWheels();
        technology->SetPaint();
        technology->SetSalon();
    }
};

int main()
{
    Conveyor conv;
    conv.SetTechnology(new MiniAutoTechnology());
    conv.Configuration();

    Car* car = conv.GetCar();
    car->Show();
    cout << endl;
    delete car;

    conv.SetTechnology(new SportsAutoTechnology());
    conv.Configuration();
    car = conv.GetCar();
    car->Show();
    cout << endl;
    delete car;

    conv.SetTechnology(new SUVAutoTechnology());
    conv.Configuration();
    car = conv.GetCar();
    car->Show();
    cout << endl;
    delete car;
}