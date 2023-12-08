#include <iostream>
using namespace std;

class Laptop
{
    string screenResolution;
    string processor;
    string memory;
    string hdd;
    string battery;
public:
    void SetResolution(string v) { screenResolution = v; }
    void SetProcessor(string v) { processor = v; }
    void SetMemory(string v) { memory = v; }
    void SetHdd(string v) { hdd = v; }
    void SetBattery(string v) { battery = v; }
    void Show()const
    {
        cout << "Screen resolution: " << screenResolution << endl;
        cout << "Processor: " << processor << endl;
        cout << "Memory: " << memory << endl;
        cout << "HDD: " << hdd << endl;
        cout << "Battery: " << battery << endl;
    }
};
class LaptopBuilder
{
protected:
    Laptop* laptop;
public:
    void CreateLaptop()
    {
        laptop = new Laptop();
    }
    Laptop* GetLaptop()
    {
        return laptop;
    }

    virtual void SetMonitorResolution() = 0;
    virtual void SetProcessor() = 0;
    virtual void SetMemory() = 0;
    virtual void SetHDD() = 0;
    virtual void SetBattery() = 0;
};
class GamingLaptopBuilder : public LaptopBuilder
{
public:
    void SetMonitorResolution()override
    {
        laptop->SetResolution("1900x1200");
    }
    void SetProcessor()override
    {
        laptop->SetProcessor("Intel Core I7, 2.9GHz");
    }
    void SetMemory()override
    {
        laptop->SetMemory("32 GB");
    }
    void SetHDD()override
    {
        laptop->SetHdd("1 TB");
    }
    void SetBattery()override
    {
        laptop->SetBattery("5000 mAh");
    }
};
class ProgrammerLaptopBuilder : public LaptopBuilder
{
public:
    void SetMonitorResolution()override
    {
        laptop->SetResolution("2000x1200");
    }
    void SetProcessor()override
    {
        laptop->SetProcessor("Intel Core I9, 3.6GHz");
    }
    void SetMemory()override
    {
        laptop->SetMemory("64 GB");
    }
    void SetHDD()override
    {
        laptop->SetHdd("2 TB");
    }
    void SetBattery()override
    {
        laptop->SetBattery("10000 mAh");
    }
};
class LaptopDirector
{
    LaptopBuilder* builder;
public:
    LaptopDirector(LaptopBuilder* builder = nullptr) : builder(builder) {}
    ~LaptopDirector()
    {
        delete builder;
    }
    void SetBuilder(LaptopBuilder* builder)
    {
        if (this->builder != nullptr) delete this->builder;
        this->builder = builder;
    }
    Laptop* GetLaptop()
    {
        return builder->GetLaptop();
    }
    void Configuration()
    {
        builder->CreateLaptop();
        builder->SetMonitorResolution();
        builder->SetProcessor();
        builder->SetMemory();
        builder->SetHDD();
        builder->SetBattery();
    }
};

int main()
{
    LaptopDirector dir;
    dir.SetBuilder(new GamingLaptopBuilder());
    dir.Configuration();

    Laptop* laptop = dir.GetLaptop();
    laptop->Show();
    cout << endl;
    delete laptop;
    dir.SetBuilder(new ProgrammerLaptopBuilder());
    dir.Configuration();
    laptop = dir.GetLaptop();
    laptop->Show();

    delete laptop;
}