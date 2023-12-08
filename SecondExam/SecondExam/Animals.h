#pragma once
#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <string>
using namespace std;

class Animal
{
protected:
    double weight;
    double speed;
    string type;
    string name;
    string place;
    int age;
public:
    Animal() :weight(0), speed(0), type(""), name(""), place(""), age(0) {}
    Animal(double w, double s, string t, string n, string p, int a) :type(t), name(n), place(p)
    {
        this->weight = w > 0 ? w : 0;
        this->speed = s > 0 ? s : 0;
        this->age = a > 0 ? a : 0;
    }
    
    double GetWeight()const { return weight; }
    double GetSpeed()const { return speed; }
    string GetType()const { return type; }
    string GetName()const { return name; }
    string GetPlace()const { return place; }
    int GetAge()const { return age; }

    void SetWeight(double weight) { this->weight = weight; }
    void SetSpeed(double speed) { this->speed = speed; }
    void SetName(string name) { this->name = name; }
    void SetPlace(string place) { this->place = place; }
    void SetAge(int age) { this->age = age; }

    virtual void Print()const = 0;
    virtual bool GetSpec()const = 0;
    virtual void EditSpec() = 0;
    virtual void SetSpec(bool spec) = 0;
};


#pragma region Mammal
class Mammal : public Animal
{
protected:
    bool fur;
public:
    Mammal() :Animal(), fur(0) {}
    Mammal(double w, double s, string n, string p, int a, bool f) :Animal(w > 0 ? w : 0, s > 0 ? s : 0, "Mammal", n, p, a > 0 ? a : 0), fur(f) {}

    bool GetSpec()const override { return fur; }
    void EditSpec()override;

    void SetSpec(bool spec)override { this->fur = spec; }

    void Print()const override;
};
#pragma endregion


#pragma region Bird
class Bird : public Animal
{
protected:
    bool feathers;
public:
    Bird() :Animal(), feathers(0) {}
    Bird(double w, double s, string n, string p, int a, bool f) :Animal(w > 0 ? w : 0, s > 0 ? s : 0, "Bird", n, p, a > 0 ? a : 0), feathers(f) {}

    bool GetSpec()const override { return feathers; }
    void EditSpec()override;

    void SetSpec(bool spec)override { this->feathers = spec; }

    void Print()const override;
};
#pragma endregion


#pragma region Fish
class Fish : public Animal
{
protected:
    bool scales;
public:
    Fish() :Animal(), scales(0) {}
    Fish(double w, double s, string n, string p, int a, bool scales) :Animal(w > 0 ? w : 0, s > 0 ? s : 0, "Fish", n, p, a > 0 ? a : 0), scales(scales) {}

    bool GetSpec()const override { return scales; }
    void EditSpec()override;

    void SetSpec(bool spec)override { this->scales = spec; }

    void Print()const override;
};
#pragma endregion


#pragma region Reptile
class Reptile : public Animal
{
protected:
    bool teeth;
public:
    Reptile() :Animal(), teeth(0) {}
    Reptile(double w, double s, string n, string p, int a, bool t) :Animal(w > 0 ? w : 0, s > 0 ? s : 0, "Reptile", n, p, a > 0 ? a : 0), teeth(t) {}

    bool GetSpec()const override { return teeth; }
    void EditSpec()override;

    void SetSpec(bool spec)override { this->teeth = spec; }

    void Print()const override;
};
#pragma endregion


#pragma region Amphibian
class Amphibian : public Animal
{
protected:
    bool legs;
public:
    Amphibian() :Animal(), legs(0) {}
    Amphibian(double w, double s, string n, string p, int a, bool l) :Animal(w > 0 ? w : 0, s > 0 ? s : 0, "Amphibian", n, p, a > 0 ? a : 0), legs(l) {}

    bool GetSpec()const override { return legs; }
    void EditSpec()override;

    void SetSpec(bool spec)override { this->legs = spec; }

    void Print()const override;
};
#pragma endregion