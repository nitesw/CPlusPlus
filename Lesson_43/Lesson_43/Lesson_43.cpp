#include <iostream>
using namespace std;

/*
int GetMax(int* arr, int size)
{
    int max = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
long GetMax(long* arr, int size)
{
    int max = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
short GetMax(short* arr, int size)
{
    int max = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
*/

template<typename T_arr>
T_arr GetMax(T_arr* arr, int size)
{
    T_arr max = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

template<typename T_coord>
class Point
{
    T_coord x;
    T_coord y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(T_coord value)
    {
        x = y = value;
    }
    Point(T_coord x, T_coord y)
    {
        this->x = x;
        this->y = y;
    }
    void setCoords(T_coord x, T_coord y)
    {
        this->x = x;
        this->y = y;
    }
    void Print()const
    {
        cout << "X : " << x << " Y: " << y << endl;
    }
};
template<typename T_X, typename T_Y>
class NewPoint
{
    T_X x;
    T_Y y;
public:
    NewPoint()
    {
        x = y = 0;
    }
    NewPoint(T_X value)
    {
        x = y = value;
    }
    NewPoint(T_X x, T_Y y)
    {
        this->x = x;
        this->y = y;
    }
    void setCoords(T_X x, T_Y y)
    {
        this->x = x;
        this->y = y;
    }
    void Print()const
    {
        cout << "X : " << x << " Y: " << y << endl;
    }
};

template<class T_coll, class T_val>
class MyClass
{
    int size;
    T_coll* collection;
    T_val point;
public:
    MyClass()
    {
        size = 0;
        collection = nullptr;
        //point = 0;
    }
    MyClass(T_coll* collection, T_val value) :collection(collection), point(value) {}

    void SetCollection(T_coll* coll)
    {
        collection = coll;
    }
    void SetPoint(T_val value);
    void Print();
    

    ~MyClass()
    {
        if (collection != nullptr) delete[] collection;
    }
};

class Array
{
    int* arr;
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
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    Array(const initializer_list<int>& list)
    {
        this->size = list.size();
        arr = new int[size];
        
        int i = 0;
        for (int element : list)
        {
            arr[i++] = element;
        }
    }
    void Print()const
    {
        cout << "Array size: " << size << endl;
        for (size_t i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void Fill(const initializer_list<int>& list)
    {
        if (arr != nullptr) delete[] arr;
        this->size = list.size();
        arr = new int[size];

        int i = 0;
        for (int element : list)
        {
            arr[i++] = element;
        }
    }
};

int main()
{
    /*const int size = 10;
    int number1[size] = { 1,6,4,3,7,9,11,6,8,0 };
    cout << "Max num: " << GetMax(number1, size) << endl;
    long number2[size] = { 1,6,4,3,7,9,11,6,8,0 };
    cout << "Max num: " << GetMax(number2, size) << endl;
    short number3[size] = { 1,6,4,3,7,9,11,6,8,0 };
    cout << "Max num: " << GetMax(number3, size) << endl;
    float number4[size] = { 1,6,4,3,7.2,9.8,11.6,6,8,0 };
    cout << "Max num: " << GetMax(number4, size) << endl;
    double number5[size] = { 1,6,4.5,3,7,9,11.2,6,8,0 };
    cout << "Max num: " << GetMax(number5, size) << endl;*/

    /*long* long_arr = new long[4];
    for (size_t i = 0; i < 4; i++)
    {
        long_arr[i] = i + 1;
        cout << long_arr[i] << " ";
    }
    cout << endl;
    
    char* char_arr = new char[4];
    for (size_t i = 0; i < 4; i++)
    {
        char_arr[i] = 'a' + i;
        cout << char_arr[i] << " ";
    }
    cout << endl;

    MyClass<long, string> cl1(long_arr, "Class with long arr");
    MyClass<char, string> cl2(char_arr, "Class with char arr");

    cl1.Print();
    cl2.Print();*/

    /*delete[] long_arr;
    delete[] char_arr;*/

    /*Point<int> p1(10, 15);
    p1.Print();
    p1.setCoords(33, 44);
    p1.Print();

    Point<float> p2(0.325, 0.145);
    p2.Print();

    NewPoint<int, float> p3(10, 0.145);
    p3.Print();
    p3.setCoords(33, 44);
    p3.Print();*/

    int static_arr[5] = { 1,2,3,4,5 };
    int* dynam_arr = new int[5]{ 1,2,3,4,5 };

    Array arr;
    arr.Print();

    Array arr2(2);
    arr2.Print();

    Array arr3({ 12,24,5,6,1,4,63,34,7,3,45,7 });
    arr3.Print();
    arr3.Fill({ 99,44,22,11,33 });
    arr3.Print();

    delete[] dynam_arr;
}

template<class T_coll, class T_val>
void MyClass<T_coll, T_val>::Print()
{
    cout << "Collection " << collection << endl;
    cout << "Value " << point << endl;
}
template<class T_coll, class T_val>
void MyClass<T_coll, T_val>::SetPoint(T_val value)
{
    point = value;
}