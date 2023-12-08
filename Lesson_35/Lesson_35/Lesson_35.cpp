#include <iostream>
using namespace std;

int Max(int a, int b)
{
    return a > b ? a : b;
}
float Max(float a, float b)
{
    return a > b ? a : b;
}
int Max(int a, int b, int c)
{
    return a > b ? a : b;
}

struct date
{
    int day;
    int month;
    int year;
};

class Student
{
private:
    string name;
    string surname;
    string last_name;
    date birth_date;
    string phone;
    string city;
    string country;
    string education;
    string education_city;
    string education_country;
    int number_group;
    int* marks;
    int markCount;
    float avarageMark;
    void SetAvarage()
    {
        float sum = 0;
        for (size_t i = 0; i < markCount; i++)
        {
            sum += marks[i];
        }
        avarageMark =(float) sum / markCount;
    }

public:
    // ctor + TAB
    Student()
    {
        cout << "Constructor " << name << endl;
        name = "no name";
        surname = "no surname";
        last_name = "no last_name";
        birth_date = { 0,0,0 };
        phone = "no phone";
        city = "no city";
        country = "no country";
        education = "no education";
        education_city = "no education_city";
        education_country = "no education_country";
        number_group = 0;
        marks = nullptr;
        markCount = 0;
        avarageMark = 0;
    }
    Student(string name)
    {
        cout << "Constructor invocation...." << endl;
        this->name = name;
    }
    Student(string name, string lastname)
    {
        cout << "Constructor invocation...." << endl;
        this->name = name;
        this->last_name = lastname;
    }
    Student(string name, string lastname, int num)
    {
        cout << "Constructor invocation...." << endl;
        this->name = name;
        this->last_name = lastname;
        this->number_group = num;
    }
// #region
#pragma region Methods
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setLastname(string lastname)
    {
        this->last_name = lastname;
    }
    string getLastname()
    {
        return last_name;
    }
    void setSurname(string surname)
    {
        this->surname = surname;
    }
    string getSurname()
    {
        return surname;
    }
    void setBirthday(date d)
    {
        this->birth_date.day = d.day;
        this->birth_date.month = d.month;
        this->birth_date.year = d.year;
    }
    date getBirthday()
    {
        return birth_date;
    }
    void setPhone(string phone)
    {
        this->phone = phone;
    }
    string getPhone()
    {
        return phone;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    string getCity()
    {
        return city;
    }

    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Last name: " << last_name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Birthdate: " << birth_date.day << "/" << birth_date.month << "/" << birth_date.year << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << country << endl;
        cout << "Education place: " << education << endl;
        cout << "Education city: " << education_city << endl;
        cout << "Education country: " << education_country << endl;
        cout << "Number of a group: " << number_group << endl;
        cout << "Marks: ";
        for (size_t i = 0; i < markCount; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Avarage mark: " << avarageMark << endl;
    }
    void Init()
    {
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Last name: "; cin >> last_name;
        cout << "Enter Surname: "; cin >> surname;
        cout << "Enter Birthdate: "; cin >> birth_date.day; cin >> birth_date.month; cin >> birth_date.year;
        cout << "Enter Phone: "; cin >> phone;
        cout << "Enter City: "; cin >> country;
        cout << "Enter Education place: "; cin >> education;
        cout << "Enter Education city: "; cin >> education_city;
        cout << "Enter Education country: "; cin >> education_country;
        cout << "Enter Number of a group: "; cin >> number_group;
    }

    void AddMark(int mark)
    {
        markCount++;
        int* temp = new int[markCount];
        for (size_t i = 0; i < markCount - 1; i++)
        {
            temp[i] = marks[i];
        }
        temp[markCount - 1] = mark;
        if (marks != nullptr) delete[] marks;
        marks = temp;
        SetAvarage();
    }
    void Delete()
    {
        if (marks != nullptr) delete[] marks;
    }
#pragma endregion
    
    // ~ + TAB
    ~Student()
    {
        cout << "Destructor " << name << endl;
        Delete();
    }
};

int main()
{
    Student st; // default c-tor
    st.setName("Vasya");
    st.AddMark(12);
    st.AddMark(8);
    st.AddMark(6);
    st.AddMark(3);
    st.AddMark(11);
    st.AddMark(10);
    st.AddMark(4);
    st.Print();
    cout << endl << endl;
    /*st.Init();
    cout << endl << endl;
    st.Print();

    st.setCity("Kyiv");
    st.setPhone("+380675961456");
    cout << endl << endl;
    st.Print();*/

    Student st2;
    st2.setName("Ivan");
    cout << endl << endl;

    Student student("Andrii", "Pedos");
    student.Print();
    cout << endl << endl;
    Student student2("Andrii", "Pedos", 123);
    student2.Print();
}