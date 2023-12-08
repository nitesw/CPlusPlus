#include <iostream>
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
        Node* newNode = new Node(nullptr, value, head);//address

        if (IsEmpty())
        {
            head = tail = newNode;
        }
        head->prev = newNode;
        head = newNode;;//address
        size++;
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
    T_data GetElement(int pos)
    {
        if (IsEmpty())
            throw invalid_argument("List is empty");
        if (pos < 1 || pos > size)
            throw out_of_range("Position is less than 0 or out of range");

        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    T_data operator[](int pos)
    {
        if (IsEmpty())
            throw invalid_argument("List is empty");
        if (pos < 1 || pos > size)
            throw out_of_range("Position is less than 0 or out of range");

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
        if (IsEmpty())
            throw invalid_argument("List is empty");

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
        if (IsEmpty()) 
            throw invalid_argument("List is empty");

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
        if (IsEmpty())
            throw invalid_argument("List is empty");
        if (pos < 1 || pos > size)
            throw out_of_range("Position is less than 0 or out of range");

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
            Node* current = nullptr;// = head;

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
};

int main()
{
    try
    {
        List<int> list;

        //list.DeleteFromHead();
        //list.DeleteFromTail();
        //list.DeleteByPosition(1);
        //list[1];

        list.AddToHead(1);
        list.AddToHead(2);
        list.AddToHead(3);
        
        //list[5];
        list.DeleteByPosition(5);
    }
    catch (out_of_range ex)
    {
        cout << ex.what() << endl;
    }
    catch (invalid_argument ex)
    {
        cout << ex.what() << endl;
    }
    catch (logic_error ex)
    {
        cout << ex.what() << endl;
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
    }
}
