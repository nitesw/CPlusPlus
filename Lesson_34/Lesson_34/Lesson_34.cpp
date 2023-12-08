#include <iostream>
#include <fstream>
using namespace std;
/*
struct Player
{
    string name;
    short age;
    int games;
    int goals;
};

void PrintPlayer(Player& player)
{
    cout << "Name : " << player.name << endl;
    cout << "Age : " << player.age << endl;
    cout << "Games : " << player.games << endl;
    cout << "Goals : " << player.goals << endl;
}
void InitPlayer(Player& player)
{
    cout << "Name : "; cin >> player.name;
    cout << "Age : "; cin >> player.age;
    player.games = 0;
    player.goals = 0;
}
void AddGameToPlayer(Player& player, int goals = 0)
{
    ++player.games;
    player.goals += goals;
}
*/

class Player
{
private:
    string name;
    short age;
    int games;
    int goals;

public:
    void PrintPlayer()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Games : " << games << endl;
        cout << "Goals : " << goals << endl;
    }
    void Initialize()
    {
        name = "no name";
        age = 0;
        games = 0;
        goals = 0;
    }
    void InitPlayerFromKeyboard()
    {
        cout << "Name : "; cin >> name;
        cout << "Age : "; cin >> age;
    }
    bool IsValidGoals(int goals)
    {
        return goals >= 0;
    }
    void AddGame(int goals = 0)
    {
        ++games;
        if(IsValidGoals(goals))
            this->goals += goals;
        //goals += goals;
    }
};

class Student
{
private:
    string name;
    int marks[3];

public:
    double GetAvarage()
    {
        double sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += marks[i];
        }
        return sum / 3;
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setMark(int mark, int index)
    {
        if (mark < 1 || mark > 12)
            mark = 0;
        marks[index] = mark;
    }
    int getMark(int index)
    {
        return marks[index];
    }
};

class Dot
{
private:
    int x;
    int y;
    int z;
public:
    void setX(int x = 0)
    {
        this->x = x;
    }
    int getX()
    {
        return x;
    }
    void setY(int y = 0)
    {
        this->y = y;
    }
    int getY()
    {
        return y;
    }
    void setZ(int z = 0)
    {
        this->z = z;
    }
    int getZ()
    {
        return z;
    }

    void PrintDot()
    {
        cout << "Coordinates: " << "X: " << getX() << " Y: " << getY() << " Z: " << getZ() << endl;
    }
    void InitDotFromKeyboard()
    {
        setX();
        setY();
        setZ();
        cout << "Coordinates of a dot by default: " << "X: " << getX() << " Y: " << getY() << " Z: " << getZ() << endl;

        cout << "Enter coordinates of dot (x, y, z): "; cin >> x >> y >> z;
        setX(x);
        setY(y);
        setZ(z);
        ofstream file("dot.txt");
        if (!file.is_open())
        {
            cout << "Error!" << endl;
        }
        else
        {
            file << getX() << endl;
            file << getY() << endl;
            file << getZ() << endl;
        }
    }
};

int main()
{
    //int a = 5;
    //int* pa = &a;
    //cout << a << endl;
    //cout << pa << endl;
    //cout << *pa << endl;

    /*Player player;
    InitPlayer(player);
    cout << endl << endl;
    PrintPlayer(player);

    cout << endl << endl;
    AddGameToPlayer(player, 2);
    AddGameToPlayer(player);
    AddGameToPlayer(player, 3);
    PrintPlayer(player);*/

    /*Player player;
    player.Initialize();
    player.InitPlayerFromKeyboard();
    cout << endl << endl;
    player.PrintPlayer();

    cout << endl << endl;
    player.AddGame();
    player.AddGame(5);
    player.AddGame(1);
    player.PrintPlayer();*/

    /*
    Student st; // object
    st.name = "Peter";
    st.marks[0] = 10;
    st.marks[1] = 7;
    st.marks[2] = 8;

    cout << "Name : " << st.name << ", Mark : " << st.marks[0] << endl;

    cout << "Avarage mark : " << st.GetAvarage() << endl;
    */

    /*
    Student st; // object
    st.setName("Peter");
    st.setMark(10, 0);
    st.setMark(7, 1);
    st.setMark(8, 2);

    cout << "Name : " << st.getName() << ", Mark : " << st.getMark(0) << endl;
    cout << "Avarage mark : " << st.GetAvarage() << endl;
    */

    Dot dot;
    
    dot.InitDotFromKeyboard();
    cout << endl;
    dot.PrintDot();
}