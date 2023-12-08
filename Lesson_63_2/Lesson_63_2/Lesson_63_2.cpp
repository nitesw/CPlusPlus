#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Singleton
{
	static Singleton* p_instance;
	Singleton() {}
	Singleton(const Singleton& other) = delete;
	Singleton& operator=(const Singleton& other) = delete;
public:
	static Singleton* GetInstance()
	{
		if (p_instance == nullptr)
		{
			p_instance = new Singleton();
		}
		return p_instance;
	}

	void Log(string msg)
	{
		cout << msg << endl;
	}
	void LogToFile(string msg)
	{
		ofstream file("log.txt", ios_base::app);
		file << msg << endl;
		file.close();
	}
	void ReadFromFile()
	{
		ifstream file("log.txt", ios_base::in);
		while (!file.eof())
		{
			string msg;
			getline(file, msg);
			cout << msg << endl;
		}
	}
};
Singleton* Singleton::p_instance = nullptr;

int main()
{
	//Singleton* s = Singleton::GetInstance();
	//s->Log("Hello");
	//Singleton* s1 = Singleton::GetInstance();
	//s1->Log("Insert was new user at 21:59 PM");
	//Singleton::GetInstance()->LogToFile("user Delete VS");
	//Singleton::GetInstance()->LogToFile("user Donwload Fortnite");
	//Singleton::GetInstance()->LogToFile("user Filed Game");

	Singleton::GetInstance()->ReadFromFile();
}