#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Consumer {
private:
	string name;
	string surname;
	string lastname;

	string homePhone;
	string workPhone;
	string mobilePhone;

	string contactInformation;
	static int consumerCounter;
public:
	Consumer()
	{
		name = "No name";
		surname = "No surname";
		lastname = "No lastname";
		homePhone = "0";
		workPhone = "0";
		mobilePhone = "0";
		contactInformation = "No information";
	}
	Consumer(string name, string surname, string lastname) : Consumer()
	{
		this->name = name;
		this->surname = surname;
		this->lastname = lastname;
	}
	Consumer(string name, string surname, string lastname, string homePhone, string workPhone, string mobilePhone) : Consumer(name, surname, lastname)
	{
		this->homePhone = homePhone;
		this->workPhone = workPhone;
		this->mobilePhone = mobilePhone;
	}
	Consumer(string name, string surname, string lastname, string homePhone, string workPhone, string mobilePhone, string contactInformation) : Consumer(name, surname, lastname, homePhone, workPhone, mobilePhone)
	{
		this->contactInformation = contactInformation;
	}
	inline string getName(Consumer subscriber) 
	{
		return subscriber.name;
	}
	inline string getSurname(Consumer subscriber) 
	{
		return subscriber.surname;
	}
	inline string getLastname(Consumer subscriber) 
	{
		return subscriber.lastname;
	}
	inline string getHomePhone(Consumer subscriber) 
	{
		return subscriber.homePhone;
	}
	inline string getWorkPhone(Consumer subscriber) 
	{
		return subscriber.workPhone;
	}
	inline string getMobilePhone(Consumer subscriber) 
	{
		return subscriber.mobilePhone;
	}
	inline string getContactInformation(Consumer subscriber) 
	{
		return subscriber.contactInformation;
	}
	inline Consumer* getSubscriber(Consumer* subscriber) 
	{
		return subscriber;
	}
	void Show(Consumer* subscriber, int size) {
		for (size_t i = 0; i < size; i++)
		{
			cout << "\nSubscriber #" << i + 1 << endl;
			cout << "FullName	    :: " << getLastname(subscriber[i]) << " " << getName(subscriber[i]) << " " << getSurname(subscriber[i]) << endl;
			cout << "Home phone	    :: " << getHomePhone(subscriber[i]) << endl;
			cout << "Work phone	    :: " << getWorkPhone(subscriber[i]) << endl;
			cout << "Mobile phone	    :: " << getMobilePhone(subscriber[i]) << endl;
			cout << "Contact information :: " << getContactInformation(subscriber[i]) << endl;
			cout << "Consumer Counter     :: " << consumerCounter << endl;
		}
	}
	void AddSubscriber(string name, string surname, string lastname, string homePhone, string workPhone, string mobilePhone, string contactInformation, Consumer*& subscriber, int& size) 
	{
		Consumer* tmp = new Consumer[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			tmp[i] = subscriber[i];
		}
		tmp[size].name = name;
		tmp[size].surname = surname;
		tmp[size].lastname = lastname;
		tmp[size].homePhone = homePhone;
		tmp[size].workPhone = workPhone;
		tmp[size].mobilePhone = mobilePhone;
		tmp[size].contactInformation = contactInformation;
		delete[] subscriber;
		subscriber = tmp;
		++size;
		++consumerCounter;
	}
	void DeleteSubscriber(string name, string surname, string lastname, Consumer*& subscriber, int& size) 
	{
		Consumer* tmp = new Consumer[size - 1];
		bool flag = false;
		for (size_t i = 0; i < size; i++)
		{
			if (subscriber[i].name != name and subscriber[i].surname != surname and subscriber[i].lastname != lastname and !flag) 
			{
				tmp[i] = subscriber[i];
			}
			else if (subscriber[i].name != name and subscriber[i].surname != surname and subscriber[i].lastname != lastname and flag) 
			{
				tmp[i] = subscriber[i + 1];
			}
			else 
			{
				flag = true;
			}
		}
		delete[] subscriber;
		subscriber = tmp;
		--size;
		--consumerCounter;
	}
	void Search(string name, string surname, string lastname, Consumer*& subscriber, int& size) 
	{
		bool flag = false;
		for (size_t i = 0; i < size; i++)
		{
			if (subscriber[i].name == name and subscriber[i].surname == surname and subscriber[i].lastname == lastname) 
			{
				cout << "FullName: " << getLastname(subscriber[i]) << " " << getName(subscriber[i]) << " " << getSurname(subscriber[i]) << endl;
				cout << "Home phone: " << getHomePhone(subscriber[i]) << endl;
				cout << "Work phone: " << getWorkPhone(subscriber[i]) << endl;
				cout << "Mobile phone: " << getMobilePhone(subscriber[i]) << endl;
				cout << "Contact information: " << getContactInformation(subscriber[i]) << endl;
				cout << "ConsumerCounter: " << consumerCounter << endl;

				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "No subscriber" << endl;
		}
	}
	~Consumer()
	{

	}
};
int Consumer::consumerCounter = 0;
int main() {
	int size = 0;
	Consumer* subscriber = new Consumer[size];
	subscriber->AddSubscriber("Vasya", "Vasyok", "Vasyuchevski", "0678881234", "0668725168", "0962271203", "No", subscriber, size);
	subscriber->AddSubscriber("Margo", "Kinky", "Patterson", "0931883121", "067773211", "098787645", "No", subscriber, size);
	subscriber->AddSubscriber("Vlad", "Vladok", "Vladyusik", "0971115723", "0961349098", "0981157262", "No", subscriber, size);
	subscriber->AddSubscriber("Max", "Edwin", "Murphy", "0667890011", "0981112233", "0978001254", "No", subscriber, size);
	subscriber->Show(subscriber, size);
	cout << endl;

	cout << "Delete\n" << endl;
	subscriber->DeleteSubscriber("Max", "Edwin", "Murphy", subscriber, size);
	subscriber->Show(subscriber, size);
	cout << endl;

	cout << "Search\n" << endl;
	subscriber->Search("Margo", "Kinky", "Patterson", subscriber, size);
	cout << endl;
}