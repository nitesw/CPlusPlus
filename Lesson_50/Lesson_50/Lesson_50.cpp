#include <iostream>
using namespace std;

class Animal // abstract class
{
protected:
    float weight;
    int speed;
    string type;
    string name;
    string place;
public:
    Animal() :weight(0), speed(0), type(""), name(""), place("") {}
    Animal(float w, int s, string t, string n, string p) :type(t), name(n), place(p) 
    {
        this->weight = w > 0 ? w : 0;
        this->speed = s > 0 ? s : 0;
    }
    
    void Print()const
    {
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Type: " << type << endl;
        cout << "Name: " << name << endl;
        cout << "Place: " << place << endl;
    }

    virtual void Move()const
    {
        cout << "I am moving..." << endl;
    }
    virtual void MakeSound()const = 0;// pure virtual method
};

class Lion : public Animal
{
    int soundStrength;
public:
    Lion() :soundStrength(0), Animal() {}
    Lion(float w, int s, string t, string n, string p, int sound) :soundStrength(sound), Animal(w, s, t, n, p) {}

    void MakeSound()const override
    {
        cout << "Rrrrrrrrrrrrrrr-rrrrrrrr-rrrrrrr" << endl;
        cout << "I have Sound Strength: " << soundStrength << " db" << endl;
    }
    void Move()const
    {
        cout << "I am running with speed of: " << speed << " km/h" << endl;
    }
};
class Duck : public Animal
{
    float flyHeight;
public:
    Duck() :flyHeight(0), Animal() {}
    Duck(float w, int s, string t, string n, string p, float h) :flyHeight(h), Animal(w, s, t, n, p) {}

    void MakeSound()const override
    {
        cout << "Kra-kra-kra-kra-kra" << endl;
    }
    void Move()const
    {
        cout << "I am swimming and flying up to: " << flyHeight << " km" << endl;
    }
};
class Reptile : public Animal
{
protected:
    float swimDeep;
public:
    Reptile() :swimDeep(0), Animal() {}
    Reptile(float w, int s, string t, string n, string p, float d) :swimDeep(d), Animal(w, s, t, n, p) {}

    void Move()const
    {
        cout << "I am diving up to: " << swimDeep << " km" << endl;
    }
};
class Frog : public Reptile
{
    float jumpLength;
public:
    Frog() :jumpLength(0), Reptile() {}
    Frog(float w, int s, string t, string n, string p, float d, float j) :jumpLength(j), Reptile(w, s, t, n, p, d) {}

    void MakeSound()const override
    {
        cout << "Kwah-kwah-kwah-kwah-kwah" << endl;
    }
};

void RollCall(Animal& animal)
{
    animal.MakeSound();
    animal.Move();
    animal.Print();
    cout << "____________________" << endl;
}

int main()
{
    Lion lion(190, 75, "Predator", "Lion", "Africa", 114);
    lion.MakeSound();
    lion.Move();
    lion.Print();
    cout << endl;

    Duck duck(1, 15, "Bird", "Duck", "Lake", 2);
    duck.MakeSound();
    duck.Move();
    duck.Print();
    cout << endl;

    Frog frog(0.1, 16, "Reptile", "Frog", "Swamp", 0.5, 30);

    RollCall(duck);
    RollCall(lion);
    RollCall(frog);
}
