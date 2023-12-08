#include <iostream>
using namespace std;

class Animal
{
protected:
    string species;
    int speed;
    float weight;
    string livingEnvironment;
    string movement;
    string saying;
public:
    Animal() :species("no species"), speed(0), weight(0), livingEnvironment("no living environment"), movement("no movement"), saying("no saying") {}
    Animal(string s, int sp, float w, string lV) :species(s), speed(sp), weight(w), livingEnvironment(lV) {}

    void Movement(string m)
    {
        this->movement = m;
    }
    void Say(string s)
    {
        this->saying = s;
    }

    void Print()
    {
        cout << species << ": " << speed << " km/h, " << weight << " kg, " << livingEnvironment << ", " << movement << ", " << saying << endl;
    }
};

class Bird : public Animal
{
protected:
    float lengthOfBird;
    string color;
public:
    Bird() :lengthOfBird(0), color("no color"), Animal() {}
    Bird(float l, string s, int sp, float w, string lV) :lengthOfBird(l), Animal(s, sp, w, lV) {}

    void ColorOfFeathers(string color)
    {
        this->color = color;
    }

    void Print()
    {
        Animal::Print();
        cout << color << ", " << lengthOfBird << " cm" << endl;
    }
};
class Fish : public Animal
{
protected:
    float lengthOfFish;
    string color;
public:
    Fish() :lengthOfFish(0), color("no color"), Animal() {}
    Fish(float l, string s, int sp, float w, string lV) :lengthOfFish(l), Animal(s, sp, w, lV) {}

    void ColorOfFishScale(string color)
    {
        this->color = color;
    }

    void Print()
    {
        Animal::Print();
        cout << color << ", " << lengthOfFish << " cm" << endl;
    }
};
class Reptile : public Animal
{
protected:
    float lengthOfReptile;
    string color;
public:
    Reptile() :lengthOfReptile(0), color("no color"), Animal() {}
    Reptile(float l, string s, int sp, float w, string lV) :lengthOfReptile(l), Animal(s, sp, w, lV) {}

    void ColorOfSkin(string color)
    {
        this->color = color;
    }

    void Print()
    {
        Animal::Print();
        cout << color << ", " << lengthOfReptile << " cm" << endl;
    }
};

class Crow : public Bird
{
    int lengthOfBeak;
public:
    Crow() :lengthOfBeak(0), Bird() {}
    Crow(int lOB, float l, string s, int sp, float w, string lV) :lengthOfBeak(lOB), Bird(l, s, sp, w, lV) {}

    void Print()
    {
        Bird::Print();
        cout << "Length of beak: " << lengthOfBeak << " cm" << endl;
    }
};

class Megalodon : public Fish
{
    int amountOfTeeth;
public:
    Megalodon() :amountOfTeeth(0), Fish() {}
    Megalodon(int aOT, float l, string s, int sp, float w, string lV) :amountOfTeeth(aOT), Fish(l, s, sp, w, lV) {}

    void Print()
    {
        Fish::Print();
        cout << "Amount of teeth: " << amountOfTeeth << endl;
    }
};

class Crocodile : public Reptile
{
    int lengthOfTail;
public:
    Crocodile() :lengthOfTail(0), Reptile() {}
    Crocodile(int lOT, float l, string s, int sp, float w, string lV) :lengthOfTail(lOT), Reptile(l, s, sp, w, lV) {}

    void Print()
    {
        Reptile::Print();
        cout << "Length of tail: " << lengthOfTail << endl;
    }
};

int main()
{
    Crow crow(3, 15.2, "Bird", 12, 4.6, "Cities");
    crow.ColorOfFeathers("Black");
    crow.Movement("Fly");
    crow.Say("Car!");
    crow.Print();
    cout << endl;
    
    Megalodon megalodon(276, 1800, "Fish", 5, 7000, "Sea");
    megalodon.ColorOfFishScale("Blue and White");
    megalodon.Movement("Swim");
    megalodon.Say("Blup! Blup!");
    megalodon.Print();
    cout << endl;

    Crocodile crocodile(2, 400, "Reptile", 3, 300, "Sea");
    crocodile.ColorOfSkin("Dark Green");
    crocodile.Movement("Walk");
    crocodile.Say("Arhhh!");
    crocodile.Print();
}