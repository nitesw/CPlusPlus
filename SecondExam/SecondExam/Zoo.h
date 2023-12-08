#pragma once
#include "Animals.h";

class Zoo
{
	list<Animal*> animals;
	string name;
	int countAnimals;
	bool IsExistPlace(string place);
	bool IsExistName(string name);
	static bool CompareAnimalNames(const Animal* a, const Animal* b);
public:
	Zoo() :name(""), countAnimals(0) {}
	Zoo(string n) :name(n), countAnimals(0) {}

	void PrintZoo()const;
	void AddToZoo(Animal& an);
	void DeleteFromZoo(string name);
	void SortByName();
	void SearchByName(string name);
	void SearchByPlace(string place);
	void EditAnimal(string name);

	string GetName() { return name; }
	int GetCount() { return countAnimals; }
	void SetName(string name) { this->name = name; }
	bool IsEmpty() { return animals.empty() ? true : false; }

	friend ostream& operator<<(ostream& out, const Animal& an);
	friend ofstream& operator<<(ofstream& out, Zoo& zoo);
	friend ifstream& operator>>(ifstream& in, Zoo& zoo);

	void SaveToFile();
	void Load();
};

class Feed
{
	multimap<string, int> feed;
	int countFeed;
	int sumOfPricing;
	bool DoesPriceExist(int price)const;
public:
	Feed() :countFeed(0), sumOfPricing(0) {}
	void PrintFeed();
	void AddFeed(int num);
	void DeleteFeedByPrice(int price);
	void EditFeedSpending(int num);

	bool IsEmpty() { return feed.empty() ? true : false; }
	int GetCount() { return countFeed; }
	int GetSum() { return sumOfPricing; }

	friend ofstream& operator<<(ofstream& out, Feed& f);
	friend ifstream& operator>>(ifstream& in, Feed& f);

	void SaveToFile();
	void Load();
};