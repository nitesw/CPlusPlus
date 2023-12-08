#include "Zoo.h";

#pragma region Zoo
void Zoo::PrintZoo()const
{
    cout << "\n\t\t\t--------------- " << name << " ---------------" << endl;
    for (Animal* an : animals)
    {
        cout << "\n\t\t\t";
        an->Print();
    }
    cout << endl;
}

void Zoo::AddToZoo(Animal& an)
{
    countAnimals++;
    animals.push_back(&an);
}

void Zoo::DeleteFromZoo(string name)
{ 
    if (!animals.empty())
    {
        if (!IsExistName(name))
        {
            cout << "\t\t\tThere is no such an animal with name " << name << "." << endl << endl;
        }
        for (auto it = animals.begin(); it != animals.end();)
        {
            if (name == (*it)->GetName())
            {
                countAnimals--;
                it = animals.erase(it);
            }
            else
            {
                ++it;
            }
        }
        cout << endl;
    }
    else
    {
        cout << "\t\t\tYou don't have any animals in the zoo to delete!" << endl << endl;
    }
}

bool Zoo::CompareAnimalNames(const Animal* a, const Animal* b)
{
    return a->GetName() < b->GetName();
}

void Zoo::SortByName()
{
    animals.sort(CompareAnimalNames);
}

bool Zoo::IsExistName(string name)
{
    for (const Animal* an : animals)
    {
        if (an->GetName() == name)
        {
            return true;
        }
    }
    return false;
}
void Zoo::SearchByName(string name)
{
    if (!animals.empty())
    {
        if (!IsExistName(name))
        {
            cout << "\t\t\t\tName of the animal in the zoo doesn't exist." << endl;
        }
        else
        {
            for (const Animal* an : animals)
            {
                if (an->GetName() == name)
                {
                    cout << "\n\t\t\t\t";
                    an->Print();
                }
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\t\t\tYou don't have any animals in the zoo to search for!" << endl << endl;
    }
}

bool Zoo::IsExistPlace(string place)
{
    for (const Animal* an : animals)
    {
        if (an->GetPlace() == place)
        {
            return true;
        }
    }
    return false;
}
void Zoo::SearchByPlace(string place)
{
    if (!animals.empty())
    {
        if (!IsExistPlace(place))
        {
            cout << "\t\t\t\tPlace in the zoo doesn't exist." << endl;
        }
        else
        {
            for (const Animal* an : animals)
            {
                if (an->GetPlace() == place)
                {
                    cout << "\n\t\t\t\t";
                    an->Print();
                }
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\t\t\tYou don't have any animals in the zoo to search for!" << endl << endl;
    }
}

void Zoo::EditAnimal(string name)
{
    if (!animals.empty())
    {
        if (!IsExistName(name))
        {
            cout << "\t\t\tName of the animal in the zoo doesn't exist" << endl;
        }
        else
        {
            for (Animal* an : animals)
            {
                if (an->GetName() == name)
                {
                    int choice;
                    do
                    {
                        cout << "\t\t\tWhat do you want to edit?" << endl;
                        cout << "\t\t\t1. Name" << endl;
                        cout << "\t\t\t2. Place" << endl;
                        cout << "\t\t\t3. Age" << endl;
                        cout << "\t\t\t4. Weight" << endl;
                        cout << "\t\t\t5. Speed" << endl;
                        cout << "\t\t\t6. Spec" << endl;
                        cout << "\t\t\t0. Go back to main menu" << endl;
                        cout << "\t\t\tEnter your choice: "; cin >> choice;
                        system("cls");
                        switch (choice)
                        {
                        case 1:
                        {
                            string name;
                            cout << "\n\t\t\tEnter new name: ";
                            cin.ignore();
                            getline(cin, name);
                            an->SetName(name);
                            system("cls");
                            break;
                        }
                        case 2:
                        {
                            string place;
                            cout << "\n\t\t\tEnter new place: ";
                            cin.ignore();
                            getline(cin, place);
                            an->SetPlace(place);
                            system("cls");
                            break;
                        }
                        case 3:
                        {
                            int age;
                            cout << "\n\t\t\tEnter new age: ";
                            cin.ignore();
                            cin >> age;
                            an->SetAge(age);
                            system("cls");
                            break;
                        }
                        case 4:
                        {
                            double weight;
                            cout << "\n\t\t\tEnter new weight: ";
                            cin.ignore();
                            cin >> weight;
                            an->SetWeight(weight);
                            system("cls");
                            break;
                        }
                        case 5:
                        {
                            double speed;
                            cout << "\n\t\t\tEnter new speed: ";
                            cin.ignore();
                            cin >> speed;
                            an->SetSpeed(speed);
                            system("cls");
                            break;
                        }
                        case 6:
                        {
                            cin.ignore();
                            an->EditSpec();
                            system("cls");
                            break;
                        }
                        case 0:
                            break;
                        }
                    } while (choice != 0);
                }
            }
        }
    }
    else
    {
        cout << "\t\t\tYou don't have any animals in the zoo to delete!" << endl << endl;
    }
}

#pragma region Save & Load
void Zoo::SaveToFile()
{
    ofstream out_file("zoo.txt", ios_base::out);
    out_file << *this;
    out_file.close();
}
void Zoo::Load()
{
    ifstream in("zoo.txt", ios_base::in);
    in >> *this;
    in.close();
}
#pragma endregion
#pragma endregion

ostream& operator<<(ostream& out, const Animal& an)
{
    out << an.GetType() << endl;
    out << an.GetName() << endl;
    out << an.GetPlace() << endl;
    out << an.GetAge() << endl;
    out << an.GetWeight() << endl;
    out << an.GetSpeed() << endl;
    out << an.GetSpec() << endl;
    return out;
}

ofstream& operator<<(ofstream& out, Zoo& zoo)
{
    out << zoo.name << endl;
    out << zoo.countAnimals << endl;

    for (const Animal* an : zoo.animals)
    {
        out << *an << endl;
    }
    return out;
}

ifstream& operator>>(ifstream& in, Zoo& zoo)
{
    zoo.animals.clear();

    getline(in, zoo.name);
    in >> zoo.countAnimals;
    in.ignore();

    while (!in.eof())
    {
        string type;
        in >> type;

        Animal* animal = nullptr;

        if (type == "Mammal")
        {
            double weight, speed;
            string name, place;
            int age;
            bool spec;

            in.ignore();
            getline(in, name);
            getline(in, place);
            in >> age >> weight >> speed >> spec;
            in.ignore();
            animal = new Mammal(weight, speed, name, place, age, spec);
        }
        else if (type == "Bird")
        {
            double weight, speed;
            string name, place;
            int age;
            bool spec;

            in.ignore();
            getline(in, name);
            getline(in, place);
            in >> age >> weight >> speed >> spec;
            in.ignore();
            animal = new Bird(weight, speed, name, place, age, spec);
        }
        else if (type == "Fish")
        {
            double weight, speed;
            string name, place;
            int age;
            bool spec;

            in.ignore();
            getline(in, name);
            getline(in, place);
            in >> age >> weight >> speed >> spec;
            in.ignore();
            animal = new Fish(weight, speed, name, place, age, spec);
        }
        else if (type == "Reptile")
        {
            double weight, speed;
            string name, place;
            int age;
            bool spec;

            in.ignore();
            getline(in, name);
            getline(in, place);
            in >> age >> weight >> speed >> spec;
            in.ignore();
            animal = new Reptile(weight, speed, name, place, age, spec);
        }
        else if (type == "Amphibian")
        {
            double weight, speed;
            string name, place;
            int age;
            bool spec;

            in.ignore();
            getline(in, name);
            getline(in, place);
            in >> age >> weight >> speed >> spec;
            in.ignore();
            animal = new Amphibian(weight, speed, name, place, age, spec);
        }

        if (animal)
        {
            zoo.animals.push_back(animal);
        }
    }
    return in;
}


#pragma region Feed
void Feed::PrintFeed()
{
    cout << "\n\t\t\t--------------- Feeds ---------------" << endl;
    for (const auto& pair : feed)
    {
        cout << "\t\t\t" << pair.first << ". Price: " << pair.second << endl;
    }
    cout << endl;
}
void Feed::AddFeed(int num)
{
    int price;
    for (size_t i = 0; i < num; i++)
    {
        countFeed++;
        cout << "\t\t\t\tEnter price of #" << i + 1 << " feed: "; cin >> price;
        sumOfPricing += price;
        feed.insert(make_pair("Feed", price));
    }
}
bool Feed::DoesPriceExist(int price) const
{
    for (const auto& entry : feed)
    {
        if (entry.second == price) 
        {
            return true;
        }
    }
    return false;
}
void Feed::DeleteFeedByPrice(int price)
{
    if (!feed.empty())
    {
        if (!DoesPriceExist(price))
        {
            cout << "\t\t\t\tFeed by this price doesn't exist." << endl;
        }
        if (countFeed > 0)
        {
            for (auto it = feed.begin(); it != feed.end();)
            {
                if (it->second == price)
                {
                    sumOfPricing -= it->second;
                    it = feed.erase(it);
                    countFeed--;
                }
                else 
                {
                    ++it;
                }
            }
        }
    }
    else
    {
        cout << "\t\t\t\tYou don't have any feed in the zoo." << endl << endl;
    }
}
void Feed::EditFeedSpending(int num)
{
    if (num > sumOfPricing)
        sumOfPricing = num;
    else
        cout << "\t\t\t\tError! Price is lower than spendings." << endl;
}
#pragma region Save & Load
void Feed::SaveToFile()
{
    ofstream out_file("feed.txt", ios_base::out);
    out_file << *this;
    out_file.close();
}
void Feed::Load()
{
    ifstream in("feed.txt", ios_base::in);
    in >> *this;
    in.close();
}
#pragma endregion
#pragma endregion

ofstream& operator<<(ofstream& out, Feed& f)
{
    out << f.countFeed << endl;
    out << f.sumOfPricing << endl;

    for (auto pair : f.feed)
    {
        out << pair.first << endl;
        out << pair.second << endl;
    }
    return out;
}

ifstream& operator>>(ifstream& in, Feed& f)
{
    f.feed.clear();

    in >> f.countFeed;
    in >> f.sumOfPricing;
    while (!in.eof())
    {
        string name;
        in >> name;
        if (name.empty()) break;
        int price;
        in >> price;
        f.feed.insert(make_pair(name, price));
    }
    return in;
}
