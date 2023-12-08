#include <iostream>
using namespace std;

class Pizza
{
public:
    virtual void CookPizza() = 0;
};

class MilanPizza : public Pizza
{
public:
    void CookPizza() override
    {
        cout << "Pizza Milan is cooking" << endl;
    }
};
class GreecePizza : public Pizza
{
public:
    void CookPizza() override
    {
        cout << "Pizza Greece is cooking" << endl;
    }
};

class Sauce
{
public:
    virtual void CookSauce() = 0;
};

class MilanSauce : public Sauce
{
public:
    void CookSauce() override
    {
        cout << "Sauce Milan is cooking" << endl;
    }
};
class GreeceSauce : public Sauce
{
public:
    void CookSauce() override
    {
        cout << "Sauce Greece is cooking" << endl;
    }
};

class Factory
{
public:
    virtual void MakePizza() = 0;
};

class MilanFactory : public Factory
{
    MilanPizza mP;
    MilanSauce mS;
public:
    void MakePizza()
    {
        mS.CookSauce();
        mP.CookPizza();
        cout << "Milan pizza is done!" << endl;
    }
};
class GreeceFactory : public Factory
{
    GreecePizza gP;
    GreeceSauce gS;
public:
    void MakePizza()
    {
        gS.CookSauce();
        gP.CookPizza();
        cout << "Greece pizza is done!" << endl;
    }
};

int main()
{
    MilanFactory mF;
    GreeceFactory gF;

    mF.MakePizza();
    cout << endl;
    gF.MakePizza();
}