#include <iostream>
using namespace std;

class UkrainianCurrency
{
public:
    float getUkrainianCurrency()
    {
        float u = 0.027;
        return u;
    }
};

class Convertor
{
public:
    virtual ~Convertor() {}
    virtual float getCurrency(float num) = 0;
};

class Adapter : public Convertor
{
private:
    UkrainianCurrency* uah;
public:
    Adapter(UkrainianCurrency* u) : uah(u) {}

    float getCurrency(float num) override
    {
        return uah->getUkrainianCurrency() * num;
    }

};

class ControlSystem
{
public:
    void Normilize(Convertor* convertor, float num)
    {
        cout << "UAH converted to USD: " << convertor->getCurrency(num) << endl;
    }
};

int main()
{
    UkrainianCurrency* ukrainianCurrency = new UkrainianCurrency();

    Adapter ad(ukrainianCurrency);

    int num;
    cout << "Enter amount of UAH to convert to USD: "; cin >> num;
    ControlSystem system;
    system.Normilize(&ad, num);

    delete ukrainianCurrency;
}