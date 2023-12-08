#include <iostream>
using namespace std;

class Array
{
    int size;
    int* arr;
public:
    explicit Array(int size = 10)
    {
        this->size = size;
        arr = new int[size];
    }
    Array(const Array& other)
    {
        this->size = other.size;
        this->arr = new int[other.size];
        for (size_t i = 0; i < other.size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    ~Array()
    {
        delete[] arr;
    }
    int getSize()const
    {
        return size;
    }
    int getValue(int index)const
    {
        return arr[index];
    }
    void setValue(int index, int value)
    {
        arr[index] = value;
    }

    void Display()const
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void Fill()
    {
        for (size_t i = 0; i < size; i++)
        {
            setValue(i, size - i - 1);
        }
    }
    void AddElement(int value)
    {
        int* tmp = new int[size + 1];
        for (size_t i = 0; i < size; i++)
        {
            tmp[i] = arr[i];
        }
        tmp[size] = value;

        delete[] arr;
        arr = tmp;
        size++;
    }
    void deleteElement(int index)
    {
        int* tmp = new int[size - 1];
        int j = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (i != index)
            {
                tmp[j] = arr[i];
                j++;
            }
        }

        delete[] arr;
        arr = tmp;
        size--;
    }
    void sortArr()
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }
    void findInArr()
    {
        int minNum = arr[0];
        int maxNum = arr[0];
        double sum = arr[0];

        for (size_t i = 1; i < size; i++)
        {
            if (arr[i] < minNum)
            {
                minNum = arr[i];
            }

            if (arr[i] > maxNum)
            {
                maxNum = arr[i];
            }

            sum += arr[i];
        }

        double average = sum / size;

        cout << "Minimum number: " << minNum << endl;
        cout << "Maximum number: " << maxNum << endl;
        cout << "Average: " << average << endl;
    }

    void operator()(int number)
    {
        for (size_t i = 0; i < size; i++)
        {
            arr[i] += number;
        }
    }
    void operator[](int index)
    {
        if (index < 0 || index >= size) cout << "Error" << endl;
        cout << arr[index] << endl;
    }
};

int main()
{
    int size = 4;
    Array arr(size);

    arr.Fill();
    arr.Display();
    cout << endl;

    arr.AddElement(5);
    arr.Display();
    cout << endl;
    arr.AddElement(3);
    arr.Display();
    cout << endl;

    arr.deleteElement(5);
    arr.Display();
    cout << endl;
    
    arr(2);
    arr.Display();
    cout << endl;
    
    arr[2];
    arr.Display();
    cout << endl;

    arr.sortArr();
    arr.Display();
    cout << endl;

    arr.findInArr();
    cout << endl;
}