#include <iostream>
#include <conio.h>
using namespace std;

class Queue
{
    int* arr;
    int size;
    int top;
public:
    Queue() = default;
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        top = 0;
    }
    ~Queue()
    {
        delete[] arr;
    }

    bool IsEmpty()const
    {
        return top == 0;
    }
    bool IsFull()const
    {
        return top == size;
    }
    void Enqueue(int elem)
    {
        if (!IsFull())
        {
            arr[top++] = elem;
        }
    }
    int Dequeue()
    {
        if (!IsEmpty())
        {
            int first = arr[0];
            for (size_t i = 0; i < top; i++)
            {
                arr[i] = arr[i + 1];
            }
            top--;
            return first;
        }
    }
    int GetCount()const
    {
        return top;
    }
    void Clear()
    {
        top = 0;
    }
    void Print()const
    {
        for (size_t i = 0; i < top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    srand(time(0));
    Queue q(25);
    for (size_t i = 0; i < 10; i++)
    {
        q.Enqueue(rand() % 30);
    }
    q.Print();
    cout << "Count of elements: " << q.GetCount() << endl;
    while (!q.IsEmpty())
    {
        cout << "Elemnt: " << q.Dequeue() << endl;
    }
}