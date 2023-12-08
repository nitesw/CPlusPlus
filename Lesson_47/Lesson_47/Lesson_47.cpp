#include <iostream>
using namespace std;

template<class T>
class List
{
private:
    struct Node
    {
        Node* prev;
        T value;
        Node* next;
        Node(Node* prev, T value, Node* next) :prev(prev), value(value), next(next) {}
    };
    Node* head;
    Node* tail;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    List(const List& other)
    {
        for (Node* current = other.head; current != nullptr; current = current->next)
        {
            this->AddToTail(current->value);
        }
    }
    void Clear()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }

    List& operator =(const List& other)
    {
        Clear();
        for (Node* current = other.head; current != nullptr; current = current->next)
        {
            this->AddToTail(current->value);
        }
        return *this;
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    void AddToHead(T value)
    {
        Node* newNode = new Node(nullptr, value, head);

        if (IsEmpty())
        {
            head = tail = newNode;
        }

        head->prev = newNode;
        head = newNode;
    }
    void PrintList()const
    {
        for (Node* current = head; current != nullptr; current = current->next)
        {
            cout << current->value << " ";
        }
        cout << endl;
    }
    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void AddToTail(T value)
    {
        Node* newNode = new Node(tail, value, nullptr);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    T GetElement(int pos)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    void DeleteFromTail()
    {
        if (IsEmpty()) return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }
    void DeleteFromHead()
    {
        if (IsEmpty()) return;

        Node* nodeToDelete = head;

        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        delete nodeToDelete;
    }
    T operator[](int pos)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
};

struct Vagon
{
	int number_Vagony;// номер вагону
	int amount_Of_Pasanger_Place;// кількість місць
	int amountPasangers;// кількість пасажирів
	Vagon() :number_Vagony(0), amount_Of_Pasanger_Place(0), amountPasangers(0) {}
	Vagon(int num, int places)
	{
		number_Vagony = num;
		amount_Of_Pasanger_Place = places;
		amountPasangers = 0;
	}
    Vagon(int n, int p, int pass) :number_Vagony(n), amount_Of_Pasanger_Place(p), amountPasangers(pass) {}
	void Print()
	{
		cout << "Number : " << number_Vagony << endl;
		cout << "amount_Of_Pasanger_Place : " << amount_Of_Pasanger_Place << endl;
		cout << "amountPasangers : " << amountPasangers << endl;
	}
};
ostream& operator <<(ostream& out, const Vagon& other)
{
    out << "Number : " << other.number_Vagony << endl;
    out << "amount_Of_Pasanger_Place : " << other.amount_Of_Pasanger_Place << endl;
    out << "amountPasangers : " << other.amountPasangers << endl;
    return out;
}

class Train
{
	string model;// модель
	int amount_of_vagons;// кількість вагонів
    List<Vagon> vagons;
public:
	Train()
	{
		model = "no model";
		amount_of_vagons = 0;
	}
	Train(string model)// В класі потяг оголосити дефолтний конструктор і перезавантажений конструктор.
	{
		this->model = model;
		this->amount_of_vagons = 0;
	}
	Train(const Train& other) :vagons(vagons)
	{
		this->model = other.model;
		this->amount_of_vagons = other.amount_of_vagons;
		//this->vagons = other.vagons;//operator =
	}

	void Show()
	{
		cout << "Name Train : " << model << endl;
		cout << "Number of wagons : " << amount_of_vagons << endl;
        vagons.PrintList();
	}
    void Add_VagonToTail(Vagon v)
    {
        vagons.AddToTail(v);
        amount_of_vagons++;
    }
    void Add_VagonToHead(Vagon v)
    {
        vagons.AddToHead(v);
        amount_of_vagons++;
    }
    void DeleteVagonFromHead()
    {
        vagons.DeleteFromHead();
        amount_of_vagons--;
    }
    void DeleteVagonFromTail()
    {
        vagons.DeleteFromHead();
        amount_of_vagons--;
    }
};

int main()
{
    /*List<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }
    l.PrintList();

    l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    l.AddToTail(400);
    l.AddToTail(500);
    l.PrintList();

    cout << "Element by pos 3 : " << l.GetElement(3) << endl;
    cout << "Element by pos 5 : " << l[5] << endl;

    l.DeleteFromTail();
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.PrintList();

    l.DeleteFromHead();
    l.DeleteFromHead();
    l.DeleteFromHead();
    l.PrintList();*/

    Train train("Tom");
    train.Add_VagonToTail(Vagon{ 1,20,3 });
    train.Add_VagonToTail(Vagon{ 2,10,7 });
    train.Add_VagonToTail(Vagon{ 3,15,12 });
    train.Add_VagonToTail(Vagon{ 4,10,8 });
    train.Add_VagonToTail(Vagon{ 5,25,24 });
    train.Show();

    /*Train newTrain(train);
    newTrain.Show();

    newTrain = train;
    newTrain.Show();*/

    train.Add_VagonToHead(Vagon{ 0,15,8 });
    train.Show();

    train.DeleteVagonFromHead();
    train.Show();

    train.DeleteVagonFromTail();
    train.Show();
}
