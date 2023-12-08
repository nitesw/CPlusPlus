#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

enum Status { None, Increase, Decrease };

struct CryptoCurrency
{
    string name;
    double price;
    Status status;
    int incCount = 0;
    int decCount = 0;

    CryptoCurrency(string n, double p)
    {
        name = n;
        price = p;
        status = None;
        incCount = 0;
        decCount = 0;
    }
    void SetNewPrice(double newPrice, CryptoCurrency* currency)
    {
        if (currency->name == "Bitcoin")
        {
            if (newPrice > price)
            {
                incCount++;
                decCount = 0;
                if (incCount >= 10) status = Increase;
                else status = None;
            }
            else if (newPrice < price)
            {
                decCount++;
                incCount = 0;
                if (decCount >= 3) status = Decrease;
                else status = None;
            }
            price = newPrice;
        }
        else if (currency->name == "Ethereum")
        {
            if (newPrice > price)
            {
                incCount++;
                decCount = 0;
                if (incCount >= 5) status = Increase;
                else status = None;
            }
            else if (newPrice < price)
            {
                decCount++;
                incCount = 0;
                if (decCount >= 3) status = Decrease;
                else status = None;
            }
            price = newPrice;
        }
        else if (currency->name == "USDT")
        {
            if (newPrice > price)
            {
                incCount++;
                decCount = 0;
                if (incCount >= 3) status = Increase;
                else status = None;
            }
            else if (newPrice < price)
            {
                decCount++;
                incCount = 0;
                if (decCount >= 3) status = Decrease;
                else status = None;
            }
            price = newPrice;
        }
        else if (currency->name == "BNB")
        {
            if (newPrice > price)
            {
                incCount++;
                decCount = 0;
                if (incCount >= 4) status = Increase;
                else status = None;
            }
            else if (newPrice < price)
            {
                decCount++;
                incCount = 0;
                if (decCount >= 3) status = Decrease;
                else status = None;
            }
            price = newPrice;
        }
        else if (currency->name == "XRP")
        {
            if (newPrice > price)
            {
                incCount++;
                decCount = 0;
                if (incCount >= 3) status = Increase;
                else status = None;
            }
            else if (newPrice < price)
            {
                decCount++;
                incCount = 0;
                if (decCount >= 3) status = Decrease;
                else status = None;
            }
            price = newPrice;
        }
    }
};

class Trader
{
    string name;
    double price;
public:
    Trader(string n) :name(n)
    {
        price = rand() % 100000 + 10000;
    }
    string GetName(){ return name; }
    double GetPrice(){ return price; }
    void Update(CryptoCurrency* currency, Trader* trader)
    {
        switch (currency->status)
        {
        case None: cout << "I am " << name << ", balance: " << price << ". Do nothing with currency " << currency->name << endl; break;
        case Increase: 
        {
            if (price < currency->price)
            {
                cout << "I am " << name << ", balance: " << price << ". Sell " << currency->name << endl; 
                price += currency->price;
            }
            else
            {
                cout << "I am " << name << ", balance: " << price << ". Do nothing with currency " << currency->name << endl;
            }
            break;
        }
        case Decrease: 
        {
            if (price > currency->price)
            {
                cout << "I am " << name << ", balance: " << price << ". Buy " << currency->name << endl; 
                price -= currency->price;
            }
            else
            {
                cout << "I am " << name << ", balance: " << price << ". Do nothing with currency " << currency->name << endl;
            }
            break;
        }
        }
    }
};

class Exchange
{
private:
    vector<CryptoCurrency*> cryptos;
    vector<Trader*> traders;
public:
    Exchange()
    {
        cryptos.push_back(new CryptoCurrency("Bitcoin", 27210.50));
        cryptos.push_back(new CryptoCurrency("Ethereum", 1630.00));
        cryptos.push_back(new CryptoCurrency("USDT", 1.00));
        cryptos.push_back(new CryptoCurrency("BNB", 215.79));
        cryptos.push_back(new CryptoCurrency("XRP", 0.5198));
    }

    void Subscribe(Trader* trader)
    {
        traders.push_back(trader);
    }
    void UnSubscribe(Trader* trader)
    {
        auto it = traders.begin();
        while (it != traders.end())
        {
            if ((*it)->GetName() == trader->GetName())
            {
                delete* it;
                it = traders.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
    double RandomPrice(double price)
    {
        return price + rand() % 21 - 10;
    }

    void GenerateCourse()
    {
        for (auto c : cryptos)
        {
            c->SetNewPrice(RandomPrice(c->price), c);
            Notify(c);
        }
    }
    void Notify(CryptoCurrency* currency)
    {
        for (auto t : traders)
        {
            if (t->GetPrice() <= 0)
            {
                cout << "I am " << t->GetName() << ", balance is zero or negative. Unsubscribing..." << endl;
                UnSubscribe(t);
            }
            t->Update(currency, t);
        }
    }
    void StartTraders()
    {
        for (size_t i = 0; i < 10; i++)
        {
            GenerateCourse();
            Sleep(1000);
            cout << endl << endl;
        }
    }
};

int main()
{
    srand(time(0));

    Exchange exchange;

    Trader* td1 = new Trader("Max");
    //Trader* td2 = new Trader("Andrew");
    //Trader* td3 = new Trader("Alex");
    //Trader* td4 = new Trader("John");
    //Trader* td5 = new Trader("Stephen");

    exchange.Subscribe(td1);
    //exchange.Subscribe(td2);
    //exchange.Subscribe(td3);
    //exchange.Subscribe(td4);
    //exchange.Subscribe(td5);

    exchange.StartTraders();
    //exchange.UnSubscribe(td1);
    //exchange.StartTraders();

    delete td1;
    //delete td2;
    //delete td3;
    //delete td4;
    //delete td5;
}