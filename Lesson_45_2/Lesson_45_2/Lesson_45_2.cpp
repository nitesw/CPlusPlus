#include <iostream>
using namespace std;

template<typename T_arr>
class Stack
{
	enum { EMPTY = -1 };
	int size;
	T_arr* arr;
	int top;
public:
	Stack() = delete;
	Stack(int size) :size(size)
	{
		arr = new T_arr[size];
		top = EMPTY;
	}
	bool IsFull() const
	{
		return top == size - 1;
	}
	bool Push(T_arr elem)
	{
		if (!IsFull())
		{
			arr[++top] = elem;
			return true;
		}
		return false;
	}
	bool IsEmpty() const
	{
		return top == EMPTY;
	}
	T_arr Pop()
	{
		if (!IsEmpty())
		{
			return arr[top--];
		}
	}
	T_arr Peek() const
	{
		if (!IsEmpty())
		{
			return arr[top];
		}
	}
	int GetCount() const
	{
		return top + 1;
	}
	void Clear()
	{
		top = EMPTY;
	}
	~Stack()
	{
		delete[] arr;
	}
};

int main()
{
	Stack<char> st(10);
	st.Push('s');
	st.Push('a');
	st.Push('d');
	st.Push('*');
	st.Push('/');
	cout << "Cout of element in Stack: " << st.GetCount() << endl;
	st.Pop();
	cout << "Cout of element in Stack: " << st.GetCount() << endl;
	cout << st.Peek() << endl << endl;
	while (!st.IsEmpty())
	{
		cout << "Pop element: " << st.Pop() << endl;
	}
	cout << "Cout of element in Stack: " << st.GetCount() << endl;
}
