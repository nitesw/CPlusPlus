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
    //int top;
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
            cout << "Value: " << arr[i].value << ". Priority: " << arr[i].priority << endl;
        }
        cout << endl;
        cout << "- - - - - - - - - - - - - - - - - - -" << endl;
    }
};

int main()
{
    Queue<string> q;
    q.Enqueue("A", 1);
    q.Enqueue("L", 12);
    q.Enqueue("G", 5);
    q.Enqueue("B", 2);
    q.Enqueue("K", 8);
    q.Enqueue("C", 3);
    q.Print();

    q.Enqueue("D", 4);
    cout << "---------------------------------" << endl;
    q.Print();

    while (!q.IsEmpty())
    {
        cout << "Element: " << q.Dequeue().value << endl;
    }
}