#include <iostream>
using namespace std;

struct Vagon
{
    int vagonNum;
    int numberOfSeats;
    int numberOfPassengers;
};

class Train
{
    string modelOfTrain;
    int numberOfVagons;
    Vagon* vagon;
public:
    Train() : numberOfVagons{0}, vagon{0}
    {
        modelOfTrain = "no model";
    }
    Train(int numberOfVagons, string text)
    {
        this->numberOfVagons = numberOfVagons;
        this->modelOfTrain = text;
        vagon = new Vagon[numberOfVagons];
    }
    Train(const Train& other)
    {
        this->numberOfVagons = other.numberOfVagons;
        this->modelOfTrain = other.modelOfTrain;
        this->vagon = new Vagon[other.numberOfVagons];
        for (int i = 0; i < other.numberOfVagons; i++)
        {
            vagon[i] = other.vagon[i];
        }
    }
    void Init()
    {
        cout << "\t----------- " << "Initalize a train" << " ----------";
        cout << "\n\tEnter the model of a train: "; cin >> modelOfTrain;
        cout << "\n\tEnter number of the vagons: "; cin >> numberOfVagons;
        cout << endl;
        vagon = new Vagon[numberOfVagons];
        for (size_t i = 0; i < numberOfVagons; i++)
        {
            cout << "\n\tVagon #" << i + 1 << endl;
            cout << "\tEnter number of the seats: "; cin >> vagon[i].numberOfSeats;
            cout << "\n\tEnter number of the passengers: "; cin >> vagon[i].numberOfPassengers;
        }
        
    }
    void Show()
    {
        cout << "\t---------- " << modelOfTrain << " ----------";
        cout << "\n\tNumber of vagons: " << numberOfVagons;
        for (size_t i = 0; i < numberOfVagons; i++)
        {
            cout << "\n\tVagon number: " << i + 1 << endl;
            cout << "\tNumber of seats and number of passengers: ";
            cout << vagon[i].numberOfSeats << " " << vagon[i].numberOfPassengers << endl;
        }
    }
    void addVagon()
    {
        Vagon* newVagon = new Vagon[numberOfVagons + 1];

        for (size_t i = 0; i < numberOfVagons; i++)
        {
            newVagon[i] = vagon[i];
        }
        cout << "\n\tVagon #" << numberOfVagons + 1 << endl;
        cout << "\tEnter number of the seats: ";
        cin >> newVagon[numberOfVagons].numberOfSeats;
        cout << "\n\tEnter number of the passengers: ";
        cin >> newVagon[numberOfVagons].numberOfPassengers;

        delete[] vagon;
        vagon = newVagon;
        numberOfVagons++;
    }
    void addPassenger()
    {
        int num;
        cout << "\n\tEnter the vagon you want to add passenger at: "; cin >> num;
        if (num >= 1 && num <= numberOfVagons) {
            vagon[num - 1].numberOfPassengers++;
            cout << "\n\tPassenger added to vagon #" << num << endl;
        }
        else {
            cout << "\n\tInvalid vagon number!" << endl;
        }
    }
    ~Train()
    {
        if (vagon != nullptr)
            delete[] vagon;
    }
};

int main()
{
    Train tr;
    tr.Init();
    int choice;
    do
    {
        cout << "\n\n\t1. Print train" << endl;
        cout << "\t2. Add a vagon to the train" << endl;
        cout << "\t3. Add passenger to the train" << endl;
        cout << "\t4. Copy train" << endl;
        cout << "\t> "; cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            tr.Show();
            break;
        }
        case 2:
        {
            tr.addVagon();
            break;
        }
        case 3:
        {
            tr.addPassenger();
            break;
        }
        case 4:
        {
            Train testTr = Train(tr);
            cout << "\n\tFrom: ";
            tr.Show();
            cout << "\n\tTo: ";
            testTr.Show();
        }
        default:
            break;
        }
    } while (choice != 0);
}