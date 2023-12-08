#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int>& v)
{
    for (int element : v)
    {
        cout << element << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr; //default ctor
    cout << "Size: " << arr.size() << endl;
    cout << "Capacity: " << arr.capacity() << endl;

    vector<int> v = { 1,2,3,4,5,6,7,8,9 };
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    vector<int> v2 = { 10,11,12,13,14 };
    cout << "Size: " << v2.size() << endl;
    cout << "Capacity: " << v2.capacity() << endl;

    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    Print(v);

    //delete elem
    v.erase(v.begin());
    Print(v);
    v.erase(v.begin() + 2);
    Print(v);

    v.erase(v.end() - 1);
    Print(v);
    v.erase(v.begin() + 2, v.end() - 2);
    Print(v);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    //add elem
    v.insert(v.end(), { 77,88,99,101 });
    Print(v);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    v.insert(v.begin(), 5, 8);
    Print(v);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    v.insert(v.begin(), 100);
    Print(v);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    v.insert(v.end(), v2.begin() + 1, v2.end() - 2);
    Print(v);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v[0] = 999;
    Print(v);

    v.push_back(777);
    v.push_back(777);
    v.push_back(777);
    v.push_back(777);
    Print(v);

    v.pop_back();
    v.pop_back();
    v.pop_back();
    Print(v);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    /*cout << "Before swap: " << endl;
    Print(v);
    Print(v2);

    v.swap(v2);

    cout << "After swap: " << endl;
    Print(v);
    Print(v2);*/

    cout << "Frist elem: " << v.front() << endl;

    v.resize(20);
    Print(v);
    v.push_back(777);
    v.push_back(777);
    v.push_back(777);
    v.push_back(777);
    Print(v);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.resize(4);
    Print(v);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    v.shrink_to_fit();
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    v.push_back(777);
    v.push_back(777);
    v.push_back(777);
    v.push_back(777);
    v.push_back(7);
    v.push_back(777);
    v.push_back(777);
    Print(v);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == 7)
        {
            v.insert(v.begin() + i + 1, 10);
            break;
        }
    }
    Print(v);
}