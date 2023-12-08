#include <iostream>
#include <exception>
using namespace std;

class List
{
private:
    int size;
public:
    List() :size(0) {}
    List(int s) :size(s) {}

    int GetFromPosition(int pos)
    {
        if (size == 0) return 1;
        if (pos < 1 || pos > size) return 2;

        return rand() % 10;
    }
};

float Divide(float a, float b)
{
    float res = 0;
    //exception ex("You can't divide by 0. You need to study math");
    if (b == 0)
    {
        throw exception("You can't divide by 0. You need to study math");
        //cout << "You can't divide by 0. You need to study math" << endl;
    }
    if (b == 1)
    {
        throw 404;
    }
    if (b == 5)
    {
        throw "You can't divide by 0. You need to study math";
    }
    if (b == 10)
    {
        throw 'A';
    }
    res = a / b;
    cout << "Result: " << res << endl;
    return res;
}

class PasswordInvalidException : public exception
{
public:
    PasswordInvalidException(const char* message) :exception(message) {}
};
class PasswordIsSmallException : public exception
{
    int length;
public:
    PasswordIsSmallException(const char* message, int length) :exception(message), length(length) {}
    void Message()const
    {
        cout << what() << endl;
        cout << "Actual length: " << length << endl;
    }
};
void Validation(const char* login, const char* password)
{
    if (strlen(password) < 6)
        throw PasswordIsSmallException("Password is too small", strlen(password));
    if (!isalpha(password[0]) || !islower(password[0]))
        throw PasswordInvalidException("Password is invalid");
    if (!isalpha(login[0]) || !isupper(login[0]))
        throw exception("Login is invalid");

    cout << "Loading..." << endl;
}

class MyArr
{
private:
    int* arr;
    int size;
public:
    MyArr(int size = 10) :size(size)
    {
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = rand() % 20;
        }
    }
    ~MyArr()
    {
        if (arr != nullptr) delete[] arr;
    }
    int operator[](int index)
    {
        if (index < 0 || index >= size)
            throw out_of_range("Index is less than 0 or more than size");
        else
            return arr[index];
    }
    void CheckLength(int len)
    {
        if (len < 0)
            throw length_error("Some error with length...");

        cout << "Length is valid" << endl;
    }

    void SetSize(int newSize)
    {
        if (newSize <= 0)
            throw invalid_argument("New size is less than 0");
        else
        {
            int* temp = new int[newSize];
            for (size_t i = 0; i < size && i < newSize; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            size = newSize;
        }
    }

    void Print()const
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Stack
{
    enum { EMPTY = -1 };
    int size;
    int* arr;
    int top;
public:
    Stack() = delete;
    Stack(int size) :size(size)
    {
        if (size <= 0)
        {
            throw invalid_argument("Size is less than 0");
        }
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
        throw out_of_range("Index is more than size (Push)");
    }
    bool IsEmpty()const
    {
        return top == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
            return arr[top--];
        throw out_of_range("Index is less than 0");
    }
    int Peek()const
    {
        if (!IsEmpty())
            return arr[top];
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
        delete[]arr;
    }
    void Print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    /*float a, b;
    cout << "Enter a and b: "; cin >> a >> b;

    try
    {
        float res = Divide(a, b);
        cout << "Result in main: " << res << endl;
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
    catch (int ex)
    {
        cout << ex << endl;
        cout << "Error with divide by 1...." << endl;
    }
    catch (const char* ex)
    {
        cout << ex << endl;
    }
    catch (...)
    {
        cout << "Unknown error!" << endl;
    }

    cout << "Continue..." << endl;
    cout << "Continue..." << endl;
    cout << "Continue..." << endl;*/

    /*char login[100];
    char password[100];

    for (size_t i = 0; i < 5; i++)
    {
        cout << "Enter login: "; cin >> login;
        cout << "Enter password: "; cin >> password;

        try
        {
            Validation(login, password);
        }
        catch (PasswordInvalidException ex)
        {
            cout << "Invalid... do something... " << endl;
            cout << ex.what() << endl;
            cout << "You need to use A-z, a-z, 0-9" << endl;
        }
        catch (PasswordIsSmallException ex)
        {
            cout << "Too small... do something... " << endl;
            ex.Message();
            cout << "Length must be more than 6 symbols" << endl;
        }
        catch (exception& ex)
        {
            cout << "\nGeneral error: " << endl;
            cout << ex.what() << endl;
        }
        catch (...)
        {
            cout << "Unknown exception" << endl;
        }
    }*/

    /*MyArr arr(8);
    arr.Print();

    try
    {
        cout << "Element: " << arr[2] << endl;
        //cout << "Element: " << arr[100] << endl;

        //arr.CheckLength(-10);

        arr.SetSize(-7);
    }
    catch (out_of_range ex)
    {
        cout << ex.what() << endl;
    }
    catch (invalid_argument ex)
    {
        cout << "Invalid argument" << endl;
        cout << ex.what() << endl;
    }
    catch (logic_error ex)
    {
        cout << "Logic error" << endl;
        cout << ex.what() << endl;
    }
    catch (exception ex)
    {
        cout << "Exception catch" << endl;
        cout << ex.what() << endl;
    }*/

    int size;
    cout << "Enter size of stack: "; cin >> size;

    try
    {
        Stack st(size);
        st.Push(4);
        st.Print();
        //st.Push(1);
        st.Pop();
        st.Print();
        st.Pop();
    }
    catch (invalid_argument ex)
    {
        cout << ex.what() << endl;
    }
    catch (out_of_range ex)
    {
        cout << ex.what() << endl;
    }
    catch (logic_error ex)
    {
        cout << ex.what() << endl;
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
    }
}