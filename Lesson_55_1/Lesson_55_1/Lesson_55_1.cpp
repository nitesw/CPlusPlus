#include <iostream>
#include <vector>
using namespace std;

struct Time
{
    short h, m, s;
};

class Train
{
    int number;
    Time departureTime;
    string destination;
public:
    Train() :number(0), destination("")
    {
        departureTime.h = 0;
        departureTime.m = 0;
        departureTime.s = 0;
    }
    Train(int n, string d, short h, short m, short s) :number(n), destination(d)
    {
        departureTime.h = h;
        departureTime.m = m;
        departureTime.s = s;
    }

    void setTime(short h, short m, short s)
    {
        this->departureTime.h = h;
        this->departureTime.m = m;
        this->departureTime.s = s;
    }
    string getDest()
    {
        return destination;
    }

    void Print()const
    {
        cout << "Train #" << number << endl;
        cout << "Depature time: " << departureTime.h << ":" << departureTime.m << ":" << departureTime.s << endl;   
        cout << "Destination: " << destination << endl;
    }

    friend ostream& operator<<(ostream& out, const Train& train);
};

class Railway
{
    vector<Train> trains;
public:
    void AddTrain(Train tr)
    {
        trains.push_back(tr);
    }
    void PrintAll()
    {
        for (Train element : trains)
        {
            cout << element << endl;
        }
    }
    void PrintTrain(int num)
    {
        cout << trains[num - 1] << endl;
    }
    void PrintTrainsToStation(string station)
    {
        for (Train element : trains)
        {
            if (element.getDest() == station)
            {
                element.Print();
                cout << endl;
            }
        }
    }
    void EditTime(int num, short h, short m, short s)
    {
        trains[num - 1].setTime(h, m, s);
    }
};

ostream& operator<<(ostream& out, const Train& train)
{
    out << "Train #" << train.number << endl;
    out << "Depature time: " << train.departureTime.h << ":" << train.departureTime.m << ":" << train.departureTime.s << endl;
    out << "Destination: " << train.destination << endl;
    return out;
}


int main()
{
    Train tr1(1, "Kyiv", 12, 30, 15);
    Train tr2(2, "Rivne", 7, 15, 00);
    Train tr3(3, "Lviv", 18, 20, 00);
    Train tr4(4, "Kyiv", 15, 00, 00);

    Railway trains;
    trains.AddTrain(tr1);
    trains.AddTrain(tr2);
    trains.AddTrain(tr3);
    trains.AddTrain(tr4);
    trains.PrintAll();
    cout << "------------------------" << endl;
    trains.PrintTrain(1);
    trains.EditTime(2, 6, 30, 00);
    trains.PrintTrain(2);
    cout << "------------------------" << endl;
    trains.PrintTrainsToStation("Kyiv");
}