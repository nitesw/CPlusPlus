#include "Animals.h";

#pragma region MammalPrint
void Mammal::EditSpec()
{
    int spec;
    
    cout << "\n\t\t\tDoes your mammal have fur?" << endl;
    cout << "\t\t\t1. Yes" << endl;
    cout << "\t\t\t2. No" << endl;
    cout << "\t\t\tEnter your choice: ";
    cin >> spec;
    if (spec == 1)
    {
        this->fur = true;
    }
    else if (spec == 2)
    {
        this->fur = false;
    }
    else
    {
        cout << "\t\t\tInvalid choice. Assuming no fur." << endl;
        this->fur = false;
    }
    
}
void Mammal::Print()const
{
    cout << name << " (" << type << ")" << " - " << place << ", " << age << " yo, " << weight << " kg, " << speed << " km/h. ";
    if (fur)
    {
        cout << "I have fur." << endl;
    }
    else
    {
        cout << "I don't have fur." << endl;
    }
}
#pragma endregion


#pragma region BirdPrint
void Bird::EditSpec()
{
    int spec;

    cout << "\n\t\t\tDoes your Bird have feathers?" << endl;
    cout << "\t\t\t1. Yes" << endl;
    cout << "\t\t\t2. No" << endl;
    cout << "\t\t\tEnter your choice: ";
    cin >> spec;
    if (spec == 1)
    {
        this->feathers = true;
    }
    else if (spec == 2)
    {
        this->feathers = false;
    }
    else
    {
        cout << "\t\t\tInvalid choice. Assuming no feathers." << endl;
        this->feathers = false;
    }
}
void Bird::Print()const
{
    cout << name << " (" << type << ")" << " - " << place << ", " << age << " yo, " << weight << " kg, " << speed << " km/h. ";
    if (feathers)
    {
        cout << "I have feathers." << endl;
    }
    else
    {
        cout << "I don't have feathers." << endl;
    }
}
#pragma endregion


#pragma region FishPrint
void Fish::EditSpec()
{
    int spec;

    cout << "\n\t\t\tDoes your fish have scales?" << endl;
    cout << "\t\t\t1. Yes" << endl;
    cout << "\t\t\t2. No" << endl;
    cout << "\t\t\tEnter your choice: ";
    cin >> spec;
    if (spec == 1)
    {
        this->scales = true;
    }
    else if (spec == 2)
    {
        this->scales = false;
    }
    else
    {
        cout << "\t\t\tInvalid choice. Assuming no scales." << endl;
        this->scales = false;
    }
}
void Fish::Print()const
{
    cout << name << " (" << type << ")" << " - " << place << ", " << age << " yo, " << weight << " kg, " << speed << " km/h. ";
    if (scales)
    {
        cout << "I have scales." << endl;
    }
    else
    {
        cout << "I don't have scales." << endl;
    }
}
#pragma endregion


#pragma region ReptilePrint
void Reptile::EditSpec()
{
    int spec;

    cout << "\n\t\t\tDoes your reptile have teeth?" << endl;
    cout << "\t\t\t1. Yes" << endl;
    cout << "\t\t\t2. No" << endl;
    cout << "\t\t\tEnter your choice: ";
    cin >> spec;
    if (spec == 1)
    {
        this->teeth = true;
    }
    else if (spec == 2)
    {
        this->teeth = false;
    }
    else
    {
        cout << "\t\t\tInvalid choice. Assuming no teeth." << endl;
        this->teeth = false;
    }
}
void Reptile::Print()const
{
    cout << name << " (" << type << ")" << " - " << place << ", " << age << " yo, " << weight << " kg, " << speed << " km/h. ";
    if (teeth)
    {
        cout << "I have teeth." << endl;
    }
    else
    {
        cout << "I don't have teeth." << endl;
    }
}
#pragma endregion


#pragma region AmphibianPrint
void Amphibian::EditSpec()
{
    int spec;

    cout << "\n\t\t\tDoes your amphibian have legs?" << endl;
    cout << "\t\t\t1. Yes" << endl;
    cout << "\t\t\t2. No" << endl;
    cout << "\t\t\tEnter your choice: ";
    cin >> spec;
    if (spec == 1)
    {
        this->legs = true;
    }
    else if (spec == 2)
    {
        this->legs = false;
    }
    else
    {
        cout << "\t\t\tInvalid choice. Assuming no legs." << endl;
        this->legs = false;
    }
}
void Amphibian::Print()const
{
    cout << name << " (" << type << ")" << " - " << place << ", " << age << " yo, " << weight << " kg, " << speed << " km/h. ";
    if (legs)
    {
        cout << "I have legs." << endl;
    }
    else
    {
        cout << "I don't have legs." << endl;
    }
}
#pragma endregion