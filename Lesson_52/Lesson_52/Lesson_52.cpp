#include <iostream>
using namespace std;

class Document
{
private:
    string name;
    string format;
    int pages;
public:
    Document() :name("no name"), format("no format"), pages(0) {}
    Document(string n, string f, int p) :name(n), format(f)
    {
        this->pages = p > 0 ? p : 0;
    }
    void ShowInfo()const
    {
        cout << "________________Document________________" << endl;
        cout << "Name: " << name << endl;
        cout << "Format: " << format << endl;
        cout << "Pages: " << pages << endl;
        cout << endl;
    }
};

class Scanner
{
private:
    float scanResolution;
    float height, width;
public:
    Scanner() :scanResolution(0), height(0), width(0) {}
    Scanner(float s, float h, float w) :scanResolution(s), height(h), width(w) {}

    void ShowInfo()const
    {
        cout << "Scan Resolution: " << scanResolution << " dpi" << endl;
        cout << "Height: " << height << " mm" << endl;
        cout << "Width: " << width << " mm" << endl;
    }
};
class Cartridge
{
public:
    enum Type {None, Standart, XL, XXL};
private:
    float volume;
    string color;
    Type type;
public:
    Cartridge() :volume(0), color("none"), type(None) {}
    Cartridge(float v, string c, Type t) :volume(v), color(c), type(t) {}

    void ShowInfo()const
    {
        cout << "Volume: " << volume << endl;
        cout << "Color: " << color << endl;
        cout << "Type: ";
        switch (type)
        {
        case Cartridge::None:cout << "None" << endl; break;
        case Cartridge::Standart:cout << "Standart" << endl; break;
        case Cartridge::XL:cout << "XL" << endl; break;
        case Cartridge::XXL:cout << "XXL" << endl; break;
        }
        cout << endl;
    }
};

class Printer
{
private:
    string model;
    Scanner scanner;
    Cartridge* cartridges;
    int countCartridge;
    const Document* doc;
public:
    Printer() :model("no model"), cartridges(nullptr), countCartridge(0), doc(nullptr) {}
    Printer(string model, float s, float h, float w)
    {
        doc = nullptr;
        this->model = model;
        scanner = Scanner(s, h, w);

        countCartridge = 5;
        cartridges = new Cartridge[countCartridge];

        cartridges[0] = Cartridge(100, "Red", Cartridge::Standart);
        cartridges[1] = Cartridge(300, "Yellow", Cartridge::XL);
        cartridges[2] = Cartridge(150, "Green", Cartridge::Standart);
        cartridges[3] = Cartridge(400, "Black", Cartridge::XXL);
        cartridges[4] = Cartridge(120, "Blue", Cartridge::Standart);
    }
    void AddDocument(const Document& doc)
    {
        this->doc = &doc;
    }
    void Scan()
    {
        cout << "Scanning... with settings: " << endl;
        scanner.ShowInfo();
    }
    void PrintDocument()
    {
        if (doc == nullptr)
        {
            cout << "No document to print" << endl;
        }
        else
        {
            cout << "Printing..." << endl;
            doc->ShowInfo();
        } 
    }
    void PrintSettings()
    {
        cout << "Printing... with settings: " << endl;
        for (size_t i = 0; i < countCartridge; i++)
        {
            cartridges[i].ShowInfo();
        }
    }
    void Cancel()
    {
        doc = nullptr;
    }
    ~Printer()
    {
        if (cartridges != nullptr) delete[] cartridges;
    }
};

int main()
{
    Document document("Passport", "A5", 7);
    Document document2("C++ for Beginners", "A4", 1500);

    Printer printer("Cannon", 300, 310, 150);
    printer.Scan();
    cout << endl;
    printer.PrintDocument();
    cout << endl;

    printer.AddDocument(document);
    printer.PrintDocument();
    cout << endl;

    printer.AddDocument(document2);
    printer.Cancel();
    printer.PrintDocument();
}