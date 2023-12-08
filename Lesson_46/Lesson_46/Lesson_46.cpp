#include <iostream>
using namespace std;

template<class T>
struct Node
{
    T value;
    Node* next;
    Node(T value, Node* next) :value(value), next(next) {}
};

template<class T>
class List
{
private:
    Node<T>* head;
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(T value)
    {
        Node<T>* newNode = new Node<T>(value, head);
        //newNode->value = value;
        //newNode->next = head;

        head = newNode;
    }
    void PrintList()const
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
    ~List()
    {
        Node<T>* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void AddToTail(T value)
    {
        Node<T>* newNode = new Node<T>(value, nullptr);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T>* current = head;

            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    T GetElement(T pos)
    {
        Node<T>* current = head;

        //index
        /*for (size_t i = 0; i < pos; i++)
        {
            current = current->next;
        }
        return current->value;*/

        //numeration
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
        if (head == nullptr) return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node<T>* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }
    void DeleteFromHead()
    {
        Node<T>* current = head;
        head = head->next;
        delete current;
    }
    void DeleteAll()
    {
        Node<T>* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
};

int main()
{
    List<int> l;
    for (size_t i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }
    l.PrintList();

    l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    l.PrintList();

    cout << "Elem by pos 3: " << l.GetElement(3) << endl;

    l.DeleteFromTail();
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.PrintList();

    l.DeleteFromHead();
    l.PrintList();

    l.DeleteAll();
    l.AddToTail(300);
    l.PrintList();
}