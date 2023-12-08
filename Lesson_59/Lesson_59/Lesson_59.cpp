#include <iostream>
#include <memory>
using namespace std;

template<typename T>
class SmartPointer
{
    T* ptr;
public:
	SmartPointer() :ptr(nullptr) {}
	SmartPointer(T* ptr) :ptr(ptr) {}
	~SmartPointer()
	{
		if (ptr != nullptr)
		{
			cout << "Destructor for: " << *ptr << endl;
			delete ptr;
			ptr = nullptr;
		}
	}
	T* Get()const
	{
		return ptr;
	}
	T operator *()
	{
		return *ptr;
	}
};

void FuncWithException()
{
	int i = rand() % 2;
	if (i == 0)
	{
		throw exception();
	}
	cout << "Good" << endl;
}
void SetNumber(int& num)
{
	//int* newNum = new int;
	//cin >> *newNum;

	SmartPointer<int> newNum(new int);
	cin >> *(newNum.Get());

	FuncWithException();

	if (*newNum == 0)
	{
		//delete newNum;
		throw exception();
	}

	num = *newNum;
	//delete newNum;
}

int main()
{
	srand(time(0));
	int num = 0;

	try
	{
		SetNumber(num);
		cout << "Number: " << num << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	cout << "Number: " << num << endl;
}