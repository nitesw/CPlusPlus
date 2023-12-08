#include <iostream>
using namespace std;

template<class T_arr>
class Array
{
    T_arr* arr;
    int size;
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }
    explicit Array(int size)
    {
        this->size = size;
        arr = new T_arr[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    Array(const initializer_list<T_arr>& list)
    {
        this->size = list.size();
        arr = new T_arr[size];

        int i = 0;
        for (T_arr element : list)
        {
            arr[i++] = element;
        }
    }
    void Print() const
    {
        cout << "Array size: " << size << endl;
        for (size_t i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void Fill(const initializer_list<T_arr>& list)
    {
        if (arr != nullptr)
            delete[] arr;
        this->size = list.size();
        arr = new T_arr[size];

        int i = 0;
        for (T_arr element : list)
        {
            arr[i++] = element;
        }
    }
    ~Array()
    {
        delete[] arr;
    }
    T_arr GetMax();
    T_arr GetMin();
    void SortArr();
    T_arr BinarySearch(int target);
    void Replace(int index, int num);
};

int main()
{
    Array<float> arr;
    arr.Print();

    Array<char> arr2(2);
    arr2.Print();

    Array<int> arr3({ 12, 24, 5, 6, 1, 4, 63, 34, 7, 3, 45, 7 });
    arr3.Print();
    arr3.Fill({ 99, 44, 22, 11, 33 });
    arr3.Print();

    cout << "\nMax num: " << arr3.GetMax() << endl;
    cout << "Min num: " << arr3.GetMin() << endl;
    arr3.SortArr();
    cout << "Sorted arr: " << endl;
    arr3.Print();

    cout << "Binary search: " << arr3.BinarySearch(33) << endl;

    arr3.Replace(0, 5);
    arr3.Print();
}

template<class T_arr>
T_arr Array<T_arr>::GetMax()
{
    T_arr max = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template<class T_arr>
T_arr Array<T_arr>::GetMin()
{
    T_arr min = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

template<class T_arr>
void Array<T_arr>::SortArr()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T_arr temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<class T_arr>
T_arr Array<T_arr>::BinarySearch(int target) 
{
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

template<class T_arr>
void Array<T_arr>::Replace(int index, int num)
{
    arr[index] = num;
}