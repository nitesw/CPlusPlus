#include <iostream>
#include <list>
using namespace std;

struct Ticket
{
    string destination;
    int flightNumber;
    string initsOfPassanger;
    string desiredDepatureDate;
};

bool CompareTicketByDest(const Ticket& t1, const Ticket& t2);

ostream& operator<<(ostream& out, const Ticket& ticket)
{
    out << "Destination: " << ticket.destination << endl;
    out << "Flight number: " << ticket.flightNumber << endl;
    out << "Inits of passanger: " << ticket.initsOfPassanger << endl;
    out << "Desired depature date: " << ticket.desiredDepatureDate << endl;
    return out;
}

class Airport
{
    list<Ticket> tickets;
public:
    void AddRequest(Ticket& ticket)
    {
        tickets.push_back(ticket);
    }
    void DeleteRequestByFlightNumber(int num)
    {
        for (auto it = tickets.begin(); it != tickets.end(); ++it)
        {
            if (it->flightNumber == num)
            {
                tickets.erase(it);
                break;
            }
        }
    }
    void PrintAllRequests()
    {
        for (Ticket t : tickets)
        {
            cout << t << endl;
        }
    }
    void PrintByDate(string date)
    {
        for (auto it = tickets.begin(); it != tickets.end(); ++it)
        {
            if (it->desiredDepatureDate == date)
            {
                cout << *it << endl;
                break;
            }
        }
    }
    void SortByDest()
    {
        tickets.sort(CompareTicketByDest);
    }
};

int main()
{
    Ticket t1 = { "New York", 123, "Jake", "2023-09-12" };
    Ticket t2 = { "California", 558, "Drake", "2023-09-06" };
    Ticket t3 = { "Washington", 703, "Mary", "2023-09-01" };

    Airport airport;

    airport.AddRequest(t1);
    airport.AddRequest(t2);
    airport.AddRequest(t3);

    airport.PrintAllRequests();

    cout << "-------------------Sorted By Destination-------------------" << endl;
    airport.SortByDest();
    airport.PrintAllRequests();

    cout << "-------------------Printed By Date-------------------" << endl;
    airport.PrintByDate("2023-09-06");

    cout << "-------------------After Deleting One-------------------" << endl;
    airport.DeleteRequestByFlightNumber(123);
    airport.PrintAllRequests();
}

bool CompareTicketByDest(const Ticket& t1, const Ticket& t2)
{
    return t1.destination < t2.destination;
}