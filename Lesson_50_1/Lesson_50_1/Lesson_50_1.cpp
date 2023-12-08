#include <iostream>
#include <ctime>
using namespace std;

template<class T_data>
class List
{
private:
    struct Node
    {
        Node* prev;
        T_data value;
        Node* next;
        Node(Node* prev, T_data value, Node* next) :prev(prev), value(value), next(next) {}
    };
    Node* head;
    Node* tail;
    int size;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
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
    
    List& operator = (const List& other)
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
    void AddToHead(T_data value)
    {
        Node* newNode = new Node(nullptr, value, head);

        if (IsEmpty())
        {
            head = tail = newNode;
        }
        head->prev = newNode;
        head = newNode;
        size++;
    }
    void PrintList()const
    {
        for (Node* current = head; current != nullptr; current = current->next)
        {
            cout << current->value << endl;
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
    void AddToTail(T_data value)
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
        size++;
    }
    T_data& GetElement(int pos)
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
    T_data& operator[](int pos)
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
        if (IsEmpty())return;
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
        size--;
    }
    void DeleteFromHead()
    {
        if (IsEmpty()) return;

        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node* nodeToDelete = head->next;
            delete head;
            head = nodeToDelete;
        }
        size--;
    }
    int GetLength()
    {
        return size;
    }
    void DeleteByPosition(int pos)
    {
        if (pos < 1 || pos > size)return;
        else if (pos == 1)
        {
            DeleteFromHead();
        }
        else if (pos == size)
        {
            DeleteFromTail();
        }
        else
        {
            Node* current = nullptr;

            if (pos <= size / 2)
            {
                current = head;
                for (int i = 1; i < pos; i++)
                {
                    current = current->next;
                }
            }
            else
            {
                current = tail;
                for (int i = size; i > pos; i--)
                {
                    current = current->prev;
                }
            }
            current->next->prev = current->prev;
            current->prev->next = current->next;
            delete current;
            size--;
        }
    }
    
    int GetIndex(T_data value)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (value == current->value) return i;
            current = current->next;
            i++;
        }
        return 0;
    }
};

class Animal
{
protected:
    float weight;
    int speed;
    string type;
    string name;
    string place;
    int age;
public:
    Animal() :weight(0), speed(0), type(""), name(""), place(""), age(0) {}
    Animal(float w, int s, string t, string n, string p, int a) :type(t), name(n), place(p)
    {
        this->weight = w > 0 ? w : 0;
        this->speed = s > 0 ? s : 0;
        this->age = a > 0 ? a : 0;
    }

    float GetWeight()const { return weight; }
    int GetSpeed()const { return speed; }
    string GetType()const { return type; }
    string GetName()const { return name; }
    string GetPlace()const { return place; }
    int GetAge()const { return age; }

    void Print()const
    {
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Type: " << type << endl;
        cout << "Name: " << name << endl;
        cout << "Place: " << place << endl;
        cout << "Age: " << age << endl;
    }

    virtual void Move()const
    {
        cout << "I am moving..." << endl;
    }
    virtual void MakeSound()const = 0;
};

class Plants 
{
protected:
    string name;
public:
    Plants() :name("") {}
    Plants(string name) :name(name) {}
    void Print() 
    {
        cout << name << endl;
    }
    string getName()const 
    {
        return name;
    }
};

class Grass : public Plants 
{
    List<Grass> grass;
    int size;
public:
    Grass() :size(0) {}
    Grass(int size, string name) :size(size), Plants(name) {}
    void PrintFamily() 
    {
        grass.PrintList();
    }
    void MakeFamily(int num)
    {
        for (size_t i = 0; i < num; i++)
        {
            int random = (rand() % 8) + 1;
            grass.AddToTail(Grass(random, "Grass"));
        }
    }
    void Delete() 
    {
        if (grass.GetLength() != 0) grass.DeleteFromHead();
    }
    int getSize()const 
    {
        return size;
    }
    int getLen() 
    {
        return grass.GetLength();
    }
    void AmountOfFamilyMembers()
    {
        cout << "Amount of grass: " << grass.GetLength() << endl << endl << endl;
    }
};

class Rabbit : public Animal
{
    List<Rabbit> family;
    int eatenGrass;
public:
    Rabbit() :eatenGrass(0), Animal() {}
    Rabbit(float w, int s, string t, string n, string p, int a) :eatenGrass(0), Animal(w, s, t, n, p, a) {}

    int GetGrass()const { return eatenGrass; }
    int GetLength() { return family.GetLength(); }

    void MakeFamily(int num)
    {
        for (size_t i = 0; i < num; i++)
        {
            int random_age = (rand() % 5) + 1;
            family.AddToTail(Rabbit(2, 20, "Animal", "Rabbit", "Forest", random_age));
        }
    }

    void Eat(Rabbit& rabbit, Grass& grass)
    {
        if (rabbit.GetLength() > grass.getLen())
        {
            grass.Delete();
            eatenGrass++;
            cout << "Rabbit eats grass" << endl;
        }
        else
        {
            cout << "Rabbit doesn't eat grass" << endl;
        }
    }

    void Hunted()
    {
        family.DeleteFromHead();
    }

    void Die(Rabbit& rabbit)
    {
        if (rabbit.GetAge() >= 5)
        {
            cout << "The rabbit has been dead" << endl;
            family.DeleteByPosition(family.GetIndex(rabbit));
        }
        else
        {
            cout << "The rabbit is alive" << endl;
        }
    }

    void PrintFamily()
    {
        family.PrintList();
    }

    void MakeSound()const
    {
        cout << "Pi-pi-pi-shu-shu" << endl;
    }

    void AmountOfFamilyMembers()
    {
        cout << "Amount of rabbits: " << family.GetLength() << endl << endl << endl;
    }
};

class Fox : public Animal
{
    List<Fox> family;
    int eatenRabbits;
public:
    Fox() :eatenRabbits(0), Animal() {}
    Fox(float w, int s, string t, string n, string p, int a) :eatenRabbits(0), Animal(w, s, t, n, p, a) {}

    int GetRabbits()const { return eatenRabbits; }  
    void AddRabbits() { eatenRabbits += 1; }
    int GetLength() { return family.GetLength(); }
    int GetIndex(Fox& fox) 
    { 
        return family.GetIndex(fox); 
    }


    void MakeFamily(int num)
    {
        for (size_t i = 0; i < num; i++)
        {
            int random_age = (rand() % 8) + 1;
            family.AddToTail(Fox(5, 13, "Animal", "Fox", "Forest", random_age));
        }
    }

    void Die(Fox& fox)
    {
        if (fox.GetAge() >= 8)
        {
            cout << "The fox has been dead" << endl;
            family.DeleteByPosition(family.GetIndex(fox));
        }
        else
        {
            cout << "The fox is alive" << endl;
        }
    }

    void AmountOfFamilyMembers()
    {
        cout << "Amount of foxes: " << family.GetLength() << endl << endl << endl;
    }

    void Hunt(Fox& fox, Rabbit& rabbit)
    {
        if (fox.GetLength() > rabbit.GetLength())
        {
            if (rand() % 10 + 1 > 5)
            {
                rabbit.Hunted();
                fox.AddRabbits();
                cout << "The fox caught the rabbit. Rabbit was hunted" << endl;
            }
            else
            {
                cout << "The fox didn't catch the rabbit" << endl;
            }
        }
        else
        {
            cout << "Too many rabbits" << endl;
        }
    }

    void PrintFamily()
    {
        family.PrintList();
    }

    void MakeSound()const
    {
        cout << "Arrr-rrr-rrr" << endl;
    }
};

bool operator ==(const Fox& f1, const Fox& f2) 
{
    return f1.GetAge() == f2.GetAge() and f1.GetRabbits() == f2.GetRabbits() and f1.GetName() == f2.GetName() and f1.GetPlace() == f2.GetPlace() and f1.GetSpeed() == f2.GetSpeed() and f1.GetType() == f2.GetType() and f1.GetWeight() == f2.GetWeight();
}
bool operator ==(const Rabbit& f1, const Rabbit& f2) 
{
    return f1.GetAge() == f2.GetAge() and f1.GetGrass() == f2.GetGrass() and f1.GetName() == f2.GetName() and f1.GetPlace() == f2.GetPlace() and f1.GetSpeed() == f2.GetSpeed() and f1.GetType() == f2.GetType() and f1.GetWeight() == f2.GetWeight();
}

ostream& operator<<(ostream& out, const Fox& fox)
{
    out << "Weight: " << fox.GetWeight() << " kg" << endl;
    out << "Speed: " << fox.GetSpeed() << " km/h" << endl;
    out << "Type: " << fox.GetType() << endl;
    out << "Name: " << fox.GetName() << endl;
    out << "Place: " << fox.GetPlace() << endl;
    out << "Age: " << fox.GetAge() << endl;
    out << "Eaten rabbits: " << fox.GetRabbits() << endl;
    return out;
}
ostream& operator<<(ostream& out, const Rabbit& rabbit)
{
    out << "Weight: " << rabbit.GetWeight() << " kg" << endl;
    out << "Speed: " << rabbit.GetSpeed() << " km/h" << endl;
    out << "Type: " << rabbit.GetType() << endl;
    out << "Name: " << rabbit.GetName() << endl;
    out << "Place: " << rabbit.GetPlace() << endl;
    out << "Age: " << rabbit.GetAge() << endl;
    out << "Eaten grass: " << rabbit.GetGrass() << endl;
    return out;
}
ostream& operator<<(ostream& out, const Grass& grass) 
{
    out << "Name: " << grass.getName() << ", Size: " << grass.getSize();
    return out;
}

int main()
{
    srand(time(0));

    int max_num = (rand() % 5) + 1;
    int tmp = max_num;
    Fox foxes;
    foxes.MakeFamily(max_num);
    foxes.PrintFamily();
    for (size_t i = 0; i < max_num; i++)
    {
        foxes.Die(foxes);
    }
    foxes.AmountOfFamilyMembers();
    
    max_num = (rand() % 7) + 1;

    Rabbit rabbits;
    rabbits.MakeFamily(max_num);
    rabbits.PrintFamily();
    for (size_t i = 0; i < max_num; i++)
    {
        rabbits.Die(rabbits);
    }
    rabbits.AmountOfFamilyMembers();

    max_num = (rand() % 10) + 1;

    Grass grass;
    grass.MakeFamily(max_num);
    grass.PrintFamily();
    grass.AmountOfFamilyMembers();

    cout << "================================================" << endl;
    for (size_t i = 0; i < max_num; i++)
    {
        if (grass.getLen() != 0)
        {
            rabbits.Eat(rabbits, grass);
            grass.AmountOfFamilyMembers();
        }
        else
        {
            cout << "All rabbits are eaten" << endl;
            break;
        }
    }
    for (size_t i = 0; i < tmp; i++)
    {
        if (rabbits.GetLength() != 0)
        {
            foxes.Hunt(foxes, rabbits);
            rabbits.AmountOfFamilyMembers();
        }
        else
        {
            cout << "All rabbits are eaten" << endl;
            break;
        }
    }
    
}