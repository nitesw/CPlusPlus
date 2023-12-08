#include <iostream>
using namespace std;

//class Stack
//{
//	enum {EMPTY = -1, FULL = 9};
//	int arr[FULL + 1];
//	int topIndex;
//public:
//	Stack()
//	{
//		topIndex = EMPTY;
//	}
//	~Stack() = default;
//	Stack(const Stack& other) = delete;
//
//	bool IsFull()const
//	{
//		return topIndex == FULL;
//	}
//	bool Push(int elem)
//	{
//		if (!IsFull())
//		{
//			arr[++topIndex] = elem;
//			return true;
//		}
//		return false;
//	}
//	bool IsEmpty()const
//	{
//		return topIndex == EMPTY;
//	}
//	int Pop()
//	{
//		if (!IsEmpty())
//		{
//			return arr[topIndex--];
//		}
//	}
//	int GetCount()const
//	{
//		return topIndex + 1;
//	}
//	void Clear()
//	{
//		topIndex = EMPTY;
//	}
//	int Peek()const
//	{
//		if (!IsEmpty())
//		{
//			return arr[topIndex];
//		}
//	}
//	void Print()
//	{
//		for (size_t i = 0; i <= topIndex; i++)
//		{
//			cout << arr[i] << " ";
//		}
//	}
//};

template<typename T_arr>
class Stack
{
	enum {EMPTY = -1};
	int size;
	T_arr* arr;
	int top;
public:
	Stack() = delete;
	Stack(int size) :size(size)
	{
		arr = new int[size];
		top = EMPTY;
	}
	bool IsFull()const
	{
		return top == size - 1;
	}
	bool Push(int elem)
	{
		if (!IsFull())
		{
			arr[++top] = elem;
			return true;
		}
		return false;
	}
	bool IsEmpty()const
	{
		return top == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty())
		{
			return arr[top--];
		}
	}
	int Peek()const
	{
		if (!IsEmpty())
		{
			return arr[top];
		}
	}
	int GetCount()const
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

bool IsValidCode(string code) 
{
	Stack<int> stack(15);
	for (char s : code)
	{
		if (s == '{') stack.Push(1);
		if (s == '}') 
		{
			if (stack.IsEmpty()) return false;
			if (stack.Peek() == 1)stack.Pop();

		}
		if (s == '(') stack.Push(2);
		if (s == ')') 
		{
			if (stack.IsEmpty()) return false;
			if (stack.Peek() == 2)stack.Pop();


		}
		if (s == '[') stack.Push(3);
		if (s == ']') 
		{
			if (stack.IsEmpty()) return false;
			if (stack.Peek() == 3)stack.Pop();
		}
	}
	return stack.IsEmpty();
}

int main()
{
	/*Stack st;
	st.Push(56);
	cout << "Cout of element in Stack: " << st.GetCount() << endl;
	st.Push(33);
	st.Push(12);
	st.Push(4);
	st.Push(8);
	st.Push(24);
	cout << "Cout of element in Stack: " << st.GetCount() << endl;
	st.Print();
	cout << endl;
	while (!st.IsEmpty())
	{
		cout << "Pop element: " << st.Pop() << endl;
	}
	cout << "Cout of element in Stack: " << st.GetCount() << endl;*/

	string validCode = "({x-y-z} * [x + 2y] - (z + 4x))";
	string inValidCode = "([x-y-z} * [x + 2y) - {z + 4x)]";

	if (IsValidCode(validCode))
	{
		cout << "Code is valid" << endl;
	}
	else
	{
		cout << "Code is not valid" << endl;
	}
	if (IsValidCode(inValidCode))
	{
		cout << "Code is valid" << endl;
	}
	else
	{
		cout << "Code is not valid" << endl;
	}

	Stack<int> st(15);
	cout << "Cout of element in Stack: " << st.GetCount() << endl;
	st.Push(33);
	st.Push(12);
	st.Push(4);
	st.Push(8);
	st.Push(24);
	cout << "Cout of element in Stack: " << st.GetCount() << endl;
	cout << endl;
	while (!st.IsEmpty())
	{
		cout << "Pop element: " << st.Pop() << endl;
	}
	cout << "Cout of element in Stack: " << st.GetCount() << endl;
}