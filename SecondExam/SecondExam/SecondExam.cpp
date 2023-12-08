#include "Animals.h"
#include "Zoo.h"

int main()
{
    int choice;
    Zoo zoo("");
    Feed feed;
    do
    {
        cout << "\n\t\t================Zoo Manger================" << endl;
        cout << "\t\t1. Print (animals / feed / full zoo)" << endl;
        cout << "\t\t2. Add animals to the zoo" << endl;
        cout << "\t\t3. Delete animals from the zoo" << endl;
        cout << "\t\t4. Edit animals in the zoo" << endl;
        cout << "\t\t5. Search for animal in the zoo" << endl;
        cout << "\t\t6. Sort zoo by animals' names" << endl;
        cout << "\t\t7. Add/Delete feed in the zoo" << endl;
        cout << "\t\t8. Expense account" << endl;
        cout << "\t\t9. Load/Save zoo" << endl;
        cout << "\t\t0. Exit" << endl;
        cout << "\t\tEnter your choice: "; cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            int printChoice;
            cout << "\n\t\t\tWhat do you want to print?" << endl;
            cout << "\t\t\t1. Animals in the zoo" << endl;
            cout << "\t\t\t2. Feed in the zoo" << endl;
            cout << "\t\t\t3. Combined (Animals & Feed)" << endl;
            cout << "\t\t\tEnter your choice: "; cin >> printChoice;
            switch (printChoice)
            {
            case 1:
            {
                system("cls");
                if (!zoo.IsEmpty())
                    zoo.PrintZoo();
                else
                    cout << "\t\t\tYou don't have any animals to print" << endl;
                break;
            }
            case 2:
            {
                system("cls");
                if(!feed.IsEmpty())
                    feed.PrintFeed();
                else
                    cout << "\t\t\tYou don't have any feeds to print" << endl;
                break;
            }
            case 3:
            {
                system("cls");
                if (!zoo.IsEmpty() && !feed.IsEmpty())
                {
                    zoo.PrintZoo();
                    feed.PrintFeed();
                }
                else
                    cout << "\t\t\tYou don't have any animals or feeds to print" << endl;
                break;
            }
            default:
                break;
            }
            break;
        }
        case 2:
        {
            system("cls");
            Animal* animal = nullptr;
            if (zoo.GetName() == "")
            {
                string zooName;
                cout << "\n\t\t\tEnter name of the zoo: "; 
                cin.ignore();
                getline(cin, zooName);
                zoo.SetName(zooName);
            }
            int animalChoice;
            cout << "\n\t\t\tWhich type of animal do you want to add?" << endl;
            cout << "\t\t\t1. Mammal" << endl;
            cout << "\t\t\t2. Bird" << endl;
            cout << "\t\t\t3. Fish" << endl;
            cout << "\t\t\t4. Reptile" << endl;
            cout << "\t\t\t5. Amphibian" << endl;
            cout << "\t\t\tEnter your choice: "; cin >> animalChoice;
            switch (animalChoice)
            {
            case 1:
            {
                string name, place;
                int age;
                double weight, speed;
                int spec;
                system("cls");
                cout << "\t\t\tType of animal is Mammal" << endl;
                cout << "\t\t\tEnter animal's name: "; 
                cin.ignore();
                getline(cin, name);
                cout << "\t\t\tEnter animal's habitat place: "; 
                getline(cin, place);
                cout << "\t\t\tEnter animal's age: "; cin >> age;
                cout << "\t\t\tEnter animal's weight: "; cin >> weight;
                cout << "\t\t\tEnter animal's speed: "; cin >> speed;

                animal = new Mammal(weight, speed, name, place, age, false);

                cout << "\t\t\tDoes your mammal have fur?" << endl;
                cout << "\t\t\t\t1. Yes" << endl;
                cout << "\t\t\t\t2. No" << endl;
                cout << "\t\t\t\tEnter your choice: "; cin >> spec;
                cin.ignore();
                system("cls");
                if (spec == 1)
                {
                    animal->SetSpec(true);
                }
                else if (spec == 2)
                {
                    animal->SetSpec(false);
                }
                else
                {
                    cout << "\t\t\tInvalid choice. Assuming no fur." << endl;
                    animal->SetSpec(false);
                }
                zoo.AddToZoo(*animal);
                break;
            }
            case 2:
            {
                string name, place;
                int age;
                double weight, speed;
                int spec;
                system("cls");
                cout << "\t\t\tType of animal is Bird" << endl;
                cout << "\t\t\tEnter animal's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\t\t\tEnter animal's habitat place: ";
                getline(cin, place);
                cout << "\t\t\tEnter animal's age: "; cin >> age;
                cout << "\t\t\tEnter animal's weight: "; cin >> weight;
                cout << "\t\t\tEnter animal's speed: "; cin >> speed;

                animal = new Bird(weight, speed, name, place, age, false);

                cout << "\t\t\tDoes your bird have feathers?" << endl;
                cout << "\t\t\t\t1. Yes" << endl;
                cout << "\t\t\t\t2. No" << endl;
                cout << "\t\t\t\tEnter your choice: "; cin >> spec;
                cin.ignore();
                if (spec == 1)
                {
                    animal->SetSpec(true);
                }
                else if (spec == 2)
                {
                    animal->SetSpec(false);
                }
                else
                {
                    cout << "\t\t\tInvalid choice. Assuming no feathers." << endl;
                    animal->SetSpec(false);
                }
                zoo.AddToZoo(*animal);
                system("cls");
                break;
            }
            case 3:
            {
                string name, place;
                int age;
                double weight, speed;
                int spec;
                system("cls");
                cout << "\t\t\tType of animal is Fish" << endl;
                cout << "\t\t\tEnter animal's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\t\t\tEnter animal's habitat place: ";
                getline(cin, place);
                cout << "\t\t\tEnter animal's age: "; cin >> age;
                cout << "\t\t\tEnter animal's weight: "; cin >> weight;
                cout << "\t\t\tEnter animal's speed: "; cin >> speed;

                animal = new Fish(weight, speed, name, place, age, false);

                cout << "\t\t\tDoes your fish have scales?" << endl;
                cout << "\t\t\t\t1. Yes" << endl;
                cout << "\t\t\t\t2. No" << endl;
                cout << "\t\t\t\tEnter your choice: "; cin >> spec;
                cin.ignore();
                if (spec == 1)
                {
                    animal->SetSpec(true);
                }
                else if (spec == 2)
                {
                    animal->SetSpec(false);
                }
                else
                {
                    cout << "\t\t\tInvalid choice. Assuming no scales." << endl;
                    animal->SetSpec(false);
                }
                zoo.AddToZoo(*animal);
                system("cls");
                break;
            }
            case 4:
            {
                string name, place;
                int age;
                double weight, speed;
                int spec;
                system("cls");
                cout << "\t\t\tType of animal is Reptile" << endl;
                cout << "\t\t\tEnter animal's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\t\t\tEnter animal's habitat place: ";
                getline(cin, place);
                cout << "\t\t\tEnter animal's age: "; cin >> age;
                cout << "\t\t\tEnter animal's weight: "; cin >> weight;
                cout << "\t\t\tEnter animal's speed: "; cin >> speed;

                animal = new Reptile(weight, speed, name, place, age, false);

                cout << "\t\t\tDoes your reptile have teeth?" << endl;
                cout << "\t\t\t\t1. Yes" << endl;
                cout << "\t\t\t\t2. No" << endl;
                cout << "\t\t\t\tEnter your choice: "; cin >> spec;
                cin.ignore();
                if (spec == 1)
                {
                    animal->SetSpec(true);
                }
                else if (spec == 2)
                {
                    animal->SetSpec(false);
                }
                else
                {
                    cout << "\t\t\tInvalid choice. Assuming no teeth." << endl;
                    animal->SetSpec(false);
                }
                zoo.AddToZoo(*animal);
                system("cls");
                break;
            }
            case 5:
            {
                string name, place;
                int age;
                double weight, speed;
                int spec;
                system("cls");
                cout << "\t\t\tType of animal is Amphibian" << endl;
                cout << "\t\t\tEnter animal's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\t\t\tEnter animal's habitat place: ";
                getline(cin, place);
                cout << "\t\t\tEnter animal's age: "; cin >> age;
                cout << "\t\t\tEnter animal's weight: "; cin >> weight;
                cout << "\t\t\tEnter animal's speed: "; cin >> speed;

                animal = new Amphibian(weight, speed, name, place, age, false);

                cout << "\t\t\tDoes your amphibian have legs?" << endl;
                cout << "\t\t\t\t1. Yes" << endl;
                cout << "\t\t\t\t2. No" << endl;
                cout << "\t\t\t\tEnter your choice: "; cin >> spec;
                cin.ignore();
                if (spec == 1)
                {
                    animal->SetSpec(true);
                }
                else if (spec == 2)
                {
                    animal->SetSpec(false);
                }
                else
                {
                    cout << "\t\t\tInvalid choice. Assuming no teeth." << endl;
                    animal->SetSpec(false);
                }
                zoo.AddToZoo(*animal);
                system("cls");
                break;
            }
            default:
                break;
            }
            break;
        }
        case 3:
        {
            system("cls");
            string name;
            cout << "\n\t\t\tEnter name of the animal to delete: ";
            cin.ignore();
            getline(cin, name);
            zoo.DeleteFromZoo(name);
            break;
        }
        case 4:
        {
            system("cls");
            string name;
            cout << "\n\t\t\tEnter name of the animal to edit: ";
            cin.ignore();
            getline(cin, name);
            zoo.EditAnimal(name);
            break;
        }
        case 5:
        {
            system("cls");
            int searchChoice;
            do
            {
                cout << "\n\t\t\tWhat do you want to search for?" << endl;
                cout << "\t\t\t1. Search for animal by name" << endl;
                cout << "\t\t\t2. Search for animal by place" << endl;
                cout << "\t\t\t0. Go to main menu" << endl;
                cout << "\t\t\tEnter your choice: "; cin >> searchChoice;
                switch (searchChoice)
                {
                case 1:
                {
                    system("cls");
                    string name;
                    cout << "\n\t\t\t\tEnter the name of an animal to search for: ";
                    cin.ignore();
                    getline(cin, name);
                    zoo.SearchByName(name);
                    break;
                }
                case 2:
                {
                    system("cls");
                    string place;
                    cout << "\n\t\t\t\tEnter the place of an animal to search for: ";
                    cin.ignore();
                    getline(cin, place);
                    zoo.SearchByPlace(place);
                    break;
                }
                default:
                    break;
                }
            } while (searchChoice != 1 && searchChoice != 2 && searchChoice != 0);
            break;
        }
        case 6:
        {
            system("cls");
            zoo.SortByName();
            break;
        }
        case 7:
        {
            system("cls");
            int feedChoice;
            cout << "\n\t\t\tWhat do you want to do?" << endl;
            cout << "\t\t\t1. Add feed to the zoo" << endl;
            cout << "\t\t\t2. Delete feed from the zoo" << endl;
            cout << "\t\t\tEnter your choice: "; cin >> feedChoice;
            switch (feedChoice)
            {
            case 1:
            {
                cout << "\t\t\t\tHow much feed do you want to add?: "; cin >> feedChoice;
                system("cls");
                feed.AddFeed(feedChoice);
                system("cls");
                break;
            }
            case 2:
            {
                int price;
                cout << "\t\t\t\tEnter price of feed to delete: "; cin >> price;
                system("cls");
                feed.DeleteFeedByPrice(price);
                break;
            }
            default:
                break;
            }
            break;
        }
        case 8:
        {
            system("cls");
            if (!zoo.IsEmpty() && !feed.IsEmpty())
            {
                int choice;
                do
                {
                    cout << "\n\t\t\tZoo name: " << zoo.GetName() << endl;
                    cout << "\t\t\tAnimals in the zoo: " << zoo.GetCount() << endl;
                    cout << "\t\t\tFeeds in the zoo: " << feed.GetCount() << endl;
                    cout << "\n\t\t\tSpendings on the feeds: " << feed.GetSum() << endl;
                    cout << "\n\t\t\tWhat do you want to do?" << endl;
                    cout << "\t\t\t1. Change zoo's spendings" << endl;
                    cout << "\t\t\t0. Go to main menu" << endl;
                    cout << "\t\t\tEnter your choice: "; cin >> choice;
                    switch (choice)
                    {
                    case 1:
                    {
                        int spendings;
                        cout << "\n\t\t\t\tEnter new spendings (must be higher than spendings): "; cin >> spendings;
                        system("cls");
                        feed.EditFeedSpending(spendings);
                    }
                    case 0:
                        system("cls");
                    default:
                        break;
                    }
                } while (choice != 0);
            }
            else
                cout << "\t\t\tYou don't have any animals or feeds to count" << endl;
            break;
        }
        case 9:
        {
            system("cls");
            int fileChoice;

            do
            {
                cout << "\n\t\t\tWhat do you want to do?" << endl;
                cout << "\t\t\t1. Save zoo to file" << endl;
                cout << "\t\t\t2. Load zoo from file" << endl;
                cout << "\t\t\t0. Go to main menu" << endl;
                cout << "\t\t\tEnter your choice: "; cin >> fileChoice;
                switch (fileChoice)
                {
                case 1:
                {
                    zoo.SaveToFile();
                    feed.SaveToFile();
                    break;
                }
                case 2:
                {
                    zoo.Load();
                    feed.Load();
                    break;
                }
                default:
                    break;
                }
            } while (fileChoice != 0 && fileChoice != 1 && fileChoice != 2);
            system("cls");
            break;
        }
        }
    } while (choice != 0);

}