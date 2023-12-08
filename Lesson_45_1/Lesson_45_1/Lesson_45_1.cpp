#include <iostream>
using namespace std;

template<typename T>
class Queue
{
public:
    struct Element
    {
        T value;
        int priority;
    };
private:
    Element* arr;
    int size;
public:
    Queue() :arr(nullptr), size(0) {}
    ~Queue()
    {
        if (arr != nullptr) delete[] arr;
    }
    void Enqueue(T value, int priority)
    {
        int index = 0;
        while (index < size && arr[index].priority < priority)
        {
            index++;
        }
        size++;
        Element* temp = new Element[size];
        for (size_t i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        temp[index] = Element{ value, priority };
        for (size_t i = index; i < size - 1; i++)
        {
            temp[i + 1] = arr[i];
        }
        if (arr != nullptr) delete[] arr;
        arr = temp;
    }
    bool IsEmpty()
    {
        return size == 0;
    }
    Element Dequeue()
    {
        if (!IsEmpty())
        {
            Element first = arr[0];
            for (size_t i = 0; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            return first;
        }
        return Element();
    }
    void Print()const
    {
        cout << "- - - - - - - - Queue - - - - - - - -" << endl;
        for (size_t i = 0; i < size; i++)
        {
            cout << "Value: " << arr[i].value << ". Priority: " << arr[i].priority << " - ";
            switch (arr[i].priority)
            {
            case 1:
                cout << "director." << endl;
                break;
            case 2:
                cout << "manager." << endl;
                break;
            case 3:
                cout << "admin." << endl;
                break;
            case 4:
                cout << "guest." << endl;
                break;
            }
        }
        cout << endl;
        cout << "- - - - - - - - - - - - - - - - - - -" << endl;
    }
};

int main()
{
    Queue<string> q;
    int prior, num;
    string file;
    cout << "Enter the number of files: "; cin >> num;
    for (size_t i = 0; i < num; i++)
    {
        cout << "Enter name of the file: "; cin >> file;
        cout << "Enter your job title (1 - guest, 2 - admin, 3 - manager, 4 - director): "; cin >> prior;
        switch (prior)
        {
        case 1:
            q.Enqueue(file, 4);
            break;
        case 2:
            q.Enqueue(file, 3);
            break;
        case 3:
            q.Enqueue(file, 2);
            break;
        case 4:
            q.Enqueue(file, 1);
            break;
        default:
            cout << "Error!" << endl;
            break;
        }
        system("cls");
    }
    cout << endl;
    q.Print();
    
    cout << endl;
    while (!q.IsEmpty())
    {
        cout << "Element: " << q.Dequeue().value << endl;
    }
}