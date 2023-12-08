#include <iostream>
using namespace std;
class Point;

template <class T>
struct Node 
{
	T value;
	Node* next;
	Node(T value, Node* next) :value(value), next(next) {}
};
template <class T>
class List
{
	Node<T>* head;
public:
	List()
	{
		head = nullptr;
	}
	void AddToHead(T val) 
	{
		Node<T>* newNode = new Node<T>(val, head);
		head = newNode;
	}
	void PrintList()const 
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			current->value.Print();
			current = current->next;
		}
		cout << endl;
	}
	~List()
	{
		Node<T>* current = nullptr;
		while (current != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
	void AddToTail(T val) 
	{
		Node<T>* newNode = new Node<T>(val, nullptr);
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
	T GetElement(int pos) 
	{
		Node<T>* current = head;
		int i = 0;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
	}
	void DeleteFromTail() 
	{
		if (head == nullptr)return;
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
		if (head == nullptr)return;
		else 
		{
			Node<T>* current = head;
			head = current->next;
			delete current;
		}
	}
	void DeleteAll() 
	{
		if (head == nullptr) return;
		else 
		{
			Node<T>* current = head;
			while (current != nullptr)
			{
				current = current->next;
				this->DeleteFromHead();
			}
			delete head;
			head = nullptr;
		}
	}
};
class Point
{
	int x;
	int y;
public:
	Point() :x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	void Print()
	{
		cout << "X: " << x << " Y: " << y << endl;
	}
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
};
class Vector 
{
private:
	List<Point> points;
public:
	Vector() :points() {}

	void AddPoint(int x, int y) 
	{
		points.AddToTail(Point(x, y));
	}

	void DeletePointFromHead()
	{
		points.DeleteFromHead();
	}
	void DeletePointFromTail() 
	{
		points.DeleteFromTail();
	}

	void PrintVector()
	{
		points.PrintList();
	}
};
int main()
{
	Vector vect;
	for (size_t i = 0; i < 5; i++)
	{
		vect.AddPoint(i + 3 - 1, i + 2 - 1);
	}

	vect.PrintVector();

	vect.DeletePointFromHead();
	vect.PrintVector();

	vect.DeletePointFromTail();
	vect.PrintVector();
}