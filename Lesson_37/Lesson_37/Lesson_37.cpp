#include <iostream>
using namespace std;

inline void Hello()
{
    cout << "Hello world!" << endl;
}

class Human
{
private:
    string name;
    int age;
    int weight;
    static int countHuman;
public:
    static int getCount()
    {
        return countHuman;
    }
    Human():name(""), age(0), weight(0)
    {
        countHuman++;
        /*name = "";
        age = 0;
        weight = 0;*/
    }
    Human(string name):Human()
    {
        this->name = name;
        /*age = 0;
        weight = 0;*/
    }
    Human(string name, int age):Human(name)
    {
        //this->name = name;
        this->age = age;
        //weight = 0;
    }
    Human(string name, int age, int weight):Human(name, age)
    {
        /*this->name = name;
        this->age = age;*/
        this->weight = weight;
    }
    
    void Show()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
        cout << "Count of human: " << countHuman << endl;
    }

    ~Human()
    {
        countHuman--;
    }
};

int Human::countHuman = 0;

int main()
{
    //Hello();

    Human h;
    Human h2("Petro");
    Human h3("Ivan", 20);

    h.Show();
    cout << endl;
    h2.Show();
    cout << endl;
    h3.Show();
    cout << endl;
    if (true)
    {
        Human h4("Kolya", 12, 40);
        h4.Show();
        cout << endl;
    }

    cout << "Count of human: " << h.getCount() << endl;
    cout << "Count of human: " << h2.getCount() << endl;
    cout << "Count of human: " << h3.getCount() << endl;
    cout << "Count of human: " << Human::getCount() << endl;
}