#include <iostream>
using namespace std;

class Student
{
protected:
    string name;
    string specialization;
    int* marks;
    int markCount;
public:
    Student() :name(""), specialization(""), marks(nullptr), markCount(0) {}
    Student(string n, string s) :name(n), specialization(s)
    {
        markCount = rand() % 10 + 1;
        marks = new int[markCount];
        for (size_t i = 0; i < markCount; i++)
        {
            marks[i] = rand() % 5 + 8;
        }
    }
    virtual void Print()const
    {
        cout << "\nName: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Marks: ";
        for (size_t i = 0; i < markCount; i++)
        {
            cout << marks[i] << " ";
        }
        cout << "\n_________________________________" << endl;
    }
    virtual ~Student()
    {
        if (marks != nullptr) delete[] marks;
    }
};

class Aspirant : public Student
{
    string* subjects;
    int countSubjects;
public:
    Aspirant(string n, string s, initializer_list<string> list) : Student(n, s) 
    {
        this->countSubjects = list.size();
        subjects = new string[countSubjects];
        int i = 0;
        for (string s : list)
        {
            subjects[i] = s;
            i++;
        }
    }

    void Print()const
    {
        Student::Print();
        cout << "Subject: ";
        for (size_t i = 0; i < countSubjects; i++)
        {
            cout << subjects[i] << " ";
        }
        cout << endl;
    }

    ~Aspirant() override
    {
        if (subjects != nullptr) delete[] subjects;
    }
};

int main()
{
    srand(time(0));

    Student student("Boban Jr.", "Programmer");
    student.Print();

    Aspirant aspirant("Boban", "Water Engineer", { "Recuperation", "Math", "Pump" });
    aspirant.Print();

    Student* groups[3]
    {
        new Student("Boban Jr.", "Programmer"),
        new Aspirant("Boban", "Water Engineer", { "Recuperation", "Math", "Pump" }),
        new Aspirant("Nickki", "Design", { "UI/UX", "Pattern", "Main page" })
    };
    for (size_t i = 0; i < 3; i++)
    {
        groups[i]->Print();
        delete groups[i];
    }
}