#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BadConnectionException : public exception
{
public:
    BadConnectionException(string message) : exception(message.c_str()) {}
};

class Database
{
    const string connectionString = "database.txt";
    bool isConnected = false;

    bool IsConnectedImmitatingConnectivitiyIssues()
    {
        return (rand() % 10) < 6;
    }
public:
    bool IsConnected()
    {
        isConnected = IsConnectedImmitatingConnectivitiyIssues();
        return isConnected;
    }
    void Log(string msg)
    {
        ofstream file(connectionString, ios_base::app);
        file << msg << endl;
        file.close();
    }
    void Connect(string connString)
    {
        if (connString != connectionString)
        {
            cout << "Error! File doesn't exist!" << endl;
        }
        else
        {
            for (size_t i = 0; i < 3; i++)
            {
                if (IsConnected())
                {
                    string msg = "Succesfully connected!";
                    cout << msg << endl;
                    Log(msg);
                    return;
                }
                else
                {
                    cout << "Doesn't connected, trying again." << endl;
                }
            }
            throw BadConnectionException("Couldn't connect to database...");
        }
    }
};

class Proxy
{
    Database db;
    string proxyFile = "localTempDatabase.txt";
public:
    void Log(string msg)
    {
        ofstream file(proxyFile, ios_base::app);
        file << msg << endl;
        file.close();
    }
    void ErrorCatch()
    {
        try
        {
            db.Connect("database.txt");
        }
        catch (BadConnectionException& e)
        {
            string err = e.what();
            cout << err << endl;
            Log(err);
        }
    }
};

int main()
{
    srand(time(0));

    Proxy proxy;
    proxy.ErrorCatch();
}