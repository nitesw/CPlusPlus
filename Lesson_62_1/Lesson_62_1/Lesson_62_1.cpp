#include <iostream>
using namespace std;

#pragma region Proccesor
class Proccesor
{
protected:
    string model;
public:
    Proccesor(string model) :model(model) {}
    virtual void ShowInfo()const
    {
        cout << "Proccesor model: " << model << endl;
    }
};
class AmdProccesor : public Proccesor
{
public:
    AmdProccesor() :Proccesor("AMD") {}
    void ShowInfo()const override
    {
        cout << "Proccesor model: " << model << endl;
    }
};
class IntelProccesor : public Proccesor
{
public:
    IntelProccesor() :Proccesor("Intel") {}
    void ShowInfo()const override
    {
        cout << "Proccesor model: " << model << endl;
    }
};
#pragma endregion

#pragma region MainBoard
class MainBoard
{
protected:
    string model;
public:
    MainBoard(string model) :model(model) {}
    virtual void ShowInfo()const
    {
        cout << "MainBoard model: " << model << endl;
    }
};
class AsusMainBoard : public MainBoard
{
public:
    AsusMainBoard() :MainBoard("Asus") {}
    void ShowInfo()const override
    {
        cout << "MainBoard model: " << model << endl;
    }
};
class MSIMainBoard : public MainBoard
{
public:
    MSIMainBoard() :MainBoard("MSI") {}
    void ShowInfo()const override
    {
        cout << "MainBoard model: " << model << endl;
    }
};
#pragma endregion

#pragma region Box
class Box
{
protected:
    string model;
public:
    Box(string model) :model(model) {}
    virtual void ShowInfo()const
    {
        cout << "Box model: " << model << endl;
    }
};
class BlackBox : public Box
{
public:
    BlackBox() :Box("Black") {}
    void ShowInfo()const override
    {
        cout << "Box model: " << model << endl;
    }
};
class SilverBox : public Box
{
public:
    SilverBox() :Box("Silver") {}
    void ShowInfo()const override
    {
        cout << "Box model: " << model << endl;
    }
};
#pragma endregion

#pragma region Hdd
class Hdd
{
protected:
    string model;
public:
    Hdd(string model) :model(model) {}
    virtual void ShowInfo()const
    {
        cout << "HDD model: " << model << endl;
    }
};
class LGHDD : public Hdd
{
public:
    LGHDD() :Hdd("LG") {}
    void ShowInfo()const override
    {
        cout << "HDD model: " << model << endl;
    }
};
class SamsungHDD : public Hdd
{
public:
    SamsungHDD() :Hdd("Samsung") {}
    void ShowInfo()const override
    {
        cout << "HDD model: " << model << endl;
    }
};
#pragma endregion

#pragma region Memory
class Memory
{
protected:
    string model;
public:
    Memory(string model) :model(model) {}
    virtual void ShowInfo()const
    {
        cout << "Memory model: " << model << endl;
    }
};
class Ddr : public Memory
{
public:
    Ddr() :Memory("DDR") {}
    void ShowInfo()const override
    {
        cout << "Memory model: " << model << endl;
    }
};
class Ddr2 : public Memory
{
public:
    Ddr2() :Memory("DDR2") {}
    void ShowInfo()const override
    {
        cout << "Memory model: " << model << endl;
    }
};
#pragma endregion

#pragma region PcFactory
class PcFactory
{
public:
    virtual Proccesor* CreateProccesor() = 0;
    virtual MainBoard* CreateMainBoard() = 0;
    virtual Box* CreateBox() = 0;
    virtual Hdd* CreateHdd() = 0;
    virtual Memory* CreateMemory() = 0;
};
class OfficePcFactory : public PcFactory
{
    Proccesor* CreateProccesor()override
    {
        return new AmdProccesor();
    }
    MainBoard* CreateMainBoard()override
    {
        return new AsusMainBoard();
    }
    Box* CreateBox()override
    {
        return new BlackBox();
    }
    Hdd* CreateHdd()override
    {
        return new LGHDD();
    }
    Memory* CreateMemory()override
    {
        return new Ddr();
    }
};
class HomePcFactory : public PcFactory
{
    Proccesor* CreateProccesor()override
    {
        return new IntelProccesor();
    }
    MainBoard* CreateMainBoard()override
    {
        return new MSIMainBoard();
    }
    Box* CreateBox()override
    {
        return new SilverBox();
    }
    Hdd* CreateHdd()override
    {
        return new SamsungHDD();
    }
    Memory* CreateMemory()override
    {
        return new Ddr2();
    }
};
#pragma endregion

#pragma region Pc
class Pc
{
    Proccesor* proccesor;
    MainBoard* mainBoard;
    Box* box;
    Hdd* hdd;
    Memory* memory;
public:
    Pc()
    {
        proccesor = nullptr;
        mainBoard = nullptr;
        box = nullptr;
        hdd = nullptr;
        memory = nullptr;
    }
    void SetProccesor(Proccesor* proc)
    {
        proccesor = proc;
    }
    void SetMainBoard(MainBoard* mainB)
    {
        mainBoard = mainB;
    }
    void SetBox(Box* box)
    {
        this->box = box;
    }
    void SetHdd(Hdd* hdd)
    {
        this->hdd = hdd;
    }
    void SetMemory(Memory* mem)
    {
        memory = mem;
    }

    void ShowInfo()const
    {
        if (proccesor != nullptr && mainBoard != nullptr && box != nullptr && hdd != nullptr && memory != nullptr)
        {
            box->ShowInfo();
            mainBoard->ShowInfo();
            proccesor->ShowInfo();
            memory->ShowInfo();
            hdd->ShowInfo();
        }
        else
        {
            cout << "Configure PC first." << endl;
        }
    }
};
class PcConfigurator
{
    Proccesor* proccesor;
    MainBoard* mainBoard;
    Box* box;
    Hdd* hdd;
    Memory* memory;
    Pc pc;
public:
    PcConfigurator(Proccesor* p, MainBoard* m, Box* b, Hdd* h, Memory* mem, Pc& pc)
    {
        proccesor = p;
        mainBoard = m;
        box = b;
        hdd = h;
        memory = mem;
        this->pc = pc;
    }
    void Configure(Pc& pc)
    {
        pc.SetBox(box);
        pc.SetProccesor(proccesor);
        pc.SetMainBoard(mainBoard);
        pc.SetHdd(hdd);
        pc.SetMemory(memory);
    }
};
#pragma endregion


int main()
{
    PcFactory* factory = new OfficePcFactory();
    PcFactory* factory2 = new HomePcFactory();

    Box* box = factory->CreateBox();
    Hdd* hdd = factory->CreateHdd();
    MainBoard* mainBoard = factory->CreateMainBoard();
    Memory* memory = factory->CreateMemory();
    Proccesor* processor = factory->CreateProccesor();

    Box* box2 = factory2->CreateBox();
    Hdd* hdd2 = factory2->CreateHdd();
    MainBoard* mainBoard2 = factory2->CreateMainBoard();
    Memory* memory2 = factory2->CreateMemory();
    Proccesor* processor2 = factory2->CreateProccesor();
    
    Pc pc;
    PcConfigurator pcF1(processor, mainBoard, box, hdd, memory, pc);
    pcF1.Configure(pc);
    pc.ShowInfo();
    cout << "________________________________" << endl;
    PcConfigurator pcF2(processor2, mainBoard2, box2, hdd2, memory2, pc);
    pcF2.Configure(pc);
    pc.ShowInfo();
}